#pragma once
#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct GameObject GameObject;
typedef void (*UpdateFunction)(GameObject *);

/**************
游戏对象的类型，可自行添加
***************/
enum Types {
    Default = -1
};

/**************
游戏对象的标记信息
***************/
typedef struct Info{
    char name;
    int type;
    int index;
    int health;
    int tick;
    float v;
    bool activated;
    /* data */
}Info;


/**************
游戏对象的动画
***************/
typedef struct Animation
{
    int layer;
    int framePic;
    int frameCount;
    int picN;
    int picCount;
    SDL_Texture* pics[5];
}Animation;

/**************
游戏对象的位置、缩放信息
***************/
typedef struct Transform
{
    SDL_Rect drRect;
    float x;
    float y;
    float vx;
    float vy;
}Transform;

/**************
游戏对象的碰撞箱
***************/
typedef struct ColliderBox
{
    /* data */
    int n;
    SDL_Rect box[5];
}ColliderBox;

/**************
游戏对象，双向链表的一节
***************/
typedef struct GameObject{
    Transform transform;
    Animation animation;
    ColliderBox colliderBox;
    UpdateFunction Update;
    Info info;
    GameObject* next;
    GameObject* prv;
}GameObject;

/**************
玩家控制的游戏对象，游戏对象链表的头
***************/
GameObject* player;

/**************
检测游戏对象是否重叠
参数：GameObject* o1,GameObject* o2：被检测的游戏对象
返回值：若重叠返回True，否则返回False
***************/
bool ColliderDetermine(GameObject* o1,GameObject* o2);

/**************
获取默认的游戏对象标记信息
参数：无
返回值：默认的游戏对象标记信息
***************/
Info defaultInfo();

/**************
加载图片
参数：char* path：图片的相对路径
返回值：SDL_Texture*：SDL_Texture图片的指针
***************/
SDL_Texture* LoadTexture(char* path);

/**************
在控制台输出游戏对象的信息
参数：GameObject* object：游戏对象
返回值：无
***************/
void GameObjectInfo(GameObject* object);

/**************
初始化动画
参数：Animation* animation：被初始化的动画
int layer：动画的图层
int framePic：两张图片间的帧数
int picN：动画图片总数
返回值：无
***************/
void SetAnimation(Animation* animation, int layer, int framePic, int picN);

/**************
将游戏对象渲染到窗口
参数：SDL_Renderer* renderer：窗口的Renderer的指针
GameObject* object：被渲染的游戏对象
返回值：无
***************/
void RenderObject(SDL_Renderer* renderer,GameObject* object);

/**************
删除游戏对象
参数：GameObject* object：被删除的游戏对象
返回值：无
***************/
void DestroyObject(GameObject* object);

/**************
新增游戏对象
参数：Transform transfrom：游戏对象的位置、缩放信息
Animation animation：游戏对象的动画
ColliderBox colliderBox：游戏对象的碰撞箱
UpdateFunction update：游戏对象每帧执行的函数
Info info：游戏对象的标记信息
返回值：
***************/
GameObject* InitObject(Transform transfrom,Animation animation,ColliderBox colliderBox,UpdateFunction update,Info info);

#endif