// Fill out your copyright notice in the Description page of Project Settings.

#include "Tanks.h"
#include "Tank.h"
#include "TankPlayerController.h"


void ATankPlayerController::BeginPlay() {
	Super::BeginPlay();

	ATank* tank = GetControlledTank();
	if (tank)
		UE_LOG(LogTemp, Warning, TEXT("ATankPlayerController is controlling %s."), *tank->GetName())
}

void ATankPlayerController::Tick(float DeltaSeconds) {
	Super::Tick(DeltaSeconds);

	AimTowardsCrosshair();
}

ATank* ATankPlayerController::GetControlledTank() const {
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair() {
	if (!GetControlledTank()) { return; }

	FVector hitLocation;
	if (GetSightRayHitLocation(OUT hitLocation)) {
		GetControlledTank()->AimAt(hitLocation);
	}
}

bool ATankPlayerController::GetSightRayHitLocation(OUT FVector &hitLocation) const {
	// Find the crosshair position
	int32 viewPortSizeX, viewPortSizeY;
	GetViewportSize(OUT viewPortSizeX, OUT viewPortSizeY);
	FVector2D crossHairPosition = FVector2D(viewPortSizeX * CrossHairXLocation, viewPortSizeY * CrossHairYLocation);

	// Deproject screen position of the crosshair
	FVector lookDirection;
	if (GetLookDirection(crossHairPosition, OUT lookDirection)) {
		// Line trace along direction for look direction and see what we hit up to range
		return GetLookVectorHitLocation(lookDirection, OUT hitLocation);		
	}

	return false;
}

bool ATankPlayerController::GetLookDirection(FVector2D screenLocation, OUT FVector &lookDirection) const {
	FVector worldLocation;
	return DeprojectScreenPositionToWorld(screenLocation.X, screenLocation.Y, OUT worldLocation, OUT lookDirection);
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector lookDirection, OUT FVector &hitLocation) const {
	FVector startPosition = PlayerCameraManager->GetCameraLocation();
	FVector endPosition = startPosition + (lookDirection * LineTraceRange);

	FHitResult hitResult;
	if (GetWorld()->LineTraceSingleByChannel(OUT hitResult, startPosition, endPosition, ECollisionChannel::ECC_Visibility)) {
		hitLocation = hitResult.Location;
		return true;
	}
	hitLocation = FVector::ZeroVector;
	return false;
}