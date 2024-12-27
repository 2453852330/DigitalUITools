// Fill out your copyright notice in the Description page of Project Settings.


#include "BPWidgets/LineChartWidget.h"

#include "CoreWidgets/SLineChartCoreWidget.h"

void ULineChartWidget::SynchronizeProperties()
{
	Super::SynchronizeProperties();
	TestCoreWidget->CF_SyncArgs(
		SLineChartCoreWidget::FArguments()
		.Points(mPoints).LineWidth(mLineWidth)
		.AxisFont(mAxisFont).AxisFontColor(mAxisFontColor)
		.DrawSize(mDrawSize).LineColor(mLineColor)
		.XAxisName(mXAxisName).YAxisName(mYAxisName)
		.DataFont(mDataFont).DataFontColor(mDataFontColor));
}


#if WITH_EDITOR
const FText ULineChartWidget::GetPaletteCategory()
{
	return FText::FromString("Digital UI");
}
#endif


void ULineChartWidget::ReleaseSlateResources(bool bReleaseChildren)
{
	Super::ReleaseSlateResources(bReleaseChildren);
	TestCoreWidget.Reset();
}

void ULineChartWidget::BP_UpdatePoints(TArray<FVector2D> InPoints)
{
	TestCoreWidget->CF_UpdatePoints(InPoints);
}

TSharedRef<SWidget> ULineChartWidget::RebuildWidget()
{
	TestCoreWidget = SNew(SLineChartCoreWidget)
		.DrawSize(mDrawSize).LineWidth(mLineWidth)
		.Points(mPoints);
	return TestCoreWidget.ToSharedRef();
}
