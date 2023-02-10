#define _CRT_SECURE_NO_WARNINGS 1
#include "../Init.h"
#include "../GameObject.h"

GameObject DefaultObjcet;

void InitDefaultObjcet() {
    DefaultObjcet.info = defaultInfo();
    DefaultObjcet.animation.pics[0] = LoadTexture("Assets/Default/default.png");
    SetAnimation(&DefaultObjcet.animation, 1, 10, 1);
    DefineTransform(&DefaultObjcet.transform, 0, 0, 128, 128);
    DefaultObjcet.colliderBox.n = 1;
    DefaultObjcet.colliderBox.box[0]= GetRect(0, 0, 128, 128);
}

void DefaultObjcetUpdate(GameObject* object) {

    SyncTransform(object);
}

void GenerateDefaultObjcet(int index, int x, int y) {
    Transform newTransform = DefaultObjcet.transform;
    newTransform.x = x; newTransform.y = y;
    SyncTransform(InitObject(newTransform, DefaultObjcet.animation, DefaultObjcet.colliderBox, DefaultObjcetUpdate, DefaultObjcet.info));
}