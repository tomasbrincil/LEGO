/*
 * Declarations for sensor reading functions
 *
 * Copyright (C) 2017 Faculty of Electrical Engineering, CTU in Prague (Jakub Vanek <nxc4ev3@vankovi.net>)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/
 *
 * ----------------------------------------------------------------------------
 *
 * \author Faculty of Electrical Engineering, CTU in Prague (Jakub Vanek <nxc4ev3@vankovi.net>)
 * \date 2017-09-05
 * \version 1
 *
 */

#ifndef EV3SENSOR_DISPATCH_H
#define EV3SENSOR_DISPATCH_H


//
// FUNCTION POINTERS
//


typedef volatile void *bufptr_t;
/**
 * Read data from sensor.
 * 
 * @param port Port number in range [0;INPUTS)
 * @return     Pointer to sensor receive buffer.
 */
typedef bufptr_t (*sensor_read_fn)(int port);
/**
 * Parse data from sensor.
 * 
 * @param port Port number in range [0;INPUTS)
 * @param raw  Pointer to sensor receive buffer.
 * @return     Parsed measurement.
 */
typedef int   (*sensor_parse_fn)(int port, bufptr_t raw);

//
// READING FUNCTIONS
//

//! Dumb reader.
extern bufptr_t readNull(int);
//! Read last received data from UART buffer.
extern bufptr_t readUartSensor   (int sensorPort);
//! Read last received data from I2C buffer.
extern bufptr_t readIicSensor    (int sensorPort);
//! Read last measured data from ADC on new pin.
extern bufptr_t readNewDumbSensor(int sensorPort);
//! Read last measured data from ADC on old pin.
extern bufptr_t readOldDumbSensor(int sensorPort);

//
// PARSING FUNCTIONS
//

//! Dumb parser.
extern int parseNull        (int     , bufptr_t);
//! Parse ADC reading from pin connected to the button.
extern int parseTouch       (int port, bufptr_t data);
//! Parse UART message containing amount of received light.
extern int parseColor_Light (int port, bufptr_t data);
//! Parse UART message containing measured color code.
extern int parseColor_Code  (int port, bufptr_t data);
//! Parse UART message containing distance, untouched.
extern int parseDist_Basic  (int port, bufptr_t data);
//! Parse UART message containing distance, scaled down by a factor of 10.
extern int parseDist_CM     (int port, bufptr_t data);
//! Parse UART message containing gyroscope measurement.
extern int parseGyro        (int port, bufptr_t data);
//! Parse UART message containing IR proximity measurement.
extern int parseIR_Proximity(int port, bufptr_t data);
//! Parse UART message containing IR seek direction.
extern int parseIR_Seek     (int port, bufptr_t data);
//! Parse UART message containing IR keycode.
extern int parseIR_Remote   (int port, bufptr_t data);
//! Parse ??? message from NXT IR seeker.
extern int parseNXTIR_Seeker(int port, bufptr_t data);
//! Parse I2C message containing temperature from TMP275 sensor.
extern int parseNXTTemp_C   (int port, bufptr_t data);
//! Parse I2C message containing temperature from TMP275 sensor and convert it to degrees Fahrenheit.
extern int parseNXTTemp_F   (int port, bufptr_t data);
//! Read first S16 from buffer.
extern int parseDefault     (int port, bufptr_t data);

#endif//EV3SENSOR_DISPATCH_H
