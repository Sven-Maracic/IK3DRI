// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/Task/BTTask_CheckLOSForTime.h"

#include "AIController.h"
#include "Enemy/BP_Enemy.h"
#include "Enemy/Task/BTTask_CheckLOS.h"
#include "Libraries/BFL_ConeCheck.h"


UBTTask_CheckLOSForTime::UBTTask_CheckLOSForTime()
{
	NodeName = TEXT("Check line-of-sight for player pawn");
	bNotifyTick = true;
	bTickIntervals = true;
}

EBTNodeResult::Type UBTTask_CheckLOSForTime::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	startTime = std::chrono::high_resolution_clock::now();	
	
	return EBTNodeResult::InProgress;
}


void UBTTask_CheckLOSForTime::TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
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
			
		FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
		return;
	}
	UE_LOG(LogTemp, Error, TEXT("Prog"));
}
