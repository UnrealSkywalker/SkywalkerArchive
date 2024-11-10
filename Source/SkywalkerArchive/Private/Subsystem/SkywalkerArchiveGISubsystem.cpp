// Fill out your copyright notice in the Description page of Project Settings.

#include "Subsystem/SkywalkerArchiveGISubsystem.h"

#include "Kismet/GameplayStatics.h"

DEFINE_LOG_CATEGORY_STATIC(SkywalkerArchive, Log, All);

USkywalkerArchiveGISubsystem::USkywalkerArchiveGISubsystem() : UGameInstanceSubsystem()
{
	//// 创建 USkywalkerLocalPlayerSaveGame
	// LocalPlayerSaveGame = Cast<USkywalkerLocalPlayerSaveGame>(UGameplayStatics::CreateSaveGameObject(USkywalkerLocalPlayerSaveGame::StaticClass()));
	// if (LocalPlayerSaveGame == nullptr)
	//{
	//	UE_LOG(SkywalkerArchive, Error, TEXT("Create USkywalkerLocalPlayerSaveGame failed!"));
	// }
}

bool USkywalkerArchiveGISubsystem::CreateSaveGameObject(TSubclassOf<USkywalkerLocalPlayerSaveGame> SaveGameClass)
{
	if (SaveGameClass == nullptr)
	{
		UE_LOG(SkywalkerArchive, Error, TEXT("SaveGameClass is nullptr!"));
		return false;
	}

	if (LocalPlayerSaveGame != nullptr)
	{
		UE_LOG(SkywalkerArchive, Error, TEXT("USkywalkerLocalPlayerSaveGame is not nullptr!"));
		return false;
	}

	// 创建 USkywalkerLocalPlayerSaveGame
	LocalPlayerSaveGame = Cast<USkywalkerLocalPlayerSaveGame>(UGameplayStatics::CreateSaveGameObject(SaveGameClass));
	if (LocalPlayerSaveGame == nullptr)
	{
		UE_LOG(SkywalkerArchive, Error, TEXT("Create USkywalkerLocalPlayerSaveGame failed!"));
		return false;
	}

	return true;
}

void USkywalkerArchiveGISubsystem::SetSaveGame(const FString &SlotName, const int32 UserIndex)
{
	SaveGameSlotName = SlotName;
	SaveGameUserIndex = UserIndex;
}

bool USkywalkerArchiveGISubsystem::IsSaveGameExist()
{
	if (LocalPlayerSaveGame == nullptr)
	{
		UE_LOG(SkywalkerArchive, Error, TEXT("USkywalkerLocalPlayerSaveGame is nullptr!"));
		return false;
	}

	return UGameplayStatics::DoesSaveGameExist(SaveGameSlotName, SaveGameUserIndex);
}

bool USkywalkerArchiveGISubsystem::SaveGame()
{
	if (LocalPlayerSaveGame == nullptr)
	{
		UE_LOG(SkywalkerArchive, Error, TEXT("USkywalkerLocalPlayerSaveGame is nullptr!"));
		return false;
	}

	// 保存存档
	return UGameplayStatics::SaveGameToSlot(LocalPlayerSaveGame, SaveGameSlotName, SaveGameUserIndex);
}

bool USkywalkerArchiveGISubsystem::LoadGame()
{
	if (LocalPlayerSaveGame == nullptr)
	{
		UE_LOG(SkywalkerArchive, Error, TEXT("USkywalkerLocalPlayerSaveGame is nullptr!"));
		return false;
	}

	// 加载存档
	LocalPlayerSaveGame = Cast<USkywalkerLocalPlayerSaveGame>(UGameplayStatics::LoadGameFromSlot(SaveGameSlotName, SaveGameUserIndex));
	if (LocalPlayerSaveGame == nullptr)
	{
		UE_LOG(SkywalkerArchive, Error, TEXT("Load USkywalkerLocalPlayerSaveGame failed!"));
		return false;
	}

	return true;
}

bool USkywalkerArchiveGISubsystem::DeleteGame()
{
	if (LocalPlayerSaveGame == nullptr)
	{
		UE_LOG(SkywalkerArchive, Error, TEXT("USkywalkerLocalPlayerSaveGame is nullptr!"));
		return false;
	}

	// 删除存档
	return UGameplayStatics::DeleteGameInSlot(SaveGameSlotName, SaveGameUserIndex);
}

USkywalkerLocalPlayerSaveGame *USkywalkerArchiveGISubsystem::GetSaveGame()
{
	return LocalPlayerSaveGame;
}
