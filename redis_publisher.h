#ifndef __REDIS_PUBLISHER_H__
#define __REDIS_PUBLISHER_H__
#include <stdio.h>
#include <stdlib.h>
#include <hiredis/adapters/libevent.h>
#include <string.h>
#include <signal.h>
#include <semaphore.h>

typedef struct {
	struct event_base* e_base;
	sem_t	e_sem;
}Semevent, *PSemevent;

int init_semevent(PSemevent pse);

int release_semevent(PSemevent pse);

int publish(const char* channel, const char* str);

int init_publisher();

int release_publisher();

//void* event_proc();

void* event_thread(void* data);

void command_callback(redisAsyncContext* ctx, void* reply, void* privdata);

void connect_callback(const redisAsyncContext* ctx, int status);

void disconnect_callback(const redisAsyncContext* ctx, int status);

#endif
