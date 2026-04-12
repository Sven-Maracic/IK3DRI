// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/Service/BTService_PursuitInRange.h"

#include "AIController.h"

void UBTService_PursuitInRange::UpdateObjects(const UBehaviorTreeComponent& OwnerComp)
{
	enemyOwner = Cast<ABP_Enemy>(OwnerComp.GetAIOwner()->GetPawn());
	playerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	startPos = enemyOwner->GetActorLocation();
	traceLength = TargetRange.GetValue(OwnerComp);
}


void UBTService_PursuitInRange::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	UpdateObjects(OwnerComp);	
	
	FVector playerLocation = playerPawn->GetActorLocation();
	FVector targetVector = playerLocation - startPos;
	
	if (IsValid(playerPawn))
	{
		if (targetVector.Length() <= traceLength)
		{
			FHitResult hitResult;
			if (GetWorld()->LineTraceSingleByChannel(hitResult, startPos, playerLocation, ECC_Visibility))
			{
				if (hitResult.GetActor() == playerPawn)
				{
					OwnerComp.GetBlackboardComponent()->SetValueAsVector(LocationOutput.SelectedKeyName, playerPawn->GetActorLocation());
					OwnerComp.GetBlackboardComponent()->SetValueAsInt(PlayerStateOutput.SelectedKeyName, 2);
				}
			}
		}
	}
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
}

UBTService_PursuitInRange::UBTService_PursuitInRange()
{
	NodeName = TEXT("Change state to pursuit if player in range");
}
