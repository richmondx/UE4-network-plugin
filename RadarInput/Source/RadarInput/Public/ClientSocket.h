// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Networking.h"
/**
 * 
 */
DECLARE_DELEGATE_OneParam(FReceiveDataDelegate, TArray<uint8>)
class RADARINPUT_API ClientSocket:public FRunnable
{
public:
	ClientSocket(FSocket* socket);
	~ClientSocket();
	virtual bool Init() override;
	virtual uint32 Run() override;
	virtual void Stop() override;
	FReceiveDataDelegate OnReceiveListener;
private:
	FSocket* mSocket;
	
	bool bStopTag;
	
};
