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
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
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
		static const UECodeGen_Private::FClassPropertyParams NewProp_AirplaneMap_ValueProp;
		static const UECodeGen_Private::FStrPropertyParams NewProp_AirplaneMap_Key_KeyProp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AirplaneMap_MetaData[];
#endif
		static const UECodeGen_Private::FMapPropertyParams NewProp_AirplaneMap;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SelectedAirplaneClass_MetaData[];
#endif
		static const UECodeGen_Private::FClassPropertyParams NewProp_SelectedAirplaneClass;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
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
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "FlightSimulatorGameModeBase.h" },
		{ "ModuleRelativePath", "FlightSimulatorGameModeBase.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_AFlightSimulatorGameModeBase_Statics::NewProp_AirplaneMap_ValueProp = { "AirplaneMap", nullptr, (EPropertyFlags)0x0004000000000001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, Z_Construct_UClass_UClass, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_AFlightSimulatorGameModeBase_Statics::NewProp_AirplaneMap_Key_KeyProp = { "AirplaneMap_Key", nullptr, (EPropertyFlags)0x0000000000000001, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFlightSimulatorGameModeBase_Statics::NewProp_AirplaneMap_MetaData[] = {
		{ "Category", "Airplanes" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Map for airplane names and their corresponding blueprints\n" },
#endif
		{ "ModuleRelativePath", "FlightSimulatorGameModeBase.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Map for airplane names and their corresponding blueprints" },
#endif
	};
#endif
	const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_AFlightSimulatorGameModeBase_Statics::NewProp_AirplaneMap = { "AirplaneMap", nullptr, (EPropertyFlags)0x0014000000010001, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFlightSimulatorGameModeBase, AirplaneMap), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AFlightSimulatorGameModeBase_Statics::NewProp_AirplaneMap_MetaData), Z_Construct_UClass_AFlightSimulatorGameModeBase_Statics::NewProp_AirplaneMap_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFlightSimulatorGameModeBase_Statics::NewProp_SelectedAirplaneClass_MetaData[] = {
		{ "Category", "Airplanes" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Reference to the selected airplane blueprint\n" },
#endif
		{ "ModuleRelativePath", "FlightSimulatorGameModeBase.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Reference to the selected airplane blueprint" },
#endif
	};
#endif
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_AFlightSimulatorGameModeBase_Statics::NewProp_SelectedAirplaneClass = { "SelectedAirplaneClass", nullptr, (EPropertyFlags)0x0014000000000014, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFlightSimulatorGameModeBase, SelectedAirplaneClass), Z_Construct_UClass_UClass, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AFlightSimulatorGameModeBase_Statics::NewProp_SelectedAirplaneClass_MetaData), Z_Construct_UClass_AFlightSimulatorGameModeBase_Statics::NewProp_SelectedAirplaneClass_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AFlightSimulatorGameModeBase_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFlightSimulatorGameModeBase_Statics::NewProp_AirplaneMap_ValueProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFlightSimulatorGameModeBase_Statics::NewProp_AirplaneMap_Key_KeyProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFlightSimulatorGameModeBase_Statics::NewProp_AirplaneMap,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFlightSimulatorGameModeBase_Statics::NewProp_SelectedAirplaneClass,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AFlightSimulatorGameModeBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AFlightSimulatorGameModeBase>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AFlightSimulatorGameModeBase_Statics::ClassParams = {
		&AFlightSimulatorGameModeBase::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AFlightSimulatorGameModeBase_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_AFlightSimulatorGameModeBase_Statics::PropPointers),
		0,
		0x009002ACu,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AFlightSimulatorGameModeBase_Statics::Class_MetaDataParams), Z_Construct_UClass_AFlightSimulatorGameModeBase_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AFlightSimulatorGameModeBase_Statics::PropPointers) < 2048);
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
	DEFINE_VTABLE_PTR_HELPER_CTOR(AFlightSimulatorGameModeBase);
	AFlightSimulatorGameModeBase::~AFlightSimulatorGameModeBase() {}
	struct Z_CompiledInDeferFile_FID_FlightSimulator_UE5_FlightSimulator_Source_FlightSimulator_FlightSimulatorGameModeBase_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_FlightSimulator_UE5_FlightSimulator_Source_FlightSimulator_FlightSimulatorGameModeBase_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AFlightSimulatorGameModeBase, AFlightSimulatorGameModeBase::StaticClass, TEXT("AFlightSimulatorGameModeBase"), &Z_Registration_Info_UClass_AFlightSimulatorGameModeBase, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AFlightSimulatorGameModeBase), 4142452483U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_FlightSimulator_UE5_FlightSimulator_Source_FlightSimulator_FlightSimulatorGameModeBase_h_2800094036(TEXT("/Script/FlightSimulator"),
		Z_CompiledInDeferFile_FID_FlightSimulator_UE5_FlightSimulator_Source_FlightSimulator_FlightSimulatorGameModeBase_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_FlightSimulator_UE5_FlightSimulator_Source_FlightSimulator_FlightSimulatorGameModeBase_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
