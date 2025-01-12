// SoilDog


#include "BH/Character/BH_AuraCharacterBase.h"

// Sets default values
ABH_AuraCharacterBase::ABH_AuraCharacterBase()
{
 	// 把tick设为false是因为base父类现在不需要任何tick，优化性能
	PrimaryActorTick.bCanEverTick = false;

}

void ABH_AuraCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}



