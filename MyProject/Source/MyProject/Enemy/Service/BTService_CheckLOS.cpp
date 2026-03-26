// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/Service/BTService_CheckLOS.h"

#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Libraries/BFL_ConeCheck.h"

void UBTService_CheckLOS::UpdateObjects(const UBehaviorTreeComponent& OwnerComp)
{
	EnemyOwner = Cast<ABP_Enemy>(OwnerComp.GetAIOwner()->GetPawn());
	StartPos = EnemyOwner->GetActorLocation() + OriginOffset;
	Direction = EnemyOwner->GetActorForwardVector().Rotation();
	PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	TraceLength = TraceLengthKey.GetValue(OwnerComp);
}

void UBTService_CheckLOS::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	UpdateObjects(OwnerComp);
	TArray<FHitResult> hits;
	if (PlayerPawn != nullptr)	//only check LOS if player actually exists
	{
		if (UBFL_ConeCheck::ConeTraceMulti(EnemyOwner, StartPos, Direction, TraceLength, TraceRadius, ECC_Visibility, EnemyOwner, EDrawDebugTrace::ForOneFrame, hits, FLinearColor::Red, FLinearColor::Green, DrawTime))
		{
			for (auto currHit : hits)
			{
				if (currHit.GetActor() == PlayerPawn)
				{
					OwnerComp.GetBlackboardComponent()->SetValueAsVector(LocationOutput.SelectedKeyName, PlayerPawn->GetActorLocation());
				}
			}
		}
	}
	//return EBTNodeResult::Failed;
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
}

UBTService_CheckLOS::UBTService_CheckLOS()
{
	NodeName = TEXT("Check line of sight for player");
}

void UBTService_CheckLOS::InitializeFromAsset(UBehaviorTree& Asset)
{
	Super::InitializeFromAsset(Asset);

	if (const UBlackboardData* BBAsset = GetBlackboardAsset())
	{
		LocationOutput.ResolveSelectedKey(*BBAsset);
	}
}
