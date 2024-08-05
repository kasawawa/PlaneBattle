#pragma once
#include <vector>
#include <easyx.h>
#include "Button_xiaoxin.h"  // �������Ѿ���Button�����ΪButton_xiaoxin

class Widget_xiaoxin
{
private:
    int width;
    int height;
    int currentIndex;
    std::vector<IMAGE*> pages;
    std::vector<std::vector<Button_xiaoxin*>> buttons;

    void addPage(IMAGE* page);
    void addButton(int index, Button_xiaoxin* button);
    void setCurrentIndex(int index);
    void mouseClick(int mouseX, int mouseY);
    void mouseMove(int mouseX, int mouseY);
    void draw();

public:
    Widget_xiaoxin(int width, int height);
    ~Widget_xiaoxin();

    void init();
    void run();
    void Select_Plant();
};
