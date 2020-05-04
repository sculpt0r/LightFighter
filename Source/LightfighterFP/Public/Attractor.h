// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Math/UnrealMathUtility.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"
#include "Attractor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FAttractionFinishSignature);
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class LIGHTFIGHTERFP_API UAttractor : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UAttractor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	bool targetSelected = false;
	FVector targetLocation;
	FRotator targetRot;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	UFUNCTION(Category = "LightFighter", BlueprintCallable)
		virtual void SetTarget(FVector worldLocation, FRotator targetRotation);
	UPROPERTY(BlueprintAssignable, Category = "Test")
		FAttractionFinishSignature OnAttractionEnded;
};
