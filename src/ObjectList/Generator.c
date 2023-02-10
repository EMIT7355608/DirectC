#define _CRT_SECURE_NO_WARNINGS 1
#include"../GameObject.h"

extern void InitDefaultObjcet();

extern void GenerateDefaultObjcet(int index, int x, int y);

void InitGenerator() {
    InitDefaultObjcet();
}

void Generate(int kind,int index,int x,int y) {
    switch (kind)
    {
    case Default:GenerateDefaultObjcet(index, x, y); break;
        default:GenerateDefaultObjcet(index, x, y);break;
    }
}