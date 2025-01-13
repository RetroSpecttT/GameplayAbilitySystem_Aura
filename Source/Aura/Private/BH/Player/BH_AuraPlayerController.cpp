// SoilDog


#include "BH/Player/BH_AuraPlayerController.h"

#include "EnhancedInputSubsystems.h"

ABH_AuraPlayerController::ABH_AuraPlayerController()
{
	bReplicates = true;   //确保输入支持多人模式
}

void ABH_AuraPlayerController::BeginPlay()
{
	Super::BeginPlay();

	check(AuraContext);   //检查一下AuraContext这个输入模组是否有效,无效的话，下面的代码则不执行

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());   //游戏一开始加载这个增强输入模组
	check(Subsystem);   //检查一下subsystem是否有效，无效的话下面的代码则不执行
	Subsystem->AddMappingContext(AuraContext,0);   //加在AUraContext这个文件，优先度是最高的0

	bShowMouseCursor = true	;  //显示鼠标指针
	DefaultMouseCursor = EMouseCursor::Default;   //鼠标指针的风格为Default

	FInputModeGameAndUI InputModeData;   //这个功能使用白字的设定（白字的设定相当于一个struct）
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);   //而白色的设定则把鼠标设置为 不锁定
	InputModeData.SetHideCursorDuringCapture(false);   //鼠标被屏幕记录到的时候，不要隐藏
	SetInputMode(InputModeData);   //设置输入模式 为 白字的struct设定
}
