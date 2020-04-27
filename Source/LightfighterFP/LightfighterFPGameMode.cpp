// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "LightfighterFPGameMode.h"
#include "LightfighterFPHUD.h"
#include "LightfighterFPCharacter.h"
#include "UObject/ConstructorHelpers.h"

ALightfighterFPGameMode::ALightfighterFPGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	//static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FP_GravityCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = ALightfighterFPHUD::StaticClass();
}
