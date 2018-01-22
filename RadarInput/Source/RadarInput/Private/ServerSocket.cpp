// Fill out your copyright notice in the Description page of Project Settings.

#include "RadarInput.h"
#include "ServerSocket.h"

UServerSocket::UServerSocket()
{
	
}
void UServerSocket::Init(FIPv4Address ip, int32 port, const FString& descriptionName, int32 bufferSize)
{
	this->ip = ip;
	this->port = port;
	serverSocket = NULL;
	serverSocket = FTcpSocketBuilder(*descriptionName).AsReusable()
		.BoundToAddress(ip)
		.BoundToPort(port)
		.Listening(8);
	if (!serverSocket)
	{
		UE_LOG(LogTemp, Error, TEXT("create server error"));
		return;
	}
	int32 newSize = 0;
	serverSocket->SetReceiveBufferSize(bufferSize, newSize);
	//添加定时器回调 处理连接逻辑
	UWorld* world = GetOuter()->GetWorld();
	world->GetTimerManager().SetTimer(connectHandler, this, &UServerSocket::ConnectCallback, 1.0, true);

}

void UServerSocket::StopServer()
{
	for (int i = 0; i < connectionThreads.Num(); i++)
	{
		connectionThreads[i]->Kill();
		delete connectionThreads[i];
		connectionThreads[i] = nullptr;
	}
	connectionThreads.Empty();
	if (serverSocket)
	{
		serverSocket->Close();
		ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->DestroySocket(serverSocket);
	}
	
}

void UServerSocket::ConnectCallback()
{
	bool pending = false;
	if (serverSocket->HasPendingConnection(pending) && pending)
	{
		//有客户端连接
		FSocket* socket = serverSocket->Accept(TEXT("Client Socket"));
		ClientSocket* client = new ClientSocket(socket);
		
		FRunnableThread *tempThread = FRunnableThread::Create(client, TEXT("RecvThread"));
		connectionThreads.Add(tempThread);
		OnConnect.ExecuteIfBound(client);
	}
}



