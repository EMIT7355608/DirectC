#pragma once
#include <SDL2/SDL_mixer.h>
/**************
�������ֹ�����
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
�������ֹ�����
***************/
BGMManager bgmManager;

/**************
����ָ����������
������int n��ָ���������ֵ����
����ֵ����
***************/
void BGMPlay(int n);
/**************
��ʼ����������
��������
����ֵ����
***************/
void InitBGM();
/**************
��������ϵͳ��֡�¼�
��������
����ֵ����
***************/
void BGMProcess();

