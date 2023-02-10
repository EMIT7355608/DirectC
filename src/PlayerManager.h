#pragma once
#include <stdbool.h>
#include "GameObject.h"
/**************
包含关于游戏中被控制主体player的参数
***************/
typedef struct PlayerManager
{
    int HP;
}PlayerManager;

/**************
包含关于游戏中被控制主体player的参数
***************/
extern PlayerManager playerManager;

/**************
初始化player
参数：无
返回值：无
***************/
void InitPlayer();