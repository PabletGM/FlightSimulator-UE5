// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/AudioComponent.h"
#include "Sound/SoundBase.h"
#include "AudioManager.generated.h"

class UGameInstanceFlightSimulator;
UCLASS()
class FLIGHTSIMULATOR_API AAudioManager : public AActor
{
	GENERATED_BODY()
    
public:
	AAudioManager();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "Audio")
	void PlayMusic();

	UFUNCTION(BlueprintCallable, Category = "Audio")
	void StopMusic();

	UFUNCTION(BlueprintCallable, Category = "Audio")
	void SetMusicVolume(float Volume);

	UFUNCTION(BlueprintCallable, Category = "Audio")
	void PlaySFX1(FText SoundName);

	UFUNCTION(BlueprintCallable, Category = "Audio")
	void PlaySFX2(FText SoundName);

	UFUNCTION(BlueprintCallable, Category = "Audio")
	void PlaySFX3(FText SoundName);

	
private:
	UPROPERTY(VisibleAnywhere, Category = "Audio")
	UAudioComponent* MusicComponent;

	UPROPERTY(VisibleAnywhere, Category = "Audio")
	UAudioComponent* SFXComponent1;

	UPROPERTY(VisibleAnywhere, Category = "Audio")
	UAudioComponent* SFXComponent2;

	UPROPERTY(VisibleAnywhere, Category = "Audio")
	UAudioComponent* SFXComponent3;

	UPROPERTY(VisibleAnywhere, Category = "Audio")
	bool OnGameplay = false;

	UPROPERTY(VisibleAnywhere, Category = "Audio")
	bool OnSelector = false;

	FString CurrentLevel;

	UPROPERTY(EditAnywhere, Category = "Audio")
	TMap<FString, USoundBase*> SoundMap;
};