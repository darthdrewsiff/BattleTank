// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"

// Tick
    //Super
    
void ATankPlayerController::BeginPlay()
{
    Super::BeginPlay();

    auto ControlledTank = GetControlledTank();
    if (!ControlledTank)
    {
        UE_LOG(LogTemp, Warning, TEXT("PlayerController not possessing a tank"))

    }
    else
    {

        UE_LOG(LogTemp, Warning, TEXT("PlayerController possessing: %s"), *(ControlledTank->GetName()))
    }

}

void ATankPlayerController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    AimTowardsCrosshair();
}



ATank* ATankPlayerController::GetControlledTank() const
{
   return Cast<ATank>(GetPawn());
}
void ATankPlayerController::AimTowardsCrosshair()
{
    if (!GetControlledTank()) { return; }
    //Get world locatino if linetrace through crosshair
    // If it hits the landscape
        //Tell contrlled tank to aim at his point
}