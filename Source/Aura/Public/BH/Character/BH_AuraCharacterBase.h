// SoilDog

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BH_AuraCharacterBase.generated.h"

UCLASS(Abstract)// 写abstract是为了防止这个Uclass被放进这个level
class AURA_API ABH_AuraCharacterBase : public ACharacter
{
	GENERATED_BODY()

public://相当于 construction script
	ABH_AuraCharacterBase();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category="Combat")
	TObjectPtr<USkeletalMeshComponent> Weapon; //一开始先创建一个SKM叫做Weapon，因为所有人物都需要,但是里面是空壳子
	


	

//把tick和input删了，因为base蓝图不惜要tick，而敌人也不需要input，所以删了

};
