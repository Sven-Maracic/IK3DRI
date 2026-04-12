// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/BP_Enemy.h"

#include "BehaviorTree/BlackboardData.h"

// Sets default values
ABP_Enemy::ABP_Enemy()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}



void ABP_Enemy::Attack()
{
}

void ABP_Enemy::Move()
{
}

// Called when the game starts or when spawned
void ABP_Enemy::BeginPlay()
{
	Super::BeginPlay();
}

UBehaviorTree* ABP_Enemy::GetBehaviourTree() const
{
	return BehaviorTree;
}