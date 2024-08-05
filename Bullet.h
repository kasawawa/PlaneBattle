#pragma once
//子弹类，暂时不考虑非子弹武器
class Bullet
{
private:
    //子弹编号
    int id;
    //子弹伤害
    int damage;
    //大小x，决定碰撞
    int sizex;
    //大小y，决定碰撞
    int sizey;
    //速度
    int speed;
    //横坐标
    int x;
    //纵坐标
    int y;
    //特殊效果 
    // 1:8%秒杀
    // 2:减速
    int power;
    //子弹图片
    IMAGE img;
    //黑底
    IMAGE img0;
public:
    /*
        功能：直接根据编号初始化子弹
        参数：子弹编号
    */
    Bullet(int id_bullet, int ix, int iy);
    // Getter 和 Setter 方法
    int getId() const {
        return id;
    }

    void setId(int id_bullet) {
        id = id_bullet;
    }

    int getDamage() const {
        return damage;
    }

    void setDamage(int damage_bullet) {
        damage = damage_bullet;
    }

    int getSizeX() const {
        return sizex;
    }

    void setSize(int sizex_bullet) {
        sizex = sizex_bullet;
    }

    int getSizeY() const {
        return sizey;
    }

    void setSizeY(int sizey_bullet) {
        sizey = sizey_bullet;
    }
    int getSpeed() const {
        return speed;
    }

    void setSpeed(int speed_bullet) {
        speed = speed_bullet;
    }

    int getX() const {
        return x;
    }

    IMAGE getimg() const {
        return img;
    }

    IMAGE getimg0() const {
        return img0;
    }

    void setX(int x_bullet) {
        x = x_bullet;
    }

    int getY() const {
        return y;
    }

    void setY(int y_bullet) {
        y = y_bullet;
    }

    int getPower() const {
        return power;
    }

    void setPower(int power_bullet) {
        power = power_bullet;
    }
};