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

////////////////
// I/O LIBRARY
//

//
// Sensor I/O
//

//
// Macros coming from NXC
//

#define NBC_TYPE_NO_SENSOR      0x00 
#define NBC_TYPE_SWITCH         0x01 
#define NBC_TYPE_TEMPERATURE    0x02 
#define NBC_TYPE_REFLECTION     0x03 
#define NBC_TYPE_ANGLE          0x04 
#define NBC_TYPE_LIGHT_ACTIVE   0x05 
#define NBC_TYPE_LIGHT_INACTIVE 0x06 
#define NBC_TYPE_SOUND_DB       0x07 
#define NBC_TYPE_SOUND_DBA      0x08 
#define NBC_TYPE_CUSTOM         0x09 
#define NBC_TYPE_LOWSPEED       0x0A 
#define NBC_TYPE_LOWSPEED_9V    0x0B 
#define NBC_TYPE_HISPEED        0x0C 
#define NBC_TYPE_COLORFULL      0x0D 
#define NBC_TYPE_COLORRED       0x0E 
#define NBC_TYPE_COLORGREEN     0x0F 
#define NBC_TYPE_COLORBLUE      0x10 
#define NBC_TYPE_COLORNONE      0x11 
#define NBC_TYPE_COLOREXIT      0x12 
#define NBC_MODE_RAW           0x00 
#define NBC_MODE_BOOLEAN       0x20 
#define NBC_MODE_TRANSITIONCNT 0x40 
#define NBC_MODE_PERIODCOUNTER 0x60 
#define NBC_MODE_PCTFULLSCALE  0x80 
#define NBC_MODE_CELSIUS       0xA0 
#define NBC_MODE_FAHRENHEIT    0xC0 
#define NBC_MODE_ANGLESTEP     0xE0 
#define NBC_MODE_SLOPEMASK     0x1F 
#define NBC_MODE_MODEMASK      0xE0 

#define NXC_TYPE_NONE            NBC_TYPE_NO_SENSOR
#define NXC_TYPE_TOUCH           NBC_TYPE_SWITCH
#define NXC_TYPE_TEMPERATURE     NBC_TYPE_TEMPERATURE
#define NXC_TYPE_LIGHT           NBC_TYPE_REFLECTION
#define NXC_TYPE_ROTATION        NBC_TYPE_ANGLE
#define NXC_TYPE_LIGHT_ACTIVE    NBC_TYPE_LIGHT_ACTIVE
#define NXC_TYPE_LIGHT_INACTIVE  NBC_TYPE_LIGHT_INACTIVE
#define NXC_TYPE_SOUND_DB        NBC_TYPE_SOUND_DB
#define NXC_TYPE_SOUND_DBA       NBC_TYPE_SOUND_DBA
#define NXC_TYPE_CUSTOM          NBC_TYPE_CUSTOM
#define NXC_TYPE_LOWSPEED        NBC_TYPE_LOWSPEED
#define NXC_TYPE_LOWSPEED_9V     NBC_TYPE_LOWSPEED_9V
#define NXC_TYPE_HIGHSPEED       NBC_TYPE_HISPEED
#define NXC_TYPE_COLORFULL       NBC_TYPE_COLORFULL
#define NXC_TYPE_COLORRED        NBC_TYPE_COLORRED
#define NXC_TYPE_COLORGREEN      NBC_TYPE_COLORGREEN
#define NXC_TYPE_COLORBLUE       NBC_TYPE_COLORBLUE
#define NXC_TYPE_COLORNONE       NBC_TYPE_COLORNONE

#define NXC_MODE_RAW         NBC_MODE_RAW
#define NXC_MODE_BOOL        NBC_MODE_BOOLEAN
#define NXC_MODE_EDGE        NBC_MODE_TRANSITIONCNT
#define NXC_MODE_PULSE       NBC_MODE_PERIODCOUNTER
#define NXC_MODE_PERCENT     NBC_MODE_PCTFULLSCALE
#define NXC_MODE_CELSIUS     NBC_MODE_CELSIUS
#define NXC_MODE_FAHRENHEIT  NBC_MODE_FAHRENHEIT
#define NXC_MODE_ROTATION    NBC_MODE_ANGLESTEP


//
// Implementation
//

void SetSensorType__ubyte_ubyte(uint8_t port, uint8_t type) {
	// todo this sort-of works for some sensors
	int ev3type = NO_SEN;
	switch (type) {
	case NXC_TYPE_NONE:
		ev3type = NO_SEN;
		break;
	case NXC_TYPE_TOUCH:
		ev3type = TOUCH_PRESS;
		break;
	case NXC_TYPE_LIGHT:
	case NXC_TYPE_LIGHT_ACTIVE:
		ev3type = COL_REFLECT;
		break;
	case NXC_TYPE_LIGHT_INACTIVE:
		ev3type = COL_AMBIENT;
		break;
	case NXC_TYPE_COLORFULL:
	case NXC_TYPE_COLORRED:
	case NXC_TYPE_COLORGREEN:
	case NXC_TYPE_COLORBLUE:
		ev3type = COL_COLOR;
		break;
	case NXC_TYPE_COLORNONE:
		ev3type = COL_AMBIENT;
		break;
	case NXC_TYPE_ROTATION:
	case NXC_TYPE_SOUND_DB:
	case NXC_TYPE_SOUND_DBA:
	case NXC_TYPE_CUSTOM:
	case NXC_TYPE_LOWSPEED:
	case NXC_TYPE_LOWSPEED_9V:
	case NXC_TYPE_TEMPERATURE:
	case NXC_TYPE_HIGHSPEED:
		ev3type = NO_SEN;
		break;
	}
	setSensorMode(port, ev3type);
}
void ResetSensor__ubyte(uint8_t port) {
	int mode = getSensorMode(port);
	setSensorMode(port, NO_SEN);
	Wait(500); // todo measure
	setSensorMode(port, mode);
}
// todo 
void ClearSensor__ubyte(uint8_t port) {
	ResetSensor__ubyte(port);
}
void SetSensor__ubyte_cuint(uint8_t port, const uint16_t config) {
	SetSensorType__ubyte_ubyte(port, config >> 8);
}
void SetSensorTouch__ubyte(uint8_t port) {
	setSensorMode(port, TOUCH_PRESS);
}
void SetSensorLight__ubyte_bool(uint8_t port, bool bActive) {
	setSensorMode(port, bActive ? COL_REFLECT : COL_AMBIENT);
}
void SetSensorSound__ubyte_bool(uint8_t port, bool bdBScaling) {
	// todo
}
void SetSensorLowspeed__ubyte_bool(uint8_t port, bool bIsPowered) {
	// todo
}
void SetSensorUltrasonic__ubyte(uint8_t port) {
	setSensorMode(port, US_DIST_CM);
}
void SetSensorUltrasonicMM__ubyte(uint8_t port) {
	setSensorMode(port, US_DIST_MM);
}
void SetSensorHTGyro__ubyte(uint8_t port) {
	setSensorMode(port, GYRO_RATE);
}
void SetSensorColorFull__ubyte(uint8_t port) {
	setSensorMode(port, COL_COLOR);
}
void SetSensorColorRed__ubyte(uint8_t port) {
	setSensorMode(port, COL_COLOR);
}
void SetSensorColorGreen__ubyte(uint8_t port) {
	setSensorMode(port, COL_COLOR);
}
void SetSensorColorBlue__ubyte(uint8_t port) {
	setSensorMode(port, COL_COLOR);
}
void SetSensorColorNone__ubyte(uint8_t port) {
	setSensorMode(port, COL_COLOR);
}
float GetInput__ubyte_cubyte(uint8_t port, const uint8_t field) {
	return readSensor(port);
}
int16_t SensorHTGyro__ubyte_sint(uint8_t port, int16_t offset) {
	return readSensor(port);
}
uint16_t Sensor__ubyte(uint8_t port) {
	return readSensor(port);
}
bool SensorInvalid__ubyte(uint8_t port) {
	return getSensorMode(port) == NO_SEN;
}
uint8_t SensorMode__ubyte(uint8_t port) {
	return NXC_MODE_RAW;
}
uint16_t SensorNormalized__ubyte(uint8_t port) {
	return readSensor(port);
}
uint16_t SensorRaw__ubyte(uint8_t port) {
	return readSensor(port);
}
uint16_t SensorScaled__ubyte(uint8_t port) {
	return readSensor(port);
}
uint8_t SensorUS_ubyte(uint8_t port) {
	int mode = getSensorMode(port);
	if (mode != US_DIST_CM) {
		SetSensorUltrasonic__ubyte(port);
	}
	return readSensor(port);
}
uint8_t SensorType__ubyte(uint8_t port) {
	// note: this is NOT a reliable source of information for how to configure sensors.
	int mode = getSensorMode(port);
	switch(mode) {
	case NO_SEN:
		return NXC_TYPE_NONE;
	case TOUCH_PRESS:
		return NXC_TYPE_TOUCH;
	case COL_REFLECT:
		return NXC_TYPE_LIGHT_ACTIVE;
	case COL_AMBIENT:
		return NXC_TYPE_LIGHT_INACTIVE;
	case COL_COLOR:
		return NXC_TYPE_COLORFULL;
	case US_DIST_CM:
	case US_DIST_MM:
	case US_DIST_IN:
	case GYRO_ANG:
	case GYRO_RATE:
	case IR_PROX:
	case IR_SEEK:
	case IR_REMOTE:
	case NXT_IR_SEEKER:
		return NXC_TYPE_HIGHSPEED;
	case NXT_TEMP_C:
	case NXT_TEMP_F:
		return NXC_TYPE_TEMPERATURE;
	}
}
uint16_t SensorValue__ubyte(uint8_t port) {
	return readSensor(port);
}
uint16_t SensorValueRaw__ubyte(uint8_t port) {
	return readSensor(port);
}
