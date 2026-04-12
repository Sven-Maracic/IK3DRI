// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/EnemyGround/AIC_EnemyGround.h"


void AAIC_EnemyGround::LookAt(FVector TargetLocation)
{
	if (!TargetLocation.Equals(FVector::ZeroVector)){
		FRotator LookAtRot = FRotationMatrix::MakeFromX(TargetLocation - GetPawn()->GetActorLocation()).Rotator();

		FRotator CurrentRot = GetPawn()->GetActorRotation();
		GetPawn()->SetActorRotation(FRotator(CurrentRot.Pitch, LookAtRot.Yaw, CurrentRot.Roll));
	}
}
