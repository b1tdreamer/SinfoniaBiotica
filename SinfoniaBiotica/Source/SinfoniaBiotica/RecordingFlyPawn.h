#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SpectatorPawn.h"
#include "InputActionValue.h"
#include "RecordingFlyPawn.generated.h"

class UInputMappingContext;
class UInputAction;
class ULevelSequence;
class ULevelSequencePlayer;
class ALevelSequenceActor;
class UCameraComponent;

/**
 * Flying spectator pawn for PIE recording with Enhanced Input (gamepad + mouse),
 * FOV control and Level Sequence transport.
 */
UCLASS()
class SINFONIABIOTICA_API ARecordingFlyPawn : public ASpectatorPawn
{
	GENERATED_BODY()

public:
	ARecordingFlyPawn();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	TObjectPtr<UInputMappingContext> DefaultMappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	TObjectPtr<UInputAction> MoveAction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	TObjectPtr<UInputAction> LookAction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	TObjectPtr<UInputAction> FovAction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	TObjectPtr<UInputAction> FovUpAction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	TObjectPtr<UInputAction> FovDownAction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	TObjectPtr<UInputAction> FovResetAction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	TObjectPtr<UInputAction> SequencePlayStopAction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	TObjectPtr<UInputAction> SequenceGoToStartAction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	TObjectPtr<UInputAction> SequenceGoToEndAction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input", meta = (ClampMin = "0.001", ClampMax = "5.0"))
	float LookYawScale = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input", meta = (ClampMin = "0.001", ClampMax = "5.0"))
	float LookPitchScale = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input", meta = (ClampMin = "0.1", ClampMax = "5.0"))
	float MoveScale = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	int32 MappingPriority = 1;

	/** Default horizontal FOV in degrees. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera", meta = (ClampMin = "1.0", ClampMax = "170.0"))
	float DefaultFOV = 11.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera", meta = (ClampMin = "0.05", ClampMax = "30.0"))
	float FovStep = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera", meta = (ClampMin = "1.0", ClampMax = "170.0"))
	float MinFOV = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera", meta = (ClampMin = "1.0", ClampMax = "170.0"))
	float MaxFOV = 120.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sequence")
	TSoftObjectPtr<ULevelSequence> SequenceAsset;

protected:
	virtual void BeginPlay() override;
	virtual void PossessedBy(AController* NewController) override;
	virtual void PawnClientRestart() override;
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

	void HandleMove(const FInputActionValue& Value);
	void HandleLook(const FInputActionValue& Value);
	void HandleFOVAxis(const FInputActionValue& Value);
	void HandleFOVUp(const FInputActionValue& Value);
	void HandleFOVDown(const FInputActionValue& Value);
	void HandleFOVReset(const FInputActionValue& Value);
	void HandleSequencePlayStop(const FInputActionValue& Value);
	void HandleSequenceGoToStart(const FInputActionValue& Value);
	void HandleSequenceGoToEnd(const FInputActionValue& Value);

	void AddMappingContext();
	void SetupFreeCursor();
	void ApplyFOV(float NewFOV);
	float GetCurrentFOV() const;
	UCameraComponent* GetRecordingCamera() const;
	void EnsureSequencePlayer();

	UPROPERTY(Transient)
	TObjectPtr<ULevelSequencePlayer> SequencePlayer;

	UPROPERTY(Transient)
	TObjectPtr<ALevelSequenceActor> SequenceActor;
};
