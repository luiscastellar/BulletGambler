/*LUIS CASTELLAR DOMINGUEZ / COPYRIGHT*/

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "BulletGamblerGameMode.generated.h"

UCLASS()
class BULLETGAMBLER_API ABulletGamblerGameMode : public AGameMode
{
	GENERATED_BODY()
	
public:

	virtual void PostLogin(APlayerController* NewPlayer) override;
};
