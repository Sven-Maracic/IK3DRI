// Fill out your copyright notice in the Description page of Project Settings.


#include "BehaviorTree/BlackboardComponent.h"
#include "Enemy/Task/BTTask_CheckLOSForTime_Pursuit.h"
#include "Libraries/BFL_ConeCheck.h"


EBTNodeResult::Type UBTTask_CheckLOSForTime_Pursuit::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	startTime = std::chrono::high_resolution_clock::now();	
	
	return EBTNodeResult::InProgress;
}

void UBTTask_CheckLOSForTime_Pursuit::TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	UpdateObjects(OwnerComp);
	TArray<FHitResult> hits;
	if (std::chrono::high_resolution_clock::now() - startTime > std::chrono::seconds(static_cast<long>(WaitTime)))
	{
		UE_LOG(LogTemp, Error, TEXT("Fail"));
		
		FinishLatentTask(OwnerComp, EBTNodeResult::Failed);
		return;
	}
	else if (UBFL_ConeCheck::ConeTraceMulti(EnemyOwner, StartPos, Direction, TraceLength, TraceRadius, TraceTypeQuery1, EnemyOwner, EDrawDebugTrace::ForOneFrame, hits, FLinearColor::Red, FLinearColor::Green, DrawTime))
	{
		UE_LOG(LogTemp, Error, TEXT("Succ"));
		OwnerComp.GetBlackboardComponent()->SetValueAsBool("ShouldCancel", false);
		FinishLatentTask(OwnerComp, EBTNodeResult::Aborted);
		return;
	}
}
