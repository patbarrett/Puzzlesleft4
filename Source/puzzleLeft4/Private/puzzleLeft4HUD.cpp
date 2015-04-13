// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.

#include "puzzleLeft4.h"
#include "puzzleLeft4HUD.h"
#include "Engine/Canvas.h"
#include "TextureResource.h"
#include "CanvasItem.h"
#include "SPlayerHealthWidget.h"
#include "Engine/Canvas.h"

ApuzzleLeft4HUD::ApuzzleLeft4HUD(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	// Set the crosshair texture
	static ConstructorHelpers::FObjectFinder<UTexture2D> CrosshiarTexObj(TEXT("/Game/Textures/Crosshair"));
	//static ConstructorHelpers::FObjectFinder<UTexture2D> TexPath(TEXT("/Game/Textures/GreenTexture"));

	CrosshairTex = CrosshiarTexObj.Object;
	//HealthBarTexture = TexPath.Object;
}

void ApuzzleLeft4HUD::BeginPlay()
{
	//SAssignNew(PlayerWidget, SPlayerHealthWidget).OwnerHUD(this);


}

void ApuzzleLeft4HUD::DrawHUD()
{
	Super::DrawHUD();


	DrawHealthBar();

	// Draw very simple crosshair

	// find center of the Canvas
	const FVector2D Center(Canvas->ClipX * 0.5f, Canvas->ClipY * 0.5f);

	// offset by half the texture's dimensions so that the center of the texture aligns with the center of the Canvas
	const FVector2D CrosshairDrawPosition( (Center.X - (CrosshairTex->GetSurfaceWidth() * 0.5)),
										   (Center.Y - (CrosshairTex->GetSurfaceHeight() * 0.5f)) );

	// draw the crosshair
	FCanvasTileItem TileItem( CrosshairDrawPosition, CrosshairTex->Resource, FLinearColor::White);
	TileItem.BlendMode = SE_BLEND_Translucent;
	Canvas->DrawItem( TileItem );
}

void ApuzzleLeft4HUD::DrawHealthBar()
{
	//FCanvasIcon HealthBarIcon = FCanvasIcon::MakeIcon()
}

