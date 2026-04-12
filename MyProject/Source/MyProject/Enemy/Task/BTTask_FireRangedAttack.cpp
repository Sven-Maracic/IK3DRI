// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/Task/BTTask_FireRangedAttack.h"

#include "Enemy/AIControllers/AIC_EnemyTurret.h"

UBTTask_FireRangedAttack::UBTTask_FireRangedAttack()
{
	NodeName = "Fire projectile towards player";
}

void UBTTask_FireRangedAttack::UpdateObjects(const UBehaviorTreeComponent& OwnerComp)
{
	playerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	enemy = Cast<AAIC_EnemyTurret>(OwnerComp.GetAIOwner());
	predictionBias = PredictionBias.GetValue(OwnerComp);
	projectileSpeed = ProjectileSpeed.GetValue(OwnerComp);
}

EBTNodeResult::Type UBTTask_FireRangedAttack::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UpdateObjects(OwnerComp);
	FVector endPos = GetExpectedLocation();
	
	if (IsDebug)	DrawDebugSphere(GetWorld(), endPos, 10.0f, 16, FColor::Green, false, 2, 0, 2.0f);

	if (IsValid(enemy))
	{
		enemy->FireProjectile(endPos);
	}
	return Super::ExecuteTask(OwnerComp, NodeMemory);
}



FVector UBTTask_FireRangedAttack::GetExpectedLocation() const
{
	FVector playerStartVel = playerPawn->GetVelocity();
	FVector playerStartPos = playerPawn->GetActorLocation();
	float timeOffset =  (enemy->GetPawn()->GetActorLocation() - playerStartPos).Length() / projectileSpeed;
	FVector endPos = playerStartPos + FVector(playerStartVel.X * timeOffset, playerStartVel.Y * timeOffset, playerStartVel.Z * timeOffset  / 4) / predictionBias ;
	return endPos;
}