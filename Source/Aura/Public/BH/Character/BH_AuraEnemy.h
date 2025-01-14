// SoilDog

#pragma once

#include "CoreMinimal.h"
#include "BH/Character/BH_AuraCharacterBase.h"
#include "BH/Interaction/BH_EnemyInterface.h"
#include "BH_AuraEnemy.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API ABH_AuraEnemy : public ABH_AuraCharacterBase, public IBH_EnemyInterface   //继承接口
{
	GENERATED_BODY()

public:
	ABH_AuraEnemy();   //Construction Script
	
	virtual void HighlightActor() override;   //覆盖这个接口，写下自己的内容
	virtual void UnHighlightActor() override;   //覆盖这个接口，写下自己的内容
	
	
};