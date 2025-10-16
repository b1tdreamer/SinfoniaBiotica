// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "../FMODCallbackHandler.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFMODCallbackHandler() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UInterface();
	FMODSTUDIO_API UClass* Z_Construct_UClass_UFMODCallbackHandler();
	FMODSTUDIO_API UClass* Z_Construct_UClass_UFMODCallbackHandler_NoRegister();
	UPackage* Z_Construct_UPackage__Script_FMODStudio();
// End Cross Module References
	void UFMODCallbackHandler::StaticRegisterNativesUFMODCallbackHandler()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UFMODCallbackHandler);
	UClass* Z_Construct_UClass_UFMODCallbackHandler_NoRegister()
	{
		return UFMODCallbackHandler::StaticClass();
	}
	struct Z_Construct_UClass_UFMODCallbackHandler_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UFMODCallbackHandler_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UInterface,
		(UObject* (*)())Z_Construct_UPackage__Script_FMODStudio,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UFMODCallbackHandler_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UFMODCallbackHandler_Statics::Class_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/FMODCallbackHandler.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UFMODCallbackHandler_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<IFMODCallbackHandler>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UFMODCallbackHandler_Statics::ClassParams = {
		&UFMODCallbackHandler::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x000840A1u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UFMODCallbackHandler_Statics::Class_MetaDataParams), Z_Construct_UClass_UFMODCallbackHandler_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UFMODCallbackHandler()
	{
		if (!Z_Registration_Info_UClass_UFMODCallbackHandler.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UFMODCallbackHandler.OuterSingleton, Z_Construct_UClass_UFMODCallbackHandler_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UFMODCallbackHandler.OuterSingleton;
	}
	template<> FMODSTUDIO_API UClass* StaticClass<UFMODCallbackHandler>()
	{
		return UFMODCallbackHandler::StaticClass();
	}
	UFMODCallbackHandler::UFMODCallbackHandler(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UFMODCallbackHandler);
	UFMODCallbackHandler::~UFMODCallbackHandler() {}
	struct Z_CompiledInDeferFile_FID_BuildAgent1_work_c1c3f17eb167c494_build_staging_FMODStudio_HostProject_Plugins_FMODStudio_Source_FMODStudio_Public_FMODCallbackHandler_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_BuildAgent1_work_c1c3f17eb167c494_build_staging_FMODStudio_HostProject_Plugins_FMODStudio_Source_FMODStudio_Public_FMODCallbackHandler_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UFMODCallbackHandler, UFMODCallbackHandler::StaticClass, TEXT("UFMODCallbackHandler"), &Z_Registration_Info_UClass_UFMODCallbackHandler, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UFMODCallbackHandler), 2722193149U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_BuildAgent1_work_c1c3f17eb167c494_build_staging_FMODStudio_HostProject_Plugins_FMODStudio_Source_FMODStudio_Public_FMODCallbackHandler_h_592761129(TEXT("/Script/FMODStudio"),
		Z_CompiledInDeferFile_FID_BuildAgent1_work_c1c3f17eb167c494_build_staging_FMODStudio_HostProject_Plugins_FMODStudio_Source_FMODStudio_Public_FMODCallbackHandler_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_BuildAgent1_work_c1c3f17eb167c494_build_staging_FMODStudio_HostProject_Plugins_FMODStudio_Source_FMODStudio_Public_FMODCallbackHandler_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
