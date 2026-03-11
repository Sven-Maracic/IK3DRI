// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Decorators/BTDecorator_BlackboardBase.h"
#include "Enemy/BP_Enemy.h"
#include "BTDecorator_CheckEnemyState.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT_API UBTDecorator_CheckEnemyState : public UBTDecorator_BlackboardBase
{
	GENERATED_BODY()

protected:
	virtual bool CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const override;
	
public:
	explicit UBTDecorator_CheckEnemyState();
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="LOS-Debug")
	TEnumAsByte<EEnemyStates> RequiredState;
};
