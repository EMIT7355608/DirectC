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
初始化输入的Transform对象
参数：Transform* trs：需定义的Transform对象
float x,float y,int w,int h：Transform对象的系数
返回值：无
*******************************************/
void DefineTransform(Transform* trs,float x,float y,int w,int h);

/******************************************
获得新定义的SDL_Rect对象，类似于new SDL_Rect
参数：SDL_Rect的参数
返回值：新定义的SDL_Rect对象
*******************************************/
SDL_Rect GetRect(int x,int y,int w,int h);

/******************************************
在每次Update之后调用，将Transform的更改同步到drRect
参数：GameObject *object：需同步的游戏对象
返回值：无
*******************************************/
void SyncTransform(GameObject *object);

/******************************************
初始化SDL、窗口、游戏对象、事件系统等
参数：无
返回值：无
*******************************************/
void Initialize();
#endif