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
	 * 创建存档对象
	 */
	UFUNCTION(BlueprintCallable, Category = "Skywalker|SaveGame")
	bool CreateSaveGameObject(TSubclassOf<USkywalkerLocalPlayerSaveGame> SaveGameClass);

	/**
	 * 设置存档
	 */
	UFUNCTION(BlueprintCallable, Category = "Skywalker|SaveGame")
	void SetSaveGame(const FString &SlotName, const int32 UserIndex);

	/**
	 * 判断存档是否存在
	 */
	UFUNCTION(BlueprintCallable, Category = "Skywalker|SaveGame")
	bool IsSaveGameExist();

	/**
	 * 保存存档
	 */
	UFUNCTION(BlueprintCallable, Category = "Skywalker|SaveGame")
	bool SaveGame();

	/**
	 * 加载存档
	 */
	UFUNCTION(BlueprintCallable, Category = "Skywalker|SaveGame")
	bool LoadGame();

	/**
	 * 删除存档
	 */
	UFUNCTION(BlueprintCallable, Category = "Skywalker|SaveGame")
	bool DeleteGame();

	/**
	 * 获取存档
	*/
	UFUNCTION(BlueprintCallable, Category = "Skywalker|SaveGame")
	USkywalkerLocalPlayerSaveGame *GetSaveGame();

private:
	/**
	 * SkywalkerLocalPlayerSaveGame 实例
	 */
	UPROPERTY()
	USkywalkerLocalPlayerSaveGame *LocalPlayerSaveGame = nullptr;

	/**
	 * 存档名称
	 */
	FString SaveGameSlotName = TEXT("SkywalkerLocalPlayerSaveGame");

	/**
	 * UserIndex
	 */
	int32 SaveGameUserIndex = 0;
};
