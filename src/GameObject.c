#pragma once
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct GameObject GameObject;
typedef void (*UpdateFunction)(GameObject *);

enum Types {
    Default=-1
};

typedef struct Info
{
    char name;
    int type;
    int index;
    int health;
	int tick;
    float v;
	bool activated;
}Info;


typedef struct Animation
{
    int layer;
    int framePic;
    int frameCount;
    int picN;
    int picCount;
    SDL_Texture* pics[5];
}Animation;

typedef struct Transform
{
    SDL_Rect drRect;
    float x;
    float y;
    float vx;
    float vy;
}Transform;

typedef struct ColliderBox
{
    int n;
    SDL_Rect box[5];
}ColliderBox;

typedef struct GameObject
{
    Transform transform;
    Animation animation;
    ColliderBox colliderBox;
    UpdateFunction Update;
    Info info;
    GameObject* next;
    GameObject* prv;
}GameObject;

GameObject* player;
bool ColliderDetermine(GameObject* o1, GameObject* o2);

typedef struct
{
    int dx, dy;
    GameObject window;
    GameObject* targect;
}CameraManager;

extern CameraManager cameraManager;

void GameObjectInfo(GameObject* object) {
    printf("Info: \n name;%c\nint type;%d \nint index;%d\nint health;%d\nint tick;%d\n float v;%f\nbool activated;%d\n"
        , object->info.name, object->info.type, object->info.index, object->info.health, object->info.tick, object->info.v, object->info.activated);
    printf("Transform:\n    SDL_Rect drRect; x:%d y:%d w:%d h:%d\n float x;%f\n  float y;%f\n  float vx;%f\n  float vy;%f \n"
    ,object->transform.drRect.x, object->transform.drRect.y, object->transform.drRect.w, object->transform.drRect.h, object->transform.x
        , object->transform.y, object->transform.vx, object->transform.vy);
    printf("Colliderbox: \nn:%d\nb1x:%d\nb1y:%d\nb1w:%d\nb1h:%d\n",object->colliderBox.n, object->colliderBox.box[0].x
        , object->colliderBox.box[0].y, object->colliderBox.box[0].w, object->colliderBox.box[0].h);
}

void RenderObject(SDL_Renderer* renderer,GameObject* object){
    /*
    GameObjectInfo(object);
    GameObjectInfo(&cameraManager.window);*/
    if(ColliderDetermine(object,&cameraManager.window)){
        SDL_Rect drRect = object->transform.drRect;
        drRect.x -= cameraManager.window.transform.drRect.x;
        drRect.y -= cameraManager.window.transform.drRect.y;
        SDL_RenderCopy(renderer, object->animation.pics[object->animation.picCount]
            , NULL, &drRect);
        object->animation.frameCount++;
        if (object->animation.frameCount >= object->animation.framePic) {
            object->animation.frameCount = 0;
            object->animation.picCount++;
            if (object->animation.picCount >= object->animation.picN) {
                object->animation.picCount = 0;
            }
        } 
    }
}

Info defaultInfo() {
    Info d;
    d.activated = false;
    d.health = 0;
    d.name = '\0';
    d.index = 0;
    d.type = Default;
    d.tick = 0;
    d.v = 0;
    return d;
}

bool ColliderDetermine(GameObject* o1,GameObject* o2){
    for(int i=0;i<o1->colliderBox.n;i++){
        for(int j=0;j<o2->colliderBox.n;j++){
            int x1=o1->transform.x+o1->colliderBox.box[i].x;
            int y1=o1->transform.y+o1->colliderBox.box[i].y;
            int w1=o1->colliderBox.box[i].w;
            int h1=o1->colliderBox.box[i].h;
            int x2=o2->transform.x+o2->colliderBox.box[j].x;
            int y2=o2->transform.y+o2->colliderBox.box[j].y;
            int w2=o2->colliderBox.box[j].w;
            int h2=o2->colliderBox.box[j].h;
            if(abs((x1+w1/2)-(x2+w2/2))<(w1+w2)/2&&abs((y1+h1/2)-(y2+h2/2))<(h1+h2)/2){
                return true;
            }
        }
    }
    return false;
}

void CountObject(){
	int c=0;
	GameObject* pinObject=player;
	while (pinObject!=NULL)
	{
		if(pinObject->info.name=='g'){c++;}
		pinObject=pinObject->next;
	}
    printf("\nObjects:%d\n",c);
}

void DestroyObject(GameObject* object){
    GameObject* prvObject=object->prv;
    GameObject* nextObject=object->next;
    if(nextObject!=NULL){nextObject->prv=prvObject;}
    prvObject->next=nextObject;
}

extern SDL_Renderer* renderer;

SDL_Texture* LoadTexture (char* path) {
    SDL_Surface* defaultImg = IMG_Load("Assets/Default/default.png");
    SDL_Surface* img;
    img = IMG_Load(path);
    if (img == NULL) { img = defaultImg; }
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, img);
    if (img != NULL) { SDL_FreeSurface(img); }
    if (defaultImg != NULL) { SDL_FreeSurface(defaultImg); }
    return texture;
}

void SetAnimation(Animation* animation,int layer,int framePic,int picN) {
    animation->layer = layer;
    animation->framePic = framePic;
    animation->picN = picN;
}

GameObject* getObject(){
    GameObject* newObject;
    newObject=(GameObject*)calloc(1,sizeof(GameObject));
    return newObject;
}

GameObject* InitObject(Transform transfrom,Animation animation,ColliderBox colliderBox,UpdateFunction update,Info info){
    GameObject* newObject;
    newObject=getObject();
    newObject->info=info;
    newObject->animation=animation;
    newObject->transform=transfrom;
    newObject->colliderBox=colliderBox;
    newObject->Update=update;
    GameObject* nextObject=player->next;
    newObject->prv=player;
    newObject->next=nextObject;
    if(nextObject!=NULL){nextObject->prv=newObject;}
    player->next=newObject;
    return newObject;
}