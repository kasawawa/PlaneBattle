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
#define bound_right 1600	//右边界
#define bound_bottom 900	//左边界
#define MAXENERMYNUM 10		// 同时存在于界面中的最大敌人数
#define MAXLEVELNUM 4		// 关卡总数


extern int Flag;
extern User user;
extern Volume bgm;
extern Sound audio;		// 音效
extern int rtnFlag;		////明雅流风//// (退-1)  无0  l1  m2  p3 
extern bool isSound;
extern ExMessage msg;
extern const clock_t FPS;
extern ISoundEngine* engine;

// 其他全局函数的声明...
void Register_View();		// 注册
void Login_View();			// 登录
void Opening_plot(const char* file_path);	//开场动画
void Menu_View();			// 菜单
void displayInstructions();	//游戏玩法说明
void Menu_Setting_View();	// 菜单的设置
void levelselectview();		// 选关
void Select_Plant_view();	// 选植物
void drawTextInRect(int x, int y, int width, int height, const std::string& text, COLORREF textColor = BLACK, COLORREF bgColor = WHITE);	//选择植物展示
void gamesetting();			// 游戏中的设置
bool pauseview();			// 暂停
void winView(int score, int Level);		// 胜利
void loseView(int score);	// 失败
