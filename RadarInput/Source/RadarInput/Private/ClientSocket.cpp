// Fill out your copyright notice in the Description page of Project Settings.

#include "RadarInput.h"
#include "ClientSocket.h"
#include "Engine.h"

ClientSocket::ClientSocket(FSocket* socket)
{
	mSocket = socket;
}

ClientSocket::~ClientSocket()
{
}

bool ClientSocket::Init()
{
	bStopTag = false;
	return true;
}

uint32 ClientSocket::Run()
{
	while (!bStopTag)
	{
		if (mSocket == nullptr)
			return 0;
		uint32 dataSize;
		uint8 defaultElement = 0;
		TArray<uint8> tempDatas;
		TArray<uint8> receiveDatas;
		tempDatas.Empty();
		receiveDatas.Empty();
		while (mSocket->HasPendingData(dataSize))
		{
			tempDatas.Init(defaultElement, dataSize);
			int32 Readaded = 0;
			mSocket->Recv(tempDatas.GetData(), dataSize, Readaded);
			receiveDatas += tempDatas;
		}
		if (receiveDatas.Num() <= 0)
			continue;
		//处理接收到的数据
		OnReceiveListener.ExecuteIfBound(receiveDatas);
	}
	return 1;
}

void ClientSocket::Stop()
{
	bStopTag = true;
	mSocket->Close();
	ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->DestroySocket(mSocket);
}
