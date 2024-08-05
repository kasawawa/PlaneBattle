#include "Level.h"

Level::Level() {
    // 构造函数的实现
}

Level::Level(int id, double Top, double Buttom, double left, double right, bool isLocked, bool isPassed)
    : id(id), Top(Top), Buttom(Buttom), left(left), right(right), isLocked(isLocked), isPassed(isPassed) {
    // 带参数的构造函数实现
}

Level::~Level() {
    // 析构函数的实现
}

void Level::set_id(int id) {
    this->id = id;
}

int Level::get_id() {
    return id;
}

void Level::set_Top(double Top) {
    this->Top = Top;
}

double Level::get_Top() {
    return Top;
}

void Level::set_Buttom(double Buttom) {
    this->Buttom = Buttom;
}

double Level::get_Buttom() {
    return Buttom;
}

void Level::set_left(double left) {
    this->left = left;
}

double Level::get_left() {
    return left;
}

void Level::set_right(double right) {
    this->right = right;
}

double Level::get_right() {
    return right;
}

void Level::set_isLocked(bool isLocked) {
    this->isLocked = isLocked;
}

bool Level::get_isLocked() {
    return isLocked;
}

void Level::set_isPassed(bool isPassed) {
    this->isPassed = isPassed;
}

bool Level::get_isPassed() {
    return isPassed;
}
