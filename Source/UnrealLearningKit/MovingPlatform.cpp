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
	mStartLocation = GetActorLocation();
}

// Called every frame
void AMovingPlatform::Tick(float deltaTime)
{
	Super::Tick(deltaTime);
	MovePlatform(deltaTime);
	RotatePlatform(deltaTime);
}

void AMovingPlatform::MovePlatform(float deltaTime)
{
	FVector nextLocation = GetNextLocation(deltaTime);
	
	if (ShouldMoveBack(nextLocation))
	{
		FString name = GetName();
		UE_LOG(LogTemp, Warning, TEXT("%s DistanceMoved Overshot by: %f"), *name, mDistanceMoved);

		nextLocation = GetMaxLocation();
		mMoveVelocity = -mMoveVelocity;
	}
	UE_LOG(LogTemp, Warning, TEXT("%s nextLocation is %s"), *GetName(), *nextLocation.ToString());
	SetActorLocation(nextLocation);

}

bool AMovingPlatform::ShouldMoveBack(FVector location)
{
	float distanceMoved = (location - mStartLocation).Size();
	return distanceMoved >= mMoveDistance;
}

FVector AMovingPlatform::GetMaxLocation()
{
	return mStartLocation + mMoveVelocity.GetSafeNormal() * mMoveDistance;
}

FVector AMovingPlatform::GetNextLocation(float deltaTime)
{
	FVector next = GetActorLocation() + mMoveVelocity * deltaTime;
	UE_LOG(LogTemp, Warning, TEXT("%s next %s"), *GetName(), *next.ToString());
	return next;
}

void AMovingPlatform::RotatePlatform(float deltaTime)
{
	FRotator nextRotation = mRotateVelocity * deltaTime;
	AddActorLocalRotation(nextRotation);
}