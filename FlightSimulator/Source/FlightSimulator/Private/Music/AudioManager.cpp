
#include "Music/AudioManager.h"
#include "Components/AudioComponent.h"
#include "GameInstance/GameInstanceFlightSimulator.h"
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundBase.h"

AAudioManager::AAudioManager()
{
	PrimaryActorTick.bCanEverTick = true;

	MusicComponent = CreateDefaultSubobject<UAudioComponent>(TEXT("MusicComponent"));
	MusicComponent->bAutoActivate = false;
	RootComponent = MusicComponent;

	SFXComponent1 = CreateDefaultSubobject<UAudioComponent>(TEXT("SFXComponent1"));
	SFXComponent1->bAutoActivate = false;
	SFXComponent1->SetupAttachment(RootComponent);

	SFXComponent2 = CreateDefaultSubobject<UAudioComponent>(TEXT("SFXComponent2"));
	SFXComponent2->bAutoActivate = false;
	SFXComponent2->SetupAttachment(RootComponent);
	
	SFXComponent3 = CreateDefaultSubobject<UAudioComponent>(TEXT("SFXComponent3"));
	SFXComponent3->bAutoActivate = false;
	SFXComponent3->SetupAttachment(RootComponent);
}

void AAudioManager::BeginPlay()
{
	Super::BeginPlay();

	CurrentLevel = UGameplayStatics::GetCurrentLevelName(this);
	PlayMusic();

	if (CurrentLevel == "CesiumGameplay")
	{
		UGameInstanceFlightSimulator* GameInstance = Cast<UGameInstanceFlightSimulator>(GetGameInstance());
		if (GameInstance)
		{
			FString SelectedAirplaneName = GameInstance->SelectedAirplaneName;
			PlaySFX1(FText::FromString(SelectedAirplaneName));
		}
	}
}

void AAudioManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AAudioManager::PlayMusic()
{
	if (CurrentLevel == "AirplaneSelector")
	{
		USoundBase** WindSound = SoundMap.Find("Wind");
		if (MusicComponent && WindSound && *WindSound)
		{
			MusicComponent->SetSound(*WindSound);
			MusicComponent->Play();
		}
	}
	else if (CurrentLevel == "CesiumGameplay")
	{
		USoundBase** BackgroundMusic = SoundMap.Find("BackgroundMusic");
		if (MusicComponent && BackgroundMusic && *BackgroundMusic)
		{
			MusicComponent->SetSound(*BackgroundMusic);
			MusicComponent->Play();
			PlaySFX3(FText::FromString("Wind"));
		}
	}
}

void AAudioManager::StopMusic()
{
	if (MusicComponent)
	{
		MusicComponent->Stop();
	}
}

void AAudioManager::SetMusicVolume(float Volume)
{
	if (MusicComponent)
	{
		MusicComponent->SetVolumeMultiplier(Volume);
	}
}

void AAudioManager::PlaySFX1(FText SoundName)
{
	if (!SFXComponent1)
		return;
    
	USoundBase** SelectedSFX = SoundMap.Find(SoundName.ToString());
    
	if (SelectedSFX && *SelectedSFX)
	{
		SFXComponent1->SetSound(*SelectedSFX);
		SFXComponent1->Play();
	}
}

void AAudioManager::PlaySFX2(FText SoundName)
{
	if (!SFXComponent2)
		return;
    
	USoundBase** SelectedSFX = SoundMap.Find(SoundName.ToString());
    
	if (SelectedSFX && *SelectedSFX)
	{
		SFXComponent2->SetSound(*SelectedSFX);
		SFXComponent2->Play();
	}
}

void AAudioManager::PlaySFX3(FText SoundName)
{
	if (!SFXComponent3)
		return;
    
	USoundBase** SelectedSFX = SoundMap.Find(SoundName.ToString());
    
	if (SelectedSFX && *SelectedSFX)
	{
		SFXComponent3->SetSound(*SelectedSFX);
		SFXComponent3->Play();
	}
}
