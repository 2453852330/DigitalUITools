// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/Widget.h"

#include "Types/DigitalTypes.h"

#include "PieChartWidget.generated.h"

class SPieChartCoreWidget;
/**
 * 
 */
UCLASS()
class DIGITALUITOOLS_API UPieChartWidget : public UWidget
{
	GENERATED_BODY()
public:
	
#if WITH_EDITOR
	
	virtual const FText GetPaletteCategory() override;
#endif
	
	virtual void SynchronizeProperties() override;
	virtual void ReleaseSlateResources(bool bReleaseChildren) override;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pie Chart",DisplayName="Radius")
	float mRadius = 30.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pie Chart",DisplayName="DeltaRadians")
	float mDeltaRadians = 1.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pie Chart",DisplayName="LineWidth")
	float mLineWidth = 10.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pie Chart",DisplayName="Radius")
	float mFontSpan = 5.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pie Chart",DisplayName="PieChartData")
	TArray<FPieChartData> mPieChartData;	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pie Chart",DisplayName="Font")
	FSlateFontInfo mFont;
protected:
	virtual TSharedRef<SWidget> RebuildWidget() override;

private:
	TSharedPtr<SPieChartCoreWidget> TestCoreWidget = nullptr;
};
