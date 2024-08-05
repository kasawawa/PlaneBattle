#include "Button.h"
#include <algorithm>
#include <easyx.h>
#include <cmath>
#include "Enviroment.h"

Button::Button(const std::string& label, int x, int y, int width, int height)
    : label(label), x(x), y(y), width(width), height(height),
    isHovered(false), isPressed(false),
    normalColor(RGB(200, 200, 200)),
    hoverColor(RGB(220, 220, 220)),
    pressedColor(RGB(180, 180, 180)),
    textColor(BLACK),
    scaleOnPress(0.95f) {}

void Button::setLabel(const std::string& newLabel) {
    label = newLabel;
}

void Button::setPosition(int newX, int newY) {
    x = newX;
    y = newY;
}

void Button::setSize(int newWidth, int newHeight) {
    width = newWidth;
    height = newHeight;
}

void Button::setColors(COLORREF normal, COLORREF hover, COLORREF pressed, COLORREF text) {
    normalColor = normal;
    hoverColor = hover;
    pressedColor = pressed;
    textColor = text;
}

void Button::setScaleOnPress(float scale) {
    scaleOnPress = scale;
}

void Button::setOnClick(std::function<void()> callback) {
    onClick = callback;
}

bool Button::isPointInside(int mouseX, int mouseY) const {
    return (mouseX >= x && mouseX <= x + width && mouseY >= y && mouseY <= y + height);
}

void Button::update() {
    bool wasPressed = isPressed;
    isHovered = isPointInside(msg.x, msg.y);

	isPressed = false;
    if (msg.message == WM_LBUTTONDOWN && isHovered) {
        isPressed = true;
    }
    else if (msg.message == WM_LBUTTONUP) {
        if (isPressed && isHovered && onClick) {
            onClick();
        }
        isPressed = false;
    }

    // 如果按钮状态从未按下变为按下，触发点击事件
    if (!wasPressed && isPressed && onClick) {
        onClick();
    }
}

void Button::draw() const {
    // 计算缩放和偏移
    float scale = isPressed ? scaleOnPress : 1.0f;
    int scaledWidth = static_cast<int>(width * scale);
    int scaledHeight = static_cast<int>(height * scale);
    int offsetX = (width - scaledWidth) / 2;
    int offsetY = (height - scaledHeight) / 2;

    // 设置填充颜色
    COLORREF fillColor = isPressed ? pressedColor : (isHovered ? hoverColor : normalColor);
    setfillcolor(fillColor);

    // 绘制按钮矩形
    fillroundrect(x + offsetX, y + offsetY, x + offsetX + scaledWidth, y + offsetY + scaledHeight, 10, 10);

    // 设置文本颜色和样式
    settextcolor(textColor);
    //setbkmode(TRANSPARENT);

    // 设置更大的字体大小
    int fontSize = min(scaledWidth, scaledHeight) / 2; // 你可以调整这个比例
    settextstyle(fontSize, 0, "Arial"); // 使用 Arial 字体，你可以根据需要更改

    // 计算文本位置以居中显示
    int textWidth = textwidth(label.c_str());
    int textHeight = textheight(label.c_str());
    int textX = x + offsetX + (scaledWidth - textWidth) / 2;
    int textY = y + offsetY + (scaledHeight - textHeight) / 2;

    // 绘制文本
    outtextxy(textX, textY, label.c_str());

    // 恢复默认字体设置（可选）
    settextstyle(20, 0, "宋体"); // 使用 16 作为默认字体大小
}

bool Button::wasClicked() const {
    return isPressed;
}