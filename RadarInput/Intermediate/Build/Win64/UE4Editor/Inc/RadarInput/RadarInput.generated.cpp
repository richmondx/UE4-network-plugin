// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Boilerplate C++ definitions for a single module.
	This is automatically generated by UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Public/RadarInput.h"
#include "RadarInput.generated.dep.h"
PRAGMA_DISABLE_OPTIMIZATION
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCode1RadarInput() {}
FName RADARINPUT_OnReceiveDatas = FName(TEXT("OnReceiveDatas"));
FName RADARINPUT_OnTouch = FName(TEXT("OnTouch"));
	void UServerSocket::StaticRegisterNativesUServerSocket()
	{
	}
	IMPLEMENT_CLASS(UServerSocket, 2915159747);
	void ANetWorkManager::OnReceiveDatas(TArray<FVector2D> const& datas)
	{
		NetWorkManager_eventOnReceiveDatas_Parms Parms;
		Parms.datas=datas;
		ProcessEvent(FindFunctionChecked(RADARINPUT_OnReceiveDatas),&Parms);
	}
	void ANetWorkManager::StaticRegisterNativesANetWorkManager()
	{
		FNativeFunctionRegistrar::RegisterFunction(ANetWorkManager::StaticClass(), "OnReceiveDatas",(Native)&ANetWorkManager::execOnReceiveDatas);
		FNativeFunctionRegistrar::RegisterFunction(ANetWorkManager::StaticClass(), "StopReceive",(Native)&ANetWorkManager::execStopReceive);
	}
	IMPLEMENT_CLASS(ANetWorkManager, 1514351637);
	void UTouchWidget::OnTouch(UWidget* widget)
	{
		TouchWidget_eventOnTouch_Parms Parms;
		Parms.widget=widget;
		ProcessEvent(FindFunctionChecked(RADARINPUT_OnTouch),&Parms);
	}
	void UTouchWidget::StaticRegisterNativesUTouchWidget()
	{
	}
	IMPLEMENT_CLASS(UTouchWidget, 1266141633);
#if USE_COMPILED_IN_NATIVES
// Cross Module References
	COREUOBJECT_API class UClass* Z_Construct_UClass_UObject();
	COREUOBJECT_API class UScriptStruct* Z_Construct_UScriptStruct_FVector2D();
	ENGINE_API class UClass* Z_Construct_UClass_AActor();
	UMG_API class UClass* Z_Construct_UClass_UWidget_NoRegister();
	UMG_API class UClass* Z_Construct_UClass_UUserWidget();

	RADARINPUT_API class UClass* Z_Construct_UClass_UServerSocket_NoRegister();
	RADARINPUT_API class UClass* Z_Construct_UClass_UServerSocket();
	RADARINPUT_API class UFunction* Z_Construct_UFunction_ANetWorkManager_OnReceiveDatas();
	RADARINPUT_API class UFunction* Z_Construct_UFunction_ANetWorkManager_StopReceive();
	RADARINPUT_API class UClass* Z_Construct_UClass_ANetWorkManager_NoRegister();
	RADARINPUT_API class UClass* Z_Construct_UClass_ANetWorkManager();
	RADARINPUT_API class UFunction* Z_Construct_UFunction_UTouchWidget_OnTouch();
	RADARINPUT_API class UClass* Z_Construct_UClass_UTouchWidget_NoRegister();
	RADARINPUT_API class UClass* Z_Construct_UClass_UTouchWidget();
	RADARINPUT_API class UPackage* Z_Construct_UPackage__Script_RadarInput();
	UClass* Z_Construct_UClass_UServerSocket_NoRegister()
	{
		return UServerSocket::StaticClass();
	}
	UClass* Z_Construct_UClass_UServerSocket()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_UObject();
			Z_Construct_UPackage__Script_RadarInput();
			OuterClass = UServerSocket::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= 0x20100080;


				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("ServerSocket.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("Public/ServerSocket.h"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UServerSocket(Z_Construct_UClass_UServerSocket, &UServerSocket::StaticClass, TEXT("UServerSocket"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UServerSocket);
	UFunction* Z_Construct_UFunction_ANetWorkManager_OnReceiveDatas()
	{
		UObject* Outer=Z_Construct_UClass_ANetWorkManager();
		static UFunction* ReturnFunction = NULL;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("OnReceiveDatas"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), NULL, 0x08420C00, 65535, sizeof(NetWorkManager_eventOnReceiveDatas_Parms));
			UProperty* NewProp_datas = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("datas"), RF_Public|RF_Transient|RF_MarkAsNative) UArrayProperty(CPP_PROPERTY_BASE(datas, NetWorkManager_eventOnReceiveDatas_Parms), 0x0010000008000182);
			UProperty* NewProp_datas_Inner = new(EC_InternalUseOnlyConstructor, NewProp_datas, TEXT("datas"), RF_Public|RF_Transient|RF_MarkAsNative) UStructProperty(FObjectInitializer(), EC_CppProperty, 0, 0x0000000000000000, Z_Construct_UScriptStruct_FVector2D());
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("Radar"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/NetWorkManager.h"));
			MetaData->SetValue(NewProp_datas, TEXT("NativeConst"), TEXT(""));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_ANetWorkManager_StopReceive()
	{
		UObject* Outer=Z_Construct_UClass_ANetWorkManager();
		static UFunction* ReturnFunction = NULL;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("StopReceive"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), NULL, 0x04020401, 65535);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("Radar"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/NetWorkManager.h"));
#endif
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_ANetWorkManager_NoRegister()
	{
		return ANetWorkManager::StaticClass();
	}
	UClass* Z_Construct_UClass_ANetWorkManager()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_AActor();
			Z_Construct_UPackage__Script_RadarInput();
			OuterClass = ANetWorkManager::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= 0x20900080;

				OuterClass->LinkChild(Z_Construct_UFunction_ANetWorkManager_OnReceiveDatas());
				OuterClass->LinkChild(Z_Construct_UFunction_ANetWorkManager_StopReceive());

PRAGMA_DISABLE_DEPRECATION_WARNINGS
				UProperty* NewProp_receiveDatas = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("receiveDatas"), RF_Public|RF_Transient|RF_MarkAsNative) UArrayProperty(CPP_PROPERTY_BASE(receiveDatas, ANetWorkManager), 0x0010000000000014);
				UProperty* NewProp_receiveDatas_Inner = new(EC_InternalUseOnlyConstructor, NewProp_receiveDatas, TEXT("receiveDatas"), RF_Public|RF_Transient|RF_MarkAsNative) UStructProperty(FObjectInitializer(), EC_CppProperty, 0, 0x0000000000000000, Z_Construct_UScriptStruct_FVector2D());
				UProperty* NewProp_server = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("server"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(server, ANetWorkManager), 0x0020080000000014, Z_Construct_UClass_UServerSocket_NoRegister());
PRAGMA_ENABLE_DEPRECATION_WARNINGS
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_ANetWorkManager_OnReceiveDatas(), "OnReceiveDatas"); // 3838569643
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_ANetWorkManager_StopReceive(), "StopReceive"); // 2941107874
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("NetWorkManager.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("Public/NetWorkManager.h"));
				MetaData->SetValue(NewProp_receiveDatas, TEXT("Category"), TEXT("Radar"));
				MetaData->SetValue(NewProp_receiveDatas, TEXT("ModuleRelativePath"), TEXT("Public/NetWorkManager.h"));
				MetaData->SetValue(NewProp_server, TEXT("Category"), TEXT("Radar"));
				MetaData->SetValue(NewProp_server, TEXT("ModuleRelativePath"), TEXT("Public/NetWorkManager.h"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ANetWorkManager(Z_Construct_UClass_ANetWorkManager, &ANetWorkManager::StaticClass, TEXT("ANetWorkManager"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ANetWorkManager);
	UFunction* Z_Construct_UFunction_UTouchWidget_OnTouch()
	{
		UObject* Outer=Z_Construct_UClass_UTouchWidget();
		static UFunction* ReturnFunction = NULL;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("OnTouch"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), NULL, 0x08020800, 65535, sizeof(TouchWidget_eventOnTouch_Parms));
			UProperty* NewProp_widget = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("widget"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(widget, TouchWidget_eventOnTouch_Parms), 0x0010000000000080, Z_Construct_UClass_UWidget_NoRegister());
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("Radar"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/TouchWidget.h"));
#endif
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UTouchWidget_NoRegister()
	{
		return UTouchWidget::StaticClass();
	}
	UClass* Z_Construct_UClass_UTouchWidget()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_UUserWidget();
			Z_Construct_UPackage__Script_RadarInput();
			OuterClass = UTouchWidget::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= 0x20901080;

				OuterClass->LinkChild(Z_Construct_UFunction_UTouchWidget_OnTouch());

				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_UTouchWidget_OnTouch(), "OnTouch"); // 2581090889
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("TouchWidget.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("Public/TouchWidget.h"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UTouchWidget(Z_Construct_UClass_UTouchWidget, &UTouchWidget::StaticClass, TEXT("UTouchWidget"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UTouchWidget);
	UPackage* Z_Construct_UPackage__Script_RadarInput()
	{
		static UPackage* ReturnPackage = NULL;
		if (!ReturnPackage)
		{
			ReturnPackage = CastChecked<UPackage>(StaticFindObjectFast(UPackage::StaticClass(), NULL, FName(TEXT("/Script/RadarInput")), false, false));
			ReturnPackage->SetPackageFlags(PKG_CompiledIn | 0x00000080);
			FGuid Guid;
			Guid.A = 0x6AAE10DB;
			Guid.B = 0x1AB513A2;
			Guid.C = 0x00000000;
			Guid.D = 0x00000000;
			ReturnPackage->SetGuid(Guid);

		}
		return ReturnPackage;
	}
#endif

PRAGMA_ENABLE_DEPRECATION_WARNINGS
