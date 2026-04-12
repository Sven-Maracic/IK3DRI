// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "AIC_Base.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT_API AAIC_Base : public AAIController //ai controller base class
{
	GENERATED_BODY()

public:
	AAIC_Base();

protected:
	virtual void OnPossess(APawn* Pawn) override;
};
