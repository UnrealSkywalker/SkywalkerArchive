// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "GameFramework/SaveGame.h"

#include "SaveGame/SkywalkerLocalPlayerSaveGame.h"

#include "SkywalkerArchiveGISubsystem.generated.h"

/**
 *
 */
UCLASS()
class SKYWALKERARCHIVE_API USkywalkerArchiveGISubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:

	USkywalkerArchiveGISubsystem();

	/**
	* ÅÐ¶Ï´æµµÊÇ·ñ´æÔÚ
	*/
	UFUNCTION(BlueprintCallable, Category = "Skywalker|SaveGame")
	bool IsSaveGameExist(const FString& SlotName, const int32 UserIndex);

	/**
	* ±£´æ´æµµ
	*/
	UFUNCTION(BlueprintCallable, Category = "Skywalker|SaveGame")
	bool SaveGame(const FString& SlotName, const int32 UserIndex);

	/**
	* ¼ÓÔØ´æµµ
	*/
	UFUNCTION(BlueprintCallable, Category = "Skywalker|SaveGame")
	bool LoadGame(const FString& SlotName, const int32 UserIndex);

private:
	/**
	* SkywalkerLocalPlayerSaveGame ÊµÀý
	*/
	UPROPERTY()
	USkywalkerLocalPlayerSaveGame* LocalPlayerSaveGame = nullptr;
};
