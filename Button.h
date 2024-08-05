#pragma once
#include <functional>
#include <string>
#include <easyx.h>

class Button {
private:
    std::string label;
    int x, y, width, height;
    bool isHovered;
    bool isPressed;
    COLORREF normalColor;
    COLORREF hoverColor;
    COLORREF pressedColor;
    COLORREF textColor;
    float scaleOnPress;
    std::function<void()> onClick;

public:
    Button(const std::string& label, int x, int y, int width, int height);

    void setLabel(const std::string& newLabel);
    void setPosition(int newX, int newY);
    void setSize(int newWidth, int newHeight);
    void setColors(COLORREF normal, COLORREF hover, COLORREF pressed, COLORREF text);
    void setScaleOnPress(float scale);
    void setOnClick(std::function<void()> callback);

    bool isPointInside(int mouseX, int mouseY) const;
    void update();
    void draw() const;
    bool wasClicked() const;
};