// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class UNREALLEARNINGKIT_API AMovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	int foo = 37;
	UPROPERTY(EditAnywhere)
	FVector StartLocation = GetActorLocation();
	UPROPERTY(EditAnywhere)
	float distance = 0;
	UPROPERTY(EditAnywhere)
	float distanceFunc = 0;
	UPROPERTY(EditAnywhere)
	FVector v = FVector(-2170, -2200, 96);
	UPROPERTY(EditAnywhere, Category = "Movement")
	FVector deltaMove = FVector(0, 0, 1);

};
