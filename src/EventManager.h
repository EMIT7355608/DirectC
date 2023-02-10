#pragma once
#include "Init.h"
#include "GameObject.h"

typedef struct Event Event;

/**************
��Ϸ�¼�����ָ��ʱ��֮�󴥷��¼������Զ�δ���
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
��ʼ����Ϸ�¼�ϵͳ
��������
����ֵ����
***************/
void EventInit();

/**************
������Ϸ�¼�������һ��
������float time���ӳ�ʱ��
void (*order)(GameObject*)���������¼�
GameObject* object��order�Ĳ��������¼�������
����ֵ����
***************/
void AddEvent(float time, void (*order)(GameObject*), GameObject* object);

/**************
������Ϸ�¼����������
������float time���ӳ�ʱ��
void (*order)(GameObject*)���������¼�
GameObject* object��order�Ĳ��������¼�������
int n�������Ĵ���
����ֵ����
***************/
void AddEventxN(float time, void (*order)(GameObject*), GameObject* object, int n);

/**************
��Ϸ�¼�ϵͳ֡�¼�
��������
����ֵ����
***************/
void EventFrameTime();