// Fill out your copyright notice in the Description page of Project Settings.


#include "BPWidgets/PieChartWidget.h"

#include "CoreWidgets/SPieChartCoreWidget.h"
#if WITH_EDITOR
const FText UPieChartWidget::GetPaletteCategory()
{
	return FText::FromString("Digital UI");
}
#endif


void UPieChartWidget::SynchronizeProperties()
{
	Super::SynchronizeProperties();
	TestCoreWidget->CF_SyncArgs(
		SPieChartCoreWidget::FArguments()
		.PieRadius(mRadius).PieChartData(mPieChartData)
		.DeltaRadians(mDeltaRadians).LineWidth(mLineWidth)
		.Font(mFont).FontSpan(mFontSpan));
}

void UPieChartWidget::ReleaseSlateResources(bool bReleaseChildren)
{
	Super::ReleaseSlateResources(bReleaseChildren);
	TestCoreWidget.Reset();
}

TSharedRef<SWidget> UPieChartWidget::RebuildWidget()
{
	TestCoreWidget = SNew(SPieChartCoreWidget)
		.PieRadius(mRadius).PieChartData(mPieChartData)
		.DeltaRadians(mDeltaRadians).LineWidth(mLineWidth)
		.Font(mFont).FontSpan(mFontSpan);
	return TestCoreWidget.ToSharedRef();
}
