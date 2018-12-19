/**
 * NXClib - NXC2CC Library
 * 
 * Copyright (C) 2016-2017  Faculty of Electrical Engineering, CTU in Prague
 * Author: Jakub Vanek <nxc4ev3@vankovi.net>
 * 
 * 
 * C-side headers
 */


#ifndef STD_NXC_H
#define STD_NXC_H

#define _GNU_SOURCE

#include <pthread.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <iqsort.h>

// TODO error handling

#define TASK_PTHR(tname)  __thr_ ## tname
#define TASK_FUNC(tname)  __task_ ## tname
#define TASK_SPAWN(tname) __spawned_ ## tname

#define __THREAD_START(name) thread_start(&TASK_PTHR(name), &TASK_FUNC(name))


#define __THREAD_START_PRE(name) do {       \
        pthread_attr_t attrs;               \
        pthread_attr_init(&attrs);          \
        pthread_attr_setdetachstate(&attrs, \
                PTHREAD_CREATE_DETACHED);   \
        pthread_create(&TASK_PTHR(name),    \
                &attrs,                     \
                &TASK_FUNC(name),           \
                NULL);                      \
        pthread_attr_destroy(&attrs);       \
    } while (0)                             \

#define __THREAD_STOP(name) do {         \
    if (TASK_SPAWN(name)){               \
        pthread_cancel(TASK_PTHR(name)); \
    }                                    \
} while(0)

#define __THREAD_PRIORITY(name, priority) do { \
    /* sorry, not implemented yet */           \
} while(0)

#define __THREAD_CHAIN(name) do { \
	TASK_FUNC(name)(NULL);        \
	pthread_exit(NULL);           \
} while(0)

#define MUTEX_NAME(tname) __mutex_ ## tname
#define MUTEX_INIT(tname) __mutex_ ## tname ## _init

#define __MUTEX_RAW_INIT(tname) do {                            \
    pthread_mutexattr_t attrs;                                  \
    pthread_mutexattr_init(&attrs);                             \
    pthread_mutexattr_settype(&attrs, PTHREAD_MUTEX_RECURSIVE); \
    pthread_mutex_init(&MUTEX_NAME(tname), &attrs);             \
    pthread_mutexattr_destroy(&attrs);                          \
} while(0)

#define __MUTEX_INIT(tname) do {  \
    if (!MUTEX_INIT(tname)) {     \
        __MUTEX_RAW_INIT(tname);  \
        MUTEX_INIT(tname) = true; \
    }                             \
} while(0)

typedef struct precedes_list_t {
    pthread_t *pthread;
    void *(*entrypoint)(void *);
    struct precedes_list_t *next;
} PRECEDES_LIST;


void thread_start_all(PRECEDES_LIST *list);
void thread_start(pthread_t *thr, void *(*func)(void *));
void precedes_add(PRECEDES_LIST **root, pthread_t *thr, void *(*func)(void *));
void precedes_free(PRECEDES_LIST *root);

#define PRECEDES_INIT       PRECEDES_LIST *__precedes = NULL
#define PRECEDES_ARGS       PRECEDES_LIST **__precedes
#define PRECEDES_EXEC       thread_start_all(__precedes)
#define PRECEDES_FREE       precedes_free(__precedes)
#define PRECEDES_CALL(name) name(&__precedes)

// argument reversal is intended
#define PRECEDES_ONE(name) precedes_add(__precedes, &TASK_PTHR(name), &TASK_FUNC(name))
#define PRECEDES_I_1(task)     PRECEDES_ONE(task);
#define PRECEDES_I_2(task,...) PRECEDES_I_1(__VA_ARGS__) PRECEDES_ONE(task);
#define PRECEDES_I_3(task,...) PRECEDES_I_2(__VA_ARGS__) PRECEDES_ONE(task);
#define PRECEDES_I_4(task,...) PRECEDES_I_3(__VA_ARGS__) PRECEDES_ONE(task);
#define PRECEDES_I_5(task,...) PRECEDES_I_4(__VA_ARGS__) PRECEDES_ONE(task);
#define PRECEDES_I_6(task,...) PRECEDES_I_5(__VA_ARGS__) PRECEDES_ONE(task);
#define PRECEDES_I_7(task,...) PRECEDES_I_6(__VA_ARGS__) PRECEDES_ONE(task);
#define PRECEDES_I_8(task,...) PRECEDES_I_7(__VA_ARGS__) PRECEDES_ONE(task);

#define PRECEDES_CHOOSE(_1,_2,_3,_4,_5,_6,_7,_8,NAME,...) NAME
#define PRECEDES_ITER(...) \
    PRECEDES_CHOOSE(__VA_ARGS__,\
                    PRECEDES_I_8,\
                    PRECEDES_I_7,\
                    PRECEDES_I_6,\
                    PRECEDES_I_5,\
                    PRECEDES_I_4,\
                    PRECEDES_I_3,\
                    PRECEDES_I_2,\
                    PRECEDES_I_1)(__VA_ARGS__)


#define Precedes(...) do { PRECEDES_ITER(__VA_ARGS__) } while(0)


//
// Native structs
//

struct LocationType {
  int X;  
  int Y;  
};

//
// Array functions
// fixme: side effects
//

// this ArrayLen impl is dangerous (works only on true arrays); only use as last resort
#define ArrayLen(arr) (sizeof((arr))/sizeof((arr)[0]))

#define ArrayBuild(arr,...) /* sorry, not enough time */

#define ArrayInit(arr,val,cnt) do {     \
	__typeof__(val) l_val = (val);      \
	__typeof__(cnt) l_cnt = (cnt);      \
	for(size_t i = 0; i < l_cnt; i++) { \
		(arr)[i] = l_val;               \
	}                                   \
} while(0)

#define ArraySubset(dst,src,istart,len) do {                               \
	__typeof__(istart) l_istart = (istart);                                \
	__typeof__(len)    l_len    = (len);                                   \
	for (size_t isrc = l_istart, idst = 0; idst < l_len; isrc++, idst++) { \
		(dst)[idst] = (src)[isrc];                                         \
	}                                                                      \
} while(0)

#define ArrayIndex(out,arr,index) do {   \
	__typeof__(index) l_index = (index); \
	(out) = (arr)[l_index);              \
} while(0)

#define ArrayReplace(arr,index,val) do { \
	__typeof__(val)   l_val   = (val);   \
	__typeof__(index) l_index = (index); \
	(arr)[l_index] = l_val;              \
} while(0)

#define ArraySum(arr,start,len) ({                     \
	__typeof__(start) l_start = (start);               \
	__typeof__(len)   l_len   = (len);                 \
	float sum = 0;                                     \
	for (size_t i = l_start; i < l_len+l_start; i++) { \
		sum += (arr)[i];                               \
	}                                                  \
	sum;                                               \
})

#define ArrayMean(arr,start,len) ({          \
	__typeof__(len)   l_len   = (len);       \
	float mean =  ArraySum(arr,start,l_len); \
	mean /= l_len;                           \
	mean;                                    \
})

#define ArraySumSqr(arr,start,len) ({                  \
	__typeof__(start) l_start = (start);               \
	__typeof__(len)   l_len   = (len);                 \
	float sum = 0;                                     \
	for (size_t i = l_start; i < l_len+l_start; i++) { \
		float val = (arr)[i];                          \
		sum += val*val                                 \
	}                                                  \
	sum;                                               \
})

#define ArrayStd(arr,start,len) ({                     \
	__typeof__(len)   l_len   = (len);                 \
	__typeof__(start) l_start = (start);               \
	float mean = ArrayMean(arr, l_start, l_len);       \
	float sum = 0;                                     \
	for (size_t i = l_start; i < l_len+l_start; i++) { \
		float diff = (arr)[i] - mean;                  \
		sum += diff*diff;                              \
	}                                                  \
	sum /= l_len;                                      \
	sum = sqrt(sum);                                   \
	sum;                                               \
})

#define ArrayMin(arr,start,len) ({                     \
	__typeof__(len)   l_len   = (len);                 \
	__typeof__(start) l_start = (start);               \
	float min = FLT_MAX;                               \
	for (size_t i = l_start; i < l_len+l_start; i++) { \
		float val = (arr)[i];                          \
		if (min > val)                                 \
			min = val;                                 \
	}                                                  \
	min;                                               \
})

#define ArrayMax(arr,start,len) ({                     \
	__typeof__(len)   l_len   = (len);                 \
	__typeof__(start) l_start = (start);               \
	float max = FLT_MIN;                               \
	for (size_t i = l_start; i < l_len+l_start; i++) { \
		float val = (arr)[i];                          \
		if (max < val)                                 \
			max = val;                                 \
	}                                                  \
	max;                                               \
})

#define COMPAR(a,b) ((*a)<(*b))
#define ArraySort(dst,src,start,len) do {            \
	__typeof__(len)   l_len   = (len);               \
	__typeof__(start) l_start = (start);             \
	for (size_t i = 0; i < l_len; i++) {             \
		(dst)[i] = (src)[i+l_start];                 \
	}                                                \
	QSORT(__typeof__(*(dst)), (dst), l_len, COMPAR); \
} while(0)


//
// cstdlib wrappers
//

float acosd(float val);
float asind(float val);
float atand(float val);
float cosd(float val);
float sind(float val);
float tand(float val);
float coshd(float val);
float sinhd(float val);
float tanhd(float val);
float atan2d(float val1, float val2);
bool isNAN(float val);

#endif
