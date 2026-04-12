// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/Task/BTTask_AimRangedAttack.h"

#include "AIController.h"
#include "Enemy/EnemyGround/AIC_EnemyGround.h"
#include "Kismet/KismetMathLibrary.h"

UBTTask_AimRangedAttack::UBTTask_AimRangedAttack()
{
	NodeName = TEXT("Aim Attack Toward Player");
}

EBTNodeResult::Type UBTTask_AimRangedAttack::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	if (AAIC_EnemyGround* enemy = Cast<AAIC_EnemyGround>(OwnerComp.GetAIOwner()))
	{
		enemy->LookAt(TargetLocation.GetValue(OwnerComp));
	}
	return Super::ExecuteTask(OwnerComp, NodeMemory);
}
