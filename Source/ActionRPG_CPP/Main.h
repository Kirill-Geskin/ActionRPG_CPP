// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Main.generated.h"

UCLASS()
class ACTIONRPG_CPP_API AMain : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMain();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* FollowingCamera;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class USpringArmComponent* SpringArm;

	// Base turn rates to scale turning function for the camera
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		float BaseTurnRate;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		float BaseLookUpRate;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void MoveForward(float Value);
	void MoveRight(float Value);

	/* Called via input to turn at a given rate
	param @Rate This is a normalized rate, 1.0 means 100% if desired turn rate */
	void TurnAtRate(float Rate);

	/* Called via input to look up/down at a given rate
	param @Rate This is a normalized rate, 1.0 means 100% if desired look up/down rate */
	void LookUpAtRate(float Rate);

	FORCEINLINE class UCameraComponent* GetFollowingCamera() const { return FollowingCamera; }
	FORCEINLINE class USpringArmComponent* GetSpringArm() const { return SpringArm; }
};
