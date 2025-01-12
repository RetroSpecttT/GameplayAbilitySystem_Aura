// SoilDog

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BH_AuraCharacterBase.generated.h"

UCLASS()
class AURA_API ABH_AuraCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABH_AuraCharacterBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
