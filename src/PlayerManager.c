#define _CRT_SECURE_NO_WARNINGS 1
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "GameObject.h"
#include "GameManager.h"
#include "Init.h"
#include"SaveAndLoad.h"
#include"EventManager.h"


typedef struct PlayerManager
{
    int HP;
}PlayerManager;

PlayerManager playerManager;



void PlayerUpdate(GameObject* object) {
    SyncTransform(player);
}

void InitPlayer() {
	player = (GameObject*)calloc(1,sizeof(GameObject));
	if (player == NULL) { printf("Fatal Error: Memory Execption"); return; }
	player->info = defaultInfo();
	player->info.name = 'p';
	player->next = NULL;
	player->prv = NULL;
	DefineTransform(&player->transform, 0, 0, 128, 128);
	player->Update = PlayerUpdate;
	player->animation.pics[0] = LoadTexture("Assets/Default/default.png");
	SetAnimation(&player->animation, 0, 10, 1);
	player->colliderBox.n = 1;
	player->colliderBox.box[0] = GetRect(0, 0, 128, 128);
}