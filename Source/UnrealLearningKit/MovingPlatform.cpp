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
	foo += 3;
	
	
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector location = GetActorLocation();
	if (location.Z > 1000)
		deltaMove.Z = -1;
	if (location.Z < 0)
		deltaMove.Z = 1;
	location += deltaMove * DeltaTime * 100;
	SetActorLocation(location);
}
