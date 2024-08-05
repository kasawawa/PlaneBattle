#include "Enviroment.h"

// 定义全局变量并初始化
User user;

Volume bgm;

int rtnFlag;		////明雅流风//// (退-1)  无0  l1  m2  p3

Sound audio;

int Flag = -1;

ExMessage msg;

bool isSound = true;

const clock_t FPS = 1000 / 60;

ISoundEngine* engine = nullptr;
