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

public:
	UPROPERTY(EditAnywhere)
	float mMoveDistance = 100;

	UPROPERTY(EditAnywhere)
	FVector mMoveVelocity = FVector(0, 0, 100);

	UPROPERTY(EditAnywhere)
	FVector mStartLocation = GetActorLocation();
	
	UPROPERTY(EditAnywhere)
	float mDistanceMoved = 0;

	UPROPERTY(EditAnywhere, Category="Rotation")
	FRotator mRotateVelocity;

	void MovePlatform(float deltaTime);

	bool ShouldMoveBack(FVector location);

	FVector GetMaxLocation();

	FVector GetNextLocation(float deltaTime);

	void RotatePlatform(float);

};
