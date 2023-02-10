#define _CRT_SECURE_NO_WARNINGS 1
#include "GameObject.h"
#include "GameManager.h"
#include "Init.h"

typedef struct
{
    int dx,dy;
    GameObject window;
    GameObject* target;
}CameraManager;

CameraManager cameraManager;
extern float reSize;
void InitCamera() {
    cameraManager.target = player;
    cameraManager.dx = -100;
    cameraManager.window.colliderBox.n = 1;
    cameraManager.window.colliderBox.box[0].w = (int)(windowWidth / reSize);
    cameraManager.window.colliderBox.box[0].h = (int)(windowHeight / reSize);
    cameraManager.window.colliderBox.box[0].x = 0;
    cameraManager.window.colliderBox.box[0].y = deltaY-setWindowHeight;
    cameraManager.window.transform.x = 0;
    cameraManager.window.transform.y = 0;
}

void SyncCamera() {
    cameraManager.window.transform.x = player->transform.x;
    cameraManager.window.transform.drRect.x = (int)(cameraManager.window.transform.x * reSize);
//    cameraManager.window.transform.x+= gameManager.overAllSpeed * deltaTime-1;
}