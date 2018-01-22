// Fill out your copyright notice in the Description page of Project Settings.

#include "RadarInput.h"
#include "TouchWidget.h"
#include "NetWorkManager.h"
#include "EngineUtils.h"
#include "Blueprint/WidgetTree.h"
#include "Blueprint/SlateBlueprintLibrary.h"
#include "Blueprint/WidgetLayoutLibrary.h"
#include "Components/CanvasPanelSlot.h"
#include "Components/Button.h"

void UTouchWidget::NativeConstruct()
{
	if (GetWorld())
	{
		TActorIterator<ANetWorkManager> actorItr = TActorIterator<ANetWorkManager>(GetWorld());
		if (actorItr && *actorItr != nullptr)
		{
			//存在数据源
			ANetWorkManager *net = *actorItr;
			net->updateEvent.AddUObject(this, &UTouchWidget::OnReceivePoses);
			//TArray<FVector> receivePoints = (*actorItr)
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("You are using touch Widget, but there is no NetWorkManager actor"));
		}	
		
	}
	showTestButton = false;
	currentUICount = 0;
	cacheButtons.Empty();
	cachePoses.Empty();
    Super::NativeConstruct();
	
}
float tempTime = 0;
void UTouchWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	tempTime += InDeltaTime;
	if(tempTime > 0.5)
	{
		if (GetWorld()->GetFirstPlayerController()->IsInputKeyDown(FKey("T")))
		{
			tempTime = 0;
			showTestButton = !showTestButton;
			FString message;
			if (showTestButton)
			{
				message = TEXT("开启调试按钮！");
			}
			else
			{
				message = TEXT("关闭调试按钮！");
			}
			if (GEngine)
			{
				GEngine->AddOnScreenDebugMessage(0, 5.0f, FColor::Red, message);
			}
		}
		
							
	}
	
	if (showTestButton && cachePoses.Num() > 0)
	{
		for (int i = 0; i < cachePoses.Num(); i++)
		{
			if(currentUICount > 240)
				UE_LOG(LogTemp, Warning, TEXT("ui count > 240, limist is 255 cann't display"));
			currentUICount++;
			
			if (cacheButtons.Num() > i)
			{
				UWidget* button = cacheButtons[i];
				UCanvasPanelSlot* buttonSlot = UWidgetLayoutLibrary::SlotAsCanvasSlot(button);
				buttonSlot->SetPosition(cachePoses[i]);
			}
			else
			{
				UButton* button = WidgetTree->ConstructWidget<UButton>(UButton::StaticClass());
				UPanelWidget* root = Cast<UPanelWidget>(GetRootWidget());
				UCanvasPanelSlot* buttonSlot = Cast<UCanvasPanelSlot>(root->AddChild(button));
				buttonSlot->SetSize(FVector2D(50, 50));
				buttonSlot->SetAnchors(FAnchors(0, 0));
				buttonSlot->SetPosition(cachePoses[i]);
				cacheButtons.Add(button);
			}
			
		}
		if (cacheButtons.Num() > cachePoses.Num())
		{
			for (int i = cacheButtons.Num() - 1; i >= cachePoses.Num() -1; i--)
			{
				cacheButtons[i]->RemoveFromParent();
				cacheButtons.RemoveAt(i);
			}
		}
	}
	else
	{
		for (int i = cacheButtons.Num() - 1; i >= 0; i--)
		{
			cacheButtons[i]->RemoveFromParent();
			cacheButtons.RemoveAt(i);
		}
	}
	//while (!testButtons.IsEmpty())
	//{
	//	//0.5s后删除button
	//	FTimerHandle timerHandle;
	//	UWidget* testBtn;
	//	testButtons.Dequeue(testBtn);
	//	FTimerDelegate removeDelegate = FTimerDelegate::CreateUObject(this, &UTouchWidget::RemoveWidget, testBtn);
	//	GetWorld()->GetTimerManager().SetTimer(timerHandle, removeDelegate, 1, false);
	//}
	Super::NativeTick(MyGeometry, InDeltaTime);
}
void UTouchWidget::OnReceivePoses(TArray<FVector2D> poses)
{
	
	currentUICount = 0;
	WidgetTree->ForEachWidget([&](UWidget* widget) {
		currentUICount++;
		FString name;
		widget->GetName(name);
		FVector2D positionInScreen;
		FVector2D positionInViewPort;
		USlateBlueprintLibrary::AbsoluteToViewport(GetWorld(), widget->GetCachedGeometry().AbsolutePosition, positionInScreen, positionInViewPort);		
		FVector2D size = widget->GetCachedGeometry().Size;
		
		FSlateRect boundRect(positionInViewPort, positionInViewPort +size);
		for (int i = 0; i < poses.Num(); i++)
		{
			if (boundRect.ContainsPoint(poses[i]))
			{
				OnTouch(widget);
				break;
			}
		}
	});
	cachePoses = poses;
	//if (showTestButton)
	//{
	//	
	//	for (int i = 0; i < poses.Num(); i++)
	//	{
	//		if (count > 240)
	//		{
	//			if (GEngine)
	//				GEngine->AddOnScreenDebugMessage(0, 5.0f, FColor::Red, "UI count too much, can't display test button");
	//			UE_LOG(LogTemp, Warning, TEXT("ui count > 240, limist is 255 cann't display"));
	//			return;
	//		}
	//		UButton* button = WidgetTree->ConstructWidget<UButton>(UButton::StaticClass());
	//		UPanelWidget* root = Cast<UPanelWidget>(GetRootWidget());
	//		UCanvasPanelSlot* childSlot = Cast<UCanvasPanelSlot>(root->AddChild(button));
	//		childSlot->SetSize(FVector2D(50, 50));
	//		childSlot->SetAnchors(FAnchors(0, 0));
	//		childSlot->SetPosition(poses[i]);
	//		testButtons.Enqueue(button);
	//		count++;
	//	}

	//}
}

//void UTouchWidget::RemoveWidget(UWidget* widget)
//{
//	widget->RemoveFromParent();
//}

