// Fill out your copyright notice in the Description page of Project Settings.


#include "Ability.h"

// Sets default values for this component's properties
UAbility::UAbility()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UAbility::BeginPlay()
{
	Super::BeginPlay();

	// ...

}


// Called every frame
void UAbility::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}
void UAbility::ActivateAbility()
{

}

void UAbility::DeactivateAbility()
{

}

void UAbility::TargetAtSurface(FVector start, FVector end)
{
	UWorld* world = GetOwner()->GetWorld();

	if (world->LineTraceSingleByChannel(hitResult, start, end, ECollisionChannel::ECC_Visibility))
	{
		ApplyColor(FColor::White);

		currentTargetActor = hitResult.GetActor();

		ApplyColor(FColor::Red);
		FVector pointDistancedFromTarget = hitResult.ImpactPoint + (hitResult.ImpactNormal * 250);

		//from hit to point distanced from wall (perpendicular)
		DrawDebugLine(world, hitResult.ImpactPoint, pointDistancedFromTarget, FColor::Red, false, -1.f, 0, 8.f);

		//Draw forward vector that player shoould have
		FVector futureForwardDirection = pointDistancedFromTarget;
		DrawDebugLine(world, pointDistancedFromTarget, futureForwardDirection, FColor::Blue, false, -1.f, 0, 8.f);

		DrawDebugLine(world, pointDistancedFromTarget, futureForwardDirection, FColor::Blue, false, -1.f, 0, 8.f);
	}
	else
	{
		ApplyColor(FColor::White);
	}
}

void UAbility::ApplyColor(FColor color)
{
	if (currentTargetActor->IsValidLowLevel())
	{
		auto staticMesh = currentTargetActor->FindComponentByClass<UStaticMeshComponent>();
		staticMesh->SetVectorParameterValueOnMaterials(TEXT("Color"), { (float)color.R, (float)color.G, (float)color.B });//apply white
	}
}

