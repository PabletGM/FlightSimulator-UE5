// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "FlightSimulator/FlightSimulatorGameModeBase.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFlightSimulatorGameModeBase() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	FLIGHTSIMULATOR_API UClass* Z_Construct_UClass_AFlightSimulatorGameModeBase();
	FLIGHTSIMULATOR_API UClass* Z_Construct_UClass_AFlightSimulatorGameModeBase_NoRegister();
	UPackage* Z_Construct_UPackage__Script_FlightSimulator();
// End Cross Module References
	void AFlightSimulatorGameModeBase::StaticRegisterNativesAFlightSimulatorGameModeBase()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AFlightSimulatorGameModeBase);
	UClass* Z_Construct_UClass_AFlightSimulatorGameModeBase_NoRegister()
	{
		return AFlightSimulatorGameModeBase::StaticClass();
	}
	struct Z_Construct_UClass_AFlightSimulatorGameModeBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AFlightSimulatorGameModeBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_FlightSimulator,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AFlightSimulatorGameModeBase_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFlightSimulatorGameModeBase_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "FlightSimulatorGameModeBase.h" },
		{ "ModuleRelativePath", "FlightSimulatorGameModeBase.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AFlightSimulatorGameModeBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AFlightSimulatorGameModeBase>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AFlightSimulatorGameModeBase_Statics::ClassParams = {
		&AFlightSimulatorGameModeBase::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009002ACu,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AFlightSimulatorGameModeBase_Statics::Class_MetaDataParams), Z_Construct_UClass_AFlightSimulatorGameModeBase_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_AFlightSimulatorGameModeBase()
	{
		if (!Z_Registration_Info_UClass_AFlightSimulatorGameModeBase.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AFlightSimulatorGameModeBase.OuterSingleton, Z_Construct_UClass_AFlightSimulatorGameModeBase_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AFlightSimulatorGameModeBase.OuterSingleton;
	}
	template<> FLIGHTSIMULATOR_API UClass* StaticClass<AFlightSimulatorGameModeBase>()
	{
		return AFlightSimulatorGameModeBase::StaticClass();
	}
	AFlightSimulatorGameModeBase::AFlightSimulatorGameModeBase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AFlightSimulatorGameModeBase);
	AFlightSimulatorGameModeBase::~AFlightSimulatorGameModeBase() {}
	struct Z_CompiledInDeferFile_FID_FlightSimulator_UE5_FlightSimulator_Source_FlightSimulator_FlightSimulatorGameModeBase_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_FlightSimulator_UE5_FlightSimulator_Source_FlightSimulator_FlightSimulatorGameModeBase_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AFlightSimulatorGameModeBase, AFlightSimulatorGameModeBase::StaticClass, TEXT("AFlightSimulatorGameModeBase"), &Z_Registration_Info_UClass_AFlightSimulatorGameModeBase, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AFlightSimulatorGameModeBase), 1336927790U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_FlightSimulator_UE5_FlightSimulator_Source_FlightSimulator_FlightSimulatorGameModeBase_h_3777417604(TEXT("/Script/FlightSimulator"),
		Z_CompiledInDeferFile_FID_FlightSimulator_UE5_FlightSimulator_Source_FlightSimulator_FlightSimulatorGameModeBase_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_FlightSimulator_UE5_FlightSimulator_Source_FlightSimulator_FlightSimulatorGameModeBase_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
