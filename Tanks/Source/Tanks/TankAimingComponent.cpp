// Fill out your copyright notice in the Description page of Project Settings.

#include "Tanks.h"
#include "TankAimingComponent.h"
#include "TankBarrel.h"
#include "TankTurret.h"

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = false;
}

void UTankAimingComponent::SetBarrelReference(UTankBarrel *BarrelToSet) {
	this->barrelStaticMeshComponent = BarrelToSet;
}

void UTankAimingComponent::SetTurretReference(UTankTurret *TurretToSet) {
	this->turretStaticMeshComponent = TurretToSet;
}

// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();
}


// Called every frame
void UTankAimingComponent::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );
}

void UTankAimingComponent::AimAt(FVector location, float launchSpeed) {
	if (!turretStaticMeshComponent) return;
	if (!barrelStaticMeshComponent) return;

	FVector outLaunchVelocity;
	FVector startLocation = barrelStaticMeshComponent->GetSocketLocation(FName("Projectile"));

	// Calculate the OutLaunchVelocity
	if (UGameplayStatics::SuggestProjectileVelocity(this, outLaunchVelocity, startLocation, location, launchSpeed, false, 0, 0, ESuggestProjVelocityTraceOption::DoNotTrace)) {
		UE_LOG(LogTemp, Warning, TEXT("Aim solution found."))
		FVector aimDirection = outLaunchVelocity.GetSafeNormal();
		MoveBarrelTowards(aimDirection);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("No aim solution found."))
	}
}

void UTankAimingComponent::MoveBarrelTowards(FVector aimDirection) {
	FRotator BarrelRotator = barrelStaticMeshComponent->GetForwardVector().Rotation();
	FRotator AimRotator = aimDirection.Rotation();
	FRotator deltaRotator = AimRotator - BarrelRotator;

	barrelStaticMeshComponent->Elevate(deltaRotator.Pitch);
	turretStaticMeshComponent->Rotate(deltaRotator.Yaw);
}
