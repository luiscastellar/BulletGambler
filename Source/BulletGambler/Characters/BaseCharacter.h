//LUIS CASTELLAR DOMINGUEZ / COPYRIGHT

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "BaseCharacter.generated.h"

class SpringArmComponent;
class CameraComponent;
class UInputMappingContext;
class UInputAction;

UCLASS()
class BULLETGAMBLER_API ABaseCharacter : public ACharacter
{
	GENERATED_BODY()

	public:

		ABaseCharacter();

		virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

		virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	protected:

		virtual void BeginPlay() override;

		UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
		UInputMappingContext* DefaultMappingContext;

		UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
		UInputAction* MoveAction;
		UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
		UInputAction* LookAction;
		UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
		UInputAction* JumpAction;

		void Move(const FInputActionValue& Value);
		void Look(const FInputActionValue& Value);

	private:

		UPROPERTY(VisibleAnywhere, Category = "Camera")
		class USpringArmComponent* CameraBoom;

		UPROPERTY(VisibleAnywhere, Category = "Camera")
		class UCameraComponent* FollowCamera;

		UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		class UWidgetComponent* OverheadWidget;

		UPROPERTY(ReplicatedUsing = OnRep_OverlappingWeapon)
		class ABaseWeapon* OverlappingWeapon;

		UFUNCTION()
		void OnRep_OverlappingWeapon(ABaseWeapon* LastWeapon);

		UPROPERTY(EditAnywhere)
		class UCombatComponent* CombatComponent;

	public:

		void SetOverlappingWeapon(ABaseWeapon* Weapon);
};
