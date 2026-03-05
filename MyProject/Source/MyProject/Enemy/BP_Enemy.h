// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BehaviorTree.h"
#include "GameFramework/Character.h"
#include "BP_Enemy.generated.h"


UENUM(BlueprintType)
enum EEnemyStates
{
	Idle,		//0
	Patrolling,	//1
	Aggro,		//2
	Stunned,	//3
	Dead		//4
};

UCLASS()
class MYPROJECT_API ABP_Enemy : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABP_Enemy();

	

protected:
	EEnemyStates CurrentState = Idle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AI")
		UBehaviorTree* BehaviorTree;

	virtual void Attack();
	virtual void Move();
	virtual void BeginPlay() override;

public:
	UBehaviorTree* GetBehaviourTree() const;
	UFUNCTION(BlueprintCallable, Category="State")
	void ChangeState(EEnemyStates state);
	UFUNCTION(BlueprintCallable, Category="State")
	EEnemyStates GetState();
};
