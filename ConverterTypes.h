/*
	Converter Types variables

	A lot of functions to convert types of variables without
	conflit. For more compatibilty with communication with
	non typed languages

	Author: Ozeias Ribeiro
	Data: 2020/12/25 (Japanese Format YYYY/MM/DD)
*/

#ifndef converterTypes_h
#define ConverterTypes_h

#include <math.h>
#include <Arduino.h>

//Converter String to Int
int StringToInt(String str);

//Converter String to Float
float StringToFloat(String str);
#endif
