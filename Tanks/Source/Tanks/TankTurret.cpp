// Fill out your copyright notice in the Description page of Project Settings.

#include "Tanks.h"
#include "TankTurret.h"


void UTankTurret::Rotate(float RelativeSpeed) {
	float rotationChange = FMath::Clamp(RelativeSpeed, -1.0f, 1.0f) * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	float RawNewRotation = RelativeRotation.Yaw + rotationChange;
	SetRelativeRotation(FRotator(0, RawNewRotation, 0));
}

