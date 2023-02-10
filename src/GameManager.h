#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H
#include <stdbool.h>
#include "GameObject.h"

/**************
������Ϸȫ���¼�
***************/
typedef struct GameManager
{
    int chapter;
    bool pause;
    bool lose;
}GameManager;

/**************
������Ϸȫ���¼�
***************/
GameManager gameManager;

/**************
֡�����¼�
��������
����ֵ����
***************/
void FrameController();

/**************
��ͣ�����ã�������ͣϵͳ
��������
����ֵ����
***************/
void PauseController();

/**************
���¿�ʼ��Ϸ
��������
����ֵ����
***************/
void StartOver();

/**************
��ʼ����Ϸ����
��������
����ֵ����
***************/
void SetParameter();

#endif