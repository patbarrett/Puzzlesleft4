// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "BaseWeaponComponent.generated.h"


UCLASS(ClassGroup = (Custom))
class PUZZLELEFT4_API UBaseWeaponComponent : public UActorComponent
{
	GENERATED_BODY()

<<<<<<< HEAD
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
	
=======
public:
	// Sets default values for this component's properties
	UBaseWeaponComponent();


	// Called when the game starts
	virtual void InitializeComponent() override;

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	float Damage;
	float Force;
	float FireRate; //Shots PER SECOND
	float TimePassed; //Time since last shot
	float WeaponRange; //Length of Raycats/Range of Weapon

>>>>>>> origin/Kent5.0
	bool isShootable; //Can I Shoot?

	int AmmoCost; //Ammo Cost Per Shot
	int CurrentAmmo; //Current Ammo in Clip/Magazine
	int CurrentReserveAmmo; //Current Reserve Ammo for Reloading

	int MaxCurrent; //Maximum Ammo in Clip/Magazine
	int MaxReserve; //Maximum Reserve Ammo for Reloading

	FHitResult HitTarget; //Raycast Hit Information

	//UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	UCameraComponent* MainCameraComponent;


	bool CastRay(UCameraComponent* MainCam);
	bool UpdateAmmo();

	void Reload();

	virtual void UpdateIsShootable();

<<<<<<< HEAD
	virtual void FireWeapon() PURE_VIRTUAL(UBaseWeaponComponent FireWeapon,);
};
=======
	virtual void FireWeapon() PURE_VIRTUAL(UBaseWeaponComponent FireWeapon, );
};
>>>>>>> origin/Kent5.0
