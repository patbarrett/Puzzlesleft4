// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BaseWeaponComponent.h"
<<<<<<< HEAD
#include "HealthComponent.h"
#include "RifleWeaponComponent.generated.h"

/**
 * 
 */
=======
#include "BaseHealthComponent.h"
#include "RifleWeaponComponent.generated.h"

/**
*
*/
>>>>>>> origin/Kent5.0
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class PUZZLELEFT4_API URifleWeaponComponent : public UBaseWeaponComponent
{
	GENERATED_BODY()

public:
	URifleWeaponComponent();
<<<<<<< HEAD
		virtual void FireWeapon() override;
	
};
=======
	virtual void FireWeapon() override;

};
>>>>>>> origin/Kent5.0
