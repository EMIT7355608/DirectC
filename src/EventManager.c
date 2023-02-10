#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include "Init.h"
#include "GameObject.h"

typedef struct Event Event;

typedef struct Event
{
	float countTime;
    float time;
    int n;
	void (*order)(GameObject*);
	GameObject* object;
	Event* prv;
	Event* next;
}Event;

Event head;

void EventInit() {
	head.next = NULL;
}

void AddEventxN(float time, void (*order)(GameObject*), GameObject* object,int n) {
    Event* newEvent = (Event*)malloc(sizeof(Event));
    Event* next = head.next;
    newEvent->countTime = time;
    newEvent->time = time;
    newEvent->n = n;
    newEvent->order = order;
    newEvent->object = object;
    newEvent->next = next;
    newEvent->prv = &head;
    if (next != NULL) {
        next->prv = newEvent;
    }
    head.next = newEvent;
}

void AddEvent(float time, void (*order)(GameObject*), GameObject* object) {
	Event* newEvent = (Event*)malloc(sizeof(Event));
	Event* next = head.next;
	newEvent->countTime = time;
    newEvent->time = time;
    newEvent->n = 1;
	newEvent->order = order;
	newEvent->object = object;
	newEvent->next = next;
	newEvent->prv = &head;
	if (next != NULL) {
		next->prv = newEvent;
	}
	head.next = newEvent;
}

void EventFrameTime() {
	Event* pinEvent=head.next;
	while (pinEvent!=NULL)
	{
		pinEvent->time -= deltaTime;
		while (pinEvent->time <= 0) {
            pinEvent->n--; 
            pinEvent->time += pinEvent->countTime;
            pinEvent->order(pinEvent->object);
            if (pinEvent->n <= 0) {
                Event* prv = pinEvent->prv;
                Event* next = pinEvent->next;
                prv->next = next;
                if (next != NULL) {
                    next->prv = prv;
                }
                break;
            }
		}
		pinEvent = pinEvent->next;
	}
}