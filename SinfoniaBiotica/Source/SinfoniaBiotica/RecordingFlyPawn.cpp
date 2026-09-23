#include "RecordingFlyPawn.h"

#include "Camera/CameraComponent.h"
#include "Camera/PlayerCameraManager.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "GameFramework/PlayerController.h"
#include "InputAction.h"
#include "InputMappingContext.h"
#include "LevelSequence.h"
#include "LevelSequenceActor.h"
#include "LevelSequencePlayer.h"
#include "UObject/ConstructorHelpers.h"

ARecordingFlyPawn::ARecordingFlyPawn()
{
	PrimaryActorTick.bCanEverTick = false;

	bUseControllerRotationPitch = true;
	bUseControllerRotationYaw = true;
	bUseControllerRotationRoll = false;
	bAddDefaultMovementBindings = false;

	static ConstructorHelpers::FObjectFinder<UInputMappingContext> IMCFinder(
		TEXT("/Game/VRSpectator/Input/IMC_VRSpectator.IMC_VRSpectator"));
	if (IMCFinder.Succeeded())
	{
		DefaultMappingContext = IMCFinder.Object;
	}

	static ConstructorHelpers::FObjectFinder<UInputAction> MoveFinder(
		TEXT("/Game/VRSpectator/Input/Actions/IA_VRSpectator_Move.IA_VRSpectator_Move"));
	if (MoveFinder.Succeeded())
	{
		MoveAction = MoveFinder.Object;
	}

	static ConstructorHelpers::FObjectFinder<UInputAction> LookFinder(
		TEXT("/Game/VRSpectator/Input/Actions/IA_VRSpectator_Look.IA_VRSpectator_Look"));
	if (LookFinder.Succeeded())
	{
		LookAction = LookFinder.Object;
	}

	static ConstructorHelpers::FObjectFinder<UInputAction> FovFinder(
		TEXT("/Game/VRSpectator/Input/Actions/IA_VRSpectator_FOV.IA_VRSpectator_FOV"));
	if (FovFinder.Succeeded())
	{
		FovAction = FovFinder.Object;
	}

	static ConstructorHelpers::FObjectFinder<UInputAction> FovUpFinder(
		TEXT("/Game/VRSpectator/Input/Actions/IA_Recording_FOVUp.IA_Recording_FOVUp"));
	if (FovUpFinder.Succeeded())
	{
		FovUpAction = FovUpFinder.Object;
	}

	static ConstructorHelpers::FObjectFinder<UInputAction> FovDownFinder(
		TEXT("/Game/VRSpectator/Input/Actions/IA_Recording_FOVDown.IA_Recording_FOVDown"));
	if (FovDownFinder.Succeeded())
	{
		FovDownAction = FovDownFinder.Object;
	}

	static ConstructorHelpers::FObjectFinder<UInputAction> FovResetFinder(
		TEXT("/Game/VRSpectator/Input/Actions/IA_VRSpectator_FOV_Reset.IA_VRSpectator_FOV_Reset"));
	if (FovResetFinder.Succeeded())
	{
		FovResetAction = FovResetFinder.Object;
	}

	static ConstructorHelpers::FObjectFinder<UInputAction> SeqPlayFinder(
		TEXT("/Game/VRSpectator/Input/Actions/IA_Recording_SequencePlayStop.IA_Recording_SequencePlayStop"));
	if (SeqPlayFinder.Succeeded())
	{
		SequencePlayStopAction = SeqPlayFinder.Object;
	}

	static ConstructorHelpers::FObjectFinder<UInputAction> SeqStartFinder(
		TEXT("/Game/VRSpectator/Input/Actions/IA_Recording_SequenceGoToStart.IA_Recording_SequenceGoToStart"));
	if (SeqStartFinder.Succeeded())
	{
		SequenceGoToStartAction = SeqStartFinder.Object;
	}

	static ConstructorHelpers::FObjectFinder<UInputAction> SeqEndFinder(
		TEXT("/Game/VRSpectator/Input/Actions/IA_Recording_SequenceGoToEnd.IA_Recording_SequenceGoToEnd"));
	if (SeqEndFinder.Succeeded())
	{
		SequenceGoToEndAction = SeqEndFinder.Object;
	}

	static ConstructorHelpers::FObjectFinder<ULevelSequence> SeqFinder(
		TEXT("/Game/Sequences/Main_Sequence.Main_Sequence"));
	if (SeqFinder.Succeeded())
	{
		SequenceAsset = SeqFinder.Object;
	}

	if (UFloatingPawnMovement* MoveComp = Cast<UFloatingPawnMovement>(GetMovementComponent()))
	{
		MoveComp->MaxSpeed = 800.f;
		MoveComp->Acceleration = 4000.f;
		MoveComp->Deceleration = 8000.f;
	}
}

void ARecordingFlyPawn::BeginPlay()
{
	Super::BeginPlay();
	SetupFreeCursor();
	AddMappingContext();
	ApplyFOV(DefaultFOV);
	EnsureSequencePlayer();
}

void ARecordingFlyPawn::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	SetupFreeCursor();
	AddMappingContext();
	ApplyFOV(DefaultFOV);
}

void ARecordingFlyPawn::PawnClientRestart()
{
	Super::PawnClientRestart();
	SetupFreeCursor();
	AddMappingContext();
	ApplyFOV(DefaultFOV);
}

void ARecordingFlyPawn::SetupFreeCursor()
{
	if (APlayerController* PC = Cast<APlayerController>(GetController()))
	{
		FInputModeGameAndUI Mode;
		Mode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
		Mode.SetHideCursorDuringCapture(false);
		Mode.SetWidgetToFocus(nullptr);
		PC->SetInputMode(Mode);
		PC->bShowMouseCursor = true;
		PC->SetShowMouseCursor(true);
		PC->bEnableClickEvents = true;
		PC->bEnableMouseOverEvents = true;
		PC->CurrentMouseCursor = EMouseCursor::Default;
		PC->DefaultMouseCursor = EMouseCursor::Default;
	}
}

void ARecordingFlyPawn::AddMappingContext()
{
	if (!DefaultMappingContext)
	{
		return;
	}

	if (APlayerController* PC = Cast<APlayerController>(GetController()))
	{
		if (ULocalPlayer* LP = PC->GetLocalPlayer())
		{
			if (UEnhancedInputLocalPlayerSubsystem* Subsystem =
					LP->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
			{
				Subsystem->AddMappingContext(DefaultMappingContext, MappingPriority);
			}
		}
	}
}

void ARecordingFlyPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (!FovUpAction)
	{
		FovUpAction = LoadObject<UInputAction>(
			nullptr, TEXT("/Game/VRSpectator/Input/Actions/IA_Recording_FOVUp.IA_Recording_FOVUp"));
	}
	if (!FovDownAction)
	{
		FovDownAction = LoadObject<UInputAction>(
			nullptr, TEXT("/Game/VRSpectator/Input/Actions/IA_Recording_FOVDown.IA_Recording_FOVDown"));
	}

	if (UEnhancedInputComponent* EIC = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		if (MoveAction)
		{
			EIC->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ARecordingFlyPawn::HandleMove);
		}
		if (LookAction)
		{
			EIC->BindAction(LookAction, ETriggerEvent::Triggered, this, &ARecordingFlyPawn::HandleLook);
		}
		if (FovAction)
		{
			EIC->BindAction(FovAction, ETriggerEvent::Triggered, this, &ARecordingFlyPawn::HandleFOVAxis);
		}
		if (FovUpAction)
		{
			EIC->BindAction(FovUpAction, ETriggerEvent::Started, this, &ARecordingFlyPawn::HandleFOVUp);
		}
		if (FovDownAction)
		{
			EIC->BindAction(FovDownAction, ETriggerEvent::Started, this, &ARecordingFlyPawn::HandleFOVDown);
		}
		if (FovResetAction)
		{
			EIC->BindAction(FovResetAction, ETriggerEvent::Started, this, &ARecordingFlyPawn::HandleFOVReset);
		}
		if (SequencePlayStopAction)
		{
			EIC->BindAction(SequencePlayStopAction, ETriggerEvent::Started, this, &ARecordingFlyPawn::HandleSequencePlayStop);
		}
		if (SequenceGoToStartAction)
		{
			EIC->BindAction(SequenceGoToStartAction, ETriggerEvent::Started, this, &ARecordingFlyPawn::HandleSequenceGoToStart);
		}
		if (SequenceGoToEndAction)
		{
			EIC->BindAction(SequenceGoToEndAction, ETriggerEvent::Started, this, &ARecordingFlyPawn::HandleSequenceGoToEnd);
		}
	}
}

void ARecordingFlyPawn::HandleMove(const FInputActionValue& Value)
{
	if (!Controller)
	{
		return;
	}

	const FVector Axis = Value.Get<FVector>();
	const FRotator YawRot(0.f, Controller->GetControlRotation().Yaw, 0.f);
	const FVector Forward = FRotationMatrix(YawRot).GetUnitAxis(EAxis::X);
	const FVector Right = FRotationMatrix(YawRot).GetUnitAxis(EAxis::Y);

	AddMovementInput(Forward, Axis.Y * MoveScale);
	AddMovementInput(Right, Axis.X * MoveScale);
	AddMovementInput(FVector::UpVector, Axis.Z * MoveScale);
}

void ARecordingFlyPawn::HandleLook(const FInputActionValue& Value)
{
	const FVector2D Axis = Value.Get<FVector2D>();
	AddControllerYawInput(Axis.X * LookYawScale);
	AddControllerPitchInput(Axis.Y * LookPitchScale);
}

void ARecordingFlyPawn::HandleFOVAxis(const FInputActionValue& Value)
{
	const float Axis = Value.Get<float>();
	if (FMath::IsNearlyZero(Axis))
	{
		return;
	}
	ApplyFOV(GetCurrentFOV() + Axis * FovStep);
}

void ARecordingFlyPawn::HandleFOVUp(const FInputActionValue& Value)
{
	ApplyFOV(GetCurrentFOV() + FovStep);
}

void ARecordingFlyPawn::HandleFOVDown(const FInputActionValue& Value)
{
	ApplyFOV(GetCurrentFOV() - FovStep);
}

void ARecordingFlyPawn::HandleFOVReset(const FInputActionValue& Value)
{
	ApplyFOV(DefaultFOV);
}

float ARecordingFlyPawn::GetCurrentFOV() const
{
	if (const UCameraComponent* Cam = GetRecordingCamera())
	{
		return Cam->FieldOfView;
	}
	if (const APlayerController* PC = Cast<APlayerController>(GetController()))
	{
		if (PC->PlayerCameraManager)
		{
			return PC->PlayerCameraManager->GetFOVAngle();
		}
	}
	return DefaultFOV;
}

void ARecordingFlyPawn::ApplyFOV(float NewFOV)
{
	const float Clamped = FMath::Clamp(NewFOV, MinFOV, MaxFOV);

	if (UCameraComponent* Cam = GetRecordingCamera())
	{
		Cam->SetFieldOfView(Clamped);
		Cam->FieldOfView = Clamped;
	}

	if (APlayerController* PC = Cast<APlayerController>(GetController()))
	{
		if (APlayerCameraManager* CamMgr = PC->PlayerCameraManager)
		{
			// SpectatorPawn has no camera component by default; without DefaultFOV
			// the manager resets ViewFOV every frame back to 90.
			CamMgr->DefaultFOV = Clamped;
			CamMgr->SetFOV(Clamped);
		}
	}
}

UCameraComponent* ARecordingFlyPawn::GetRecordingCamera() const
{
	return FindComponentByClass<UCameraComponent>();
}

void ARecordingFlyPawn::EnsureSequencePlayer()
{
	ULevelSequence* Sequence = SequenceAsset.LoadSynchronous();
	if (!Sequence || SequencePlayer)
	{
		return;
	}

	FMovieSceneSequencePlaybackSettings Settings;
	Settings.bAutoPlay = false;
	Settings.bPauseAtEnd = true;

	ALevelSequenceActor* OutActor = nullptr;
	SequencePlayer = ULevelSequencePlayer::CreateLevelSequencePlayer(
		GetWorld(), Sequence, Settings, OutActor);
	SequenceActor = OutActor;
}

void ARecordingFlyPawn::HandleSequencePlayStop(const FInputActionValue& Value)
{
	if (!Value.Get<bool>())
	{
		return;
	}

	EnsureSequencePlayer();
	if (!SequencePlayer)
	{
		return;
	}

	if (SequencePlayer->IsPlaying())
	{
		SequencePlayer->Pause();
	}
	else
	{
		SequencePlayer->Play();
	}
}

void ARecordingFlyPawn::HandleSequenceGoToStart(const FInputActionValue& Value)
{
	if (!Value.Get<bool>())
	{
		return;
	}

	EnsureSequencePlayer();
	if (!SequencePlayer)
	{
		return;
	}

	SequencePlayer->Pause();
	SequencePlayer->SetPlaybackPosition(
		FMovieSceneSequencePlaybackParams(SequencePlayer->GetStartTime().Time, EUpdatePositionMethod::Jump));
}

void ARecordingFlyPawn::HandleSequenceGoToEnd(const FInputActionValue& Value)
{
	if (!Value.Get<bool>())
	{
		return;
	}

	EnsureSequencePlayer();
	if (!SequencePlayer)
	{
		return;
	}

	SequencePlayer->Pause();
	SequencePlayer->SetPlaybackPosition(
		FMovieSceneSequencePlaybackParams(SequencePlayer->GetEndTime().Time, EUpdatePositionMethod::Jump));
}
