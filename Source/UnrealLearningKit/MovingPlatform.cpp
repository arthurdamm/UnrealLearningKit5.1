// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	StartLocation = GetActorLocation();
	
	
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	MovePlatform(DeltaTime);
}

void AMovingPlatform::MovePlatform(float DeltaTime)
{
	FVector location = GetActorLocation() + moveVelocity * DeltaTime;
	distanceMoved = (location - StartLocation).Size();
	if (distanceMoved >= moveDistance)
	{
		FString name = GetName();
		UE_LOG(LogTemp, Warning, TEXT("%s DistanceMoved Overshot by: %f"), *name, distanceMoved);

		location = StartLocation + moveVelocity.GetSafeNormal() * moveDistance;
		moveVelocity = -moveVelocity;
	}
	SetActorLocation(location);

}
