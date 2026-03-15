// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enemy/Task/BTTask_CheckLOSForTime.h"
#include "BTTask_CheckLOSForTime_Pursuit.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT_API UBTTask_CheckLOSForTime_Pursuit : public UBTTask_CheckLOSForTime
{
	GENERATED_BODY()

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	virtual void TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
	
private:
	std::chrono::time_point<std::chrono::steady_clock> startTime;
};
