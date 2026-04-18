// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/ValueOrBBKey.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "Enemy/AIControllers/AIC_EnemyTurret.h"
#include "BTTask_FireRangedAttack.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT_API UBTTask_FireRangedAttack : public UBTTask_BlackboardBase
{
	GENERATED_BODY()

public:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	UBTTask_FireRangedAttack();
	void UpdateObjects(const UBehaviorTreeComponent& OwnerComp);
	FVector GetExpectedLocation() const;
	
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="Attack")
	FValueOrBBKey_Float ProjectileSpeed = 3500.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "Attack")
	FValueOrBBKey_Float PredictionBias = 1;	//Higher value = less prediction
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="Debug")
	bool IsDebug = false;
	
protected:
	APawn* playerPawn;
	AAIC_EnemyTurret* enemy;
	float projectileSpeed;
	float predictionBias;
};
