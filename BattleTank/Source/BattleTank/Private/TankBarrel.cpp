// Fill out your copyright notice in the Description page of Project Settings.


#include "TankBarrel.h"

void UTankBarrel::Elevate(float DegreesPerSecond)
{
	//Move barrel the right amount this frame

	//Given a max elevation spped, and the frame time
	UE_LOG(LogTemp, Warning, TEXT("BarrelElevate called at speed %f"), DegreesPerSecond)
}