#define _CRT_SECURE_NO_WARNINGS 1
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<SDL2/SDL_ttf.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "GameObject.h"
#include "Init.h"
#include "GameManager.h"
#include"PlayerManager.h"


TTF_Font* font0;
TTF_Font* font1;
void Write(int x,int y,TTF_Font* font,char* text,SDL_Color color);

void InitUI() {
    font0 = TTF_OpenFont("Assets/Font/NaikaiFont-Light.ttf", 36);
    if (!font0) {
        printf("TTF_OpenFont: %s\n", TTF_GetError());
    }
    font1 = TTF_OpenFont("Assets/Font/NaikaiFont-Light.ttf", 72);
    if (!font1) {
        printf("TTF_OpenFont: %s\n", TTF_GetError());
    }
}

void RenderUI(SDL_Renderer* renderer){
    SDL_Color cr0={30,30,30,255};
    char line[50]={0};
    sprintf(line,"score:%.6d",0);
    Write(windowWidth-400,20,font0,line,cr0);
}

void Write(int x,int y,TTF_Font* font,char* text,SDL_Color color){
    SDL_Surface *img;
    img = TTF_RenderUTF8_Solid(font, text, color); 
    SDL_Texture* texture=SDL_CreateTextureFromSurface(renderer,img);
    SDL_Rect rec={x,y,img->w,img->h};
    SDL_RenderCopy(renderer,texture,NULL,&rec);
    SDL_FreeSurface(img);
    SDL_DestroyTexture(texture);
}
