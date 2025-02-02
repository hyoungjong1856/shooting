// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile.h"
#include "Boss_Rain_Projectile.generated.h"

UCLASS()
class SOMTEMPLATE_VR_API ABoss_Rain_Projectile : public AProjectile
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABoss_Rain_Projectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void Check_Destroy() override;
};
