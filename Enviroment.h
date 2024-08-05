// globals.h
#pragma once

#include <list>
#include <cmath>
#include <memory>
#include <string>
#include <time.h>
#include <vector>
#include <conio.h>
#include <easyx.h>
#include <fstream>
#include <utility>
#include <iostream>
#include <stdlib.h>
#include <graphics.h>
#include <irrKlang.h>
#include <mmsystem.h>
#include <functional>
#include "Boss.h"
#include "game.h"
#include "User.h"
#include "Level.h"
#include "Bullet.h"
#include "Button.h"
#include "Enermy.h"
#include "Player.h"
#include "Enermy.h"
#include "MenuSetting.h"
#include "quintessence.h"
#include "Button_xiaoxin.h"
#include "Widget_xiaoxin.h"

using namespace irrklang;

#define WIDTH 1600
#define HEIGHT 900
#define bound_right 1600	//�ұ߽�
#define bound_bottom 900	//��߽�
#define MAXENERMYNUM 10		// ͬʱ�����ڽ����е���������
#define MAXLEVELNUM 4		// �ؿ�����


extern int Flag;
extern User user;
extern Volume bgm;
extern Sound audio;		// ��Ч
extern int rtnFlag;		////��������//// (��-1)  ��0  l1  m2  p3 
extern bool isSound;
extern ExMessage msg;
extern const clock_t FPS;
extern ISoundEngine* engine;

// ����ȫ�ֺ���������...
void Register_View();		// ע��
void Login_View();			// ��¼
void Opening_plot(const char* file_path);	//��������
void Menu_View();			// �˵�
void displayInstructions();	//��Ϸ�淨˵��
void Menu_Setting_View();	// �˵�������
void levelselectview();		// ѡ��
void Select_Plant_view();	// ѡֲ��
void drawTextInRect(int x, int y, int width, int height, const std::string& text, COLORREF textColor = BLACK, COLORREF bgColor = WHITE);	//ѡ��ֲ��չʾ
void gamesetting();			// ��Ϸ�е�����
bool pauseview();			// ��ͣ
void winView(int score, int Level);		// ʤ��
void loseView(int score);	// ʧ��
