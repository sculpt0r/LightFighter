// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once 

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "LightfighterFPHUD.generated.h"

UCLASS()
class ALightfighterFPHUD : public AHUD
{
	GENERATED_BODY()

public:
	ALightfighterFPHUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;

};

