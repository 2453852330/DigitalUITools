// Fill out your copyright notice in the Description page of Project Settings.


#include "CoreWidgets/SPieChartCoreWidget.h"

#include "SlateOptMacros.h"

#include "Fonts/FontMeasure.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION

void SPieChartCoreWidget::Construct(const FArguments& InArgs)
{
	mPieChartData = InArgs._PieChartData;
	mPieRadius = InArgs._PieRadius;
	mDeltaRadians = InArgs._DeltaRadians;
	mLineWidth = InArgs._LineWidth;
	mFont = InArgs._Font;
	mFontSpan = InArgs._FontSpan;
	
}

void SPieChartCoreWidget::CF_SyncArgs(const FArguments InArgs)
{
	mPieChartData = InArgs._PieChartData;
	mPieRadius = InArgs._PieRadius;
	mDeltaRadians = InArgs._DeltaRadians;
	mLineWidth = InArgs._LineWidth;
	mFont = InArgs._Font;
	mFontSpan = InArgs._FontSpan;
}

int32 SPieChartCoreWidget::OnPaint(const FPaintArgs& Args, const FGeometry& AllottedGeometry,
	const FSlateRect& MyCullingRect, FSlateWindowElementList& OutDrawElements, int32 LayerId,
	const FWidgetStyle& InWidgetStyle, bool bParentEnabled) const
{
	if (mPieChartData.IsEmpty())
	{
		return LayerId;
	}
	
	TArray<FVector2f> DrawPoints;
	float startRadians = 0.0f;
	
	
	// calc total
	float totalRatio = 0.f;
	for (const FPieChartData & it : mPieChartData)
	{
		totalRatio += it.Ratio;
	}
	FVector2f centerPos = AllottedGeometry.ToPaintGeometry().GetLocalSize() / 2.f;
	float xPos = centerPos.X + centerPos.X * 0.3f;
	float yStartPos = centerPos.Y * 0.2f;
	// 
	FVector2f result =FSlateApplication::Get().GetRenderer()->GetFontMeasureService()->Measure(TEXT("H"),mFont,1);
	// draw pie
	for (const FPieChartData & it : mPieChartData)
	{
		if (it.Ratio <= 0.f)
		{
			continue;
		}
		float needRadians = ( it.Ratio / totalRatio ) * 2 * PI;
		float tmpRadians = 0.f;
		// mDeltaRadians
		while (tmpRadians + mDeltaRadians <= needRadians)
		{
			tmpRadians += mDeltaRadians;
			
			DrawPoints.Reset();
			DrawPoints.Add(centerPos - FVector2f(centerPos.X / 3.f,0.f));
			FVector2f pointEnd(mPieRadius * FMath::Cos(tmpRadians+startRadians), mPieRadius * FMath::Sin(tmpRadians+startRadians));
			DrawPoints.Add(centerPos + pointEnd - FVector2f(centerPos.X / 3.f,0.f));
			FSlateDrawElement::MakeLines(OutDrawElements, LayerId, AllottedGeometry.ToPaintGeometry(), DrawPoints, ESlateDrawEffect::None, it.Color,true,mLineWidth);
		}
		startRadians += needRadians;
		
		// draw name - 使用outline加粗
		FSlateFontInfo tmp = mFont;
		tmp.OutlineSettings.OutlineColor = it.Color;
		FSlateDrawElement::MakeText(OutDrawElements,LayerId,
			AllottedGeometry.ToOffsetPaintGeometry(FVector2f(xPos,yStartPos)),
			it.Name,tmp,ESlateDrawEffect::None,it.Color);
		// calc next pos
		yStartPos += result.Y + mFontSpan;
	}
	
	
	return LayerId;
}



FVector2D SPieChartCoreWidget::ComputeDesiredSize(float) const
{
	return FVector2D(mPieRadius * 2, mPieRadius * 2);
}

END_SLATE_FUNCTION_BUILD_OPTIMIZATION
