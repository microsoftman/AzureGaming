// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "MenuInterface.h"
#include "MainMenu.generated.h"

/**
 * 
 */
UCLASS()
class AZUREGAMING_API UMainMenu : public UUserWidget
{
	GENERATED_BODY()

public:
	void SetMenuInterface(IMenuInterface* MenuInterface);

protected:
	virtual bool Initialize();
	

private:
	UPROPERTY(meta = (BindWidget))
	class UButton* MainMenuHostBtn;

	UPROPERTY(meta = (BindWidget))
	class UButton* MainMenuJoinBtn;

	UFUNCTION()
	void HostServer();

	IMenuInterface* MenuInterface;
};
