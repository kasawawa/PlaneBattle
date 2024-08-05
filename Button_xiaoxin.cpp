#include "Button_xiaoxin.h"
#include <easyx.h>  // 假设您使用的是EasyX图形库

Button_xiaoxin::Button_xiaoxin(int x, int y, int width, int height, const std::string& text, const std::function<void()>& onClick)
    : x(x), y(y), width(width), height(height), text(text), onClick(onClick), scale(1.0f), isMouseOver(false)
{
}

void Button_xiaoxin::checkMouseOver(int mouseX, int mouseY)
{
    isMouseOver = (mouseX >= x && mouseX <= x + width && mouseY >= y && mouseY <= y + height);
    scale = isMouseOver ? 0.9f : 1.0f;
}

bool Button_xiaoxin::checkClick(int mouseX, int mouseY)
{
    if (mouseX >= x && mouseX <= x + width && mouseY >= y && mouseY <= y + height)
    {
        onClick();
        isMouseOver = false;
        scale = 1.0f;
        return true;
    }
    return false;
}

void Button_xiaoxin::draw()
{
    int scaledWidth = width * scale;
    int scaledHeight = height * scale;
    int scaledX = x + (width - scaledWidth) / 2;
    int scaledY = y + (height - scaledHeight) / 2;

    if (isMouseOver)
    {
        setlinecolor(0);
        setlinestyle(PS_SOLID, 3);
        setfillcolor(RGB(142 / 3 * 2, 163 / 3 * 2, 168 / 3 * 2));
    }
    else
    {
        setlinecolor(0);//142,163,168
        setlinestyle(PS_SOLID, 3);
        setfillcolor(RGB(142, 163, 168));
    }

    fillroundrect(scaledX, scaledY, scaledX + scaledWidth, scaledY + scaledHeight, 10, 10);

    settextcolor(BLACK);
    //setbkmode(TRANSPARENT);
    settextstyle(40 * scale, 0, _T("微软雅黑"));

    int textX = scaledX + (scaledWidth - textwidth(text.c_str())) / 2;
    int textY = scaledY + (scaledHeight - textheight(_T("微软雅黑"))) / 2;
    outtextxy(textX, textY, text.c_str());
}