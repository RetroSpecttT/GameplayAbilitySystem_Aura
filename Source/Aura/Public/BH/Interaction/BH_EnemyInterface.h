// SoilDog

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "BH_EnemyInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UBH_EnemyInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class AURA_API IBH_EnemyInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	virtual void HighlightActor() = 0;   //如果把这个虚拟函数赋值为0，则不需要去定义，也不需要写任何东西，只是个接口,就会变成一个抽象，抽象是无法被实例化的
	virtual void UnHighlightActor() = 0;   //现在有两个接口了

	
};
