#include "Enviroment.h"

void levelselectview()
{
    IMAGE bg;
    IMAGE lockImage;  // δ����ͼƬ
    int levelstatus = user.get_Num_Of_isPassed_Level();//����ͨ�������ȸ�ֵ��levelstaus����
    loadimage(&lockImage, _T("./src/locked.png"), 100, 100);
    loadimage(&bg, _T("./src/picture/Select_Level.jpg"), 1600, 900);

    while (!rtnFlag)		////��������//// (��-1)  ��0  l1  m2  p3
    {
		BeginBatchDraw();
        //���������ɫΪǳ��ɫ���������ĸ����Σ��ֱ�����ĸ���ͬ������
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
        //����������ʽ�ͱ���ģʽ������ָ��λ������ı� "��һ��"��"�ڶ���"��"������"��"���Ĺ�"
        settextstyle(100, 0, _T("Consolas"));
        outtextxy(750 - textwidth(_T("��  ��  ѡ  ��")) / 2, 50, _T("��  ��  ѡ  ��"));
        outtextxy(230 + (610 - 230) / 2 - textwidth(_T("��һ��")) / 2, 300 + (480 - 300) / 2 - textheight(_T("��һ��")) / 2, _T("��һ��"));
        outtextxy(1000 + (1380 - 1000) / 2 - textwidth(_T("�ڶ���")) / 2, 300 + (480 - 300) / 2 - textheight(_T("�ڶ���")) / 2, _T("�ڶ���"));
        outtextxy(230 + (610 - 230) / 2 - textwidth(_T("������")) / 2, 600 + (780 - 600) / 2 - textheight(_T("������")) / 2, _T("������"));
        outtextxy(1000 + (1380 - 1000) / 2 - textwidth(_T("���Ĺ�")) / 2, 600 + (780 - 600) / 2 - textheight(_T("���Ĺ�")) / 2, _T("���Ĺ�"));

        settextstyle(50, 0, "Consolas");
        settextcolor(0xFFFFFF);
        outtextxy(0, 800, "ֲ��");
        outtextxy(0, 850, "ѡ��");

		settextcolor(LIGHTMAGENTA);
		settextstyle(50, 0, "����");
		std::string score = "��ʷ�÷�:��";
		score += std::to_string(user.get_History_Score());
		outtextxy(600,200, (score + "��").data());
		settextstyle(50, 0, "Consolas");
		settextcolor(0xFFFFFF);

        //��ȡ�����Ϣ���洢�� m ������
        msg = getmessage(EX_MOUSE);
        //������λ���ڵ�ĳ�����������ڣ������ɫ��Ϊ���ɫ��ͬʱ����ı���������������£��ж��Ƿ�������������ֱ����ת����Ϸ����
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

		//��������ڵ�һ�����������ڵ����
        if (msg.x >= 0 && msg.y >= 800 && msg.x <= 100 && msg.y <= 900)
        {
            setfillcolor(DARKGRAY);
            fillroundrect(0, 800, 100, 900, 10, 10);
            settextstyle(50, 0, "Consolas");
            settextcolor(0xFFFFFF);
            outtextxy(0, 800, "ֲ��");
            outtextxy(0, 850, "ѡ��");
            if (msg.lbutton == true)
            {
                //ֲ��ѡ��
				rtnFlag = 3;		////��������//// (��-1)  ��0  l1  m2  p3
            }
        }

        //��������ڵڶ������������ڵ����
        if (msg.x >= 230 && msg.y >= 300 && msg.x <= 610 && msg.y <= 480)
        {
            if (levelstatus >= 0)
            {
                setfillcolor(DARKGRAY);
                settextstyle(136, 0, _T("Consolas"));
                solidrectangle(230, 300, 610, 480);
                outtextxy(231, 316, _T("��һ��"));
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
						//д������
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

        // ��������ڵ��������������ڵ����
        if (msg.x >= 1000 && msg.y >= 300 && msg.x <= 1380 && msg.y <= 480)
        {
            if (levelstatus >= 1)  // ֻ��ͨ����һ�ز��ܽ����ڶ���
            {
                setfillcolor(DARKGRAY);
                settextstyle(136, 0, _T("Consolas"));
                solidrectangle(1000, 300, 1380, 480);
                outtextxy(1001, 316, _T("�ڶ���"));

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
                        //д������
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

        // ��������ڵ��ĸ����������ڵ����
        if (msg.x >= 230 && msg.y >= 600 && msg.x <= 610 && msg.y <= 780)
        {
            if (levelstatus >= 2)  // ֻ��ͨ���ڶ��ز��ܽ���������
            {
               setfillcolor(DARKGRAY);
                settextstyle(136, 0, _T("Consolas"));
                solidrectangle(230, 600, 610, 780);
                outtextxy(231, 616, _T("������"));
                
                if (msg.lbutton == true)
                {
                    if (bgm.isMusicPlaying()) {
                        bgm.stopMusic();
                        bgm.playmusic("./src/music/play.mp3");
                    }
                    int x=gameview(2);
                    // ��ת��������
                    levelstatus = user.get_Num_Of_isPassed_Level();
                    if (bgm.isMusicPlaying()) {
                        bgm.playmusic("./src/music/Select.mp3");
                    }
                    if (x > user.get_History_Score()) {
                        user.set_History_Score(x);
                        //д������
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

        // ��������ڵ�������������ڵ����
        if (msg.x >= 1000 && msg.y >= 600 && msg.x <= 1380 && msg.y <= 780)
        {
            if (levelstatus >= 3)  // ֻ��ͨ�������ز��ܽ������Ĺ�
            {
                setfillcolor(DARKGRAY);
                settextstyle(136, 0, _T("Consolas"));
                solidrectangle(1000, 600, 1380, 780);
                outtextxy(1001, 616, _T("���Ĺ�"));
                
                if (msg.lbutton == true)
                {
                    if (bgm.isMusicPlaying()) {
                        bgm.stopMusic();
                        bgm.playmusic("./src/music/play.mp3");
                    }
                    int x=gameview(3);
                    levelstatus = user.get_Num_Of_isPassed_Level();
                    if (x > user.get_History_Score()) {
                        //д������
                        user.set_History_Score(x);
                        user.save();
                    }
                    if (user.get_isAllPassed() && user.get_isFirstPassed()) {
                        //����
                        bgm.stopMusic();
                        closegraph();
                        bgm.playvideomusic("./src/video/end.ogg");
                        Opening_plot("./src/video/end.mp4");
                        //ͨ�ؽ��桪����Ա�Ŷ�
                        bgm.stopMusic();
						bgm.playvideomusic("./src/video/thanks.mp3");
                        Opening_plot("./src/video/thanks.mp4");
						if (bgm.isMusicPlaying())
							bgm.stopMusic();
						bgm.playmusic("./src/music/Login.mp3");
						// ����
                        user.set_isFirstPassed(false);
                        user.save();
                        //�������˵�
						initgraph(WIDTH, HEIGHT, EX_NOCLOSE);
						SetWindowPos(GetHWnd(), NULL, 60, 35, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
						setbkcolor(LIGHTCYAN);
						setbkmode(TRANSPARENT);
						rtnFlag = 2;		////��������//// (��-1)  ��0  l1  m2  p3
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

        EndBatchDraw(); // ������ͼ
    }

	if (rtnFlag == 3)		////��������//// (��-1)  ��0  l1  m2  p3
		rtnFlag = 0;
}