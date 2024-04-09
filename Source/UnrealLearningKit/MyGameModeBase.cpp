#include "MyGameModeBase.h"
#include "GameFramework/Actor.h"
#include "Logging/LogMacros.h"

#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "DrawDebugHelpers.h"

void AMyGameModeBase::BeginPlay()
{
    Super::BeginPlay();

    UE_LOG(LogTemp, Warning, TEXT("Hello World!"));
    // Define the location and rotation
    FVector Location = FVector(-2390,-2770,300);
    FRotator Rotation = FRotator(0,0,0);
    

    // Optionally, define a scale if you want something other than the default (1,1,1)
    FVector Scale = FVector(1.0f, 1.0f, 1.0f);

    // Create a Transform using Location and Rotation, and optionally Scale
    FTransform SpawnTransform(Rotation, Location, Scale);

    // Spawn the actor using the Transform
    // ABP_TestCPPActorFromScratch* SpawnedActor = GetWorld()->SpawnActor<ABP_TestCPPActorFromScratch>(ABP_TestCPPActorFromScratch::StaticClass(), SpawnTransform);
    // AMovingPlatform* SpawnedActor = GetWorld()->SpawnActor<AMovingPlatform>(AMovingPlatform::StaticClass(), SpawnTransform);
    // Assume you're doing this in a function inside an actor or somewhere you have access to GetWorld()

    UObject* SpawnLocation = GetWorld();
    if (SpawnLocation)
    {
        // Assuming the base class of your Blueprint is known and is AMyBaseActor
        UWorld* World = SpawnLocation->GetWorld();
        if (World)
        {
            // Path to your Blueprint, replace with actual path
            FString PathToBP = TEXT("Blueprint'/Game/BP_TestCPPActorFromScratch.BP_TestCPPActorFromScratch_C'");
            
            // Load the Blueprint class
            UClass* BPClass = Cast<UClass>(StaticLoadObject(UClass::StaticClass(), nullptr, *PathToBP));
            if (BPClass)
            {
                // Spawn the Blueprint subclass
                AActor* SpawnedActor = World->SpawnActor<AActor>(BPClass, SpawnTransform);
                if (SpawnedActor)
                {
                    UE_LOG(LogTemp, Warning, TEXT("Successfully spawned actor from Blueprint: %s"), *PathToBP);
                    // Successfully spawned, you can now work with SpawnedActor
                } else {
                    UE_LOG(LogTemp, Warning, TEXT("Failed to spawn actor from Blueprint: %s"), *PathToBP);
                
                }
                if (SpawnedActor)
                {
                    FTransform ActorTransform = SpawnedActor->GetActorTransform();
                    FVector ActorLocation = ActorTransform.GetLocation();
                    FRotator ActorRotation = ActorTransform.GetRotation().Rotator();
                    FVector ActorScale = ActorTransform.GetScale3D();

                    UE_LOG(LogTemp, Warning, TEXT("Spawned Actor Transform: Location(%s), Rotation(%s), Scale(%s)"),
                        *ActorLocation.ToString(), 
                        *ActorRotation.ToString(), 
                        *ActorScale.ToString());

                    // Optionally, set the actor's location again explicitly if needed
                    SpawnedActor->SetActorLocation(Location);

                    // Debug log to confirm the spawn and location set operation
                    UE_LOG(LogTemp, Warning, TEXT("Actor spawned and location set to: %s"), *Location.ToString());
                }
                else
                {
                    UE_LOG(LogTemp, Warning, TEXT("Spawned actor is NULL. Spawn failed or aborted."));
                }
                    DrawDebugSphere(GetWorld(), Location, 100.0f, 32, FColor::Red, true, 10.0f);
                    UE_LOG(LogTemp, Warning, TEXT("Bye World!"));
                }

            }
        }
}


    // static ConstructorHelpers::FObjectFinder<UBlueprint> ActorBlueprint(TEXT("Blueprint'/Game/BP_MovingPlatform.BP_MovingPlatform'"));
    // if (ActorBlueprint.Object)
    // {
    //     UClass* ActorClass = ActorBlueprint.Object->GeneratedClass;
    //     ABP_MovingPlatform* SpawnedActor = GetWorld()->SpawnActor<ABP_MovingPlatform>(ActorClass, SpawnTransform);
    // }
    // else
    // {
    //     UE_LOG(LogTemp, Warning, TEXT("Failed to find Blueprint'/Game/Path/To/Your/BP_MovingPlatform.BP_MovingPlatform'"));
    // }



