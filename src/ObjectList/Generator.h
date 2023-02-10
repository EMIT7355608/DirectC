#pragma once

/**************
初始化所有集成生成的游戏对象
参数：无
返回值：无
***************/
void InitGenerator();

/**************
集成生成游戏对象
参数：int kind：游戏对象分类
int index：游戏对象系数
int x, int y：生成位置坐标
返回值：无
***************/
void Generate(int kind, int index, int x, int y);