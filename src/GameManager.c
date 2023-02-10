#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "GameObject.h"
#include "PlayerManager.h"
#include "ObjectList/Generator.h"
#include "SaveAndLoad.h"
#include "ChapterManager.h"
#include "Init.h"

typedef struct GameManager
{
    int chapter;
    bool pause;
    bool lose;
}GameManager;

extern GameManager gameManager;

void SetParameter(){
    playerManager.HP = 4;
    srand((unsigned)time(NULL));
    Load();
    LoadChapter(0);
}

void StartOver(){
    player->next=NULL;
    SetParameter();
}


void FrameController() {

}

void PauseController(){
    if(gameManager.pause){
        if(!gameManager.lose){
            gameManager.pause=false;
        }
    }else{
        gameManager.pause=true;
    }
}

