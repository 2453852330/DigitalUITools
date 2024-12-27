// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/Widget.h"
#include "TestWidget.generated.h"

class STestCoreWidget;
/**
 * 
 */
UCLASS()
class DIGITALUITOOLS_API UTestWidget : public UWidget
{
	GENERATED_BODY()
public:
	virtual void SynchronizeProperties() override;
	virtual void ReleaseSlateResources(bool bReleaseChildren) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Test Widget",DisplayName="DrawSize")
	FVector2D mDrawSize = FVector2D(100.f, 100.f);
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Test Widget",DisplayName="LineWidth")
	float mLineWidth = 1.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Test Widget",DisplayName="DrawSize")
	TArray<FVector2D> mPoints;

protected:
	virtual TSharedRef<SWidget> RebuildWidget() override;

private:
	TSharedPtr<STestCoreWidget> TestCoreWidget = nullptr;
};
