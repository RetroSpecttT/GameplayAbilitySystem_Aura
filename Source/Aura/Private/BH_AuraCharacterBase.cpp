// SoilDog


#include "BH_AuraCharacterBase.h"

// Sets default values
ABH_AuraCharacterBase::ABH_AuraCharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABH_AuraCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABH_AuraCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABH_AuraCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

