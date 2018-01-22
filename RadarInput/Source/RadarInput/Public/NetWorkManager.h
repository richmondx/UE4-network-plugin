// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "ServerSocket.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NetWorkManager.generated.h"

DECLARE_EVENT_OneParam(ANetWorkManager, AUpdateDataEvent, TArray<FVector2D>)
UCLASS()
class RADARINPUT_API ANetWorkManager : public AActor
{
	GENERATED_BODY()
		
public:	
	// Sets default values for this actor's properties
	ANetWorkManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	void StartServer(FIPv4Address ip, int32 port, const FString& desName = TEXT("PosSocket"), int32 bufferSize = 2048);
	void ReadConfig(FString Name, FIPv4Address& ip, int32& port);
	void OnConnect(ClientSocket* client);
	void OnReceiveFromClient(TArray<uint8> datas);
	UPROPERTY(BlueprintReadOnly, Category = "Radar")
	UServerSocket* server;
	FString receiveStr;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	AUpdateDataEvent updateEvent;
	UFUNCTION(BlueprintCallable, Category = "Radar")
		void StopReceive();
	UFUNCTION(BlueprintNativeEvent, Category = "Radar")
		void OnReceiveDatas(const TArray<FVector2D>& datas);
	void OnReceiveDatas_Implementation(const TArray<FVector2D>& datas);
	UPROPERTY(BlueprintReadOnly, Category = "Radar")
		TArray<FVector2D> receiveDatas;

	
};
