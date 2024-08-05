#include "Enviroment.h"

void levelselectview()
{
    IMAGE bg;
    IMAGE lockImage;  // 未解锁图片
    int levelstatus = user.get_Num_Of_isPassed_Level();//调用通关数量比赋值给levelstaus变量
    loadimage(&lockImage, _T("./src/locked.png"), 100, 100);
    loadimage(&bg, _T("./src/picture/Select_Level.jpg"), 1600, 900);

    while (!rtnFlag)		////明雅流风//// (退-1)  无0  l1  m2  p3
    {
		BeginBatchDraw();
        //设置填充颜色为浅蓝色，并绘制四个矩形，分别代表四个不同的区域
        putimage(0, 0, &bg);
        //setfillcolor(RGB(173, 216, 230));  
        setlinecolor(0xb4b4b4);
        setlinestyle(PS_SOLID, 5);
        setfillcolor(0x797455);
        fillroundrect(50, 50, 1600 - 50, 150, 10, 10);
        fillroundrect(230, 300, 610, 480, 10, 10);
        fillroundrect(1000, 300, 1380, 480, 10, 10);
        fillroundrect(230, 600, 610, 780, 10, 10);
        fillroundrect(1000, 600, 1380, 780, 10, 10);
        fillroundrect(0, 800, 100, 900, 10, 10);
        //设置字体样式和背景模式，并在指定位置输出文本 "第一关"、"第二关"、"第三关"、"第四关"
        settextstyle(100, 0, _T("Consolas"));
        outtextxy(750 - textwidth(_T("关  卡  选  择")) / 2, 50, _T("关  卡  选  择"));
        outtextxy(230 + (610 - 230) / 2 - textwidth(_T("第一关")) / 2, 300 + (480 - 300) / 2 - textheight(_T("第一关")) / 2, _T("第一关"));
        outtextxy(1000 + (1380 - 1000) / 2 - textwidth(_T("第二关")) / 2, 300 + (480 - 300) / 2 - textheight(_T("第二关")) / 2, _T("第二关"));
        outtextxy(230 + (610 - 230) / 2 - textwidth(_T("第三关")) / 2, 600 + (780 - 600) / 2 - textheight(_T("第三关")) / 2, _T("第三关"));
        outtextxy(1000 + (1380 - 1000) / 2 - textwidth(_T("第四关")) / 2, 600 + (780 - 600) / 2 - textheight(_T("第四关")) / 2, _T("第四关"));

        settextstyle(50, 0, "Consolas");
        settextcolor(0xFFFFFF);
        outtextxy(0, 800, "植物");
        outtextxy(0, 850, "选择");

		settextcolor(LIGHTMAGENTA);
		settextstyle(50, 0, "楷体");
		std::string score = "历史得分:【";
		score += std::to_string(user.get_History_Score());
		outtextxy(600,200, (score + "】").data());
		settextstyle(50, 0, "Consolas");
		settextcolor(0xFFFFFF);

        //获取鼠标消息并存储在 m 变量中
        msg = getmessage(EX_MOUSE);
        //如果鼠标位置在第某个矩形区域内，填充颜色变为深灰色，同时输出文本。如果鼠标左键按下，判断是否解锁，解锁后就直接跳转到游戏界面
        if (levelstatus <= 0) {
            setfillcolor(RGB(173, 216, 230));
            solidrectangle(1000, 300, 1380, 480);
            putimage((1000 + 1380) / 2 - 50, (300 + 480) / 2 - 50, &lockImage);
        }
        if (levelstatus <= 1) {
            setfillcolor(RGB(173, 216, 230));
            solidrectangle(230, 600, 610, 780);
            putimage((230 + 610) / 2 - 50, (600 + 780) / 2 - 50, &lockImage);
        }
        if (levelstatus <= 2) {
            setfillcolor(RGB(173, 216, 230));
            solidrectangle(1000, 600, 1380, 780);
            putimage((1000 + 1380) / 2 - 50, (600 + 780) / 2 - 50, &lockImage);
        }

		//处理鼠标在第一个矩形区域内的情况
        if (msg.x >= 0 && msg.y >= 800 && msg.x <= 100 && msg.y <= 900)
        {
            setfillcolor(DARKGRAY);
            fillroundrect(0, 800, 100, 900, 10, 10);
            settextstyle(50, 0, "Consolas");
            settextcolor(0xFFFFFF);
            outtextxy(0, 800, "植物");
            outtextxy(0, 850, "选择");
            if (msg.lbutton == true)
            {
                //植物选择
				rtnFlag = 3;		////明雅流风//// (退-1)  无0  l1  m2  p3
            }
        }

        //处理鼠标在第二个矩形区域内的情况
        if (msg.x >= 230 && msg.y >= 300 && msg.x <= 610 && msg.y <= 480)
        {
            if (levelstatus >= 0)
            {
                setfillcolor(DARKGRAY);
                settextstyle(136, 0, _T("Consolas"));
                solidrectangle(230, 300, 610, 480);
                outtextxy(231, 316, _T("第一关"));
                if (msg.lbutton == true)
                {
                    if (bgm.isMusicPlaying()) {
                        bgm.stopMusic();
                        bgm.playmusic("./src/music/play.mp3");
                    }
                    int x=gameview(0);
                    levelstatus = user.get_Num_Of_isPassed_Level();
                    if(x>user.get_History_Score()){
                        user.set_History_Score(x);
						//写入数据
                        user.save();
					}
                    if (bgm.isMusicPlaying()) {
                        bgm.stopMusic();
                        bgm.playmusic("./src/music/Select.mp3");
                    }
                }
            }
            else
            {
                setfillcolor(RGB(173, 216, 230));
                solidrectangle(230, 300, 610, 480);
                putimage((230 + 610) / 2 - 50, (300 + 480) / 2 - 50, &lockImage);
            }
        }

        // 处理鼠标在第三个矩形区域内的情况
        if (msg.x >= 1000 && msg.y >= 300 && msg.x <= 1380 && msg.y <= 480)
        {
            if (levelstatus >= 1)  // 只有通过第一关才能解锁第二关
            {
                setfillcolor(DARKGRAY);
                settextstyle(136, 0, _T("Consolas"));
                solidrectangle(1000, 300, 1380, 480);
                outtextxy(1001, 316, _T("第二关"));

                if (msg.lbutton == true)
                {
                    if (bgm.isMusicPlaying()) {
                        bgm.playmusic("./src/music/play.mp3");
                    }
                    int x=gameview(1);
                    levelstatus = user.get_Num_Of_isPassed_Level();
                    if (bgm.isMusicPlaying()) {
                        bgm.playmusic("./src/music/Select.mp3");
                    }
                    if (x > user.get_History_Score()) {
                        user.set_History_Score(x);
                        //写入数据
                        user.save();
                    }
                }
            }
            else
            {
                setfillcolor(RGB(173, 216, 230));
                solidrectangle(1000, 300, 1380, 480);
                putimage((1000 + 1380) / 2 - 50, (300 + 480) / 2 - 50, &lockImage);
            }
        }

        // 处理鼠标在第四个矩形区域内的情况
        if (msg.x >= 230 && msg.y >= 600 && msg.x <= 610 && msg.y <= 780)
        {
            if (levelstatus >= 2)  // 只有通过第二关才能解锁第三关
            {
               setfillcolor(DARKGRAY);
                settextstyle(136, 0, _T("Consolas"));
                solidrectangle(230, 600, 610, 780);
                outtextxy(231, 616, _T("第三关"));
                
                if (msg.lbutton == true)
                {
                    if (bgm.isMusicPlaying()) {
                        bgm.stopMusic();
                        bgm.playmusic("./src/music/play.mp3");
                    }
                    int x=gameview(2);
                    // 跳转到第三关
                    levelstatus = user.get_Num_Of_isPassed_Level();
                    if (bgm.isMusicPlaying()) {
                        bgm.playmusic("./src/music/Select.mp3");
                    }
                    if (x > user.get_History_Score()) {
                        user.set_History_Score(x);
                        //写入数据
                        user.save();
                    }
                }
            }
            else
            {
                setfillcolor(RGB(173, 216, 230));
                solidrectangle(230, 600, 610, 780);
                putimage((230 + 610) / 2 - 50, (600 + 780) / 2 - 50, &lockImage);
            }
        }

        // 处理鼠标在第五个矩形区域内的情况
        if (msg.x >= 1000 && msg.y >= 600 && msg.x <= 1380 && msg.y <= 780)
        {
            if (levelstatus >= 3)  // 只有通过第三关才能解锁第四关
            {
                setfillcolor(DARKGRAY);
                settextstyle(136, 0, _T("Consolas"));
                solidrectangle(1000, 600, 1380, 780);
                outtextxy(1001, 616, _T("第四关"));
                
                if (msg.lbutton == true)
                {
                    if (bgm.isMusicPlaying()) {
                        bgm.stopMusic();
                        bgm.playmusic("./src/music/play.mp3");
                    }
                    int x=gameview(3);
                    levelstatus = user.get_Num_Of_isPassed_Level();
                    if (x > user.get_History_Score()) {
                        //写入数据
                        user.set_History_Score(x);
                        user.save();
                    }
                    if (user.get_isAllPassed() && user.get_isFirstPassed()) {
                        //大结局
                        bgm.stopMusic();
                        closegraph();
                        bgm.playvideomusic("./src/video/end.ogg");
                        Opening_plot("./src/video/end.mp4");
                        //通关界面——成员团队
                        bgm.stopMusic();
						bgm.playvideomusic("./src/video/thanks.mp3");
                        Opening_plot("./src/video/thanks.mp4");
						if (bgm.isMusicPlaying())
							bgm.stopMusic();
						bgm.playmusic("./src/music/Login.mp3");
						// 保存
                        user.set_isFirstPassed(false);
                        user.save();
                        //返回主菜单
						initgraph(WIDTH, HEIGHT, EX_NOCLOSE);
						SetWindowPos(GetHWnd(), NULL, 60, 35, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
						setbkcolor(LIGHTCYAN);
						setbkmode(TRANSPARENT);
						rtnFlag = 2;		////明雅流风//// (退-1)  无0  l1  m2  p3
                    }
                    else {
                        if (bgm.isMusicPlaying()) {
                            bgm.stopMusic();
                            bgm.playmusic("./src/music/Select.mp3");
                        }
                    }
                }
            }
            else
            {
                setfillcolor(RGB(173, 216, 230));
                solidrectangle(1000, 600, 1380, 780);
                putimage((1000 + 1380) / 2 - 50, (600 + 780) / 2 - 50, &lockImage);
            }
        }

        EndBatchDraw(); // 批量绘图
    }

	if (rtnFlag == 3)		////明雅流风//// (退-1)  无0  l1  m2  p3
		rtnFlag = 0;
}