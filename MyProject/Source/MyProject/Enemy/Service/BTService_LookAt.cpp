// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/Service/BTService_LookAt.h"

void UBTService_LookAt::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	enemy = Cast<AAIC_Base>(OwnerComp.GetAIOwner());
	
	if (IsValid(enemy))
	{
		enemy->LookAt(TargetLocation.GetValue(OwnerComp));
	}
	else UE_LOG(LogTemp, Error, TEXT("UBTTask_LookTowardsPlayer -> enemy not valid"));
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
}

UBTService_LookAt::UBTService_LookAt()
{
	NodeName = TEXT("Look at Vector location");
}
