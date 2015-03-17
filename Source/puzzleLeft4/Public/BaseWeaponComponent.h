// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "BaseWeaponComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PUZZLELEFT4_API UBaseWeaponComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UBaseWeaponComponent();

	// Called when the game starts
	virtual void InitializeComponent() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

	float Damage;
	float FireRate; //Shots PER SECOND
	float TimePassed; //Time since last shot
	float WeaponRange; //Length of Raycats/Range of Weapon
	
	bool isShootable; //Can I Shoot?

	int AmmoCost; //Ammo Cost Per Shot
	int CurrentAmmo; //Current Ammo in Clip/Magazine
	int CurrentReserveAmmo; //Current Reserve Ammo for Reloading

	int MaxCurrent; //Maximum Ammo in Clip/Magazine
	int MaxReserve; //Maximum Reserve Ammo for Reloading

	FHitResult Target; //Raycast Hit Information

	bool CastRay(FVector Origin, FVector Direction);
};
