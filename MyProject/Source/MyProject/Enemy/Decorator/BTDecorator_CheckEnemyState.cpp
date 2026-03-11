// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/Decorator/BTDecorator_CheckEnemyState.h"

#include "AIController.h"

bool UBTDecorator_CheckEnemyState::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp,
                                                              uint8* NodeMemory) const
{
	if (Cast<ABP_Enemy>(OwnerComp.GetAIOwner()->GetPawn())->GetState() == RequiredState)
	{
		return true;
	}
	return false;
}

UBTDecorator_CheckEnemyState::UBTDecorator_CheckEnemyState()
{
	NodeName = "Check if enemy state matches selected state";
	bAllowAbortLowerPri = true;
	bAllowAbortChildNodes = true;
	bAllowAbortNone = true;
}
