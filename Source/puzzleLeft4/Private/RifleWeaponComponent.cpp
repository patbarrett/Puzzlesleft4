// Fill out your copyright notice in the Description page of Project Settings.

#include "puzzleLeft4.h"
#include "RifleWeaponComponent.h"

URifleWeaponComponent::URifleWeaponComponent()
{
	Damage = 10.0f;
<<<<<<< HEAD
=======
	Force = 5000.0f;
>>>>>>> origin/Kent5.0
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
<<<<<<< HEAD
			if (HitTarget.GetActor()->GetComponentByClass(UHealthComponent::StaticClass()))
			{
				UHealthComponent* Target = Cast<UHealthComponent>(HitTarget.GetActor()->GetComponentByClass(UHealthComponent::StaticClass()));
				if (!Target->InflictDamage(Damage))
				{
					if (HitTarget.GetActor()->GetComponentByClass(USkeletalMeshComponent::StaticClass()))
					{
						USkeletalMeshComponent* TargetMesh = Cast<USkeletalMeshComponent>(HitTarget.GetActor()->GetComponentByClass(USkeletalMeshComponent::StaticClass()));

						TargetMesh->bUpdateJointsFromAnimation = true;
					}

					HitTarget.GetActor()->SetLifeSpan(5.0f);
					HitTarget.GetComponent()->SetSimulatePhysics(true);
					HitTarget.GetComponent()->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
					HitTarget.GetComponent()->SetCollisionObjectType(ECollisionChannel::ECC_PhysicsBody);
				}
=======
			if (HitTarget.GetActor()->GetComponentByClass(UBaseHealthComponent::StaticClass()))
			{
				UBaseHealthComponent* Target = Cast<UBaseHealthComponent>(HitTarget.GetActor()->GetComponentByClass(UBaseHealthComponent::StaticClass()));

				Target->InflictDamage(Damage, MainCameraComponent->GetForwardVector(), Force);
>>>>>>> origin/Kent5.0
			}
		}
	}
}
