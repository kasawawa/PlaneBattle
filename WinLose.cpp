#include"Enviroment.h"

void winView(int score,int Level)
{
	if (bgm.isMusicPlaying()) {
		bgm.stopMusic();
		bgm.onceplay("./src/music/vector.wav");
	}
	settextstyle(188, 0, _T("庞门正道标题体免费版"));
	BeginBatchDraw();
	setfillcolor(WHITE);
	solidrectangle(0, 0, bound_right, bound_bottom);
	IMAGE bkground_win;
	loadimage(&bkground_win, _T(".\\src\\bkground_win.jpg"));
	putimage(0, 0, &bkground_win);
	settextcolor(RGB(252, 202, 0));
	//setbkmode(TRANSPARENT);
	outtextxy(500, 200, _T("VICTORY"));
	settextcolor(RGB(250, 250, 250));
	std::string sc_str = std::to_string(score);
	const char* outputscore = sc_str.c_str();
	settextstyle(128, 0, _T("consolas"));
	outtextxy(700, 400, outputscore);
	settextcolor(RGB(200, 200, 200));
	settextstyle(36, 0, _T("庞门正道标题体免费版"));
	outtextxy(670, 570, _T("点击任意位置返回主菜单"));
	FlushBatchDraw();
	while (1)
	{
		msg = getmessage(EX_MOUSE);
		if (msg.lbutton == true)
		{
			if (Level == user.get_Num_Of_isPassed_Level()) {
				user.set_Num_Of_isPassed_Level(user.get_Num_Of_isPassed_Level() + 1);
				user.save();
			}
			if (Level == 3) {
				user.set_isAllPassed(true);
				user.save();
			}
			//setbkcolor(BLACK);
			//cleardevice();
			return;
		}
	}
}

void loseView(int score)
{
	if (bgm.isMusicPlaying()) {
		bgm.stopMusic();
		bgm.onceplay("./src/music/Failed.wav");
	}
	settextstyle(200, 0, _T("庞门正道标题体免费版"));
	BeginBatchDraw();
	setfillcolor(BLACK);
	solidrectangle(0, 0, bound_right, bound_bottom);
	IMAGE bkground_lose;
	loadimage(&bkground_lose, _T(".\\src\\bkground_lose.jpg"));
	putimage(0, 0, &bkground_lose);
	settextcolor(RGB(177, 12, 12));
	//setbkmode(TRANSPARENT);
	outtextxy(500, 200, _T("DEFEAT"));
	settextcolor(RGB(248, 248, 255));
	std::string sc_str = std::to_string(score);
	const char* outputscore = sc_str.c_str();
	settextstyle(128, 0, _T("consolas"));
	outtextxy(700, 400, outputscore);
	settextcolor(RGB(200, 200, 200));
	settextstyle(36, 0, _T("庞门正道标题体免费版"));
	outtextxy(670, 570, _T("点击任意位置返回主菜单"));
	FlushBatchDraw();
	while (1)
	{
		msg = getmessage(EX_MOUSE);
		if (msg.lbutton == true)
		{
			//setbkcolor(BLACK);
			//cleardevice();
			return;
		}
	}
}