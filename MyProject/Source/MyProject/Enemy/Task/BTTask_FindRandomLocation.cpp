// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/Task/BTTask_FindRandomLocation.h"

#include "NavigationSystem.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Enemy/EnemyGround/AIC_EnemyGround.h"
#include "NavFilters/NavigationQueryFilter.h"

UBTTask_FindRandomLocation::UBTTask_FindRandomLocation()
{
	NodeName = "Find Random Location in Radius on NavMesh";
}

EBTNodeResult::Type UBTTask_FindRandomLocation::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	//get owner of script and cast it to AI controller base class
	if (AAIC_Base* const aiController = Cast<AAIC_Base>(OwnerComp.GetAIOwner()))
	{
		if (APawn* const enemy = aiController->GetPawn()) //cast aiController object as Pawn
		{
			const FVector origin = enemy->GetActorLocation(); //get enemy location
			
			//UNavigationSystem implements NavMesh detection in our script
			if (UNavigationSystemV1* const navSys = UNavigationSystemV1::GetCurrent(GetWorld()))
			{
				FNavLocation navLocation;
				//GetRandomPointInNavigableRadius -> finds a random point on navmesh within SearchRadius starting at Origin, saves it in NavLocation
				if (navSys->GetRandomPointInNavigableRadius(origin, SearchRadius, navLocation))
				{
					//save random location to blackboard
					OwnerComp.GetBlackboardComponent()->SetValueAsVector(OutputLocationKey.SelectedKeyName, navLocation.Location);
				}
				//debug, draw where enemy is trying to move to
				DrawDebugSphere(GetWorld(), navLocation, 10.0f, 32, FColor::Cyan, false, 3, 0, 2.0f);
			}
			return EBTNodeResult::Succeeded; //return success
		}
	}
	return EBTNodeResult::Failed; //if casting failed, return fail
}

void UBTTask_FindRandomLocation::InitializeFromAsset(UBehaviorTree& Asset)
{
	Super::InitializeFromAsset(Asset);

	if (const UBlackboardData* BBAsset = GetBlackboardAsset())
	{
		OutputLocationKey.ResolveSelectedKey(*BBAsset);
	}
}