#pragma once
#include <irrKlang.h>
#include <functional>
#include <string>
#include <vector>
#include <easyx.h>
#include <iostream>

//音量类
class Volume {
private:
    int volume; // 当前音量
    static const int maxVolume = 100; // 最大音量
    static const int minVolume = 0; // 最小音量
    irrklang::ISound* currentBGM; // 当前播放的BGM
    irrklang::ISoundEngine* Bengine; // irrKlang 音乐引擎
    bool isPlaying; // 标记是否正在播放音乐
    bool isPaused; // 新增：标记是否暂停

public:
    Volume();
    ~Volume();
    void showSettingsMenu();
    void increase(); //增加音量
    void decrease(); //减少音量
    void setvolume(int); //调整音量
    int getvolume(); //获取当前音量
    void displayVolume(); //音量展示
    void playmusic(const char* soundFile); //播放bgm
    void stopMusic(); //停止播放
    bool isMusicPlaying() const; //检查是否正在播放音乐
    void onceplay(const char* soundFile) { 
        currentBGM = Bengine->play2D(soundFile, false, false, true, irrklang::ESM_AUTO_DETECT, true); 
        isPlaying = true;
    } 
    void playvideomusic(const char* soundFile) { 
        Sleep(2000); stopMusic();  
        if (Bengine) { 
            currentBGM = Bengine->play2D(soundFile, true, false, true, irrklang::ESM_AUTO_DETECT, true); 
            if (currentBGM) { 
                currentBGM->setVolume(volume / 100.0f); 
            } 
        }
        isPlaying = true;
    }

    // 新增方法
    void pauseMusic(); // 暂停播放
    void resumeMusic(); // 继续播放
    bool isMusicPaused() const; // 检查是否暂停
};

//音效类
class Sound {
private:
    irrklang::ISoundEngine* engine; // irrKlang 音效引擎
    irrklang::ISound* currentSound; // 当前播放的音效
public:
    void stopSound();//关闭音效
    void playSound(const char* soundFile);//播放音效
};

// 定义Button_muxin类，表示按钮
class Button_muxin
{
private:
    int x; // 按钮左上角x坐标
    int y; // 按钮左上角y坐标
    int width; // 按钮宽度
    int height; // 按钮高度
    float scale; // 缩放比例，用于实现鼠标悬停效果
    bool isMouseOver; // 表示鼠标是否在按钮上方
    std::string text; // 按钮文本
    std::function<void()> onClick; // 点击按钮触发的函数

public:
    // 构造函数
    Button_muxin(int x, int y, int width, int height, const std::string& text, const std::function<void()>& onClick);

    // 析构函数
    ~Button_muxin();

    // 检查鼠标是否在按钮上方
    void checkMouseOver(int mouseX, int mouseY);

    // 检查鼠标点击是否在按钮内，并执行函数
    bool checkClick(int mouseX, int mouseY);

    // 绘制按钮
    void draw();
};

// 定义Menusetting类，表示页面窗口
class Menusetting
{
private:
    int width; // 宽度
    int height; // 高度
    int currentIndex; // 当前页面索引
    std::vector<IMAGE*> pages; // 存储所有页面的图片指针
    std::vector<std::vector<Button_muxin*>> buttons; // 存储每个页面上的按钮

    // 添加一个页面
    void addPage(IMAGE* page);

    // 在指定页面上添加一个按钮
    void addButton(int index, Button_muxin* button);

    // 设置当前显示的页面索引
    void setCurrentIndex(int index);

    // 处理鼠标点击事件
    void mouseClick(int mouseX, int mouseY);

    // 处理鼠标移动事件
    void mouseMove(int mouseX, int mouseY);

    // 绘制当前页面的内容
    void draw();

public:
    Menusetting(int width, int height);
    ~Menusetting();

    // 初始化控件，创建图形环境，设置页面和按钮
    void init();

    // 运行，进入消息循环
    void run();

    // 关闭
    void Return_Menu_View();
};