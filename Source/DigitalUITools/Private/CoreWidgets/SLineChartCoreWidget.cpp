// Fill out your copyright notice in the Description page of Project Settings.


#include "CoreWidgets/SLineChartCoreWidget.h"
#include "Helpers/LogHelper.h"
#include "SlateOptMacros.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SLineChartCoreWidget::Construct(const FArguments& InArgs)
{
	// no children
	mDrawSize = InArgs._DrawSize;
	mLineWidth = InArgs._LineWidth;
	mPoints = InArgs._Points;
	mXAxisName = InArgs._XAxisName;
	mYAxisName = InArgs._YAxisName;
	mAxisFont = InArgs._AxisFont;
	mAxisFontColor = InArgs._AxisFontColor;
	mDataFont = InArgs._DataFont;
	mDataFontColor = InArgs._DataFontColor;
	mLineColor = InArgs._LineColor;
}

int32 SLineChartCoreWidget::OnPaint(const FPaintArgs& Args, const FGeometry& AllottedGeometry,
	const FSlateRect& MyCullingRect, FSlateWindowElementList& OutDrawElements, int32 LayerId,
	const FWidgetStyle& InWidgetStyle, bool bParentEnabled) const
{
	// draw axis
	FVector2f localSize =  AllottedGeometry.ToPaintGeometry().GetLocalSize();
	// LogWarning("AllottedGeometry.ToPaintGeometry().GetLocalSize() = (%f,%f)",localSize.X,localSize.Y);
	
	TArray<FVector2f> DrawPoints;
	// x [0-1] y is constant
	FVector2f XLeft  =  FVector2f(localSize.X * 0.05f,localSize.Y * 0.1f );
	FVector2f XRight =  FVector2f(localSize.X * 0.95f,localSize.Y * 0.1f);
	DrawPoints.Append({CF_ConvertPoint(XLeft),CF_ConvertPoint(XRight)});
	FSlateDrawElement::MakeLines(OutDrawElements,LayerId,AllottedGeometry.ToPaintGeometry(),DrawPoints,ESlateDrawEffect::None,FLinearColor::White,true,mLineWidth);
	//	y [0-1] x is constant
	DrawPoints.Reset();
	FVector2f YTop =  FVector2f(localSize.X * 0.1f,localSize.Y * 0.95f );
	FVector2f YDown = FVector2f(localSize.X * 0.1f,localSize.Y * 0.05f);
	DrawPoints.Append({ CF_ConvertPoint(YTop),CF_ConvertPoint(YDown) });
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
		DrawPoints.Emplace(CF_ConvertPoint(FVector2f(xPos,yPos)));
		// x
		FSlateDrawElement::MakeText(OutDrawElements,LayerId,AllottedGeometry.ToOffsetPaintGeometry(CF_ConvertPoint({xPos,localSize.Y * 0.1f})),
			FText::AsNumber(it.X),mDataFont,ESlateDrawEffect::None,mDataFontColor);
		// y
		FSlateDrawElement::MakeText(OutDrawElements,LayerId,AllottedGeometry.ToOffsetPaintGeometry(CF_ConvertPoint({localSize.X * 0.05f,yPos })),
			FText::AsNumber(it.Y),mDataFont,ESlateDrawEffect::None,mDataFontColor);
	
	}
	FSlateDrawElement::MakeLines(OutDrawElements,LayerId,AllottedGeometry.ToPaintGeometry(),DrawPoints,ESlateDrawEffect::None,mLineColor,true,mLineWidth);
	
	// draw axis font
	// x
	FSlateDrawElement::MakeText(OutDrawElements,LayerId,AllottedGeometry.ToOffsetPaintGeometry(CF_ConvertPoint({localSize.X * 0.9f,localSize.Y * 0.24f})),
		FText::FromString(mXAxisName),mAxisFont,ESlateDrawEffect::None,mAxisFontColor);
	// y
	FSlateDrawElement::MakeText(OutDrawElements,LayerId,AllottedGeometry.ToOffsetPaintGeometry(CF_ConvertPoint({localSize.X * 0.11f,localSize.Y * 0.95f })),
		FText::FromString(mYAxisName),mAxisFont,ESlateDrawEffect::None,mAxisFontColor);
	
	return LayerId;
}

void SLineChartCoreWidget::CF_SyncArgs(const FArguments  InArgs)
{
	mDrawSize = InArgs._DrawSize;
	mLineWidth = InArgs._LineWidth;
	mPoints = InArgs._Points;
	mXAxisName = InArgs._XAxisName;
	mYAxisName = InArgs._YAxisName;
	mAxisFont = InArgs._AxisFont;
	mAxisFontColor = InArgs._AxisFontColor;
	mDataFont = InArgs._DataFont;
	mDataFontColor = InArgs._DataFontColor;
	mLineColor = InArgs._LineColor;
}

void SLineChartCoreWidget::CF_UpdatePoints(TArray<FVector2D> InPoints)
{
	mPoints = InPoints;
}

FVector2D SLineChartCoreWidget::ComputeDesiredSize(float) const
{
	return mDrawSize;
}

void SLineChartCoreWidget::CF_CalcPointsSize(float& MaxX, float& MaxY) const
{
	for (const FVector2D & it : mPoints)
	{
		MaxX = FMath::Max(MaxX, it.X);
		MaxY = FMath::Max(MaxY, it.Y);
	}
}

FVector2f SLineChartCoreWidget::CF_ConvertPoint(const FVector2f& Point) const
{
	return FVector2f(Point.X, GetCachedGeometry().ToPaintGeometry().GetLocalSize().Y - Point.Y);
}

END_SLATE_FUNCTION_BUILD_OPTIMIZATION
