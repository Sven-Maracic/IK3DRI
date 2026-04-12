// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BehaviorTree.h"
#include "GameFramework/Character.h"
#include "BP_Enemy.generated.h"

UCLASS()
class MYPROJECT_API ABP_Enemy : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABP_Enemy();

	

protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AI")
		UBehaviorTree* BehaviorTree;

	virtual void Attack();
	virtual void Move();
	virtual void BeginPlay() override;

public:
	UBehaviorTree* GetBehaviourTree() const;
};
