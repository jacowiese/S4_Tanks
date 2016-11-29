// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class ATank;

/**
 *
 */
UCLASS()
class TANKS_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
		float CrossHairXLocation = 0.5f;

	UPROPERTY(EditAnywhere)
		float CrossHairYLocation = 0.3333f;

	UPROPERTY(EditAnywhere)
		float LineTraceRange = 1000000.0f;

private:
	ATank* GetControlledTank() const;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;

	void AimTowardsCrosshair();
	bool GetSightRayHitLocation(OUT FVector &hitLocation) const;
	bool GetLookDirection(FVector2D screenLocation, OUT FVector &lookDirection) const;
	bool GetLookVectorHitLocation(FVector lookDirection, OUT FVector &hitLocation) const;
};
