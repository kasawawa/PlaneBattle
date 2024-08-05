#pragma once
#include "Enviroment.h"

using namespace irrklang;

Button_muxin::Button_muxin(int x, int y, int width, int height, const std::string& text, const std::function<void()>& onClick)
    : x(x), y(y), width(width), height(height), text(text), onClick(onClick), scale(1.0f), isMouseOver(false)
{
}

template<typename T>
T clamp(const T& value, const T& low, const T& high) {
    return value < low ? low : (high < value ? high : value);
}

Button_muxin::~Button_muxin() {}

// 检查鼠标是否在按钮上方
void Button_muxin::checkMouseOver(int mouseX, int mouseY)
{
    isMouseOver = (mouseX >= x && mouseX <= x + width && mouseY >= y && mouseY <= y + height);

    if (isMouseOver) {
        scale = 0.9f; // 鼠标悬停时缩放按钮
    }
    else {
        scale = 1.0f; // 恢复按钮原始大小
    }
}

// 检查鼠标点击是否在按钮内，并执行函数
bool Button_muxin::checkClick(int mouseX, int mouseY)
{
    if (mouseX >= x && mouseX <= x + width && mouseY >= y && mouseY <= y + height)
    {
        onClick(); // 执行按钮点击时的函数
        isMouseOver = false;
        scale = 1.0f;
        return true;
    }
    return false;
}

// 绘制按钮
void Button_muxin::draw()
{
    int scaledWidth = width * scale; // 缩放后的按钮宽度
    int scaledHeight = height * scale; // 缩放后的按钮高度
    int scaledX = x + (width - scaledWidth) / 2; // 缩放后的按钮x坐标
    int scaledY = y + (height - scaledHeight) / 2; // 缩放后的按钮y坐标

    if (isMouseOver)
    {
        setlinecolor(RGB(0, 120, 215)); // 鼠标悬停时按钮边框颜色
        setfillcolor(RGB(229, 241, 251)); // 鼠标悬停时按钮填充颜色
    }
    else
    {
        setlinecolor(RGB(173, 173, 173)); // 按钮边框颜色
        setfillcolor(RGB(225, 225, 225)); // 按钮填充颜色
    }

    fillrectangle(scaledX, scaledY, scaledX + scaledWidth, scaledY + scaledHeight); // 绘制按钮
    settextcolor(BLACK); // 设置文本颜色为黑色
    //setbkmode(TRANSPARENT); // 设置文本背景透明
    settextstyle(40 * scale, 0, "微软雅黑"); // 设置文本大小和字体
    // 居中显示按钮文本
    int textX = scaledX + (scaledWidth - textwidth(text.c_str())) / 2; // 计算文本在按钮中央的x坐标
    int textY = scaledY + (scaledHeight - textheight("微软雅黑")) / 2; // 计算文本在按钮中央的y坐标
    outtextxy(textX, textY, text.c_str()); // 在按钮上绘制文本
}

Menusetting::Menusetting(int width, int height)
    : width(width), height(height), currentIndex(-1)
{
}

Menusetting::~Menusetting() {}

// 添加一个页面
void Menusetting::addPage(IMAGE* page)
{
    pages.push_back(page);
    buttons.push_back({});
}

// 在指定页面上添加一个按钮
void Menusetting::addButton(int index, Button_muxin* button)
{
    if (index >= 0 && index < buttons.size())
    {
        buttons[index].push_back(button);
    }
}

// 设置当前显示的页面索引
void Menusetting::setCurrentIndex(int index)
{
    if (index >= 0 && index < pages.size())
    {
        currentIndex = index;
    }
}

//返回菜单界面
void Menusetting::Return_Menu_View() {
    rtnFlag = 2;		////明雅流风//// (退-1)  无0  l1  m2  p3
}

// 处理鼠标点击事件
void Menusetting::mouseClick(int mouseX, int mouseY)
{
    if (currentIndex >= 0 && currentIndex < buttons.size())
    {
        for (Button_muxin* button : buttons[currentIndex])
        {
            if (button->checkClick(mouseX, mouseY))
            {
                break;
            }
        }
    }
}

// 处理鼠标移动事件
void Menusetting::mouseMove(int mouseX, int mouseY)
{
    if (currentIndex >= 0 && currentIndex < buttons.size())
    {
        for (Button_muxin* button : buttons[currentIndex])
        {
            button->checkMouseOver(mouseX, mouseY);
        }
    }
}

// 绘制当前页面的内容
void Menusetting::draw()
{
	BeginBatchDraw();	// 开始批量绘制
    if (currentIndex >= 0 && currentIndex < pages.size())
    {
        putimage(0, 0, pages[currentIndex]); // 在窗口中绘制当前页面的图片
        if (currentIndex == 0) {
            bgm.displayVolume();
            outtextxy(770, 80, "设置");
            settextstyle(220, 0, "微软雅黑");
        }
        if (currentIndex >= 0 && currentIndex < buttons.size())
        {
            for (Button_muxin* button : buttons[currentIndex])
            {
                button->draw(); // 绘制当前页面上的所有按钮
            }
        }
    }
    bgm.displayVolume();
    outtextxy(770, 80, "设置");
    settextstyle(220, 0, "微软雅黑");
	EndBatchDraw();		// 结束批量绘制
}

bool exitFlag = false; // 增加一个全局变量用于退出标志

Volume::Volume() : volume(50), currentBGM(nullptr), Bengine(nullptr), isPlaying(false), isPaused(false) {
    Bengine = irrklang::createIrrKlangDevice();
}

Volume::~Volume() {
    stopMusic();
    if (Bengine) {
        Bengine->drop();
    }
}

void Volume::showSettingsMenu() {
    //cleardevice();
    displayVolume();
}

void Volume::increase() {
    if (this->volume < maxVolume) {
        this->volume = min(this->volume + 10, maxVolume);
        setvolume(volume);
    }
}

void Volume::decrease() {
    if (this->volume > minVolume) {
        this->volume = max(this->volume - 10, minVolume);
        setvolume(volume);
    }
}

int Volume::getvolume() {
    return this->volume;
}

void Volume::displayVolume() {
    char buffer[50];
    sprintf_s(buffer, "Current Volume: %d", volume);
    settextstyle(40, 0, _T("宋体"));
    outtextxy(640, 240, buffer);
}

// 修改 stopMusic 方法，重置 isPaused 状态
void Volume::stopMusic() {
    if (currentBGM) {
        currentBGM->stop();
        currentBGM->drop();
        currentBGM = nullptr;
        isPlaying = false;
        isPaused = false;
    }
}

void Volume::playmusic(const char* soundFile) {
    stopMusic(); // 先停止当前播放的音乐（如果有）
    if (Bengine) {
        currentBGM = Bengine->play2D(soundFile, true, false, true, irrklang::ESM_AUTO_DETECT, true);
        if (currentBGM) {
            currentBGM->setVolume(volume / 100.0f);
            isPlaying = true;
            isPaused = false;
        }
    }
}

void Volume::setvolume(int newVolume) {
    volume = clamp(newVolume, minVolume, maxVolume);
    if (currentBGM) {
        currentBGM->setVolume(volume / 100.0f);
    }
}

bool Volume::isMusicPlaying() const {
    return isPlaying;
}

void Volume::pauseMusic() {
    if (currentBGM && isPlaying && !isPaused) {
        currentBGM->setIsPaused(true);
        isPaused = true;
    }
}

void Volume::resumeMusic() {
    if (currentBGM && isPlaying && isPaused) {
        currentBGM->setIsPaused(false);
        isPaused = false;
    }
}

bool Volume::isMusicPaused() const {
    return isPaused;
}

void Sound::playSound(const char* soundFile) {
    if (currentSound) {
        currentSound->stop();
        currentSound->drop();
    }
    this->engine = createIrrKlangDevice();
    this->currentSound = engine->play2D(soundFile, false, false, true, ESM_AUTO_DETECT, true);
}

void Sound::stopSound() {
    if (currentSound) {
        currentSound->stop();
        currentSound->drop();
        currentSound = nullptr;
    }
}

bool getExitFlag() {//获取是否退出
    return exitFlag;
}

//——————————————————————————————————————————————//

void Menusetting::init()
{
    //cleardevice();
    // 创建设置页面
    IMAGE* page1 = new IMAGE(width, height);//可以直接用loadimage()函数加载图片
    loadimage(page1, _T("./src/picture/Menu_Setting.jpeg"), width, height);

    addPage(page1); // 添加设置页面

    //增加音量
    Button_muxin* button1_0 = new Button_muxin(350, 295, 300, 70, "增加音量", [&]() {
        bgm.increase();
        });
    addButton(0, button1_0);//将按钮添加到页面1

    //减少音量
    Button_muxin* button1_4 = new Button_muxin(950, 295, 300, 70, "减少音量", [&]() {
        bgm.decrease();
        });
    addButton(0, button1_4);

    //打开音效
    Button_muxin* button1_5 = new Button_muxin(350, 395, 300, 70, "打开音效", [&]() {
        //打开音效,需要判断函数
        isSound = true;
        });
    addButton(0, button1_5);

    //关闭音效
    Button_muxin* button1_6 = new Button_muxin(950, 395, 300, 70, "关闭音效", [&]() {
        //关闭音效，判断函数
        isSound = false;
        });
    addButton(0, button1_6);

    //退出登录
    Button_muxin* button1_1 = new Button_muxin(350, 595, 300, 70, "退出登录", [&]() {
		rtnFlag = 1;		////明雅流风//// (退-1)  无0  l1  m2  p3
        });
    addButton(0, button1_1);

    // 键位设置
    Button_muxin* button1_2 = new Button_muxin(950, 595, 300, 70, "键位设置", [&]() {
		// 敬请期待
		MessageBox(GetHWnd(), "键位设置功能暂未开放！\n\t敬请期待……\n\n\t~_(ツ)_/~", "提示（-. -\"）", MB_OK);
        });
    addButton(0, button1_2);

    // 返回菜单
    Button_muxin* button1_3 = new Button_muxin(650, 710, 300, 70, "返回菜单", [&]() {
		Return_Menu_View();
		});
    addButton(0, button1_3);

    setCurrentIndex(0); // 设置初始显示页面为设置页面
}

// 运行，进入消息循环
void Menusetting::run()
{
    while (true)
    {
		if (rtnFlag)		////明雅流风//// (退-1)  无0  l1  m2  p3
			break;

        if (peekmessage(&msg)) // 检查是否有消息
        {
            int mouseX = msg.x; // 获取鼠标x坐标
            int mouseY = msg.y; // 获取鼠标y坐标

            switch (msg.message)
            {
            case WM_LBUTTONDOWN: // 鼠标左键按下事件
                mouseClick(mouseX, mouseY); // 处理鼠标点击事件
                break;
            case WM_MOUSEMOVE: // 鼠标移动事件
                mouseMove(mouseX, mouseY); // 处理鼠标移动事件
                break;
            }
        }

        draw();				// 绘制当前页面内容
    }
}

void Menu_Setting_View()
{
    Menusetting menu_view(1600, 900);
    menu_view.init();
    menu_view.run();
	
	if (rtnFlag != 1)		////明雅流风//// (退-1)  无0  l1  m2  p3
		rtnFlag = 0;
}
