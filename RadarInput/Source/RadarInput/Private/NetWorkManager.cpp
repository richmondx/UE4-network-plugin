// Fill out your copyright notice in the Description page of Project Settings.

#include "RadarInput.h"
#include "NetWorkManager.h"
#include "XmlParser.h"
#include "XmlFile.h"
#include <string>
#include"Json.h"

// Sets default values
ANetWorkManager::ANetWorkManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ANetWorkManager::BeginPlay()
{
	Super::BeginPlay();
	FIPv4Address ip;
	int32 port;
	FString path = FPaths::Combine(FPaths::GamePluginsDir(), TEXT("RadarInput/Config.xml"));
	ReadConfig(path, ip, port);
	StartServer(ip, port);

}
void ANetWorkManager::OnConnect(ClientSocket* client)
{
	client->OnReceiveListener.BindUObject(this, &ANetWorkManager::OnReceiveFromClient);
}
void ANetWorkManager::ReadConfig(FString Name, FIPv4Address& ip, int32& port)
{
	if (FPlatformFileManager::Get().GetPlatformFile().FileExists(*Name))
	{
		try
		{
			FXmlFile* file = new FXmlFile(Name);
			FXmlNode* rootNode = file->GetRootNode();
			//TArray<FXmlNode*> childNodes = rootNode->GetChildrenNodes();
			FString strIP = rootNode->FindChildNode("ip")->GetContent();
			FString strPort = rootNode->FindChildNode("port")->GetContent();
			delete file;
			//提取服务器ip 与 端口
			FIPv4Address::Parse(strIP, ip);
			port = FCString::Atoi(*strPort);
		}
		catch (std::exception ex)
		{
			UE_LOG(LogTemp, Error, TEXT("Config xml formate open failed!"));
		}

	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Cann't find Config xml file"));
	}
}
void ANetWorkManager::StartServer(FIPv4Address ip, int32 port, const FString& desName /* = TEXT("PosSocket") */, int32 bufferSize /* = 2048 */)
{
	server = NewObject<UServerSocket>(this);
	server->OnConnect.BindUObject(this, &ANetWorkManager::OnConnect);
	server->Init(ip, port, desName, bufferSize);
	receiveStr = "";
}
// Called every frame
void ANetWorkManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ANetWorkManager::StopReceive()
{
	server->StopServer();
}

void ANetWorkManager::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	
	StopReceive();
	Super::EndPlay(EndPlayReason);
}
void ANetWorkManager::OnReceiveFromClient(TArray<uint8> datas)
{
	//UE_LOG(LogTemp, Warning, TEXT("receive pos num %d"), datas.Num());
	std::string cstr(reinterpret_cast<const char*>(&datas[0]), datas.Num());
	receiveStr += cstr.c_str();
	
	if (receiveStr.Find(TEXT("[/TCP]")) == -1)
	{
		UE_LOG(LogTemp, Error, TEXT("receive data imperfect !"));//未接受完整
	}
	else
	{
		FString jsonStr;
		jsonStr = receiveStr.Left(receiveStr.Find(TEXT("[/TCP]"))); //截取掉[/TCP]

		receiveStr = receiveStr.Right(receiveStr.Len() - receiveStr.Find(TEXT("[/TCP]")) - 6);

		TArray<TSharedPtr<FJsonValue>> jsonParsed;
		TSharedRef<TJsonReader<TCHAR>> jsonReader = TJsonReaderFactory<TCHAR>::Create(jsonStr);
		bool flag = FJsonSerializer::Deserialize(jsonReader, jsonParsed);
		if (flag)
		{
			TArray<FVector2D> results;
			for (int i = 0; i < jsonParsed.Num(); i++)
			{
				FVector2D pos;
				pos.X = FCString::Atof(*(jsonParsed[i]->AsObject()->GetStringField("X")));
				pos.Y = FCString::Atof(*(jsonParsed[i]->AsObject()->GetStringField("Y")));
				int id = FCString::Atoi(*(jsonParsed[i]->AsObject()->GetStringField("ID")));
				results.Add(pos);
			}
			OnReceiveDatas(results);
			updateEvent.Broadcast(results);
			receiveDatas = results;
		}
	}
		
		

	
}
void ANetWorkManager::OnReceiveDatas_Implementation(const TArray<FVector2D>& datas)
{
	
	UE_LOG(LogTemp, Warning, TEXT("receive pos num %d"), datas.Num());
}
