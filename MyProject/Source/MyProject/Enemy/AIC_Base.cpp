// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/AIC_Base.h"

#include "BP_Enemy.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"

AAIC_Base::AAIC_Base()
{
}

void AAIC_Base::OnPossess(APawn* pawn)
{
	Super::OnPossess(pawn);
	if (const ABP_Enemy* enemy = Cast<ABP_Enemy>(pawn))
	{
		if (UBehaviorTree* BehaviorTree = enemy->GetBehaviourTree())
		{
			UBlackboardComponent* tempBlackboard;
			//get blackboard from behavior tree and store it in UBlackboardComponent tempBlackboard
			UseBlackboard(BehaviorTree->BlackboardAsset, tempBlackboard);
			
			tempBlackboard->SetValueAsObject("Player", UGameplayStatics::GetPlayerCharacter(GetWorld(),0));
			
			Blackboard = tempBlackboard; //save that tempBlackboard as the main AIController blackboard
			RunBehaviorTree(BehaviorTree);
		}
	}
}
