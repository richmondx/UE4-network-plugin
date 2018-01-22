// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Engine.h"
#include "Networking.h"
#include "ClientSocket.h"
#include "UObject/NoExportTypes.h"
#include "ServerSocket.generated.h"

/**
 * 
 */
DECLARE_DELEGATE_OneParam(FConnectDelegate, ClientSocket*)
UCLASS()
class RADARINPUT_API UServerSocket : public UObject
{
	GENERATED_BODY()
public:
	UServerSocket();
private:
	FIPv4Address ip;
	int32 port;
	FSocket* serverSocket;
	FTimerHandle connectHandler;
	TArray<FRunnableThread*> connectionThreads;
	
public:
	void Init(FIPv4Address ip, int32 port, const FString& desName, int32 bufferSize);
	void StopServer();
	FConnectDelegate OnConnect;
private:
	void ConnectCallback();

};
