// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/Widget.h"
#include "LineChartWidget.generated.h"

class SLineChartCoreWidget;
/**
 * 
 */
UCLASS()
class DIGITALUITOOLS_API ULineChartWidget : public UWidget
{
	GENERATED_BODY()
public:

#if WITH_EDITOR
	
	virtual const FText GetPaletteCategory() override;
#endif
	
	virtual void SynchronizeProperties() override;
	virtual void ReleaseSlateResources(bool bReleaseChildren) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LineChart",DisplayName="DrawSize")
	FVector2D mDrawSize = FVector2D(100.f, 100.f);
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LineChart | Line",DisplayName="LineWidth")
	float mLineWidth = 1.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LineChart | Line",DisplayName="LineWidth")
	FLinearColor mLineColor = FLinearColor::Red;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LineChart | Data",DisplayName="DrawPoints")
	TArray<FVector2D> mPoints;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LineChart | Data",DisplayName="DataFont")
	FSlateFontInfo mDataFont;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LineChart | Data",DisplayName="DataFontColor")
	FLinearColor mDataFontColor = FLinearColor::White;

	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LineChart | Axis",DisplayName="X-Name")
	FString mXAxisName = "X";
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LineChart | Axis",DisplayName="Y-Name")
	FString mYAxisName = "Y";

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LineChart | Axis",DisplayName="AxisFont")
	FSlateFontInfo mAxisFont;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LineChart | Axis",DisplayName="AxisFontColor")
	FLinearColor mAxisFontColor = FLinearColor::White;

	UFUNCTION(BlueprintCallable,Category="LineChart")
	void BP_UpdatePoints(TArray<FVector2D> InPoints);
protected:
	virtual TSharedRef<SWidget> RebuildWidget() override;

private:
	TSharedPtr<SLineChartCoreWidget> TestCoreWidget = nullptr;
};
