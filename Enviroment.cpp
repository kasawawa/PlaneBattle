#include "Enviroment.h"

// ����ȫ�ֱ�������ʼ��
User user;

Volume bgm;

int rtnFlag;		////��������//// (��-1)  ��0  l1  m2  p3

Sound audio;

int Flag = -1;

ExMessage msg;

bool isSound = true;

const clock_t FPS = 1000 / 60;

ISoundEngine* engine = nullptr;
