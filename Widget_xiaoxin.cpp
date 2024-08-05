#include "Enviroment.h"

Widget_xiaoxin::Widget_xiaoxin(int width, int height)
    :width(width), height(height), currentIndex(-1)
{
}

Widget_xiaoxin::~Widget_xiaoxin()
{
    // ������Դ
    for (auto page : pages) {
        delete page;
    }
    for (auto& pageButtons : buttons) {
        for (auto button : pageButtons) {
            delete button;
        }
    }
}

void Widget_xiaoxin::addPage(IMAGE* page)
{
    pages.push_back(page);
    buttons.push_back({});
}

void Widget_xiaoxin::Select_Plant() {
    Select_Plant_view();
}

void MenuSettingView() {
    Menu_Setting_View();
}

void Widget_xiaoxin::addButton(int index, Button_xiaoxin* button)
{
    if (index >= 0 && index < buttons.size())
    {
        buttons[index].push_back(button);
    }
}

void Widget_xiaoxin::setCurrentIndex(int index)
{
    if (index >= 0 && index < pages.size())
    {
        currentIndex = index;
    }
}

void Widget_xiaoxin::mouseClick(int mouseX, int mouseY)
{
    if (currentIndex >= 0 && currentIndex < buttons.size())
    {
        for (Button_xiaoxin* button : buttons[currentIndex])
        {
            if (button->checkClick(mouseX, mouseY))
            {
                break;
            }
        }
    }
}

void Widget_xiaoxin::mouseMove(int mouseX, int mouseY)
{
    if (currentIndex >= 0 && currentIndex < buttons.size())
    {
        for (Button_xiaoxin* button : buttons[currentIndex])
        {
            button->checkMouseOver(mouseX, mouseY);
        }
    }
}

void Widget_xiaoxin::draw()
{
	BeginBatchDraw();
    if (currentIndex >= 0 && currentIndex < pages.size())
    {
        putimage(0, 0, pages[currentIndex]);

        if (currentIndex >= 0 && currentIndex < buttons.size())
        {
            for (Button_xiaoxin* button : buttons[currentIndex])
            {
                button->draw();
            }
        }
    }
	EndBatchDraw();
}

void Widget_xiaoxin::init()                                         //�����˰�ťλ�ã���ɫ����С���߿���ɫ������˱���ͼƬ
{
    //cleardevice();
    // ����ҳ��1
    IMAGE* page1 = new IMAGE(width, height);

    loadimage(page1, _T("./src/picture/Menu1.png"), width, height);
    addPage(page1);

    // ���ҳ��1�İ�ť
    addButton(0, new Button_xiaoxin(100, 700, 200, 100, "��ʼ��Ϸ", [&]() { Select_Plant(); }));
    addButton(0, new Button_xiaoxin(500, 700, 200, 100, "�淨����", [&]() { displayInstructions(); }));
    addButton(0, new Button_xiaoxin(900, 700, 200, 100, "����", [&]() { Menu_Setting_View(); }));
    addButton(0, new Button_xiaoxin(1300, 700, 200, 100, "�˳���Ϸ", [&]() { rtnFlag = -1; }));		////��������//// (��-1)  ��0  l1  m2  p3

    setCurrentIndex(0);
}

void Widget_xiaoxin::run()
{
    while (true)
    {
		if (rtnFlag == 1)		////��������//// (��-1)  ��0  l1  m2  p3
			break;
		else if (rtnFlag == -1)		////��������//// (��-1)  ��0  l1  m2  p3
			if (MessageBox(GetHWnd(), "ȷ���˳���", "�˳���ʾ��-. -\"��", MB_YESNO) == IDYES)
				break;
			else
				rtnFlag = 0;

        if (peekmessage(&msg))
        {
            int mouseX = msg.x;
            int mouseY = msg.y;

            switch (msg.message)
            {
            case WM_LBUTTONDOWN:
                mouseClick(mouseX, mouseY);
                break;
            case WM_MOUSEMOVE:
                mouseMove(mouseX, mouseY);
                break;
            }
        }

        draw();
    }
}
