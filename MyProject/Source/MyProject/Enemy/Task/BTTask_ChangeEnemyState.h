// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "Enemy/BP_Enemy.h"
#include "BTTask_ChangeEnemyState.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT_API UBTTask_ChangeEnemyState : public UBTTask_BlackboardBase
{
	GENERATED_BODY()

public:
	explicit UBTTask_ChangeEnemyState();
	
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "State")
	TEnumAsByte<EEnemyStates> NewState;
};
