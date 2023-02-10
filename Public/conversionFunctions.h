

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "conversionFunctions.generated.h"


/**
 * 
 */
UCLASS()
class HMG_API UconversionFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintPure, Category = "Conversions")
	static float HexFloatingConversion(FString hexValue);

	UFUNCTION(BlueprintPure, Category = "Conversions")
	static int convertHexToDec(FString hexValue);

	UFUNCTION(BlueprintPure, Category = "Conversions")
		static FString DecimalToHex(FString decimalString);

	UFUNCTION(BlueprintPure, Category = "Conversions")
		static FString Crc16Text(const FString& data);

	UFUNCTION(BlueprintPure, Category = "Conversions")
		static FString Crc16Hex(FString data);

	UFUNCTION(BlueprintPure, Category = "Conversions")
		static FString CalculateCRC16String(FString input);

	UFUNCTION(BlueprintCallable, Category = "Files")
	static bool FileSaveString(FString SaveTextB, FString FileNameB);

	UFUNCTION(BlueprintPure, Category = "Files")
	static bool FileLoadString(FString FileNameA, FString& SaveTextA);

};
