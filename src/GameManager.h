#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H
#include <stdbool.h>
#include "GameObject.h"

/**************
管理游戏全局事件
***************/
typedef struct GameManager
{
    int chapter;
    bool pause;
    bool lose;
}GameManager;

/**************
管理游戏全局事件
***************/
GameManager gameManager;

/**************
帧控制事件
参数：无
返回值：无
***************/
void FrameController();

/**************
暂停键调用，控制暂停系统
参数：无
返回值：无
***************/
void PauseController();

/**************
重新开始游戏
参数：无
返回值：无
***************/
void StartOver();

/**************
初始化游戏参数
参数：无
返回值：无
***************/
void SetParameter();

#endif