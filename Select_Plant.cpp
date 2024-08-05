#include <graphics.h>
#include <string>
#include <vector>

// 辅助函数：将文本分割成多行
std::vector<std::string> splitText(const std::string& text, int maxWidth, const LOGFONT& font) {
    std::vector<std::string> lines;
    std::string currentLine;
    std::string word;

    settextstyle(&font);

    for (char c : text) {
        if (c == ' ' || c == '\n') {
            if (textwidth((currentLine + word).c_str()) <= maxWidth) {
                currentLine += word + c;
                word.clear();
            }
            else {
                if (!currentLine.empty()) {
                    lines.push_back(currentLine);
                    currentLine.clear();
                }
                currentLine = word + c;
                word.clear();
            }
            if (c == '\n') {
                lines.push_back(currentLine);
                currentLine.clear();
            }
        }
        else {
            word += c;
        }
    }

    if (!word.empty()) {
        if (textwidth((currentLine + word).c_str()) <= maxWidth) {
            currentLine += word;
        }
        else {
            if (!currentLine.empty()) {
                lines.push_back(currentLine);
            }
            currentLine = word;
        }
    }

    if (!currentLine.empty()) {
        lines.push_back(currentLine);
    }

    return lines;
}

// 主函数：在指定矩形区域内绘制文本
void drawTextInRect(int x, int y, int width, int height, const std::string& text, COLORREF textColor = BLACK, COLORREF bgColor = WHITE) {
    // 设置文本样式
    LOGFONT font;
    gettextstyle(&font);
    font.lfHeight = 20;  // 设置字体大小
    _tcscpy_s(font.lfFaceName, _T("宋体"));  // 设置字体
    settextstyle(&font);

    // 设置颜色
    setbkcolor(bgColor);
    settextcolor(textColor);

    // 绘制背景
    setfillcolor(bgColor);
    solidrectangle(x, y, x + width, y + height);

    // 分割文本
    std::vector<std::string> lines = splitText(text, width, font);

    // 绘制文本
    int lineHeight = textheight("A");  // 使用大写A的高度作为行高
    int startY = y;
    for (const auto& line : lines) {
        if (startY + lineHeight > y + height) break;  // 超出矩形底部，停止绘制
        outtextxy(x, startY, line.c_str());
        startY += lineHeight;
    }
	setbkcolor(LIGHTCYAN);
}