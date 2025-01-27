// Fill out your copyright notice in the Description page of Project Settings.


#include "PlaneSelector_PlayerController.h"

#include "Kismet/GameplayStatics.h"

void APlaneSelector_PlayerController::BeginPlay()
{
	Super::BeginPlay();

	SetupPlayerInputComponent(InputComponent);
	
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(InputMappingContext, 0);
	}

	if (AirplaneSelectorWidgetTemplate)
	{
		AirplaneSelectorWidget = Cast<UAirplaneSelectorWidget>(CreateWidget<UUserWidget>(this, AirplaneSelectorWidgetTemplate));
		if (AirplaneSelectorWidget)
		{
			AirplaneSelectorWidget->AddToViewport(0);
			bShowMouseCursor = true;
		}
	}

	//Initial Airplane
	if (AirplaneMap.Num() > 0)
	{
		TArray<FString> Keys;
		AirplaneMap.GetKeys(Keys);
		CurrentAirplaneName = Keys[0];
		CurrentAirplaneClass = AirplaneMap[CurrentAirplaneName];
		SpawnCurrentAirplane();
	}
}

//TO-DO
void APlaneSelector_PlayerController::ChangeAirplaneRightChoice()
{
	//check if there is anything on array
	if (AirplaneMap.Num() > 0)
	{
		TArray<FString> Keys;
		AirplaneMap.GetKeys(Keys);
		//Get the actual index
		int32 CurrentIndex = Keys.Find(CurrentAirplaneName);
		if (CurrentIndex == INDEX_NONE)
		{
			CurrentIndex = 0;
		}
		//Calculate next index
		int32 NextIndex = (CurrentIndex + 1) % Keys.Num();
		//Change current airplane string
		CurrentAirplaneName = Keys[NextIndex];
		//Change current airplane class
		CurrentAirplaneClass = AirplaneMap[CurrentAirplaneName];
		//Spawn
		SpawnCurrentAirplane();
	}
}

//TO-DO
void APlaneSelector_PlayerController::ChangeAirplaneLeftChoice()
{
	//check if there is anything on array
	if (AirplaneMap.Num() > 0)
	{
		TArray<FString> Keys;
		AirplaneMap.GetKeys(Keys);
		//Get the actual index
		int32 CurrentIndex = Keys.Find(CurrentAirplaneName);
		if (CurrentIndex == INDEX_NONE)
		{
			CurrentIndex = 0;
		}
		//Calculate next index
		int32 PreviousIndex = (CurrentIndex - 1 + Keys.Num()) % Keys.Num();
		//Change current airplane string
		CurrentAirplaneName = Keys[PreviousIndex];
		//Change current airplane class
		CurrentAirplaneClass = AirplaneMap[CurrentAirplaneName];
		// Spawn
		SpawnCurrentAirplane();
	}
}

//TO-DO
void APlaneSelector_PlayerController::EnterLevelGameplay()
{
	if (!CurrentAirplaneName.IsEmpty() && CurrentAirplaneClass)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString::Printf(TEXT("Selected Airplane: %s"), *CurrentAirplaneName));
        
		// Almacenar selección en GameInstance o cargar el nivel
		// UGameplayStatics::OpenLevel(this, FName("GameplayLevel")); 
	}
}

void APlaneSelector_PlayerController::SpawnCurrentAirplane()
{
	if (CurrentSpawnedAirplane)
	{
		// Destruir el avión actual
		CurrentSpawnedAirplane->Destroy();
		CurrentSpawnedAirplane = nullptr;
	}	
	if (CurrentAirplaneClass)
	{
		//generate params
		FActorSpawnParameters SpawnParams;
		SpawnParams.Owner = this;
		SpawnParams.Instigator = GetPawn();
		//spawn
		CurrentSpawnedAirplane = GetWorld()->SpawnActor<AActor>(CurrentAirplaneClass, SpawnLocation, FRotator::ZeroRotator, SpawnParams);
	}
	
}


// SetupPlayerInputComponent
void APlaneSelector_PlayerController::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		//Enter
		EnhancedInputComponent->BindAction(IA_Enter, ETriggerEvent::Triggered, this, &APlaneSelector_PlayerController::EnterLevelGameplay);
		
		//RightChoice
		EnhancedInputComponent->BindAction(IA_RightChoice, ETriggerEvent::Triggered, this, &APlaneSelector_PlayerController::ChangeAirplaneRightChoice);
    	
		//LeftChoice
		EnhancedInputComponent->BindAction(IA_LeftChoice, ETriggerEvent::Triggered, this, &APlaneSelector_PlayerController::ChangeAirplaneLeftChoice);  	
	}
}
