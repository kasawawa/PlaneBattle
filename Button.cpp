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

    // �����ť״̬��δ���±�Ϊ���£���������¼�
    if (!wasPressed && isPressed && onClick) {
        onClick();
    }
}

void Button::draw() const {
    // �������ź�ƫ��
    float scale = isPressed ? scaleOnPress : 1.0f;
    int scaledWidth = static_cast<int>(width * scale);
    int scaledHeight = static_cast<int>(height * scale);
    int offsetX = (width - scaledWidth) / 2;
    int offsetY = (height - scaledHeight) / 2;

    // ���������ɫ
    COLORREF fillColor = isPressed ? pressedColor : (isHovered ? hoverColor : normalColor);
    setfillcolor(fillColor);

    // ���ư�ť����
    fillroundrect(x + offsetX, y + offsetY, x + offsetX + scaledWidth, y + offsetY + scaledHeight, 10, 10);

    // �����ı���ɫ����ʽ
    settextcolor(textColor);
    //setbkmode(TRANSPARENT);

    // ���ø���������С
    int fontSize = min(scaledWidth, scaledHeight) / 2; // ����Ե����������
    settextstyle(fontSize, 0, "Arial"); // ʹ�� Arial ���壬����Ը�����Ҫ����

    // �����ı�λ���Ծ�����ʾ
    int textWidth = textwidth(label.c_str());
    int textHeight = textheight(label.c_str());
    int textX = x + offsetX + (scaledWidth - textWidth) / 2;
    int textY = y + offsetY + (scaledHeight - textHeight) / 2;

    // �����ı�
    outtextxy(textX, textY, label.c_str());

    // �ָ�Ĭ���������ã���ѡ��
    settextstyle(20, 0, "����"); // ʹ�� 16 ��ΪĬ�������С
}

bool Button::wasClicked() const {
    return isPressed;
}