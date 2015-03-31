// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BaseWeaponComponent.h"
#include "HealthComponent.h"
#include "RifleWeaponComponent.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class PUZZLELEFT4_API URifleWeaponComponent : public UBaseWeaponComponent
{
	GENERATED_BODY()

public:
	URifleWeaponComponent();
		virtual void FireWeapon() override;
	
};
