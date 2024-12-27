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
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Test Widget | Line",DisplayName="LineWidth")
	float mLineWidth = 1.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Test Widget | Line",DisplayName="LineWidth")
	FLinearColor mLineColor = FLinearColor::Red;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Test Widget | Data",DisplayName="DrawPoints")
	TArray<FVector2D> mPoints;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Test Widget | Data",DisplayName="DataFont")
	FSlateFontInfo mDataFont;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Test Widget | Data",DisplayName="DataFontColor")
	FLinearColor mDataFontColor = FLinearColor::White;

	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Test Widget | Axis",DisplayName="X-Name")
	FString mXAxisName = "X";
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Test Widget | Axis",DisplayName="Y-Name")
	FString mYAxisName = "Y";

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Test Widget | Axis",DisplayName="AxisFont")
	FSlateFontInfo mAxisFont;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Test Widget | Axis",DisplayName="AxisFontColor")
	FLinearColor mAxisFontColor = FLinearColor::White;

	UFUNCTION(BlueprintCallable,Category="Test Widget")
	void BP_UpdatePoints(TArray<FVector2D> InPoints);
protected:
	virtual TSharedRef<SWidget> RebuildWidget() override;

private:
	TSharedPtr<STestCoreWidget> TestCoreWidget = nullptr;
};
