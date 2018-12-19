/**
 * NXClib - NXC2CC Library
 * 
 * Copyright (C) 2016-2017  Faculty of Electrical Engineering, CTU in Prague
 * Author: Jakub Vanek <nxc4ev3@vankovi.net>
 * 
 * 
 * C-side implementation
 */

#define _GNU_SOURCE

#include <ev3_command.h>
#include <init.h>
#include <nxclib.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <math.h>
#include <tgmath.h>


//////////////////
// Miscellaneous
//
//int Random(unsigned int n = 0);
int16_t Random__uint(uint16_t n) {
	int16_t random = rand();
	if (n != 0) {
		if (random < 0)
			random = -random;
		if (random >= n)
			random = n - 1;
	}
	return random;
}

void Wait__ulong(uint32_t wait) {
	Wait(wait); // yeah, this is already implemented, actually pretty fascinating
}

uint32_t ts2ms(struct timespec *spec) {
	return spec->tv_sec  * 1000 +
	       spec->tv_nsec / (1000 * 1000);
}

uint32_t CurrentTick_() {
	struct timespec now;
	if (clock_gettime(CLOCK_MONOTONIC, &now) != 0) {
		fprintf(stderr, "WARNING: clock_gettime failed.\n");
		return 0;
	}
	return ts2ms(&now);
}
uint32_t FirstTick_() {
	return ts2ms(&__firstTick);
}
void Yield_() {
	pthread_yield();
}
void StopAllTasks_() {
	exit(0);
}
void Stop__bool(bool really) {
	if (really) {
		StopAllTasks_();
	}
}
// todo handle initialization
void Acquire__mutex(pthread_mutex_t (*m));
void Release__mutex(pthread_mutex_t (*m));

//////////////
// THREADING
//

void Acquire__mutex(pthread_mutex_t (*m)) {
	pthread_mutex_lock(m);
}

void Release__mutex(pthread_mutex_t (*m)) {
	pthread_mutex_unlock(m);
}

void thread_start_all(PRECEDES_LIST *list) {
    while (list != NULL) {
        thread_start(list->pthread, list->entrypoint);
        list = list->next;
    }
}

void thread_start(pthread_t *thr, void *(*func)(void *)) {
	pthread_attr_t attrs;
	pthread_attr_init(&attrs);
	pthread_attr_setdetachstate(&attrs, PTHREAD_CREATE_DETACHED);

	pthread_create(thr, &attrs, func, NULL);

	pthread_attr_destroy(&attrs);
}

void precedes_add(PRECEDES_LIST **root, pthread_t *thr, void *(*func)(void *)) {
    PRECEDES_LIST *node = malloc(sizeof(PRECEDES_LIST));
    node->pthread    = thr;
    node->entrypoint = func;
    node->next = *root;
    *root = node;
}

void precedes_free(PRECEDES_LIST *root) {
    while (root != NULL) {
        PRECEDES_LIST *next = root->next;
        free(root);
        root = next;
    }
}

#define ToRad(x) ((x) / 180.0f * M_PI)
#define ToDeg(x) ((x) * 180.0f / M_PI)

float acosd(float val) {
	return ToDeg(acos(val));
}
float asind(float val) {
	return ToDeg(asin(val));
}
float atand(float val) {
	return ToDeg(atan(val));
}
float cosd(float val) {
	return cos(ToRad(val));
}
float sind(float val) {
	return sin(ToRad(val));
}
float tand(float val) {
	return tan(ToRad(val));
}
float coshd(float val) {
	return cosh(ToRad(val));
}
float sinhd(float val) {
	return sinh(ToRad(val));
}
float tanhd(float val) {
	return tanh(ToRad(val));
}
float atan2d(float val1, float val2) {
	return ToDeg(atan2(val1, val2));
}
bool isNAN(float val) {
	return isnanf(val);
}
