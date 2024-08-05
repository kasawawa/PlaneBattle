#include"Enviroment.h"

bool pauseview()
{
	//找到图片之前先用这个
	bgm.pauseMusic();
	while (1)
	{
		setfillcolor(RGB(10, 10, 44));
		setlinecolor(RGB(182, 171, 106));
		solidroundrect(300, 100, bound_right - 300, bound_bottom - 100, 30, 30);
		roundrect(300, 100, bound_right - 300, bound_bottom - 100, 30, 30);
		//退出游戏
		setfillcolor(RGB(0, 0, 0));
		solidrectangle(bound_right / 2 - 200, 200, bound_right / 2 + 200, 300);
		solidrectangle(bound_right / 2 - 200, 400, bound_right / 2 + 200, 500);
		solidrectangle(bound_right / 2 - 200, 600, bound_right / 2 + 200, 700);
		setlinecolor(RGB(250, 210, 0));
		rectangle(bound_right / 2 - 200, 200, bound_right / 2 + 200, 300);
		rectangle(bound_right / 2 - 200, 400, bound_right / 2 + 200, 500);
		rectangle(bound_right / 2 - 200, 600, bound_right / 2 + 200, 700);
		settextcolor(RGB(255, 215, 0));
		settextstyle(100, 0, _T("庞门正道标题体免费版"));
		//setbkmode(TRANSPARENT);
		outtextxy(bound_right / 2 - 170, 190, _T("继续游戏"));
		outtextxy(bound_right / 2 - 170, 390, _T("退出游戏"));
		outtextxy(bound_right / 2 - 170, 590, _T("游戏设置"));
		ExMessage msg2;
		msg2 = getmessage(EX_MOUSE);
		if (msg2.x > bound_right / 2 - 200 && msg2.x < bound_right / 2 + 200)
		{
			if (msg2.y >= 200 && msg2.y <= 300)
			{
				setfillcolor(LIGHTBLUE);
				solidrectangle(bound_right / 2 - 200, 200, bound_right / 2 + 200, 300);
				rectangle(bound_right / 2 - 200, 200, bound_right / 2 + 200, 300);
				outtextxy(bound_right / 2 - 170, 190, _T("继续游戏"));
				if (msg2.lbutton) { 
					bgm.resumeMusic();
					return 0; 
				}
			}
			else if (msg2.y > 400 && msg2.y <= 500)
			{
				setfillcolor(LIGHTBLUE);
				solidrectangle(bound_right / 2 - 200, 400, bound_right / 2 + 200, 500);
				rectangle(bound_right / 2 - 200, 400, bound_right / 2 + 200, 500);
				outtextxy(bound_right / 2 - 170, 390, _T("退出游戏"));
				if (msg2.lbutton)
				{
					//setbkcolor(BLACK);
					//cleardevice();
					settextcolor(WHITE);
					return 1;
				}
			}
			else if (msg2.y >= 600 && msg2.y <= 700)
			{
				setfillcolor(LIGHTBLUE);
				solidrectangle(bound_right / 2 - 200, 600, bound_right / 2 + 200, 700);
				rectangle(bound_right / 2 - 200, 600, bound_right / 2 + 200, 700);
				outtextxy(bound_right / 2 - 170, 590, _T("游戏设置"));
				if (msg2.lbutton)
				{
					//setbkcolor(BLACK);
					//cleardevice();
					gamesetting();
					return 0;
				}
			}
		}
		FlushBatchDraw();
	}

	//继续游戏
	//设置
}