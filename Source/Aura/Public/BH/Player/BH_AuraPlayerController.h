// SoilDog

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Player/AuraPlayerController.h"
#include "BH_AuraPlayerController.generated.h"

class UInputComponent;   //提前把这个类放到header里


/**
 * 
 */
UCLASS()
class AURA_API ABH_AuraPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ABH_AuraPlayerController();   //相当于我们创建了一个函数，函数内容在cpp

protected:
	virtual void BeginPlay() override;   //开始游戏时执行一次，也相当于一个函数，内容在cpp

private:
	UPROPERTY(EditAnywhere, Category="Input")   //把这个模组变成可编辑，放到Input分类里
	TObjectPtr<UInputMappingContext> AuraContext;   //这个输入模组名字叫AuraContext
};
