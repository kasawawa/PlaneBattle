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

// �������Ƿ��ڰ�ť�Ϸ�
void Button_muxin::checkMouseOver(int mouseX, int mouseY)
{
    isMouseOver = (mouseX >= x && mouseX <= x + width && mouseY >= y && mouseY <= y + height);

    if (isMouseOver) {
        scale = 0.9f; // �����ͣʱ���Ű�ť
    }
    else {
        scale = 1.0f; // �ָ���ťԭʼ��С
    }
}

// ���������Ƿ��ڰ�ť�ڣ���ִ�к���
bool Button_muxin::checkClick(int mouseX, int mouseY)
{
    if (mouseX >= x && mouseX <= x + width && mouseY >= y && mouseY <= y + height)
    {
        onClick(); // ִ�а�ť���ʱ�ĺ���
        isMouseOver = false;
        scale = 1.0f;
        return true;
    }
    return false;
}

// ���ư�ť
void Button_muxin::draw()
{
    int scaledWidth = width * scale; // ���ź�İ�ť���
    int scaledHeight = height * scale; // ���ź�İ�ť�߶�
    int scaledX = x + (width - scaledWidth) / 2; // ���ź�İ�ťx����
    int scaledY = y + (height - scaledHeight) / 2; // ���ź�İ�ťy����

    if (isMouseOver)
    {
        setlinecolor(RGB(0, 120, 215)); // �����ͣʱ��ť�߿���ɫ
        setfillcolor(RGB(229, 241, 251)); // �����ͣʱ��ť�����ɫ
    }
    else
    {
        setlinecolor(RGB(173, 173, 173)); // ��ť�߿���ɫ
        setfillcolor(RGB(225, 225, 225)); // ��ť�����ɫ
    }

    fillrectangle(scaledX, scaledY, scaledX + scaledWidth, scaledY + scaledHeight); // ���ư�ť
    settextcolor(BLACK); // �����ı���ɫΪ��ɫ
    //setbkmode(TRANSPARENT); // �����ı�����͸��
    settextstyle(40 * scale, 0, "΢���ź�"); // �����ı���С������
    // ������ʾ��ť�ı�
    int textX = scaledX + (scaledWidth - textwidth(text.c_str())) / 2; // �����ı��ڰ�ť�����x����
    int textY = scaledY + (scaledHeight - textheight("΢���ź�")) / 2; // �����ı��ڰ�ť�����y����
    outtextxy(textX, textY, text.c_str()); // �ڰ�ť�ϻ����ı�
}

Menusetting::Menusetting(int width, int height)
    : width(width), height(height), currentIndex(-1)
{
}

Menusetting::~Menusetting() {}

// ���һ��ҳ��
void Menusetting::addPage(IMAGE* page)
{
    pages.push_back(page);
    buttons.push_back({});
}

// ��ָ��ҳ�������һ����ť
void Menusetting::addButton(int index, Button_muxin* button)
{
    if (index >= 0 && index < buttons.size())
    {
        buttons[index].push_back(button);
    }
}

// ���õ�ǰ��ʾ��ҳ������
void Menusetting::setCurrentIndex(int index)
{
    if (index >= 0 && index < pages.size())
    {
        currentIndex = index;
    }
}

//���ز˵�����
void Menusetting::Return_Menu_View() {
    rtnFlag = 2;		////��������//// (��-1)  ��0  l1  m2  p3
}

// ����������¼�
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

// ��������ƶ��¼�
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

// ���Ƶ�ǰҳ�������
void Menusetting::draw()
{
	BeginBatchDraw();	// ��ʼ��������
    if (currentIndex >= 0 && currentIndex < pages.size())
    {
        putimage(0, 0, pages[currentIndex]); // �ڴ����л��Ƶ�ǰҳ���ͼƬ
        if (currentIndex == 0) {
            bgm.displayVolume();
            outtextxy(770, 80, "����");
            settextstyle(220, 0, "΢���ź�");
        }
        if (currentIndex >= 0 && currentIndex < buttons.size())
        {
            for (Button_muxin* button : buttons[currentIndex])
            {
                button->draw(); // ���Ƶ�ǰҳ���ϵ����а�ť
            }
        }
    }
    bgm.displayVolume();
    outtextxy(770, 80, "����");
    settextstyle(220, 0, "΢���ź�");
	EndBatchDraw();		// ������������
}

bool exitFlag = false; // ����һ��ȫ�ֱ��������˳���־

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
    settextstyle(40, 0, _T("����"));
    outtextxy(640, 240, buffer);
}

// �޸� stopMusic ���������� isPaused ״̬
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
    stopMusic(); // ��ֹͣ��ǰ���ŵ����֣�����У�
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

bool getExitFlag() {//��ȡ�Ƿ��˳�
    return exitFlag;
}

//��������������������������������������������������������������������������������������������//

void Menusetting::init()
{
    //cleardevice();
    // ��������ҳ��
    IMAGE* page1 = new IMAGE(width, height);//����ֱ����loadimage()��������ͼƬ
    loadimage(page1, _T("./src/picture/Menu_Setting.jpeg"), width, height);

    addPage(page1); // �������ҳ��

    //��������
    Button_muxin* button1_0 = new Button_muxin(350, 295, 300, 70, "��������", [&]() {
        bgm.increase();
        });
    addButton(0, button1_0);//����ť��ӵ�ҳ��1

    //��������
    Button_muxin* button1_4 = new Button_muxin(950, 295, 300, 70, "��������", [&]() {
        bgm.decrease();
        });
    addButton(0, button1_4);

    //����Ч
    Button_muxin* button1_5 = new Button_muxin(350, 395, 300, 70, "����Ч", [&]() {
        //����Ч,��Ҫ�жϺ���
        isSound = true;
        });
    addButton(0, button1_5);

    //�ر���Ч
    Button_muxin* button1_6 = new Button_muxin(950, 395, 300, 70, "�ر���Ч", [&]() {
        //�ر���Ч���жϺ���
        isSound = false;
        });
    addButton(0, button1_6);

    //�˳���¼
    Button_muxin* button1_1 = new Button_muxin(350, 595, 300, 70, "�˳���¼", [&]() {
		rtnFlag = 1;		////��������//// (��-1)  ��0  l1  m2  p3
        });
    addButton(0, button1_1);

    // ��λ����
    Button_muxin* button1_2 = new Button_muxin(950, 595, 300, 70, "��λ����", [&]() {
		// �����ڴ�
		MessageBox(GetHWnd(), "��λ���ù�����δ���ţ�\n\t�����ڴ�����\n\n\t~_(��)_/~", "��ʾ��-. -\"��", MB_OK);
        });
    addButton(0, button1_2);

    // ���ز˵�
    Button_muxin* button1_3 = new Button_muxin(650, 710, 300, 70, "���ز˵�", [&]() {
		Return_Menu_View();
		});
    addButton(0, button1_3);

    setCurrentIndex(0); // ���ó�ʼ��ʾҳ��Ϊ����ҳ��
}

// ���У�������Ϣѭ��
void Menusetting::run()
{
    while (true)
    {
		if (rtnFlag)		////��������//// (��-1)  ��0  l1  m2  p3
			break;

        if (peekmessage(&msg)) // ����Ƿ�����Ϣ
        {
            int mouseX = msg.x; // ��ȡ���x����
            int mouseY = msg.y; // ��ȡ���y����

            switch (msg.message)
            {
            case WM_LBUTTONDOWN: // �����������¼�
                mouseClick(mouseX, mouseY); // ����������¼�
                break;
            case WM_MOUSEMOVE: // ����ƶ��¼�
                mouseMove(mouseX, mouseY); // ��������ƶ��¼�
                break;
            }
        }

        draw();				// ���Ƶ�ǰҳ������
    }
}

void Menu_Setting_View()
{
    Menusetting menu_view(1600, 900);
    menu_view.init();
    menu_view.run();
	
	if (rtnFlag != 1)		////��������//// (��-1)  ��0  l1  m2  p3
		rtnFlag = 0;
}
