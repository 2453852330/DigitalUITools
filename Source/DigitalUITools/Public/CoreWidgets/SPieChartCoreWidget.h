// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Types/DigitalTypes.h"

#include "Widgets/SLeafWidget.h"

/**
 * 
 */
class DIGITALUITOOLS_API SPieChartCoreWidget : public SLeafWidget
{
public:
	SLATE_BEGIN_ARGS(SPieChartCoreWidget)
		{
		}
	SLATE_ARGUMENT(TArray<FPieChartData>, PieChartData)
	SLATE_ARGUMENT(float, PieRadius)
	SLATE_ARGUMENT(float, DeltaRadians)
	SLATE_ARGUMENT(float, LineWidth)
	SLATE_ARGUMENT(float, FontSpan)
	SLATE_ARGUMENT(FSlateFontInfo,Font)
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);
	virtual int32 OnPaint(const FPaintArgs& Args, const FGeometry& AllottedGeometry, const FSlateRect& MyCullingRect,
							  FSlateWindowElementList& OutDrawElements, int32 LayerId, const FWidgetStyle& InWidgetStyle,
							  bool bParentEnabled) const override;


	
	void CF_SyncArgs(const FArguments InArgs);
	
private:
	virtual FVector2D ComputeDesiredSize(float) const override;
	
	TArray<FPieChartData> mPieChartData;
	float mPieRadius = 30.f;
	float mDeltaRadians = 1.f;
	float mLineWidth = 10.f;
	float mFontSpan = 5.f;
	FSlateFontInfo mFont;
};
