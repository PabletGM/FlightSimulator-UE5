// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PlaneSelector_PlayerController.generated.h"

class UMainWidget;
class UInputMappingContext;
/**
 * 
 */
UCLASS()
class FLIGHTSIMULATOR_API APlaneSelector_PlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay() override;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputMappingContext* InputMappingContext;

	// UPROPERTY(EditDefaultsOnly) TSubclassOf<UMainWidget> MainWidgetTemplate = nullptr;
	//
	// UPROPERTY()
	// UMainWidget* MainWidget = nullptr;
};
