#pragma once

#include "GameObject.h"

/**************
���������
***************/
typedef struct
{
    int dx, dy;
    GameObject window;
    GameObject* targect;
}CameraManager;

/**************
���������
***************/
CameraManager cameraManager;

/**************
��ʼ�����
��������
����ֵ����
***************/
void InitCamera();

/**************
�������Ŀ����Ϸ����
��������
����ֵ����
***************/
void SyncCamera();