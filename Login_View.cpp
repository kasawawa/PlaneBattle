#include "Enviroment.h"


// ת��ΪASCII
unsigned short toAscii() {
	BYTE keyboardState[256];
	unsigned short asciiChar;
	GetKeyboardState(keyboardState);
	bool caps = GetKeyState(VK_CAPITAL) & 0x8000;	// ��֪Ϊ�Σ�ɾ�����к��޷������д

	ToAscii(msg.vkcode, msg.scancode, keyboardState, &asciiChar, 0);

	return asciiChar;
}

void Login_View() {
	DWORD t[2]{ GetTickCount() };	// ��ʱ��
	IMAGE img;				// ����ͼƬ
	char ch;				// ת������ASCII�ַ�
	bool isExit{};			// �Ƿ��˳�
	int loginFlag{};		// ��¼�����1�ɹ�  0δ�ж�  -1�����Ϊ��  -2�˺Ŵ���  -3�������  -4���ݻ�ȡʧ�ܣ�
	int inputFlag[2]{};		// �������ֵ��0�޴�  1�ַ���֧��  2���ȹ�����
	int attention{};		// ��ע����0��  1�˺ſ�  2�����  4[ǰ��ע��]  5[��¼]  6[�˳�]��
	int kCursor{};			// ���̹�꣨�����
	int mCursor{};			// ����꣨0�հ�  1�˺ſ�  2�����  4[ǰ��ע��]  5[��¼]  6[�˳�]��
	int lbtnDown{};			// �������״̬��0��  1�˺ſ�  2�����  4[ǰ��ע��]  5[��¼]  6[�˳�]��
	std::string input[2]{};	// 0�˺�  1����
	LOGFONT font{ 0,0, font.lfQuality = ANTIALIASED_QUALITY };
	std::string tips[]{
		"��֧�ֳ���Ӣ���ַ�\t~_(��)_/~",	// 0.inputFlag = 1
		"���21���ַ�\t~_(��)_/~",			// 1.inputFlag = 2
		"����򲻿�Ϊ��\t~_(��)_/~",		// 2.loginFlag = -1
		"���޴���\t~_(��)_/~",				// 3.loginFlag = -2
		"�������\t~_(��)_/~",				// 4.loginFlag = -3
		"���ݻ�ȡʧ��\t~_(��)_/~"			// 5.loginFlag = -4
	};
	RECT rect[]{
		{ 650,100, 950,200},		// 0.���⡾�� ¼��
		{ 600,300, 680,350},		// 1.account��ʾ
		{ 600,450, 680,500},		// 2.password��ʾ
		{ 600,560,1000,610},		// 3.ʧ����ʾ
		{ 760,615, 840,635},		// 4.[ǰ��ע��]
		{ 750,650, 850,700},		// 5.[�� ¼]
		{1350,800,1450,850}			// 6.[�� ��]
	};

	// ����ѭ������������
	{
		loadimage(&img, "./src/picture/Login_Register.jpg", WIDTH, HEIGHT);		// ��ѭ��������ܿ�
		_tcscpy_s(font.lfFaceName, "����");
		bgm.playmusic("./src/music/Login.mp3");
	}

	while (true) {
		int flag = msg.message = 0;		// flag��¼�����Ϣ�Ƿ����ж�
		peekmessage(&msg);

		// �����ж�
		if (msg.message == WM_KEYDOWN) {
			// [Esc]
			if (msg.vkcode == VK_ESCAPE)
				isExit = true;
			// ˳��[Tab][��]
			else if (msg.vkcode == VK_TAB || msg.vkcode == VK_DOWN) {
				if (++attention > 6)
					attention = 1;
				else if (attention == 3)
					attention = 4;
				if (attention == 1 || attention == 2)
					kCursor = input[attention - 1].size();
			}
			// ����[��]
			else if (msg.vkcode == VK_UP) {
				if (--attention < 1)
					attention = 6;
				else if (attention == 3)
					attention = 2;
				if (attention == 1 || attention == 2)
					kCursor = input[attention - 1].size();
			}
			// [Enter]
			else if (msg.vkcode == VK_RETURN) {
				if (attention == 4) {
					Register_View();
					attention = 1;
				}
				else if (attention == 5)
					loginFlag = user.isLogin(input);
				else if (attention == 6)
					isExit = true;
				else if (attention == 1 || attention == 2) {
					if (++attention == 3)
						attention = 5;
					kCursor = input[attention - 1].size();
				}
				else
					attention = 1;
			}
			// ����
			else if (attention == 1 || attention == 2) {
				inputFlag[attention - 1] = loginFlag = 0;
				ch = (char)toAscii();
				// [ɾ��]��ɾ��
				if (msg.vkcode == VK_DELETE) {
					if (input[attention - 1].size() - kCursor)
						input[attention - 1].erase(input[attention - 1].begin() + kCursor);
				}
				// [�˸�]��ɾǰ��
				else if (msg.vkcode == VK_BACK) {
					if (kCursor) {
						input[attention - 1].erase(input[attention - 1].begin() + kCursor - 1);
						kCursor--;
					}
				}
				// [��]
				else if (msg.vkcode == VK_LEFT) {
					if (--kCursor < 0)
						kCursor = 0;
				}
				// [��]
				else if (msg.vkcode == VK_RIGHT) {
					if (++kCursor > input[attention - 1].size())
						kCursor = input[attention - 1].size();
				}
				// �ж��ַ�
				else if (ch >= 33 && ch <= 126) {
					if (input[attention - 1].size() >= 21)
						inputFlag[attention - 1] = 2;
					else {
						input[attention - 1].insert(input[attention - 1].begin() + kCursor, ch);
						kCursor++;
					}
				}
				// ��Ч�ַ�
				else
					inputFlag[attention - 1] = 1;
			}
		}

		// ����ж�
		if (msg.message == WM_MOUSEMOVE || msg.message == WM_LBUTTONDOWN || msg.message == WM_LBUTTONUP) {
			// �����
			for (int i = 1; !flag && i <= 2; i++) {
				if (msg.x > rect[i].left && msg.x<1000 && msg.y>rect[i].top && msg.y < rect[i].bottom) {
					flag = mCursor = i;
					if (msg.message == WM_LBUTTONUP) {			// ����
						attention = i;
						lbtnDown = 0;
					}
					else if (msg.lbutton) {	// ����
						lbtnDown = i;
						if (msg.x - (rect[i].right - 7) <= 0 ||						// ���̫�� -> ��궨λ��ĩβ
							msg.x - (rect[i].right - 7) > 15 * input[i - 1].size())	// ���̫�� -> ��궨λ��ĩβ
							kCursor = input[i - 1].size();
						else														// ������� -> ���������λ
							kCursor = (msg.x - (rect[i].right - 7)) / 15;
					}
				}
			}

			// ��ť
			for (int i = 4; !flag && i <= 6; i++) {
				if (msg.x > rect[i].left && msg.x<rect[i].right && msg.y>rect[i].top && msg.y < rect[i].bottom) {
					flag = mCursor = i;
					if (msg.lbutton)			// ����
						lbtnDown = i;
					else if (msg.message == WM_LBUTTONUP) {		// ����
						attention = i;
						lbtnDown = 0;
						if (i == 4) { 
							Register_View();
							attention = 1;
						}
						else if (i == 5)	loginFlag = user.isLogin(input);
						else if (i == 6)	isExit = true;
					}

				}
			}

			// �հ״�
			if (!flag) {
				mCursor = lbtnDown = 0;
				if (msg.message != WM_MOUSEMOVE)			// ���
					attention = 0;
			}
		}

		// �������
		{
			BeginBatchDraw();

			setlinecolor(WHITE);
			setlinestyle(PS_SOLID, 2);

			// ����ͼ
			putimage(0, 0, &img);

			// �����
			for (int i = 1; i <= 2; i++) {
				if (lbtnDown == i)	setfillcolor(0X333333);
				else if (mCursor == i)	setfillcolor(0X666666);
				else					setfillcolor(BLACK);
				fillrectangle(rect[i].left, rect[i].top, 1000, rect[i].bottom);
			}

			// ��ť
			if (lbtnDown == 5)	setfillcolor(0XCC33CC);
			else if (mCursor == 5)	setfillcolor(0XFF66FF);
			else					setfillcolor(0X990099);
			fillroundrect(rect[5].left, rect[5].top, rect[5].right, rect[5].bottom, 30, 30);	// [�� ¼]
			if (lbtnDown == 6)	setfillcolor(0X333333);
			else if (mCursor == 6)	setfillcolor(0X666666);
			else					setfillcolor(BLACK);
			fillroundrect(rect[6].left, rect[6].top, rect[6].right, rect[6].bottom, 30, 30);	// [�� ��]

			// ��ʾ�ı�
			settextstyle(100, 0, "����");
			settextcolor(LIGHTGREEN);
			drawtext("�� ¼", &rect[0], DT_CENTER | DT_SINGLELINE | DT_VCENTER);
			settextstyle(20, 0, "����");
			settextcolor(WHITE);
			drawtext("�˺� >", &rect[1], DT_CENTER | DT_SINGLELINE | DT_VCENTER);
			drawtext("���� >", &rect[2], DT_CENTER | DT_SINGLELINE | DT_VCENTER);
			font.lfHeight = 18;
			font.lfUnderline = true;
			settextstyle(&font);
			if (mCursor == 4)	settextcolor(CYAN);
			else				settextcolor(YELLOW);
			drawtext("ǰ��ע��", &rect[4], DT_CENTER | DT_SINGLELINE | DT_VCENTER);
			font.lfHeight = 30;
			font.lfUnderline = false;
			settextstyle(&font);
			settextcolor(LIGHTCYAN);
			drawtext("�� ¼", &rect[5], DT_CENTER | DT_SINGLELINE | DT_VCENTER);
			settextcolor(LIGHTGRAY);
			drawtext("�� ��", &rect[6], DT_CENTER | DT_SINGLELINE | DT_VCENTER);

			// �����ı�
			for (int i = 1; i <= 2; i++)
				outtextxy(rect[i].right, rect[i].top + 10, input[i - 1].data());

			// tips
			settextcolor(LIGHTRED);
			if ((attention == 1 || attention == 2) && inputFlag[attention - 1])		// �������
				outtextxy(1020, rect[attention].top + 10, tips[inputFlag[attention - 1] - 1].data());
			if (attention == 5 && loginFlag < 0)									// ��¼���
				drawtext(tips[1 - loginFlag].data(), &rect[3], DT_CENTER | DT_SINGLELINE | DT_VCENTER);

			// ��ע����
			if (attention) {
				setlinecolor(CYAN);
				roundrect(rect[attention].left, rect[attention].top, rect[attention].right, rect[attention].bottom, 20, 20);		// ��ע��
			}

			// ���̹��
			t[1] = GetTickCount();
			if ((attention == 1 || attention == 2) && (t[1] - t[0]) / 400 % 2) {
				setlinecolor(WHITE);
				line(rect[attention].right + 15 * kCursor, rect[attention].top + 10, rect[attention].right + 15 * kCursor, rect[attention].bottom - 10);
			}

			EndBatchDraw();
		}

		// ����
		{
			// ��¼�ж�
			if (loginFlag == 1) {
				MessageBox(GetHWnd(), "��¼�ɹ���\n\n\t|�� �� ��*�� �� ��|", "��¼��ʾ��-. -\"��", MB_OK);
				loginFlag = 0;
				std::cout << user.get_isInitial() << std::endl;
				std::cout << user.get_isFirstPassed() << std::endl;
				if (user.get_isInitial())	//���麯��();
				{
					bgm.stopMusic();
					bgm.playvideomusic("./src/video/Beginner.mp3");
					closegraph();
					Opening_plot("./src/video/Beginner.mp4");
					initgraph(WIDTH, HEIGHT, EX_NOCLOSE);
					SetWindowPos(GetHWnd(), NULL, 60, 35, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
					setbkcolor(LIGHTCYAN);
					setbkmode(TRANSPARENT);
					user.set_isInitial(false);
					user.save();
				}
				Menu_View();
			}
			else if (loginFlag == -4) {
				MessageBox(GetHWnd(), "��ȡ�û�����ʧ�ܣ�\n\n\t~_(��)_/~", "��¼��ʾ��-. -\"��", MB_OK);
				loginFlag = 0;
			}
			// �ֲ��˳��ж�
			if (isExit)
				if (MessageBox(GetHWnd(), "ȷ���˳���", "�˳���ʾ��-. -\"��", MB_YESNO) == IDYES)
					return;
				else
					isExit = false;
			// ȫ���˳��ж�
			else if (rtnFlag)
				return;
		}
	}
}

void Register_View() {
	DWORD t[2]{ GetTickCount() };	// ��ʱ��
	IMAGE img;				// ����ͼƬ
	char ch;				// ת������ASCII�ַ�
	bool isRtn{};			// �Ƿ񷵻�
	int registerFlag{};		// ע�������1�ɹ�  0δ�ж�  -1�����Ϊ��  -2�û��Ѵ���  -3���ݻ�ȡʧ��  -4����д��ʧ�ܣ�
	int inputFlag[3]{};		// �������ֵ��0�޴�  1�ַ���֧��  2���ȹ�����
	int attention{};		// ��ע����0��  1�ǳƿ�  2�˺ſ�  3�����  5[ע��]  6[����]��
	int kCursor{};			// ���̹�꣨�����
	int mCursor{};			// ����꣨0�հ�  1�ǳƿ�  2�˺ſ�  3�����  5[ע��]  6[����]��
	int lbtnDown{};			// �������״̬��0��  1�ǳƿ�  2�˺ſ�  3�����  5[ע��]  6[����]��
	std::string input[3]{};	// 0�ǳ�  1�˺�  2����
	LOGFONT font{ 0,0, font.lfQuality = ANTIALIASED_QUALITY };
	std::string tips[]{
		"��֧�ֳ���Ӣ���ַ�\t~_(��)_/~",	// 0.inputFlag = 1
		"���21���ַ�\t~_(��)_/~",			// 1.inputFlag = 2
		"����򲻿�Ϊ��\t~_(��)_/~",		// 2.registerFlag = -1
		"���д���\t~_(��)_/~",				// 3.registerFlag = -2
		"���ݻ�ȡʧ��\t~_(��)_/~",			// 4.registerFlag = -3
		"����д��ʧ��\t~_(��)_/~"			// 5.registerFlag = -4
	};
	RECT rect[]{
		{ 650,100, 950,200},		// 0.���⡾ע �᡿
		{ 600,300, 680,350},		// 1.�ǳ���ʾ
		{ 600,400, 680,450},		// 2.account��ʾ
		{ 600,500, 680,550},		// 3.password��ʾ
		{ 600,600,1000,650},		// 4.ʧ����ʾ
		{ 750,650, 850,700},		// 5.[ע ��]
		{1350,800,1450,850}			// 6.[�� ��]
	};

	// ����ѭ������������
	{
		loadimage(&img, "./src/picture/Login_Register.jpg", WIDTH, HEIGHT);		// ��ѭ��������ܿ�
		_tcscpy_s(font.lfFaceName, "����");
	}

	while (true) {
		int flag = msg.message = 0;		// flag��¼�����Ϣ�Ƿ����ж�
		peekmessage(&msg);

		// �����ж�
		if (msg.message == WM_KEYDOWN) {
			// [Esc]
			if (msg.vkcode == VK_ESCAPE)
				isRtn = true;
			// ˳��[Tab][��]
			else if (msg.vkcode == VK_TAB || msg.vkcode == VK_DOWN) {
				if (++attention > 6)
					attention = 1;
				else if (attention == 4)
					attention = 5;
				if (attention >= 1 && attention <= 3)
					kCursor = input[attention - 1].size();
			}
			// ����[��]
			else if (msg.vkcode == VK_UP) {
				if (--attention < 1)
					attention = 6;
				else if (attention == 4)
					attention = 3;
				if (attention >= 1 && attention <= 3)
					kCursor = input[attention - 1].size();
			}
			// [Enter]
			else if (msg.vkcode == VK_RETURN) {
				if (attention == 5)
					registerFlag = user.Register(input);
				else if (attention == 6)
					isRtn = true;
				else if (attention >= 1 && attention <= 3) {
					if (++attention == 4)
						attention = 5;
					kCursor = input[attention - 1].size();
				}
				else
					attention = 1;
			}
			// ����
			else if (attention >= 1 && attention <= 3) {
				inputFlag[attention - 1] = registerFlag = 0;
				ch = (char)toAscii();
				// [ɾ��]��ɾ��
				if (msg.vkcode == VK_DELETE) {
					if (input[attention - 1].size() - kCursor)
						input[attention - 1].erase(input[attention - 1].begin() + kCursor);
				}
				// [�˸�]��ɾǰ��
				else if (msg.vkcode == VK_BACK) {
					if (kCursor) {
						input[attention - 1].erase(input[attention - 1].begin() + kCursor - 1);
						kCursor--;
					}
				}
				// [��]
				else if (msg.vkcode == VK_LEFT) {
					if (--kCursor < 0)
						kCursor = 0;
				}
				// [��]
				else if (msg.vkcode == VK_RIGHT) {
					if (++kCursor > input[attention - 1].size())
						kCursor = input[attention - 1].size();
				}
				// �ж��ַ�
				else if (ch >= 33 && ch <= 126) {
					if (input[attention - 1].size() >= 21)
						inputFlag[attention - 1] = 2;
					else {
						input[attention - 1].insert(input[attention - 1].begin() + kCursor, ch);
						kCursor++;
					}
				}
				// ��Ч�ַ�
				else
					inputFlag[attention - 1] = 1;
			}
		}

		// ����ж�
		if (msg.message == WM_MOUSEMOVE || msg.message == WM_LBUTTONDOWN || msg.message == WM_LBUTTONUP) {
			// �����
			for (int i = 1; !flag && i <= 3; i++) {
				if (msg.x > rect[i].left && msg.x<1000 && msg.y>rect[i].top && msg.y < rect[i].bottom) {
					flag = mCursor = i;
					if (msg.message == WM_LBUTTONUP) {			// ����
						attention = i;
						lbtnDown = 0;
					}
					else if (msg.lbutton) {	// ����
						lbtnDown = i;
						if (msg.x - (rect[i].right - 7) <= 0 ||						// ���̫�� -> ��궨λ��ĩβ
							msg.x - (rect[i].right - 7) > 15 * input[i - 1].size())	// ���̫�� -> ��궨λ��ĩβ
							kCursor = input[i - 1].size();
						else														// ������� -> ���������λ
							kCursor = (msg.x - (rect[i].right - 7)) / 15;
					}
				}
			}

			// ��ť
			for (int i = 5; !flag && i <= 6; i++) {
				if (msg.x > rect[i].left && msg.x<rect[i].right && msg.y>rect[i].top && msg.y < rect[i].bottom) {
					flag = mCursor = i;
					if (msg.lbutton)		// ����
						lbtnDown = i;
					else if (msg.message == WM_LBUTTONUP) {	// ����
						attention = i;
						lbtnDown = 0;
						if (i == 5)	registerFlag = user.Register(input);
						else if (i == 6)	isRtn = true;
					}
				}
			}

			// �հ״�
			if (!flag) {
				mCursor = lbtnDown = 0;
				if (msg.message != WM_MOUSEMOVE)			// ���
					attention = 0;
			}
		}

		// ������ƣ��������̹�꣩
		{
			BeginBatchDraw();

			setlinecolor(WHITE);
			setlinestyle(PS_SOLID, 2);

			// ͼ
			putimage(0, 0, &img);
			for (int i = 1; i <= 3; i++) {		// �����
				if (lbtnDown == i)	setfillcolor(0X333333);
				else if (mCursor == i)	setfillcolor(0X666666);
				else					setfillcolor(BLACK);
				fillrectangle(rect[i].left, rect[i].top, 1000, rect[i].bottom);
			}
			if (lbtnDown == 5)	setfillcolor(0XCC33CC);
			else if (mCursor == 5)	setfillcolor(0XFF66FF);
			else					setfillcolor(0X990099);
			fillroundrect(rect[5].left, rect[5].top, rect[5].right, rect[5].bottom, 30, 30);	// [ע ��]
			if (lbtnDown == 6)	setfillcolor(0X333333);
			else if (mCursor == 6)	setfillcolor(0X666666);
			else					setfillcolor(BLACK);
			fillroundrect(rect[6].left, rect[6].top, rect[6].right, rect[6].bottom, 30, 30);	// [�� ��]

			// ��ʾ�ı�
			settextstyle(100, 0, "����");
			settextcolor(LIGHTGREEN);
			drawtext("ע ��", &rect[0], DT_CENTER | DT_SINGLELINE | DT_VCENTER);
			settextstyle(20, 0, "����");
			settextcolor(WHITE);
			drawtext("�ǳ� >", &rect[1], DT_CENTER | DT_SINGLELINE | DT_VCENTER);
			drawtext("�˺� >", &rect[2], DT_CENTER | DT_SINGLELINE | DT_VCENTER);
			drawtext("���� >", &rect[3], DT_CENTER | DT_SINGLELINE | DT_VCENTER);
			settextstyle(30, 0, "����");
			settextcolor(LIGHTCYAN);
			drawtext("ע ��", &rect[5], DT_CENTER | DT_SINGLELINE | DT_VCENTER);
			settextcolor(LIGHTGRAY);
			drawtext("�� ��", &rect[6], DT_CENTER | DT_SINGLELINE | DT_VCENTER);

			// �����ı�
			for (int i = 1; i <= 3; i++)
				outtextxy(rect[i].right, rect[i].top + 10, input[i - 1].data());

			// tips
			settextcolor(LIGHTRED);
			if (attention >= 1 && attention <= 3 && inputFlag[attention - 1])		// �������
				outtextxy(1020, rect[attention].top + 10, tips[inputFlag[attention - 1] - 1].data());
			if (attention == 5 && registerFlag < 0)									// ע�����
				drawtext(tips[1 - registerFlag].data(), &rect[4], DT_CENTER | DT_SINGLELINE | DT_VCENTER);

			// ��ע����
			if (attention) {
				setlinecolor(CYAN);
				roundrect(rect[attention].left, rect[attention].top, rect[attention].right, rect[attention].bottom, 20, 20);		// ��ע��
			}

			// ���̹��
			t[1] = GetTickCount();
			if (attention >= 1 && attention <= 3 && (t[1] - t[0]) / 400 % 2) {
				setlinecolor(WHITE);
				line(rect[attention].right + 15 * kCursor, rect[attention].top + 10, rect[attention].right + 15 * kCursor, rect[attention].bottom - 10);
			}

			EndBatchDraw();
		}

		// ����
		{
			if (registerFlag == 1) {
				MessageBox(GetHWnd(), "ע��ɹ���\n\n\t|�� �� ��*�� �� ��|", "ע����ʾ��-. -\"��", MB_OK);
				registerFlag = 0;
				attention = 6;
			}
			else if (registerFlag == -3) {
				MessageBox(GetHWnd(), "��ȡ�û�����ʧ�ܣ�\n\n\t~_(��)_/~", "ע����ʾ��-. -\"��", MB_OK);
				registerFlag = 0;
			}
			else if (registerFlag == -4) {
				MessageBox(GetHWnd(), "д���û�����ʧ�ܣ�\n\n\t~_(��)_/~", "ע����ʾ��-. -\"��", MB_OK);
				registerFlag = 0;
			}
			else if (isRtn)
				return;
		}
	}
}
