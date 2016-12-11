// Fill out your copyright notice in the Description page of Project Settings.

#include "Tanks.h"
#include "Tank.h"
#include "TankPlayerController.h"
#include "TankAIController.h"

void ATankAIController::BeginPlay() {
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaSeconds) {
	Super::Tick(DeltaSeconds);

	ATank *PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	ATank *ControlledTank = Cast<ATank>(GetPawn());

	if (PlayerTank) {
		// TODO: Move towards the player

		// Aim at towards the player
		ControlledTank->AimAt(PlayerTank->GetActorLocation());

		// Fire if ready
		ControlledTank->Fire();
	}
}
