#define _CRT_SECURE_NO_WARNINGS 1
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<SDL2/SDL_ttf.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "GameObject.h"
#include "GameManager.h"
#include "EventManager.h"
#include "PlayerManager.h"
#include "CameraManager.h"
#include "ObjectList/Generator.h"
#include "BGMManager.h"

void SyncTransform(GameObject *playerObject);

SDL_Window* win;
SDL_Renderer* renderer = NULL;
SDL_Surface* defaultImg;
int windowWidth,windowHeight;
const int deltaY=952;
const int setWindowHeight = 1080;
float reSize=1;
const int FPS=60;
float deltaTime;


SDL_DisplayMode DM;

int DrawSize(float s){return (int)(s*reSize);}

int drawnX(float x){return (int)(x*reSize);}

int drawnY(float y){return DrawSize(deltaY-y);}

SDL_Texture* test;

SDL_Texture* HP[4];

void SyncTransform(GameObject* object) {
	object->transform.drRect.x=drawnX(object->transform.x);
	object->transform.drRect.y=drawnY(object->transform.y)- object->transform.drRect.h;
}

void DefineTransform(Transform* trs,float x,float y,int w,int h){
	trs->x = x; trs->y = y;
    trs->vx = 0; trs->vy = 0;
	trs->drRect.x=drawnX(x);
	trs->drRect.y=drawnY(y+h);
	trs->drRect.w=DrawSize(w);
	trs->drRect.h=DrawSize(h);
}

SDL_Rect GetRect(int x,int y,int w,int h){
	SDL_Rect rec={x,y,w,h};
	return rec;
}

extern void InitUI();

void InitWindow() {
	deltaTime=(float)1.0/FPS;
	SDL_GetCurrentDisplayMode(0, &DM);
	win = SDL_CreateWindow("DefaultWindow", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, DM.w,DM.h-30, SDL_WINDOW_SHOWN);
	SDL_GetWindowSize(win,&windowWidth,&windowHeight);
	reSize = (float)windowHeight / (float)setWindowHeight;
	renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	SDL_SetRenderDrawColor(renderer,99,99,99,255);
}

void Initialize(){
	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();
	InitWindow();
	InitPlayer();
	EventInit();
	InitGenerator();
    InitBGM();
	InitUI();
    InitCamera();
	SetParameter();
}
