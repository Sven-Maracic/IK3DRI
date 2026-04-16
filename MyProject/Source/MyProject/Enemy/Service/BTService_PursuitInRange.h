// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/ValueOrBBKey.h"
#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "Enemy/BP_Enemy.h"
#include "BTService_PursuitInRange.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT_API UBTService_PursuitInRange : public UBTService_BlackboardBase
{
	GENERATED_BODY()

protected:
	void UpdateObjects(const UBehaviorTreeComponent& OwnerComp);
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;

public:
	UBTService_PursuitInRange();
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="LOS")
	FValueOrBBKey_Float TargetRange = 600.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Blackboard")
	FBlackboardKeySelector LocationOutput;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Blackboard")
	FBlackboardKeySelector PlayerStateOutput;
	
protected:
	ABP_Enemy* enemyOwner;
	FVector startPos;
	APawn* playerPawn;
	float traceLength;
};
