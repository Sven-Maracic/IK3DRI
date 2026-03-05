// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/Task/BTTask_ChangeEnemyState.h"

#include "AIController.h"
#include "Enemy/BP_Enemy.h"

UBTTask_ChangeEnemyState::UBTTask_ChangeEnemyState()
{
	NodeName = "Change Enemy state";
}

EBTNodeResult::Type UBTTask_ChangeEnemyState::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	ABP_Enemy* owner = Cast<ABP_Enemy>(OwnerComp.GetAIOwner()->GetPawn());
	if (owner != nullptr)
	{
		owner->ChangeState(NewState);
		return EBTNodeResult::Succeeded;
	}
	return EBTNodeResult::Failed;
}
