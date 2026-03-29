// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Enemy/AIC_Base.h"
#include "AIC_EnemyGround.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT_API AAIC_EnemyGround : public AAIC_Base
{
	GENERATED_BODY()
public:
	virtual void LookAt(FVector TargetLocation);
};
