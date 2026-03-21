// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/ValueOrBBKey.h"
#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "Enemy/BP_Enemy.h"
#include "BTService_CheckLOS.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT_API UBTService_CheckLOS : public UBTService_BlackboardBase
{
	GENERATED_BODY()

protected:
	void UpdateObjects(const UBehaviorTreeComponent& OwnerComp);
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;

public:
	UBTService_CheckLOS();
	virtual void InitializeFromAsset(UBehaviorTree& Asset) override;

	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="LOS")
	FVector OriginOffset = FVector(0.0f, 0.0f, 0.0f);
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="LOS")
	FValueOrBBKey_Float TraceLengthKey = 600.0f;
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="LOS")
	float TraceRadius = 30.0f;
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="LOS-Debug")
	float DrawTime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Blackboard")
	FBlackboardKeySelector LocationOutput;
	
protected:
	float TraceLength;
	ABP_Enemy* EnemyOwner;
	FVector StartPos;
	FRotator Direction;
	APawn* PlayerPawn;
};
