// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Blueprint/UserWidget.h"
#include "MenuSystem/MenuInterface.h"
#include "AzureGamingGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class AZUREGAMING_API UAzureGamingGameInstance : public UGameInstance, public IMenuInterface
{
	GENERATED_BODY()
	
public:
	UAzureGamingGameInstance(const FObjectInitializer& ObjectInitializer);

	virtual void Init();

	UFUNCTION(BlueprintCallable)
	void LoadMenu();

	UFUNCTION(Exec)
	void Host();

	UFUNCTION(Exec)
	void Join(const FString& Address);

private:
	TSubclassOf<class UUserWidget> MenuClass;
};
