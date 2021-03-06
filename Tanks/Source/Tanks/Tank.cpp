// Fill out your copyright notice in the Description page of Project Settings.

#include "Tanks.h"
#include "Tank.h"
#include "TankAimingComponent.h"
#include "TankBarrel.h"
#include "TankTurret.h"
#include "Projectile.h"

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	tankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component"));
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();

}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);
}

void ATank::SetBarrelReference(UTankBarrel *BarrelToSet) {
	if (tankAimingComponent != nullptr) {
		tankAimingComponent->SetBarrelReference(BarrelToSet);
	}
	Barrel = BarrelToSet;
}

void ATank::SetTurretReference(UTankTurret *TurretToSet) {
	if (tankAimingComponent != nullptr) {
		tankAimingComponent->SetTurretReference(TurretToSet);
	}
}

// Aim at specified location
void ATank::AimAt(FVector location) {
	if (tankAimingComponent != nullptr) {
		tankAimingComponent->AimAt(location, LaunchSpeed);
	}
}

void ATank::Fire() {
	bool isReloaded = (FPlatformTime::Seconds() - LastFireTime) > ReloadTimeInSeconds;
	
	if (Barrel && isReloaded) {
		FVector spawnLocation = Barrel->GetSocketLocation(FName("Projectile"));
		FRotator spawnRotation = Barrel->GetSocketRotation(FName("Projectile"));
		AProjectile *projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileBlueprint, spawnLocation, spawnRotation);

		if (projectile != nullptr)
			projectile->LaunchProjectile(LaunchSpeed);

		LastFireTime = FPlatformTime::Seconds();
	}
}