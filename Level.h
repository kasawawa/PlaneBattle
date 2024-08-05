#pragma once
#include <graphics.h> // ���� EasyX ��

class Level {
private:
    int id; // ���
    double Top; // �������
    double Buttom; // �������
    double left; // ��������
    double right; // ��������
    bool isLocked; // �ж��Ƿ����
    bool isPassed; // �ѽ���
    IMAGE image; // ͼ��
public:
    Level(); // ���� Level
    Level(int id, double Top, double Buttom, double left, double right, bool isLocked, bool isPassed); // ��ʼ��
    ~Level(); // �ͷ���Դ
    // ����Ϊ���û�ȡ��ť����� 
    void set_id(int id);
    int get_id();
    void set_Top(double Top);
    double get_Top();
    void set_Buttom(double Buttom);
    double get_Buttom();
    void set_left(double left);
    double get_left();
    void set_right(double right);
    double get_right();
    void set_isLocked(bool isLocked);
    bool get_isLocked();
    void set_isPassed(bool isPassed);
    bool get_isPassed();
};
