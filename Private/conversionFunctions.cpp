

#include "conversionFunctions.h"
#include "Misc/Parse.h"
#include "ProjectDefault/ProjectDefault.h"
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include "Misc/FileHelper.h"
#include "Misc/Paths.h"
#include <string>
#include <iostream>

//#include "HMGClasses.h"

//A function to convert a hex value to a floating point value
float UconversionFunctions::HexFloatingConversion(FString hexValue) {

	float f;
	uint32_t num;

	if (!hexValue.Contains("0x")) {
		hexValue = "0x" + hexValue;
	}


	char* result = TCHAR_TO_ANSI(*hexValue);


	sscanf_s(result, "%x", &num);

	f = *((float*)&num);


	//printf(hexValue);
	return f;
}

//A function to convert a hex value to a decimal value
int UconversionFunctions::convertHexToDec(FString hexValue) {
	
	char* actualHexValue = TCHAR_TO_ANSI(*hexValue);
	int len = strlen(actualHexValue);
	int base = 1;
	int temp = 0;
	for (int i = len - 1; i >= 0; i--) {
		if (actualHexValue[i] >= '0' && actualHexValue[i] <= '9') {
			temp += (actualHexValue[i] - 48) * base;
			base = base * 16;
		}
		else if (actualHexValue[i] >= 'A' && actualHexValue[i] <= 'F') {
			temp += (actualHexValue[i] - 55) * base;
			base = base * 16;
		}
	}
	return temp;
}

//A function to convert a decimal value to a hexadecimal value
FString UconversionFunctions::DecimalToHex(FString decimalString) {
	//FString decimalString = "234295";
	FString HexString;
	for (int32 i = 0; i < decimalString.Len(); i += 2)
	{
		FString SubString = decimalString.Mid(i, 2);
		int32 Decimal = FCString::Atoi(*SubString);
		FString Hex = FString::Printf(TEXT("%02X"), Decimal);
		HexString += Hex;
	}

	return HexString;

}

const uint16 kCrcPolynomial = 0xA001;
const uint16 kInitialValue = 0x0000;

//Calculate crc16checksum based on a input text string
FString UconversionFunctions::Crc16Text(const FString& data) {
	uint16 crc = kInitialValue;
	for (const TCHAR& c : data) {
		crc ^= c;
		for (int i = 0; i < 8; ++i) {
			if (crc & 0x0001) {
				crc = (crc >> 1) ^ kCrcPolynomial;
			}
			else {
				crc = (crc >> 1);
			}
		}
	}

	return FString::Printf(TEXT("%04X"), crc);
	
}

//Calculate crc16checksum based on a input hex string
FString UconversionFunctions::Crc16Hex(FString data) {

		uint16 crc = kInitialValue;
		for (int i = 0; i < data.Len(); i += 2) {
			if (i + 1 >= data.Len()) {
				break;
			}

			TCHAR hex[3];
			hex[0] = data[i];
			hex[1] = data[i + 1];
			hex[2] = '\0';

			uint8 c = (uint8)FCString::Strtoi(hex, nullptr, 16);
			crc ^= c;
			for (int j = 0; j < 8; ++j) {
				if (crc & 0x0001) {
					crc = (crc >> 1) ^ kCrcPolynomial;
				}
				else {
					crc = (crc >> 1);
				}
			}
		}

		return FString::Printf(TEXT("%04X"), crc);

}


uint16 CalculateCRC16(FString Input)
{
	uint16 crc = 0xFFFF;
	int16 len = Input.Len();
	TArray<FString> Strings;
	Input.ParseIntoArray(Strings, TEXT(" "), true);

	for (int16 i = 0; i < len; i++)
	{
		crc = crc ^ ((uint16)Strings[i][0]);
		for (uint8 j = 0; j < 8; j++)
		{
			if (crc & 1)
				crc = (crc >> 1) ^ 0xA001;
			else
				crc = (crc >> 1);
		}
	}

	return crc;
}


//Calculate crc16checksum based on a input hex string
FString UconversionFunctions::CalculateCRC16String(FString Input)
{
	uint16 crc = CalculateCRC16(Input);
	return FString::Printf(TEXT("%04X"), crc);
}




//save a file string
bool UconversionFunctions::FileSaveString(FString SaveTextB, FString FileNameB)
{
	return FFileHelper::SaveStringToFile(SaveTextB, *(FPaths::GameSourceDir() + FileNameB));
}

//load a file string
bool UconversionFunctions::FileLoadString(FString FileNameA, FString& SaveTextA)
{
	return FFileHelper::LoadFileToString(SaveTextA, *(FPaths::GameSourceDir() + FileNameA));
}


//AAAAA