#pragma once
#include <irrKlang.h>
#include <functional>
#include <string>
#include <vector>
#include <easyx.h>
#include <iostream>

//������
class Volume {
private:
    int volume; // ��ǰ����
    static const int maxVolume = 100; // �������
    static const int minVolume = 0; // ��С����
    irrklang::ISound* currentBGM; // ��ǰ���ŵ�BGM
    irrklang::ISoundEngine* Bengine; // irrKlang ��������
    bool isPlaying; // ����Ƿ����ڲ�������
    bool isPaused; // ����������Ƿ���ͣ

public:
    Volume();
    ~Volume();
    void showSettingsMenu();
    void increase(); //��������
    void decrease(); //��������
    void setvolume(int); //��������
    int getvolume(); //��ȡ��ǰ����
    void displayVolume(); //����չʾ
    void playmusic(const char* soundFile); //����bgm
    void stopMusic(); //ֹͣ����
    bool isMusicPlaying() const; //����Ƿ����ڲ�������
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

    // ��������
    void pauseMusic(); // ��ͣ����
    void resumeMusic(); // ��������
    bool isMusicPaused() const; // ����Ƿ���ͣ
};

//��Ч��
class Sound {
private:
    irrklang::ISoundEngine* engine; // irrKlang ��Ч����
    irrklang::ISound* currentSound; // ��ǰ���ŵ���Ч
public:
    void stopSound();//�ر���Ч
    void playSound(const char* soundFile);//������Ч
};

// ����Button_muxin�࣬��ʾ��ť
class Button_muxin
{
private:
    int x; // ��ť���Ͻ�x����
    int y; // ��ť���Ͻ�y����
    int width; // ��ť���
    int height; // ��ť�߶�
    float scale; // ���ű���������ʵ�������ͣЧ��
    bool isMouseOver; // ��ʾ����Ƿ��ڰ�ť�Ϸ�
    std::string text; // ��ť�ı�
    std::function<void()> onClick; // �����ť�����ĺ���

public:
    // ���캯��
    Button_muxin(int x, int y, int width, int height, const std::string& text, const std::function<void()>& onClick);

    // ��������
    ~Button_muxin();

    // �������Ƿ��ڰ�ť�Ϸ�
    void checkMouseOver(int mouseX, int mouseY);

    // ���������Ƿ��ڰ�ť�ڣ���ִ�к���
    bool checkClick(int mouseX, int mouseY);

    // ���ư�ť
    void draw();
};

// ����Menusetting�࣬��ʾҳ�洰��
class Menusetting
{
private:
    int width; // ���
    int height; // �߶�
    int currentIndex; // ��ǰҳ������
    std::vector<IMAGE*> pages; // �洢����ҳ���ͼƬָ��
    std::vector<std::vector<Button_muxin*>> buttons; // �洢ÿ��ҳ���ϵİ�ť

    // ���һ��ҳ��
    void addPage(IMAGE* page);

    // ��ָ��ҳ�������һ����ť
    void addButton(int index, Button_muxin* button);

    // ���õ�ǰ��ʾ��ҳ������
    void setCurrentIndex(int index);

    // ����������¼�
    void mouseClick(int mouseX, int mouseY);

    // ��������ƶ��¼�
    void mouseMove(int mouseX, int mouseY);

    // ���Ƶ�ǰҳ�������
    void draw();

public:
    Menusetting(int width, int height);
    ~Menusetting();

    // ��ʼ���ؼ�������ͼ�λ���������ҳ��Ͱ�ť
    void init();

    // ���У�������Ϣѭ��
    void run();

    // �ر�
    void Return_Menu_View();
};