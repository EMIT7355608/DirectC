#pragma once
#include <SDL2/SDL_mixer.h>
/**************
背景音乐管理器
***************/
typedef struct BGMManager
{
    Mix_Chunk* backgroundMusics[10];
    float contTime[10];
    int BGMamount;
    int pin;
    float tick;
}BGMManager;

/**************
背景音乐管理器
***************/
BGMManager bgmManager;

/**************
播放指定背景音乐
参数：int n：指定背景音乐的序号
返回值：无
***************/
void BGMPlay(int n);
/**************
初始化背景音乐
参数：无
返回值：无
***************/
void InitBGM();
/**************
背景音乐系统的帧事件
参数：无
返回值：无
***************/
void BGMProcess();

