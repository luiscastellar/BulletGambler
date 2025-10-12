/*LUIS CASTELLAR DOMINGUEZ / COPYRIGHT*/

#include "CharacterAnimInstance.h"
#include "BaseCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

void UCharacterAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	BaseCharacter = Cast<ABaseCharacter>(TryGetPawnOwner());
}

void UCharacterAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	if (!BaseCharacter)
	{
		BaseCharacter = Cast<ABaseCharacter>(TryGetPawnOwner());
	}
	if (!BaseCharacter) return;

	FVector Velocity = BaseCharacter->GetVelocity();
	Velocity.Z = 0;
	Speed = Velocity.Size();

	HorizontalSpeed = FVector::DotProduct(BaseCharacter->GetActorForwardVector(), Velocity);
	VerticalSpeed = FVector::DotProduct(BaseCharacter->GetActorRightVector(), Velocity);

	bIsInAir = BaseCharacter->GetMovementComponent()->IsFalling();

	bIsAccelerating = BaseCharacter->GetCharacterMovement()->GetCurrentAcceleration().Size() > 0.f ? true : false;
}
