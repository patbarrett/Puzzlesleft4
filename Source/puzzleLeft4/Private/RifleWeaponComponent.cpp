// Fill out your copyright notice in the Description page of Project Settings.

#include "puzzleLeft4.h"
#include "RifleWeaponComponent.h"

URifleWeaponComponent::URifleWeaponComponent()
{
	Damage = 10.0f;
	Force = 50000.0f;
	FireRate = 1.0f;
	TimePassed = 0.0f;
	WeaponRange = 800.0f;

	isShootable = true;

	AmmoCost = 1;
	CurrentAmmo = 10;
	CurrentReserveAmmo = 50;

	MaxCurrent = 10;
	MaxReserve = 60;
}

void URifleWeaponComponent::FireWeapon()
{
	if (isShootable)
	{
		if (CastRay(MainCameraComponent))
		{
			if (HitTarget.GetActor()->GetComponentByClass(UBaseHealthComponent::StaticClass()))
			{
				UBaseHealthComponent* Target = Cast<UBaseHealthComponent>(HitTarget.GetActor()->GetComponentByClass(UBaseHealthComponent::StaticClass()));

				Target->InflictDamage(Damage, MainCameraComponent->GetForwardVector(), Force);
			}
		}
	}
}
