# Better Unreal
A collection of modifications/additions (scripts/prefabs) which enhance [for me] the overall flow of using the Unity Engine.

## Purpose
Give access to multiple basic/special needs to prevent redundancy.
<br>

## Installation
You can download relevant files and directly import them inside your project.


# Contents

## 1. Helper Functions

### 1.1 File Handling
Quick small codes to easily Load Files and Save Files directly from a blueprint.

The functions are FileLoadString and FileSaveString respectively.

Definition:
```C++
bool FileLoadString(FString FileNameA, FString& SaveTextA);
bool FileSaveString(FString SaveTextB, FString FileNameB);
```


!["1.1 - File Handling"](https://github.com/sudotman/sudotman/blob/main/demos/BetterUnreal/FileHandling.png)

<br>
<br>


### 1.2 Hex/Decimal Conversions
Simple conversions between Hexadecimal numbers to Decimal numbers and vice versa right inside Unreal blueprints.

Definition:
```C++
int convertHexToDec(FString hexValue);
FString DecimalToHex(FString decimalString);

```


Do note there aren't many exception checking implemented for now so be careful with the values you pass in. (Will implement this later.)

<br>
<br>

### 1.3 Hex to Floating Point Conversion
Converts a hexadecimal value to a floating point.

Definition:
```C++
float HexFloatingConversion(FString hexValue);
```

<br>
<br>


### 1.4 CRC16 Checksum
Calculates a CRC 16 checksum using the polynomial 0xA001 and initial value 0x0000. (A newer implementation can be done to accomodate for custom polynomials too, will do that probably.)

Definition:
```C++
FString Crc16Hex(FString data);
FString Crc16Text(const FString& data);
FString CalculateCRC16String(FString Input); //if you want a checksum not for a continous string but rather say spaces (bytes being converted to string with spaced between them)
```


<br>
<br>

