// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enemy/AIC_Base.h"
#include "AIC_EnemyTurret.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT_API AAIC_EnemyTurret : public AAIC_Base
{
	GENERATED_BODY()
	
public:
	void FireProjectile(const FVector& TargetLocation) const;
};
