#include "Enviroment.h"


// 转化为ASCII
unsigned short toAscii() {
	BYTE keyboardState[256];
	unsigned short asciiChar;
	GetKeyboardState(keyboardState);
	bool caps = GetKeyState(VK_CAPITAL) & 0x8000;	// 不知为何，删除这行后，无法输出大写

	ToAscii(msg.vkcode, msg.scancode, keyboardState, &asciiChar, 0);

	return asciiChar;
}

void Login_View() {
	DWORD t[2]{ GetTickCount() };	// 计时器
	IMAGE img;				// 背景图片
	char ch;				// 转换所得ASCII字符
	bool isExit{};			// 是否退出
	int loginFlag{};		// 登录情况（1成功  0未判定  -1输入框为空  -2账号错误  -3密码错误  -4数据获取失败）
	int inputFlag[2]{};		// 输入错误（值：0无错  1字符不支持  2长度过长）
	int attention{};		// 关注对象（0无  1账号框  2密码框  4[前往注册]  5[登录]  6[退出]）
	int kCursor{};			// 键盘光标（输入框）
	int mCursor{};			// 鼠标光标（0空白  1账号框  2密码框  4[前往注册]  5[登录]  6[退出]）
	int lbtnDown{};			// 左键按下状态（0无  1账号框  2密码框  4[前往注册]  5[登录]  6[退出]）
	std::string input[2]{};	// 0账号  1密码
	LOGFONT font{ 0,0, font.lfQuality = ANTIALIASED_QUALITY };
	std::string tips[]{
		"仅支持常见英文字符\t~_(ツ)_/~",	// 0.inputFlag = 1
		"最多21个字符\t~_(ツ)_/~",			// 1.inputFlag = 2
		"输入框不可为空\t~_(ツ)_/~",		// 2.loginFlag = -1
		"查无此人\t~_(ツ)_/~",				// 3.loginFlag = -2
		"密码错误\t~_(ツ)_/~",				// 4.loginFlag = -3
		"数据获取失败\t~_(ツ)_/~"			// 5.loginFlag = -4
	};
	RECT rect[]{
		{ 650,100, 950,200},		// 0.标题【登 录】
		{ 600,300, 680,350},		// 1.account提示
		{ 600,450, 680,500},		// 2.password提示
		{ 600,560,1000,610},		// 3.失败提示
		{ 760,615, 840,635},		// 4.[前往注册]
		{ 750,650, 850,700},		// 5.[登 录]
		{1350,800,1450,850}			// 6.[退 出]
	};

	// 不需循环反复做的事
	{
		loadimage(&img, "./src/picture/Login_Register.jpg", WIDTH, HEIGHT);		// 若循环做，会很卡
		_tcscpy_s(font.lfFaceName, "楷体");
		bgm.playmusic("./src/music/Login.mp3");
	}

	while (true) {
		int flag = msg.message = 0;		// flag记录鼠标消息是否已判定
		peekmessage(&msg);

		// 输入判定
		if (msg.message == WM_KEYDOWN) {
			// [Esc]
			if (msg.vkcode == VK_ESCAPE)
				isExit = true;
			// 顺移[Tab][↓]
			else if (msg.vkcode == VK_TAB || msg.vkcode == VK_DOWN) {
				if (++attention > 6)
					attention = 1;
				else if (attention == 3)
					attention = 4;
				if (attention == 1 || attention == 2)
					kCursor = input[attention - 1].size();
			}
			// 逆移[↑]
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
			// 输入
			else if (attention == 1 || attention == 2) {
				inputFlag[attention - 1] = loginFlag = 0;
				ch = (char)toAscii();
				// [删除]（删后）
				if (msg.vkcode == VK_DELETE) {
					if (input[attention - 1].size() - kCursor)
						input[attention - 1].erase(input[attention - 1].begin() + kCursor);
				}
				// [退格]（删前）
				else if (msg.vkcode == VK_BACK) {
					if (kCursor) {
						input[attention - 1].erase(input[attention - 1].begin() + kCursor - 1);
						kCursor--;
					}
				}
				// [←]
				else if (msg.vkcode == VK_LEFT) {
					if (--kCursor < 0)
						kCursor = 0;
				}
				// [→]
				else if (msg.vkcode == VK_RIGHT) {
					if (++kCursor > input[attention - 1].size())
						kCursor = input[attention - 1].size();
				}
				// 判定字符
				else if (ch >= 33 && ch <= 126) {
					if (input[attention - 1].size() >= 21)
						inputFlag[attention - 1] = 2;
					else {
						input[attention - 1].insert(input[attention - 1].begin() + kCursor, ch);
						kCursor++;
					}
				}
				// 无效字符
				else
					inputFlag[attention - 1] = 1;
			}
		}

		// 鼠标判定
		if (msg.message == WM_MOUSEMOVE || msg.message == WM_LBUTTONDOWN || msg.message == WM_LBUTTONUP) {
			// 输入框
			for (int i = 1; !flag && i <= 2; i++) {
				if (msg.x > rect[i].left && msg.x<1000 && msg.y>rect[i].top && msg.y < rect[i].bottom) {
					flag = mCursor = i;
					if (msg.message == WM_LBUTTONUP) {			// 弹起
						attention = i;
						lbtnDown = 0;
					}
					else if (msg.lbutton) {	// 按下
						lbtnDown = i;
						if (msg.x - (rect[i].right - 7) <= 0 ||						// 点击太左 -> 光标定位到末尾
							msg.x - (rect[i].right - 7) > 15 * input[i - 1].size())	// 点击太右 -> 光标定位到末尾
							kCursor = input[i - 1].size();
						else														// 点击正常 -> 光标正常定位
							kCursor = (msg.x - (rect[i].right - 7)) / 15;
					}
				}
			}

			// 按钮
			for (int i = 4; !flag && i <= 6; i++) {
				if (msg.x > rect[i].left && msg.x<rect[i].right && msg.y>rect[i].top && msg.y < rect[i].bottom) {
					flag = mCursor = i;
					if (msg.lbutton)			// 按下
						lbtnDown = i;
					else if (msg.message == WM_LBUTTONUP) {		// 弹起
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

			// 空白处
			if (!flag) {
				mCursor = lbtnDown = 0;
				if (msg.message != WM_MOUSEMOVE)			// 点击
					attention = 0;
			}
		}

		// 界面绘制
		{
			BeginBatchDraw();

			setlinecolor(WHITE);
			setlinestyle(PS_SOLID, 2);

			// 背景图
			putimage(0, 0, &img);

			// 输入框
			for (int i = 1; i <= 2; i++) {
				if (lbtnDown == i)	setfillcolor(0X333333);
				else if (mCursor == i)	setfillcolor(0X666666);
				else					setfillcolor(BLACK);
				fillrectangle(rect[i].left, rect[i].top, 1000, rect[i].bottom);
			}

			// 按钮
			if (lbtnDown == 5)	setfillcolor(0XCC33CC);
			else if (mCursor == 5)	setfillcolor(0XFF66FF);
			else					setfillcolor(0X990099);
			fillroundrect(rect[5].left, rect[5].top, rect[5].right, rect[5].bottom, 30, 30);	// [登 录]
			if (lbtnDown == 6)	setfillcolor(0X333333);
			else if (mCursor == 6)	setfillcolor(0X666666);
			else					setfillcolor(BLACK);
			fillroundrect(rect[6].left, rect[6].top, rect[6].right, rect[6].bottom, 30, 30);	// [退 出]

			// 提示文本
			settextstyle(100, 0, "楷体");
			settextcolor(LIGHTGREEN);
			drawtext("登 录", &rect[0], DT_CENTER | DT_SINGLELINE | DT_VCENTER);
			settextstyle(20, 0, "楷体");
			settextcolor(WHITE);
			drawtext("账号 >", &rect[1], DT_CENTER | DT_SINGLELINE | DT_VCENTER);
			drawtext("密码 >", &rect[2], DT_CENTER | DT_SINGLELINE | DT_VCENTER);
			font.lfHeight = 18;
			font.lfUnderline = true;
			settextstyle(&font);
			if (mCursor == 4)	settextcolor(CYAN);
			else				settextcolor(YELLOW);
			drawtext("前往注册", &rect[4], DT_CENTER | DT_SINGLELINE | DT_VCENTER);
			font.lfHeight = 30;
			font.lfUnderline = false;
			settextstyle(&font);
			settextcolor(LIGHTCYAN);
			drawtext("登 录", &rect[5], DT_CENTER | DT_SINGLELINE | DT_VCENTER);
			settextcolor(LIGHTGRAY);
			drawtext("退 出", &rect[6], DT_CENTER | DT_SINGLELINE | DT_VCENTER);

			// 输入文本
			for (int i = 1; i <= 2; i++)
				outtextxy(rect[i].right, rect[i].top + 10, input[i - 1].data());

			// tips
			settextcolor(LIGHTRED);
			if ((attention == 1 || attention == 2) && inputFlag[attention - 1])		// 输入情况
				outtextxy(1020, rect[attention].top + 10, tips[inputFlag[attention - 1] - 1].data());
			if (attention == 5 && loginFlag < 0)									// 登录情况
				drawtext(tips[1 - loginFlag].data(), &rect[3], DT_CENTER | DT_SINGLELINE | DT_VCENTER);

			// 关注对象
			if (attention) {
				setlinecolor(CYAN);
				roundrect(rect[attention].left, rect[attention].top, rect[attention].right, rect[attention].bottom, 20, 20);		// 关注框
			}

			// 键盘光标
			t[1] = GetTickCount();
			if ((attention == 1 || attention == 2) && (t[1] - t[0]) / 400 % 2) {
				setlinecolor(WHITE);
				line(rect[attention].right + 15 * kCursor, rect[attention].top + 10, rect[attention].right + 15 * kCursor, rect[attention].bottom - 10);
			}

			EndBatchDraw();
		}

		// 操作
		{
			// 登录判定
			if (loginFlag == 1) {
				MessageBox(GetHWnd(), "登录成功！\n\n\t|┌ ∵ ┘*└ ∵ ┐|", "登录提示（-. -\"）", MB_OK);
				loginFlag = 0;
				std::cout << user.get_isInitial() << std::endl;
				std::cout << user.get_isFirstPassed() << std::endl;
				if (user.get_isInitial())	//剧情函数();
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
				MessageBox(GetHWnd(), "读取用户数据失败！\n\n\t~_(ツ)_/~", "登录提示（-. -\"）", MB_OK);
				loginFlag = 0;
			}
			// 局部退出判定
			if (isExit)
				if (MessageBox(GetHWnd(), "确认退出？", "退出提示（-. -\"）", MB_YESNO) == IDYES)
					return;
				else
					isExit = false;
			// 全局退出判定
			else if (rtnFlag)
				return;
		}
	}
}

void Register_View() {
	DWORD t[2]{ GetTickCount() };	// 计时器
	IMAGE img;				// 背景图片
	char ch;				// 转换所得ASCII字符
	bool isRtn{};			// 是否返回
	int registerFlag{};		// 注册情况（1成功  0未判定  -1输入框为空  -2用户已存在  -3数据获取失败  -4数据写入失败）
	int inputFlag[3]{};		// 输入错误（值：0无错  1字符不支持  2长度过长）
	int attention{};		// 关注对象（0无  1昵称框  2账号框  3密码框  5[注册]  6[返回]）
	int kCursor{};			// 键盘光标（输入框）
	int mCursor{};			// 鼠标光标（0空白  1昵称框  2账号框  3密码框  5[注册]  6[返回]）
	int lbtnDown{};			// 左键按下状态（0无  1昵称框  2账号框  3密码框  5[注册]  6[返回]）
	std::string input[3]{};	// 0昵称  1账号  2密码
	LOGFONT font{ 0,0, font.lfQuality = ANTIALIASED_QUALITY };
	std::string tips[]{
		"仅支持常见英文字符\t~_(ツ)_/~",	// 0.inputFlag = 1
		"最多21个字符\t~_(ツ)_/~",			// 1.inputFlag = 2
		"输入框不可为空\t~_(ツ)_/~",		// 2.registerFlag = -1
		"查有此人\t~_(ツ)_/~",				// 3.registerFlag = -2
		"数据获取失败\t~_(ツ)_/~",			// 4.registerFlag = -3
		"数据写入失败\t~_(ツ)_/~"			// 5.registerFlag = -4
	};
	RECT rect[]{
		{ 650,100, 950,200},		// 0.标题【注 册】
		{ 600,300, 680,350},		// 1.昵称提示
		{ 600,400, 680,450},		// 2.account提示
		{ 600,500, 680,550},		// 3.password提示
		{ 600,600,1000,650},		// 4.失败提示
		{ 750,650, 850,700},		// 5.[注 册]
		{1350,800,1450,850}			// 6.[返 回]
	};

	// 不需循环反复做的事
	{
		loadimage(&img, "./src/picture/Login_Register.jpg", WIDTH, HEIGHT);		// 若循环做，会很卡
		_tcscpy_s(font.lfFaceName, "楷体");
	}

	while (true) {
		int flag = msg.message = 0;		// flag记录鼠标消息是否已判定
		peekmessage(&msg);

		// 输入判定
		if (msg.message == WM_KEYDOWN) {
			// [Esc]
			if (msg.vkcode == VK_ESCAPE)
				isRtn = true;
			// 顺移[Tab][↓]
			else if (msg.vkcode == VK_TAB || msg.vkcode == VK_DOWN) {
				if (++attention > 6)
					attention = 1;
				else if (attention == 4)
					attention = 5;
				if (attention >= 1 && attention <= 3)
					kCursor = input[attention - 1].size();
			}
			// 逆移[↑]
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
			// 输入
			else if (attention >= 1 && attention <= 3) {
				inputFlag[attention - 1] = registerFlag = 0;
				ch = (char)toAscii();
				// [删除]（删后）
				if (msg.vkcode == VK_DELETE) {
					if (input[attention - 1].size() - kCursor)
						input[attention - 1].erase(input[attention - 1].begin() + kCursor);
				}
				// [退格]（删前）
				else if (msg.vkcode == VK_BACK) {
					if (kCursor) {
						input[attention - 1].erase(input[attention - 1].begin() + kCursor - 1);
						kCursor--;
					}
				}
				// [←]
				else if (msg.vkcode == VK_LEFT) {
					if (--kCursor < 0)
						kCursor = 0;
				}
				// [→]
				else if (msg.vkcode == VK_RIGHT) {
					if (++kCursor > input[attention - 1].size())
						kCursor = input[attention - 1].size();
				}
				// 判定字符
				else if (ch >= 33 && ch <= 126) {
					if (input[attention - 1].size() >= 21)
						inputFlag[attention - 1] = 2;
					else {
						input[attention - 1].insert(input[attention - 1].begin() + kCursor, ch);
						kCursor++;
					}
				}
				// 无效字符
				else
					inputFlag[attention - 1] = 1;
			}
		}

		// 鼠标判定
		if (msg.message == WM_MOUSEMOVE || msg.message == WM_LBUTTONDOWN || msg.message == WM_LBUTTONUP) {
			// 输入框
			for (int i = 1; !flag && i <= 3; i++) {
				if (msg.x > rect[i].left && msg.x<1000 && msg.y>rect[i].top && msg.y < rect[i].bottom) {
					flag = mCursor = i;
					if (msg.message == WM_LBUTTONUP) {			// 弹起
						attention = i;
						lbtnDown = 0;
					}
					else if (msg.lbutton) {	// 按下
						lbtnDown = i;
						if (msg.x - (rect[i].right - 7) <= 0 ||						// 点击太左 -> 光标定位到末尾
							msg.x - (rect[i].right - 7) > 15 * input[i - 1].size())	// 点击太右 -> 光标定位到末尾
							kCursor = input[i - 1].size();
						else														// 点击正常 -> 光标正常定位
							kCursor = (msg.x - (rect[i].right - 7)) / 15;
					}
				}
			}

			// 按钮
			for (int i = 5; !flag && i <= 6; i++) {
				if (msg.x > rect[i].left && msg.x<rect[i].right && msg.y>rect[i].top && msg.y < rect[i].bottom) {
					flag = mCursor = i;
					if (msg.lbutton)		// 按下
						lbtnDown = i;
					else if (msg.message == WM_LBUTTONUP) {	// 弹起
						attention = i;
						lbtnDown = 0;
						if (i == 5)	registerFlag = user.Register(input);
						else if (i == 6)	isRtn = true;
					}
				}
			}

			// 空白处
			if (!flag) {
				mCursor = lbtnDown = 0;
				if (msg.message != WM_MOUSEMOVE)			// 点击
					attention = 0;
			}
		}

		// 界面绘制（不含键盘光标）
		{
			BeginBatchDraw();

			setlinecolor(WHITE);
			setlinestyle(PS_SOLID, 2);

			// 图
			putimage(0, 0, &img);
			for (int i = 1; i <= 3; i++) {		// 输入框
				if (lbtnDown == i)	setfillcolor(0X333333);
				else if (mCursor == i)	setfillcolor(0X666666);
				else					setfillcolor(BLACK);
				fillrectangle(rect[i].left, rect[i].top, 1000, rect[i].bottom);
			}
			if (lbtnDown == 5)	setfillcolor(0XCC33CC);
			else if (mCursor == 5)	setfillcolor(0XFF66FF);
			else					setfillcolor(0X990099);
			fillroundrect(rect[5].left, rect[5].top, rect[5].right, rect[5].bottom, 30, 30);	// [注 册]
			if (lbtnDown == 6)	setfillcolor(0X333333);
			else if (mCursor == 6)	setfillcolor(0X666666);
			else					setfillcolor(BLACK);
			fillroundrect(rect[6].left, rect[6].top, rect[6].right, rect[6].bottom, 30, 30);	// [返 回]

			// 提示文本
			settextstyle(100, 0, "楷体");
			settextcolor(LIGHTGREEN);
			drawtext("注 册", &rect[0], DT_CENTER | DT_SINGLELINE | DT_VCENTER);
			settextstyle(20, 0, "楷体");
			settextcolor(WHITE);
			drawtext("昵称 >", &rect[1], DT_CENTER | DT_SINGLELINE | DT_VCENTER);
			drawtext("账号 >", &rect[2], DT_CENTER | DT_SINGLELINE | DT_VCENTER);
			drawtext("密码 >", &rect[3], DT_CENTER | DT_SINGLELINE | DT_VCENTER);
			settextstyle(30, 0, "楷体");
			settextcolor(LIGHTCYAN);
			drawtext("注 册", &rect[5], DT_CENTER | DT_SINGLELINE | DT_VCENTER);
			settextcolor(LIGHTGRAY);
			drawtext("返 回", &rect[6], DT_CENTER | DT_SINGLELINE | DT_VCENTER);

			// 输入文本
			for (int i = 1; i <= 3; i++)
				outtextxy(rect[i].right, rect[i].top + 10, input[i - 1].data());

			// tips
			settextcolor(LIGHTRED);
			if (attention >= 1 && attention <= 3 && inputFlag[attention - 1])		// 输入情况
				outtextxy(1020, rect[attention].top + 10, tips[inputFlag[attention - 1] - 1].data());
			if (attention == 5 && registerFlag < 0)									// 注册情况
				drawtext(tips[1 - registerFlag].data(), &rect[4], DT_CENTER | DT_SINGLELINE | DT_VCENTER);

			// 关注对象
			if (attention) {
				setlinecolor(CYAN);
				roundrect(rect[attention].left, rect[attention].top, rect[attention].right, rect[attention].bottom, 20, 20);		// 关注框
			}

			// 键盘光标
			t[1] = GetTickCount();
			if (attention >= 1 && attention <= 3 && (t[1] - t[0]) / 400 % 2) {
				setlinecolor(WHITE);
				line(rect[attention].right + 15 * kCursor, rect[attention].top + 10, rect[attention].right + 15 * kCursor, rect[attention].bottom - 10);
			}

			EndBatchDraw();
		}

		// 操作
		{
			if (registerFlag == 1) {
				MessageBox(GetHWnd(), "注册成功！\n\n\t|┌ ∵ ┘*└ ∵ ┐|", "注册提示（-. -\"）", MB_OK);
				registerFlag = 0;
				attention = 6;
			}
			else if (registerFlag == -3) {
				MessageBox(GetHWnd(), "读取用户数据失败！\n\n\t~_(ツ)_/~", "注册提示（-. -\"）", MB_OK);
				registerFlag = 0;
			}
			else if (registerFlag == -4) {
				MessageBox(GetHWnd(), "写入用户数据失败！\n\n\t~_(ツ)_/~", "注册提示（-. -\"）", MB_OK);
				registerFlag = 0;
			}
			else if (isRtn)
				return;
		}
	}
}
