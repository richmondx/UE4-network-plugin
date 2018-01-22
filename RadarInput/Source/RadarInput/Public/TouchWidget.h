// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Blueprint/UserWidget.h"
#include "TouchWidget.generated.h"

/**
 * 
 */
UCLASS()
class RADARINPUT_API UTouchWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual void OnReceivePoses(TArray<FVector2D> poses);

	virtual void NativeConstruct() override;
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

	TArray<UWidget*> cacheButtons;
	TArray<FVector2D> cachePoses;
	int currentUICount;
	bool showTestButton;
	//void RemoveWidget(UWidget* widget);
public:
	UFUNCTION(BlueprintImplementableEvent, Category = "Radar")
		void OnTouch(UWidget* widget);
	
};
