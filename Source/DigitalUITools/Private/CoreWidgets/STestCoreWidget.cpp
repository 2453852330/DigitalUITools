// Fill out your copyright notice in the Description page of Project Settings.


#include "CoreWidgets/STestCoreWidget.h"
#include "Helpers/LogHelper.h"
#include "SlateOptMacros.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void STestCoreWidget::Construct(const FArguments& InArgs)
{
	// no children
	mDrawSize = InArgs._DrawSize;
	mLineWidth = InArgs._LineWidth;
	mPoints = InArgs._Points;
}

int32 STestCoreWidget::OnPaint(const FPaintArgs& Args, const FGeometry& AllottedGeometry,
	const FSlateRect& MyCullingRect, FSlateWindowElementList& OutDrawElements, int32 LayerId,
	const FWidgetStyle& InWidgetStyle, bool bParentEnabled) const
{
	// draw axis
	FVector2f localSize =  AllottedGeometry.ToPaintGeometry().GetLocalSize();
	TArray<FVector2f> DrawPoints;
	// x [0-1] y is constant
	FVector2f XLeft  =  FVector2f(localSize.X * 0.05f,localSize.Y * 0.1f );
	FVector2f XRight =  FVector2f(localSize.X * 0.95f,localSize.Y * 0.1f);
	DrawPoints.Append({XLeft,XRight});
	FSlateDrawElement::MakeLines(OutDrawElements,LayerId,AllottedGeometry.ToPaintGeometry(),DrawPoints,ESlateDrawEffect::None,FLinearColor::White,true,mLineWidth);
	//	y [0-1] x is constant
	DrawPoints.Reset();
	FVector2f YTop =  FVector2f(localSize.X * 0.1f,localSize.Y * 0.95f );
	FVector2f YDown = FVector2f(localSize.X * 0.1f,localSize.Y * 0.05f);
	DrawPoints.Append({ YTop,YDown });
	FSlateDrawElement::MakeLines(OutDrawElements,LayerId,AllottedGeometry.ToPaintGeometry(),DrawPoints,ESlateDrawEffect::None,FLinearColor::White,true,mLineWidth);
	// draw points
	DrawPoints.Reset();
	float MaxX,MaxY;
	CF_CalcPointsSize(MaxX,MaxY);
	for (const FVector2D& it : mPoints)
	{
		// FVector2f drawPos = (FVector2f)it + localSize * 0.1f;
		
		// scale to local size
		// [0.1 - 0.9]
		float xRatio = it.X / MaxX;
		float yRatio = it.Y / MaxY;
		float xPos = localSize.X * 0.1f + localSize.X * 0.8f * xRatio;
		float yPos = localSize.Y * 0.1f + localSize.Y * 0.8f * yRatio;
		DrawPoints.Emplace(FVector2f(xPos,yPos));
	}
	FSlateDrawElement::MakeLines(OutDrawElements,LayerId,AllottedGeometry.ToPaintGeometry(),DrawPoints,ESlateDrawEffect::None,FLinearColor::Red,true,mLineWidth);
	
	return LayerId;
}

void STestCoreWidget::CF_SyncPoints(const TArray<FVector2D>& InPoints)
{
	mPoints = InPoints;
}

FVector2D STestCoreWidget::ComputeDesiredSize(float) const
{
	return mDrawSize;
}

void STestCoreWidget::CF_CalcPointsSize(float& MaxX, float& MaxY) const
{
	for (const FVector2D & it : mPoints)
	{
		MaxX = FMath::Max(MaxX, it.X);
		MaxY = FMath::Max(MaxY, it.Y);
	}
}

FVector2D STestCoreWidget::CF_ConvertPoint(const FVector2D& Point) const
{
	return FVector2D(Point.X, GetCachedGeometry().ToPaintGeometry().GetLocalSize().Y - Point.Y);
}

END_SLATE_FUNCTION_BUILD_OPTIMIZATION
