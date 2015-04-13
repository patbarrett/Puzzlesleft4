// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.
#pragma once 
#include "GameFramework/HUD.h"
#include "puzzleLeft4HUD.generated.h"

UCLASS()
class ApuzzleLeft4HUD : public AHUD
{
	GENERATED_BODY()

public:
	ApuzzleLeft4HUD(const FObjectInitializer& ObjectInitializer);

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;
	void BeginPlay();

	TSharedPtr<class SPlayerHealthWidget> PlayerWidget;

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;

};

