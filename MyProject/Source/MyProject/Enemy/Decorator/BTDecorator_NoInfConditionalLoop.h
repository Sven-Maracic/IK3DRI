// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Decorators/BTDecorator_ConditionalLoop.h"
#include "BTDecorator_NoInfConditionalLoop.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT_API UBTDecorator_NoInfConditionalLoop : public UBTDecorator_ConditionalLoop
{
	GENERATED_BODY()

public:
	virtual void OnNodeDeactivation(FBehaviorTreeSearchData& SearchData, EBTNodeResult::Type NodeResult) override;
	explicit UBTDecorator_NoInfConditionalLoop();
};
