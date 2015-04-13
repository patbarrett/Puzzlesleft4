// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "BaseWeaponComponent.generated.h"


UCLASS(ClassGroup = (Custom))
class PUZZLELEFT4_API UBaseWeaponComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	// Sets default values for this component's properties
	UBaseWeaponComponent();


	// Called when the game starts
	virtual void InitializeComponent() override;

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	float Damage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	float Force;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	float FireRate; //Shots PER SECOND
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	float TimePassed; //Time since last shot
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	float WeaponRange; //Length of Raycats/Range of Weapon

	bool isShootable; //Can I Shoot?

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	float AmmoCost; //Ammo Cost Per Shot
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	float CurrentAmmo; //Current Ammo in Clip/Magazine
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	float CurrentReserveAmmo; //Current Reserve Ammo for Reloading

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	float MaxCurrent; //Maximum Ammo in Clip/Magazine
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	float MaxReserve; //Maximum Reserve Ammo for Reloading

	FHitResult HitTarget; //Raycast Hit Information

	//UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	UCameraComponent* MainCameraComponent;

	bool CastRay(UCameraComponent* MainCam);
	bool UpdateAmmo();

	void Reload();

	virtual void UpdateIsShootable();

	virtual void FireWeapon() PURE_VIRTUAL(UBaseWeaponComponent FireWeapon,);
};

