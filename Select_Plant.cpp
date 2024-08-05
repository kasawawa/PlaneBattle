#include <graphics.h>
#include <string>
#include <vector>

// �������������ı��ָ�ɶ���
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

// ����������ָ�����������ڻ����ı�
void drawTextInRect(int x, int y, int width, int height, const std::string& text, COLORREF textColor = BLACK, COLORREF bgColor = WHITE) {
    // �����ı���ʽ
    LOGFONT font;
    gettextstyle(&font);
    font.lfHeight = 20;  // ���������С
    _tcscpy_s(font.lfFaceName, _T("����"));  // ��������
    settextstyle(&font);

    // ������ɫ
    setbkcolor(bgColor);
    settextcolor(textColor);

    // ���Ʊ���
    setfillcolor(bgColor);
    solidrectangle(x, y, x + width, y + height);

    // �ָ��ı�
    std::vector<std::string> lines = splitText(text, width, font);

    // �����ı�
    int lineHeight = textheight("A");  // ʹ�ô�дA�ĸ߶���Ϊ�и�
    int startY = y;
    for (const auto& line : lines) {
        if (startY + lineHeight > y + height) break;  // �������εײ���ֹͣ����
        outtextxy(x, startY, line.c_str());
        startY += lineHeight;
    }
	setbkcolor(LIGHTCYAN);
}