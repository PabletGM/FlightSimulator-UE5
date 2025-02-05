// Fill out your copyright notice in the Description page of Project Settings.


#include "PawnStaticCamera_PlaneSelector.h"




// Sets default values
APawnStaticCamera_PlaneSelector::APawnStaticCamera_PlaneSelector()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	
	
	// Create the SpringArm and attach to root
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->TargetArmLength = 300.0f;
	SpringArm->bUsePawnControlRotation = true;
	SpringArm->SetupAttachment(root);

	// Create the Camera and attach to the SpringArm
	CineCamera = CreateDefaultSubobject<UCineCameraComponent>(TEXT("CineCamera"));
	CineCamera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);
	CineCamera->bUsePawnControlRotation = false;
	
	CineCamera->LensSettings.MinFocalLength = 18.0f; // Distancia focal mínima (18mm)
	CineCamera->LensSettings.MaxFocalLength = 135.0f; // Distancia focal máxima (135mm)
	CineCamera->FocusSettings.FocusMethod = ECameraFocusMethod::Manual; // Enfoque manual

}


void APawnStaticCamera_PlaneSelector::BeginPlay()
{
	Super::BeginPlay();
	
}


void APawnStaticCamera_PlaneSelector::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APawnStaticCamera_PlaneSelector::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

