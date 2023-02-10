#define _CRT_SECURE_NO_WARNINGS 1
#include <SDL2/SDL_mixer.h>
#include <stdio.h>
#include "Init.h"

typedef struct BGMManager
{
    Mix_Chunk* backgroundMusics[10];
    float contTime[10];
    int BGMamount;
    int pin;
    float tick;
}BGMManager;

BGMManager bgmManager;

void BGMPlay(int n) {
    Mix_PlayMusic(bgmManager.backgroundMusics[n], 0);
    bgmManager.pin = n;
    bgmManager.tick = 0;
}

void InitBGM() {
    Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 4096);
    bgmManager.BGMamount = 2;
    bgmManager.backgroundMusics[0] = Mix_LoadMUS("Assets/BGM/38_Dragon.wav");
    bgmManager.contTime[0] = 92;
    bgmManager.backgroundMusics[1] = Mix_LoadMUS("Assets/BGM/49_Ancient Dragon Lansseax.wav");
    bgmManager.contTime[1] = 123; 
    Mix_Volume(-1, 34);
    BGMPlay(0);
}

void BGMProcess() {
    bgmManager.tick += deltaTime;
    if (bgmManager.tick >= bgmManager.contTime[bgmManager.pin]) {
        BGMPlay((bgmManager.pin + 1)% bgmManager.BGMamount);
    }
}