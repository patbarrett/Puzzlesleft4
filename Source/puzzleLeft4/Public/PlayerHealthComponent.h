// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "HealthComponent.h"
#include "PlayerHealthComponent.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class PUZZLELEFT4_API UPlayerHealthComponent : public UHealthComponent
{
	GENERATED_BODY()
	
public:
	UPlayerHealthComponent();
	virtual void InitializeComponent() override;
	virtual void OnDeath(FVector ForceDirection, float ForceValue) override;
	
	
};
