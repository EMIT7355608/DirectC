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
��Ϸ��������ͣ����������
***************/
enum Types {
    Default = -1
};

/**************
��Ϸ����ı����Ϣ
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
��Ϸ����Ķ���
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
��Ϸ�����λ�á�������Ϣ
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
��Ϸ�������ײ��
***************/
typedef struct ColliderBox
{
    /* data */
    int n;
    SDL_Rect box[5];
}ColliderBox;

/**************
��Ϸ����˫�������һ��
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
��ҿ��Ƶ���Ϸ������Ϸ���������ͷ
***************/
GameObject* player;

/**************
�����Ϸ�����Ƿ��ص�
������GameObject* o1,GameObject* o2����������Ϸ����
����ֵ�����ص�����True�����򷵻�False
***************/
bool ColliderDetermine(GameObject* o1,GameObject* o2);

/**************
��ȡĬ�ϵ���Ϸ��������Ϣ
��������
����ֵ��Ĭ�ϵ���Ϸ��������Ϣ
***************/
Info defaultInfo();

/**************
����ͼƬ
������char* path��ͼƬ�����·��
����ֵ��SDL_Texture*��SDL_TextureͼƬ��ָ��
***************/
SDL_Texture* LoadTexture(char* path);

/**************
�ڿ���̨�����Ϸ�������Ϣ
������GameObject* object����Ϸ����
����ֵ����
***************/
void GameObjectInfo(GameObject* object);

/**************
��ʼ������
������Animation* animation������ʼ���Ķ���
int layer��������ͼ��
int framePic������ͼƬ���֡��
int picN������ͼƬ����
����ֵ����
***************/
void SetAnimation(Animation* animation, int layer, int framePic, int picN);

/**************
����Ϸ������Ⱦ������
������SDL_Renderer* renderer�����ڵ�Renderer��ָ��
GameObject* object������Ⱦ����Ϸ����
����ֵ����
***************/
void RenderObject(SDL_Renderer* renderer,GameObject* object);

/**************
ɾ����Ϸ����
������GameObject* object����ɾ������Ϸ����
����ֵ����
***************/
void DestroyObject(GameObject* object);

/**************
������Ϸ����
������Transform transfrom����Ϸ�����λ�á�������Ϣ
Animation animation����Ϸ����Ķ���
ColliderBox colliderBox����Ϸ�������ײ��
UpdateFunction update����Ϸ����ÿִ֡�еĺ���
Info info����Ϸ����ı����Ϣ
����ֵ��
***************/
GameObject* InitObject(Transform transfrom,Animation animation,ColliderBox colliderBox,UpdateFunction update,Info info);

#endif