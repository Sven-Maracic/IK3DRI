// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/Task/BTTask_CheckLOS.h"
#include "MyProject/Libraries/BFL_ConeCheck.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Enemy/BP_Enemy.h"
#include "GameFramework/Character.h"


UBTTask_CheckLOS::UBTTask_CheckLOS()
{
	NodeName = "Check line-of-sight for player pawn";
}

EBTNodeResult::Type UBTTask_CheckLOS::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	ABP_Enemy* owner = Cast<ABP_Enemy>(OwnerComp.GetAIOwner()->GetPawn());
	FVector startPos = owner->GetActorLocation() + OriginOffset;
	FRotator direction = owner->GetActorForwardVector().Rotation();
	APawn* playerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	
	//trace
	TArray<FHitResult> hits;
	if (playerPawn != nullptr)	//only check LOS if player actually exists (isnt spectator pawn)
	{
		if (UBFL_ConeCheck::ConeTraceMulti(owner, startPos, direction, TraceLength, TraceRadius, TraceTypeQuery1, owner, EDrawDebugTrace::ForOneFrame, hits, FLinearColor::Red, FLinearColor::Green, DrawTime))
		{
			for (auto currHit : hits)
			{
				if (currHit.GetActor() == playerPawn)
				{
					owner->ChangeState(EEnemyStates::Aggro);
					OwnerComp.GetBlackboardComponent()->SetValueAsInt("CurrentState", EEnemyStates::Aggro);
					return EBTNodeResult::Succeeded;
				}
			}
			
		}
	}
	return EBTNodeResult::Failed;
}

