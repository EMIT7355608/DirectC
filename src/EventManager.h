#pragma once
#include "Init.h"
#include "GameObject.h"

typedef struct Event Event;

/**************
游戏事件，在指定时间之后触发事件，可以多次触发
***************/
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

extern Event head;

/**************
初始化游戏事件系统
参数：无
返回值：无
***************/
void EventInit();

/**************
新增游戏事件，触发一次
参数：float time：延迟时间
void (*order)(GameObject*)：触发的事件
GameObject* object：order的参数，即事件的主体
返回值：无
***************/
void AddEvent(float time, void (*order)(GameObject*), GameObject* object);

/**************
新增游戏事件，触发多次
参数：float time：延迟时间
void (*order)(GameObject*)：触发的事件
GameObject* object：order的参数，即事件的主体
int n：触发的次数
返回值：无
***************/
void AddEventxN(float time, void (*order)(GameObject*), GameObject* object, int n);

/**************
游戏事件系统帧事件
参数：无
返回值：无
***************/
void EventFrameTime();