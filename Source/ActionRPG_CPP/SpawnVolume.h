
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpawnVolume.generated.h"

UCLASS()
class ACTIONRPG_CPP_API ASpawnVolume : public AActor
{
	GENERATED_BODY()
	
public:	
	ASpawnVolume();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Spawning")
	class UBoxComponent* SpawningBox;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Spawning")
	TSubclassOf<class ACritter> PawnToSpawn;

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintPure, Category = "Spawning")
	FVector GetSpawnPoint();

	/*
	BlueprintNativeEvent - Is a Hybrid option. Allows you to make settings in both CPP and Blueprints
	*
	The difference of the function lies in the fact that when using the BlueprintNativeEvent modifier, 
	we define only a part of the behavior in CPP, for this, in the file.cpp 
	we specify not the full name of the function, but the _Implementation changed with the postfix
	SpawnOurPawn_Implementation
	*/
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Spawning")
	void SpawnOurPawn(UClass* ToSpawn, const FVector& Location);

	virtual void SpawnOurPawn_Implementation(UClass* ToSpawn, const FVector& Location);
};
