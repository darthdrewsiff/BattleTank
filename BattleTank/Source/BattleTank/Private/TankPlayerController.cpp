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

    FVector HitLocation; //Out Parameter
    if (GetSightRayHitLocation(HitLocation))
    {
        //UE_LOG(LogTemp, Warning, TEXT("HitLoaction : %s"), *HitLocation.ToString())

         // TODO Tell contrlled tank to aim at his point
    }
}
//Get world location of linetrace through crosshair, true if hits landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
    // Find crosshair position
    int32 ViewportSizeX, ViewportSizeY;
    GetViewportSize(ViewportSizeX, ViewportSizeY);
    auto ScreenLocation = FVector2D(ViewportSizeX * CrosshairXLocation, ViewportSizeY * CrosshairYLocation);
    

    // De-project screen position of crosshair to world direction
    FVector LookDirection;
    if (GetLookDirection(ScreenLocation, LookDirection))
    {
        UE_LOG(LogTemp, Warning, TEXT("Look direction: %s"), *LookDirection.ToString())
    }

    // Line-trace along that look direction and see what we hit up to max range
    return true;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{
    FVector CameraWorldLocation; //For discarding
    return DeprojectScreenPositionToWorld(
        ScreenLocation.X,
        ScreenLocation.Y,
        CameraWorldLocation,
        LookDirection
    );
}