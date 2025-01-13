// SoilDog


#include "BH/Character/BH_AuraCharacterBase.h"

// Sets default values
ABH_AuraCharacterBase::ABH_AuraCharacterBase()
{
 	
	PrimaryActorTick.bCanEverTick = false;    // 把tick设为false是因为base父类现在不需要任何tick，优化性能

	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");       //游戏一开始，先把Weapon这个空的SKM放进一个SKM，名字也叫做WeaponSKM
	Weapon->SetupAttachment(GetMesh(),FName("WeaponHandSocket"));   //把这个WeaponSKM粘贴到一个插槽，叫WeaponHandSocket，基于Mesh
	Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);   //把碰撞关闭


	
}

void ABH_AuraCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}



