// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Math/Vector.h"
#include "Engine/World.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/Public/DrawDebugHelpers.h"
#include "Ability.generated.h"


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class LIGHTFIGHTERFP_API UAbility : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UAbility();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	FHitResult hitResult;
	AActor* currentTargetActor;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	virtual void ActivateAbility();
	virtual void DeactivateAbility();
	void TargetAtSurface(FVector start, FVector end);

	void ApplyColor(FColor color);



};
