/**
 * NXClib - NXC2CC Library
 * 
 * Copyright (C) 2016-2017  Faculty of Electrical Engineering, CTU in Prague
 * Author: Jakub Vanek <nxc4ev3@vankovi.net>
 * 
 * 
 * Program initialization code.
 */
 
 
#include <stdio.h>
#include <nxclib.h>
#include <time.h>
#include <dirent.h>
#include <string.h>
#include <errno.h>

#include <ev3.h>

extern void entrypoint();

struct timespec __firstTick;

void cleanup() {
    FreeEV3();
}

int numThreads() {
	int            files = -2; // . and .. subtracted
	DIR           *dir   = NULL;
	struct dirent *entry = NULL;
	
	dir = opendir("/proc/self/task");
	if (dir == NULL) {
		fprintf(stderr, "ERROR: Cannot open /proc/self/task! %s (%d)\n", strerror(errno), errno);
		exit(1);
	}
	while ((entry = readdir(dir)) != NULL) {
		if (entry->d_type == DT_DIR) {
			files++;
		}
	}
	if (closedir(dir) != 0) {
		fprintf(stderr, "ERROR: Cannot close /proc/self/task! %s (%d)\n", strerror(errno), errno);
		exit(1);
	}
	return files;
}

int main (int argc, char **argv) {
    atexit(&cleanup);
    srand(time(NULL));
    if (clock_gettime(CLOCK_MONOTONIC, &__firstTick) != 0) {
        fprintf(stderr, "CRITICAL NXCLIB ERROR: Cannot get start time.\n");
        exit(1);
    }
    InitEV3();
    entrypoint();
    while (ButtonIsUp(BTNEXIT) && numThreads() != 1) {
		Wait(50);
	}
	Wait(250); // anti-escape-press
	exit(0);
}
