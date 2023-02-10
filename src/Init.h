#ifndef INIT_H
#define INIT_H

#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include <stdbool.h>
#include "GameObject.h"

extern const int deltaY;
extern const int setWindowHeight;

extern SDL_Window* win;
extern SDL_Renderer* renderer;
extern const int FPS;
extern float deltaTime;
int windowWidth,windowHeight;
extern SDL_Texture* HP[4];

/******************************************
��ʼ�������Transform����
������Transform* trs���趨���Transform����
float x,float y,int w,int h��Transform�����ϵ��
����ֵ����
*******************************************/
void DefineTransform(Transform* trs,float x,float y,int w,int h);

/******************************************
����¶����SDL_Rect����������new SDL_Rect
������SDL_Rect�Ĳ���
����ֵ���¶����SDL_Rect����
*******************************************/
SDL_Rect GetRect(int x,int y,int w,int h);

/******************************************
��ÿ��Update֮����ã���Transform�ĸ���ͬ����drRect
������GameObject *object����ͬ������Ϸ����
����ֵ����
*******************************************/
void SyncTransform(GameObject *object);

/******************************************
��ʼ��SDL�����ڡ���Ϸ�����¼�ϵͳ��
��������
����ֵ����
*******************************************/
void Initialize();
#endif