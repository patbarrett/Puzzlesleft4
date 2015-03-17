// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.

#include "puzzleLeft4.h"
#include "puzzleLeft4GameMode.h"
#include "puzzleLeft4HUD.h"
#include "puzzleLeft4Character.h"

ApuzzleLeft4GameMode::ApuzzleLeft4GameMode(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/Blueprints/MyCharacter2"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = ApuzzleLeft4HUD::StaticClass();
}
