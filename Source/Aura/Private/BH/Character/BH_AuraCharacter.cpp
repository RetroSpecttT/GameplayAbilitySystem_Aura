// SoilDog


#include "BH/Character/BH_AuraCharacter.h"

#include "GameFramework/CharacterMovementComponent.h"


ABH_AuraCharacter::ABH_AuraCharacter()
{
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate=FRotator(0, 400, 0);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;   //都是为了让镜头不要旋转，控制器也不提供任何旋转值
}
