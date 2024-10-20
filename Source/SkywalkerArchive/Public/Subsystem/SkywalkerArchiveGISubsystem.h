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
	* ¥¥Ω®¥Êµµ∂‘œÛ
	*/
	UFUNCTION(BlueprintCallable, Category = "Skywalker|SaveGame")
	bool CreateSaveGameObject(TSubclassOf<USkywalkerLocalPlayerSaveGame> SaveGameClass);

	/**
	* …Ë÷√¥Êµµ
	*/
	UFUNCTION(BlueprintCallable, Category = "Skywalker|SaveGame")
	void SetSaveGame(const FString& SlotName, const int32 UserIndex);

	/**
	* ≈–∂œ¥Êµµ «∑Ò¥Ê‘⁄
	*/
	UFUNCTION(BlueprintCallable, Category = "Skywalker|SaveGame")
	bool IsSaveGameExist();

	/**
	* ±£¥Ê¥Êµµ
	*/
	UFUNCTION(BlueprintCallable, Category = "Skywalker|SaveGame")
	bool SaveGame();

	/**
	* º”‘ÿ¥Êµµ
	*/
	UFUNCTION(BlueprintCallable, Category = "Skywalker|SaveGame")
	bool LoadGame();

	/**
	* …æ≥˝¥Êµµ
	*/
	UFUNCTION(BlueprintCallable, Category = "Skywalker|SaveGame")
	bool DeleteGame();

private:
	/**
	* SkywalkerLocalPlayerSaveGame  µ¿˝
	*/
	UPROPERTY()
	USkywalkerLocalPlayerSaveGame* LocalPlayerSaveGame = nullptr;

	/**
	* ¥Êµµ√˚≥∆
	*/
	FString SaveGameSlotName = TEXT("SkywalkerLocalPlayerSaveGame");

	/**
	* UserIndex
	*/
	int32 SaveGameUserIndex = 0;
};
