// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "puzzleLeft4HUD.h"
#include "Slate.h"

/**
 * 
 */
class PUZZLELEFT4_API SPlayerHealthWidget : public SCompoundWidget
{
	SLATE_BEGIN_ARGS(SPlayerHealthWidget)
	{}

	SLATE_ARGUMENT(TWeakObjectPtr<class ApuzzleLeft4HUD>, OwnerHUD)

	SLATE_END_ARGS()
public:
	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);
private:
	TWeakObjectPtrclass <ApuzzleLeft4HUD> OwnerHUD;
};
