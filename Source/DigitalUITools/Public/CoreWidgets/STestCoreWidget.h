// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SLeafWidget.h"

/**
 * 
 */
class DIGITALUITOOLS_API STestCoreWidget : public SLeafWidget
{
public:
	SLATE_BEGIN_ARGS(STestCoreWidget)
	{}
	SLATE_ARGUMENT(FVector2D,DrawSize)
	SLATE_ARGUMENT(float,LineWidth)
	SLATE_ARGUMENT(TArray<FVector2D>,Points)
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);
	
	virtual int32 OnPaint(const FPaintArgs& Args, const FGeometry& AllottedGeometry, const FSlateRect& MyCullingRect,
	                      FSlateWindowElementList& OutDrawElements, int32 LayerId, const FWidgetStyle& InWidgetStyle,
	                      bool bParentEnabled) const override;

	void CF_SyncPoints(const TArray<FVector2D> & InPoints);
private:
	FVector2D mDrawSize;
	float mLineWidth = 0.f;
	TArray<FVector2D> mPoints;
	virtual FVector2D ComputeDesiredSize(float) const override;

	void CF_CalcPointsSize(float & MaxX,float & MaxY) const;
	FVector2D CF_ConvertPoint(const FVector2D & Point) const;
};


