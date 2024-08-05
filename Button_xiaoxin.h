#pragma once
#include <string>
#include <functional>

class Button_xiaoxin
{
private:
    int x;
    int y;
    int width;
    int height;
    float scale;
    bool isMouseOver;
    std::string text;
    std::function<void()> onClick;

public:
    Button_xiaoxin(int x, int y, int width, int height, const std::string& text, const std::function<void()>& onClick);

    void checkMouseOver(int mouseX, int mouseY);
    bool checkClick(int mouseX, int mouseY);
    void draw();
};