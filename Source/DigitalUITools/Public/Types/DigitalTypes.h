// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "DigitalTypes.generated.h"


USTRUCT(BlueprintType)
struct FPieChartData
{
	GENERATED_BODY()
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Pie Chart Data")
	FString Name = "Name";
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Pie Chart Data")
	float Ratio = 1.f;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Pie Chart Data")
	FLinearColor Color = FLinearColor::White;
};
