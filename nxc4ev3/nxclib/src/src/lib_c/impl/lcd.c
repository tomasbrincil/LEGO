/**
 * NXClib - NXC2CC Library
 * 
 * Copyright (C) 2016-2017  Faculty of Electrical Engineering, CTU in Prague
 * Author: Jakub Vanek <nxc4ev3@vankovi.net>
 * 
 * 
 * C-side implementation
 */

#include <ev3.h>
#include <nxclib.h>
#include <stdlib.h>
#include <stdio.h>


////////////////////
// DISPLAY LIBRARY
//

void ResetScreen_() {
	LcdClearDisplay();
	LcdUpdate();
}

void ClearScreen_() {
	LcdClearDisplay();
}

void printf__string_string(char *format, char *data) {
	LcdPrintf(true, format, data);
}
void printf__string_slong(char *format, int32_t data) {
	LcdPrintf(true, format, data);
}
void printf__string_float(char *format, float data) {
	LcdPrintf(true, format, data);
}
int8_t CircleOut__sint_sint_ubyte_ulong(int16_t x, int16_t y, uint8_t radius, uint32_t options) {
	return CircleOutEx(x, y, radius, options);
}
int8_t LineOut__sint_sint_sint_sint_ulong(int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint32_t options) {
	return LineOutEx(x1, y1, x2, y2, options);
}
int8_t PointOut__sint_sint_ulong(int16_t x, int16_t y, uint32_t options) {
	return PointOutEx(x, y, options);
}
int8_t RectOut__sint_sint_sint_sint_ulong(int16_t x, int16_t y, int16_t width, int16_t height, uint32_t options) {
	return RectOutEx(x, y, width, height, options);
}
int8_t TextOut__sint_sint_string_ulong(int16_t x, int16_t y, char * str, uint32_t options) {
	return LcdText(true, x, y, str);
}
int8_t NumOut__sint_sint_sint_ulong(int16_t x, int16_t y, int16_t value, uint32_t options) {
	return LcdTextf(true, x, y, "%d", value);
	//return NumOutEx(x, y, value, options);
}
int8_t EllipseOut__sint_sint_ubyte_ubyte_ulong(int16_t x, int16_t y, uint8_t radiusX, uint8_t radiusY, uint32_t options) {
	return EllipseOutEx(x, y, radiusX, radiusY, options);
}
int8_t PolyOut__arr1type26_ulong(struct LocationType* points, uint32_t options) {
	return PolyOutEx((PLocationType_native)points, options);
}
int8_t GraphicOut__sint_sint_string_ulong(int16_t x, int16_t y, char * filename, uint32_t options) {
	return GraphicOutEx(x, y, filename, options);
}
int8_t GraphicArrayOut__sint_sint_arr1ubyte_ulong(int16_t x, int16_t y, uint8_t* data, uint32_t options) {
	return GraphicArrayOutEx(x, y, data, options);
}
