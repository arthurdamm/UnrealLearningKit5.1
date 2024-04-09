// Fill out your copyright notice in the Description page of Project Settings.


#include "BP_TestCPPActorFromScratch.h"

// Sets default values
ABP_TestCPPActorFromScratch::ABP_TestCPPActorFromScratch()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABP_TestCPPActorFromScratch::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABP_TestCPPActorFromScratch::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector location = GetActorLocation();
	location.Z += 100 * DeltaTime;
	SetActorLocation(location);
}

