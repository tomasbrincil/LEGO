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


//
// Button I/O
//

void SetLedWarning__bool(bool Value) {
	return SetLedWarning(Value);
}
uint8_t LedWarning_() {
	return LedWarning();
}
void SetLedPattern__ubyte(uint8_t Pattern) {
	return SetLedPattern(Pattern);
}
uint8_t LedPattern_() {
	return LedPattern();
}
uint16_t ButtonWaitForAnyEvent__uint(uint16_t timeout) {
	return ButtonWaitForAnyEvent(timeout);
}
uint16_t ButtonWaitForAnyPress__uint(uint16_t timeout) {
	return ButtonWaitForAnyPress(timeout);
}
bool ButtonIsUp__ubyte(uint8_t Button) {
	return ButtonIsUp(Button);
}
bool ButtonIsDown__ubyte(uint8_t Button) {
	return ButtonIsDown(Button);
}
void ButtonWaitForPress__ubyte(uint8_t Button) {
	return ButtonWaitForPress(Button);
}
void ButtonWaitForPressAndRelease__ubyte(uint8_t Button) {
	return ButtonWaitForPressAndRelease(Button);
}


// NXC-style API
bool ButtonPressed__ubyte_bool(uint8_t btn, bool resetCount) {
	return ButtonPressedEx(btn, resetCount);
}
int8_t ReadButtonEx__ubyte_bool_bool_uint(uint8_t btn, bool reset, bool (*pressed), uint16_t (*count)) {
	return ReadButtonEx(btn, reset, pressed, count);
}
uint8_t ButtonState__ubyte(uint8_t btn) {
	return ButtonState(btn);
}



//
// Motor I/O
//
void OffEx__ubyte_cubyte(uint8_t outputs, const uint8_t reset) {
	OffEx(outputs, reset);
}
void FloatEx__ubyte_cubyte(uint8_t outputs, const uint8_t reset) {
	FloatEx(outputs, reset);
}
void CoastEx__ubyte_cubyte(uint8_t outputs, const uint8_t reset) {
	FloatEx(outputs, reset);
}
void OnFwdEx__ubyte_sbyte_cubyte(uint8_t outputs, int8_t pwr, const uint8_t reset) {
	OnFwdEx(outputs, pwr, reset);
}
void OnRevEx__ubyte_sbyte_cubyte(uint8_t outputs, int8_t pwr, const uint8_t reset) {
	OnRevEx(outputs, pwr, reset);
}
void OnFwdRegEx__ubyte_sbyte_ubyte_cubyte(uint8_t outputs, int8_t pwr, uint8_t regmode, const uint8_t reset) {
	OnFwdRegEx(outputs, pwr, regmode, reset);
}
void OnRevRegEx__ubyte_sbyte_ubyte_cubyte(uint8_t outputs, int8_t pwr, uint8_t regmode, const uint8_t reset) {
	OnRevRegEx(outputs, pwr, regmode, reset);
}
void OnFwdSyncEx__ubyte_sbyte_sbyte_cubyte(uint8_t outputs, int8_t pwr, int8_t turnpct, const uint8_t reset) {
	OnFwdSyncEx(outputs, pwr, turnpct * 2, reset);
}
void OnRevSyncEx__ubyte_sbyte_sbyte_cubyte(uint8_t outputs, int8_t pwr, int8_t turnpct, const uint8_t reset) {
	OnRevSyncEx(outputs, pwr, turnpct * 2, reset);
}
void RotateMotorEx__ubyte_sbyte_slong_sint_bool_bool(uint8_t outputs, int8_t pwr, int32_t angle, int16_t turnpct, bool sync, bool stop_) {
	RotateMotorEx(outputs, pwr, angle, turnpct * 2, sync, stop_);
}
void ResetTachoCount__ubyte(uint8_t outputs) {
	ResetTachoCount(outputs);
}
void ResetBlockTachoCount__ubyte(uint8_t outputs) {
	ResetBlockTachoCount(outputs);
}
void ResetRotationCount__ubyte(uint8_t outputs) {
	ResetRotationCount(outputs);
}
void ResetAllTachoCounts__ubyte(uint8_t outputs) {
	ResetAllTachoCounts(outputs);
}
void ResetCount__ubyte_ubyte(uint8_t Outputs, uint8_t reset) {
	ResetCount(Outputs, reset);
}
int8_t MotorPower__ubyte(uint8_t output) {
	return MotorPower(output);
}
int8_t MotorActualSpeed__ubyte(uint8_t output) {
	return MotorActualSpeed(output);
}
int32_t MotorTachoCount__ubyte(uint8_t output) {
	return MotorTachoCount(output);
}
int32_t MotorBlockTachoCount__ubyte(uint8_t output) {
	return MotorBlockTachoCount(output);
}
int32_t MotorRotationCount__ubyte(uint8_t output) {
	return MotorRotationCount(output);
}
bool MotorBusy__ubyte(uint8_t Output) {
	return MotorBusy(Output);
}

void RotateMotorRampNoWait__ubyte_sbyte_sint_sint_sint_bool(uint8_t Outputs,
                                                            int8_t  Speed,
                                                            int16_t accelAngle,
                                                            int16_t steadyAngle,
                                                            int16_t decelAngle,
                                                            bool    Stop) {
	RotateMotorRampNoWait(Outputs, Speed, accelAngle, steadyAngle, decelAngle, Stop);
}

void RotateMotorRamp__ubyte_sbyte_sint_sint_sint_bool(uint8_t Outputs,
                                                      int8_t  Speed,
                                                      int16_t accelAngle,
                                                      int16_t steadyAngle,
                                                      int16_t decelAngle,
                                                      bool    Stop) {
	RotateMotorRamp(Outputs, Speed, accelAngle, steadyAngle, decelAngle, Stop);
}

//
// Sound I/O
//



int8_t PlayFile__string(char * filename) {
	PlayFile(filename);
	return 0;
}
int8_t PlayFileEx__string_ubyte_bool_uint(char * filename, uint8_t volume, bool loop, uint16_t sr) {
	PlayFileEx(filename, volume, loop);
	return 0;
}
int8_t PlayTone__uint_uint(uint16_t frequency, uint16_t duration) {
	PlayTone(frequency, duration);
	return 0;
}
int8_t PlayToneEx__uint_uint_ubyte_bool(uint16_t frequency, uint16_t duration, uint8_t volume, bool loop) {
	PlayToneEx(frequency, duration, volume);
	return 0;
}
uint8_t SoundState_() {
	return (uint8_t)SoundState();
}
uint8_t StopSound_() {
	StopSound();
	return 0;
}
