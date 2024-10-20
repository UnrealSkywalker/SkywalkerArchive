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
	* �����浵����
	*/
	UFUNCTION(BlueprintCallable, Category = "Skywalker|SaveGame")
	bool CreateSaveGameObject(TSubclassOf<USkywalkerLocalPlayerSaveGame> SaveGameClass);

	/**
	* ���ô浵
	*/
	UFUNCTION(BlueprintCallable, Category = "Skywalker|SaveGame")
	void SetSaveGame(const FString& SlotName, const int32 UserIndex);

	/**
	* �жϴ浵�Ƿ����
	*/
	UFUNCTION(BlueprintCallable, Category = "Skywalker|SaveGame")
	bool IsSaveGameExist();

	/**
	* ����浵
	*/
	UFUNCTION(BlueprintCallable, Category = "Skywalker|SaveGame")
	bool SaveGame();

	/**
	* ���ش浵
	*/
	UFUNCTION(BlueprintCallable, Category = "Skywalker|SaveGame")
	bool LoadGame();

	/**
	* ɾ���浵
	*/
	UFUNCTION(BlueprintCallable, Category = "Skywalker|SaveGame")
	bool DeleteGame();

private:
	/**
	* SkywalkerLocalPlayerSaveGame ʵ��
	*/
	UPROPERTY()
	USkywalkerLocalPlayerSaveGame* LocalPlayerSaveGame = nullptr;

	/**
	* �浵����
	*/
	FString SaveGameSlotName = TEXT("SkywalkerLocalPlayerSaveGame");

	/**
	* UserIndex
	*/
	int32 SaveGameUserIndex = 0;
};
