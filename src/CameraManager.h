#pragma once

#include "GameObject.h"

/**************
相机管理器
***************/
typedef struct
{
    int dx, dy;
    GameObject window;
    GameObject* targect;
}CameraManager;

/**************
相机管理器
***************/
CameraManager cameraManager;

/**************
初始化相机
参数：无
返回值：无
***************/
void InitCamera();

/**************
相机跟随目标游戏对象
参数：无
返回值：无
***************/
void SyncCamera();