// SoilDog


#include "BH/Player/BH_AuraPlayerController.h"

#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "BH/Interaction/BH_EnemyInterface.h"

ABH_AuraPlayerController::ABH_AuraPlayerController()
{
	bReplicates = true;   //确保输入支持多人模式
}

void ABH_AuraPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);
	
	CursorTrace();   //每帧都执行这个函数

	
}

void ABH_AuraPlayerController::CursorTrace()
{
	FHitResult CursorHit;
	GetHitResultUnderCursor(ECollisionChannel::ECC_Visibility,false,CursorHit);   //把击中结果输出在CursorHit里面
	if (!CursorHit.bBlockingHit) return;   //如果没有击中任何东西，则return

	LastActor = ThisActor;  //每一帧，都将上一个actor设为thisactor，延迟有一帧
	ThisActor = Cast<IBH_EnemyInterface>(CursorHit.GetActor());   //用鼠标击中结果里面的getactor，去cast to 那个接口，如果这个 actor有这个接口，则成功激活这个接口
	
	
	if (LastActor == nullptr)
	{
		if (ThisActor != nullptr)
		{
			ThisActor->HighlightActor();   //Case B
		}
		else
		{
			//Case A, Both are null, do nothing
		}
	}
	else  // Last actor is valid
	{
		if (ThisActor == nullptr)
		{
			//Case C
			LastActor->UnHighlightActor();
		}
		else
		{
			if (LastActor != ThisActor)
			{
				//Case D
				LastActor->UnHighlightActor();
				ThisActor->HighlightActor();
			}
			else
			{
				//Case E do nothing
			}
		}
	}	
	
}

void ABH_AuraPlayerController::BeginPlay()
{
	Super::BeginPlay();

	check(AuraContext);   //检查一下AuraContext这个输入模组是否有效,无效的话，下面的代码则不执行

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());   //游戏一开始加载这个增强输入模组的蓝图类，然后新建一个蓝图，叫subsystem，然后把内容放进这个subsystem里面
	check(Subsystem);   //检查一下subsystem是否有效，无效的话下面的代码则不执行
	Subsystem->AddMappingContext(AuraContext,0);   //调用Subsystem里面的添加增强输入模组，加载输入配置文件，文件名字叫AUraContext，优先度是最高的0

	bShowMouseCursor = true	;  //显示鼠标指针，这个命令包含在了 controller类里面
	DefaultMouseCursor = EMouseCursor::Default;   //鼠标指针的风格为Default  这个命令包含在了 controller类里面

	FInputModeGameAndUI InputModeData;   //用FInputModeGameAndUI这个预设好的Struct创建一个变量，名字叫InputModeData
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);   //触发这个struct里面的绿字函数，然后再套娃触发绿字函数里面的这个设置，变为鼠标非锁定
	InputModeData.SetHideCursorDuringCapture(false);   //同理，让鼠标被屏幕捕捉到的时候不要隐藏
	SetInputMode(InputModeData);   //调用 绿字函数，设置输入模式 为 白字的struct设定
}

void ABH_AuraPlayerController::SetupInputComponent()   //定义函数里面的内容
{
	Super::SetupInputComponent();   //Super相当于继承之前父类的内容，先把之前父类的内容执行一次，然后才是我们的内容

	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);   //创造一个蓝图类，叫白字部分，然后把这个蓝图cast到UEnhancedInputComponent，并且检查is valid

	EnhancedInputComponent->BindAction(MoveAction,ETriggerEvent::Triggered,this, &ABH_AuraPlayerController::Move);   //使用这个组件里的内置功能BindAction,然后把MoveAction这个IA文件绑定给一个函数叫Move
}


void ABH_AuraPlayerController::Move(const FInputActionValue& InputActionValue)
{
	const FVector2D InputAxisVector = InputActionValue.Get<FVector2D>();   //创建一个FVector2D类型的变量，变量赋值为，获取这个结构体里面的FVector2D
	const FRotator Rotation = GetControlRotation();   //创建第二个变量，值是控制器的旋转值
	const FRotator YawRotation(0.f,Rotation.Yaw, 0.f);   //第三个变量也是一个旋转值，赋值只取上一个变量的yaw，其他2个都是0

	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);   //创建第四个变量，名字取好，赋予的值是首选调用紫色蓝图，使用第三个变量喂进去，然后执行里面的GetUnitAxis，只需要X，也就是前方的值
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);   //同样的步骤获取左右方向的数值

	if (APawn* ControlledPawn = GetPawn<APawn>())   //以APawn为蓝图base，创建一个pawn蓝图，白色为名字，然后赋值 获取棋子，类型是APawn
	{
		ControlledPawn->AddMovementInput(ForwardDirection,InputAxisVector.Y);   //如果APawn为true，存在，则添加移动函数，移动前后用ForwardDirection的值
		ControlledPawn->AddMovementInput(RightDirection,InputAxisVector.X);

		
	}
}

