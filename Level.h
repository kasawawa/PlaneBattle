#pragma once
#include <graphics.h> // 引入 EasyX 库

class Level {
private:
    int id; // 编号
    double Top; // 最高坐标
    double Buttom; // 最低坐标
    double left; // 最左坐标
    double right; // 最右坐标
    bool isLocked; // 判断是否解锁
    bool isPassed; // 已解锁
    IMAGE image; // 图像
public:
    Level(); // 调用 Level
    Level(int id, double Top, double Buttom, double left, double right, bool isLocked, bool isPassed); // 初始化
    ~Level(); // 释放资源
    // 以下为设置获取按钮坐标等 
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
