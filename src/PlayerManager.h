#pragma once
#include <stdbool.h>
#include "GameObject.h"
/**************
����������Ϸ�б���������player�Ĳ���
***************/
typedef struct PlayerManager
{
    int HP;
}PlayerManager;

/**************
����������Ϸ�б���������player�Ĳ���
***************/
extern PlayerManager playerManager;

/**************
��ʼ��player
��������
����ֵ����
***************/
void InitPlayer();