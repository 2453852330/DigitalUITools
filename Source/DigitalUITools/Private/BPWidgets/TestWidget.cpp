// Fill out your copyright notice in the Description page of Project Settings.


#include "BPWidgets/TestWidget.h"

#include "CoreWidgets/STestCoreWidget.h"

void UTestWidget::SynchronizeProperties()
{
	Super::SynchronizeProperties();
	TestCoreWidget->CF_SyncArgs(
		STestCoreWidget::FArguments()
		.Points(mPoints).LineWidth(mLineWidth)
		.AxisFont(mAxisFont).AxisFontColor(mAxisFontColor)
		.DrawSize(mDrawSize).LineColor(mLineColor)
		.XAxisName(mXAxisName).YAxisName(mYAxisName)
		.DataFont(mDataFont).DataFontColor(mDataFontColor));
}

void UTestWidget::ReleaseSlateResources(bool bReleaseChildren)
{
	Super::ReleaseSlateResources(bReleaseChildren);
	TestCoreWidget.Reset();
}

void UTestWidget::BP_UpdatePoints(TArray<FVector2D> InPoints)
{
	TestCoreWidget->CF_UpdatePoints(InPoints);
}

TSharedRef<SWidget> UTestWidget::RebuildWidget()
{
	TestCoreWidget = SNew(STestCoreWidget)
		.DrawSize(mDrawSize).LineWidth(mLineWidth)
		.Points(mPoints);
	return TestCoreWidget.ToSharedRef();
}
