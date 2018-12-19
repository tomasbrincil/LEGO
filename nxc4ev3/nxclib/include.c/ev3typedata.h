/*
 * EV3 internal sensor typedata API
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
#ifndef OUR_TYPEDATA_H
#define OUR_TYPEDATA_H

#include "uart.h"
#include "iic.h"
#include "analog.h"
#include "ev3sensor_dispatch.h"

/***********************************/

// define of Sensor setup
// TOUCH
#define TOUCH_TYPE 16
#define TOUCH_PRESS_MODE 0 	// Press

// Light
#define COL_TYPE 29
#define COL_REFLECT_MODE 0 	// Reflect
#define COL_AMBIENT_MODE 1 	// Ambient
#define COL_COLOR_MODE 2 	//Color

// Ultrasonic
#define US_TYPE 30
#define US_DIST_CM_MODE 0 	// Dist in cm
#define US_DIST_MM_MODE 0 	// Dist in mm
#define US_DIST_IN_MODE 1 	// Dist in inch

// Gyroskop
#define GYRO_TYPE 32
#define GYRO_ANG_MODE 0 	// angle
#define GYRO_RATE_MODE 1	// rate

// Infrared
#define IR_TYPE 33
#define IR_PROX_MODE 0		// Proximity
#define IR_SEEK_MODE 1		// Seek
#define IR_REMOTE_MODE 2	// Remote Control

// IIC 
#define IIC_TYPE 100
#define IIC_BYTE_MODE 0

//NXT Temperture
#define NXT_TEMP_TYPE 6
#define NXT_TEMP_C_MODE 0	// Temperature in C
#define NXT_TEMP_F_MODE 1	// Temperature in F

/***********************************/

/**
 * Sensor typedata entry.
 */
typedef struct {
	//! C4EV3 identifier
	int   name;
	//! Kernel constant for connection type.
	DATA8 connection;
	//! Kernel constant for sensor type.
	DATA8 type;
	//! Kernel constant for sensor mode.
	DATA8 mode;
	//! Sensor data reader.
	sensor_read_fn  reader;
	//! Sensor data parser.
	sensor_parse_fn parser;
} sensor_typedata;

/**
 * Table of sensor typedata.
 */
typedef sensor_typedata sensor_type_table[];

/***********************************/

/**
 * Find typedata entry for specified sensor name.
 * 
 * @param name Sensor type/mode identifier.
 * @return     If found, pointer to typedata array, {@code NULL} otherwise.
 */
extern sensor_typedata *stp_find           (int name);

/**
 * Fill kernel struct based on the typedata entry.
 * 
 * @param name   Desired sensor type/mode identifier.
 * @param port   Sensor port to operate on.
 * @param kernel Kernel data structure.
 * @return       {@code 0} on success, {@code -1} on failure.
 */
extern int              stp_fill_kernel    (int name, int port, DEVCON *kernel);

/**
 * Fill kernel struct for all sensors, based on typedata.
 * 
 * @param names  Array of desired sensor types/modes for all ports.
 * @param kernel Kernel data structure.
 * @return       {@code 0} on success, {@code -1} on failure.
 */
extern int              stp_fill_kernel_all(int names[INPUTS], DEVCON *kernel);

/**
 * Get reader for data from sensor.
 * 
 * @param name Sensor type/mode identifier.
 * @return     Pointer to reading function.
 */
extern sensor_read_fn   stp_get_reader     (int name);

/**
 * Get parser for data from sensor. 
 * 
 * @param name Sensor type/mode identifier.
 * @return     Pointer to parsing function.
 */
extern sensor_parse_fn  stp_get_parser     (int name);

/**
 * Get sensor type/mode identifier.
 * 
 * @param current_typedata Typedata from the sensor.
 * @return                 Name or -1 if not found.
 */
extern int              stp_get_name(volatile TYPES *remote);

/**
 * Get sensor mode number.
 * 
 * @param name Sensor type/mode identifier.
 * @return Mode number (sensor typedata index) or -1 if not found.
 */
extern int              stp_mode_number(int name);

#endif//OUR_TYPEDATA_H
