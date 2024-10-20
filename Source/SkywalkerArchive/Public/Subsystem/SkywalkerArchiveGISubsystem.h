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
	* ÉèÖÃ´æµµ
	*/
	UFUNCTION(BlueprintCallable, Category = "Skywalker|SaveGame")
	void SetSaveGame(const FString& SlotName, const int32 UserIndex);

	/**
	* ÅÐ¶Ï´æµµÊÇ·ñ´æÔÚ
	*/
	UFUNCTION(BlueprintCallable, Category = "Skywalker|SaveGame")
	bool IsSaveGameExist();

	/**
	* ±£´æ´æµµ
	*/
	UFUNCTION(BlueprintCallable, Category = "Skywalker|SaveGame")
	bool SaveGame();

	/**
	* ¼ÓÔØ´æµµ
	*/
	UFUNCTION(BlueprintCallable, Category = "Skywalker|SaveGame")
	bool LoadGame();

	/**
	* É¾³ý´æµµ
	*/
	UFUNCTION(BlueprintCallable, Category = "Skywalker|SaveGame")
	bool DeleteGame();

private:
	/**
	* SkywalkerLocalPlayerSaveGame ÊµÀý
	*/
	UPROPERTY()
	USkywalkerLocalPlayerSaveGame* LocalPlayerSaveGame = nullptr;

	/**
	* ´æµµÃû³Æ
	*/
	FString SaveGameSlotName = TEXT("SkywalkerLocalPlayerSaveGame");

	/**
	* UserIndex
	*/
	int32 SaveGameUserIndex = 0;
};
