// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "chrono"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BTTask_CheckLOSForTime.generated.h"


/**
 * 
 */
UCLASS()
class MYPROJECT_API UBTTask_CheckLOSForTime : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
	
public:
	explicit UBTTask_CheckLOSForTime();
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	virtual void TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="LOS")
	float WaitTime = 5.0f;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="LOS")
	float TickTime = 0.1f;
	
private:
	std::chrono::time_point<std::chrono::steady_clock> startTime;
};
