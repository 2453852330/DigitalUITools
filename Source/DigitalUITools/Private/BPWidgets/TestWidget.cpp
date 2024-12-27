// Fill out your copyright notice in the Description page of Project Settings.


#include "BPWidgets/TestWidget.h"

#include "CoreWidgets/STestCoreWidget.h"

void UTestWidget::SynchronizeProperties()
{
	Super::SynchronizeProperties();
	TestCoreWidget->CF_SyncPoints(mPoints);
}

void UTestWidget::ReleaseSlateResources(bool bReleaseChildren)
{
	Super::ReleaseSlateResources(bReleaseChildren);
	TestCoreWidget.Reset();
}

TSharedRef<SWidget> UTestWidget::RebuildWidget()
{
	TestCoreWidget = SNew(STestCoreWidget)
		.DrawSize(mDrawSize).LineWidth(mLineWidth)
		.Points(mPoints);
	return TestCoreWidget.ToSharedRef();
}
