// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/BTService_GetPlayerLocation.h"

#include "BehaviorTree/BlackboardComponent.h"

void UBTService_GetPlayerLocation::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	APawn* playerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (playerPawn == nullptr)	//ignore if no player in world
	{
		UE_LOG(LogTemp, Error, TEXT("Player not found"));
	}
	OwnerComp.GetBlackboardComponent()->SetValueAsVector("TargetLocation", playerPawn->GetActorLocation());
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
}
