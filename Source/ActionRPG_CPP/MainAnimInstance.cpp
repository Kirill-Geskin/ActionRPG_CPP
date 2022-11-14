// Fill out your copyright notice in the Description page of Project Settings.


#include "MainAnimInstance.h"
#include "GameFramework/CharacterMovementComponent.h"

void UMainAnimInstance::NativeInitializeAnimation()
{
	if (Pawn == nullptr) 
	{
		Pawn = TryGetPawnOwner();
	}
}

void UMainAnimInstance::UpdateAnimationProperties() 
{
	if (Pawn == nullptr)
	{
		Pawn = TryGetPawnOwner();
	}

	if (Pawn)
	{
		FVector Speed = Pawn->GetVelocity(); // GetVelocity() - built-in standart Pawn function. Return speed of Pawn 
		FVector LateralSpeed = FVector(Speed.X, Speed.Y, 0.f); //we intrsted only in horizontal direction, that why Z == 0 
		MovementSpeed = LateralSpeed.Size(); // update MovementSpeed

		bIsInAir = Pawn->GetMovementComponent()->IsFalling();
	}
}
