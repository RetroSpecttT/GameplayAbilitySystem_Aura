// SoilDog

#pragma once

#include "CoreMinimal.h"
#include "InputActionValue.h"
#include "GameFramework/PlayerController.h"
#include "Player/AuraPlayerController.h"
#include "BH_AuraPlayerController.generated.h"

class UInputComponent;   //提前把这个类放到header里，提前创建好
class UInputAction;   //提前创建好这个类
struct FInputActionValue;   //提前声明，这个浅紫色的结构 是个struct结构体
class IBH_EnemyInterface;

/**
 * 
 */
UCLASS()
class AURA_API ABH_AuraPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ABH_AuraPlayerController();   //相当于我们创建了一个函数，函数内容在cpp
	virtual void PlayerTick(float DeltaTime) override;

	

protected:
	virtual void BeginPlay() override;   //开始游戏时执行一次，也相当于一个函数，内容在cpp
	virtual void SetupInputComponent() override;   //为什么要override 因为这个函数之前在角色base有了，但是被我们删了，我们相当于是在控制器里叠加一层控制组件
	
private:
	UPROPERTY(EditAnywhere, Category="Input")   //把这个模组变成可编辑，放到Input分类里
	TObjectPtr<UInputMappingContext> AuraContext;   //添加一个增强输入模组，这个输入模组名字叫AuraContext，相当于IMC文件

	UPROPERTY(EditAnywhere, Category="Input") 
	TObjectPtr<UInputAction> MoveAction;   //创建一个组件，类型是紫色名字，名字叫MoveAction，相当于配置IA文件

	void Move(const FInputActionValue& InputActionValue);     //创建一个函数，叫Move，之后要配给上面的MoveAction。因为浅紫色

	void CursorTrace();   //创建一个函数，让鼠标能够追踪actor
	
	IBH_EnemyInterface* LastActor;   //在这个文件里面，指向敌人接口，然后在这里直接创建一个接口，叫LastActor
	IBH_EnemyInterface* ThisActor;



	
};


