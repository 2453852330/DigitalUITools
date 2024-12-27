// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SLeafWidget.h"

/**
 * 
 */
class DIGITALUITOOLS_API SLineChartCoreWidget : public SLeafWidget
{
public:
	SLATE_BEGIN_ARGS(SLineChartCoreWidget)
	{}
	SLATE_ARGUMENT(FVector2D,DrawSize)
	SLATE_ARGUMENT(float,LineWidth)
	SLATE_ARGUMENT(FLinearColor,LineColor)
	SLATE_ARGUMENT(TArray<FVector2D>,Points)
	SLATE_ARGUMENT(FString,XAxisName)
	SLATE_ARGUMENT(FString,YAxisName)
	SLATE_ARGUMENT(FSlateFontInfo,AxisFont)
	SLATE_ARGUMENT(FLinearColor,AxisFontColor)
	SLATE_ARGUMENT(FSlateFontInfo,DataFont)
	SLATE_ARGUMENT(FLinearColor,DataFontColor)
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);
	
	virtual int32 OnPaint(const FPaintArgs& Args, const FGeometry& AllottedGeometry, const FSlateRect& MyCullingRect,
	                      FSlateWindowElementList& OutDrawElements, int32 LayerId, const FWidgetStyle& InWidgetStyle,
	                      bool bParentEnabled) const override;

	void CF_SyncArgs(const FArguments InArgs);

	void CF_UpdatePoints(TArray<FVector2D> InPoints);
private:
	FVector2D mDrawSize;
	float mLineWidth = 0.f;
	TArray<FVector2D> mPoints;
	FSlateFontInfo mAxisFont;
	FLinearColor mAxisFontColor;
	FSlateFontInfo mDataFont;
	FLinearColor mDataFontColor;
	FString mXAxisName;
	FString mYAxisName;
	FLinearColor mLineColor;
	virtual FVector2D ComputeDesiredSize(float) const override;

	void CF_CalcPointsSize(float & MaxX,float & MaxY) const;
	FVector2f CF_ConvertPoint(const FVector2f & Point) const;
};




