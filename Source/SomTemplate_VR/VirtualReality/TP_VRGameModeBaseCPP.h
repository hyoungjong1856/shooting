// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.
// SomWorks :D // MIT LICENSE // Epic VR Template Convert C++ Open Source Project.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TP_VRGameModeBaseCPP.generated.h"

class ATP_VirtualRealityPawn_Motion;

UCLASS()
class SOMTEMPLATE_VR_API ATP_VRGameModeBaseCPP : public AGameModeBase
{
	GENERATED_BODY()

private:

	
public:
	ATP_VRGameModeBaseCPP();

	virtual void StartPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
};