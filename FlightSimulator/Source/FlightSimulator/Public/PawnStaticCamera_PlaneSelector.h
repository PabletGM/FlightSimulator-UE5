// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CineCameraComponent.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/SpringArmComponent.h"
#include "PawnStaticCamera_PlaneSelector.generated.h"

class USpringArmComponent;
class UCameraComponent;
class USceneComponent;

UCLASS()
class FLIGHTSIMULATOR_API APawnStaticCamera_PlaneSelector : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APawnStaticCamera_PlaneSelector();


	// Spring Arm Component
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USceneComponent* root;

	
	// Spring Arm Component
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USpringArmComponent* SpringArm;

	// Camera Component
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UCineCameraComponent* CineCamera;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
