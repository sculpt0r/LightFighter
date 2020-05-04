// Fill out your copyright notice in the Description page of Project Settings.


#include "Attractor.h"

// Sets default values for this component's properties
UAttractor::UAttractor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UAttractor::BeginPlay()
{
	Super::BeginPlay();

	// ...

}


// Called every frame
void UAttractor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
	if (targetSelected)
	{
		//float speed = FVector::Distance(GetOwner()->GetActorLocation(), targetLocation);
		float speed = 800;
		FVector target = FMath::VInterpConstantTo(
			GetOwner()->GetActorLocation(),
			targetLocation,
			GetWorld()->GetDeltaSeconds(),
			speed
		);

		float rotSpeed = 90;
		FRotator rot = FMath::RInterpConstantTo(
			GetOwner()->GetActorRotation(),
			targetRot,
			GetWorld()->GetDeltaSeconds(),
			rotSpeed
		);

		GetOwner()->SetActorLocationAndRotation(target, rot);
		float dist = (GetOwner()->GetActorLocation() - targetLocation).Size();

		UE_LOG(LogTemp, Log, TEXT("Attractor dist to target %f"), dist);

		if (dist < 10)
		{
			OnAttractionEnded.Broadcast();
			targetSelected = false;
		}
	}
}


void UAttractor::SetTarget(FVector worldLocation, FRotator targetRotation)
{
	targetLocation = worldLocation;
	targetRot = targetRotation;
	targetSelected = true;
}

