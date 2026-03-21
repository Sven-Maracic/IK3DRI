// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_CheckLOS.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "MyProject/Libraries/BFL_ConeCheck.h"
#include "AIController.h"
#include "Kismet/KismetSystemLibrary.h"



UBTTask_CheckLOS::UBTTask_CheckLOS()
{
	NodeName = TEXT("Check line-of-sight for player pawn");
}

void UBTTask_CheckLOS::UpdateObjects(const UBehaviorTreeComponent& OwnerComp)
{
	EnemyOwner = Cast<ABP_Enemy>(OwnerComp.GetAIOwner()->GetPawn());
	StartPos = EnemyOwner->GetActorLocation() + OriginOffset;
	Direction = EnemyOwner->GetActorForwardVector().Rotation();
	PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	TraceLength = TraceLengthKey.GetValue(OwnerComp);
}

EBTNodeResult::Type UBTTask_CheckLOS::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UpdateObjects(OwnerComp);
	
	//trace
	TArray<FHitResult> hits;
	if (PlayerPawn != nullptr)	//only check LOS if player actually exists (isnt spectator pawn)
	{
		if (UBFL_ConeCheck::ConeTraceMulti(EnemyOwner, StartPos, Direction, TraceLength, TraceRadius, ECC_Visibility, EnemyOwner, EDrawDebugTrace::ForOneFrame, hits, FLinearColor::Red, FLinearColor::Green, DrawTime))
		{
			for (auto currHit : hits)
			{
				if (currHit.GetActor() == PlayerPawn)
				{
					return EBTNodeResult::Succeeded;
				}
			}
		}
	}
	return EBTNodeResult::Failed;
}
