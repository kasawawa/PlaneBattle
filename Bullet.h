#pragma once
//�ӵ��࣬��ʱ�����Ƿ��ӵ�����
class Bullet
{
private:
    //�ӵ����
    int id;
    //�ӵ��˺�
    int damage;
    //��Сx��������ײ
    int sizex;
    //��Сy��������ײ
    int sizey;
    //�ٶ�
    int speed;
    //������
    int x;
    //������
    int y;
    //����Ч�� 
    // 1:8%��ɱ
    // 2:����
    int power;
    //�ӵ�ͼƬ
    IMAGE img;
    //�ڵ�
    IMAGE img0;
public:
    /*
        ���ܣ�ֱ�Ӹ��ݱ�ų�ʼ���ӵ�
        �������ӵ����
    */
    Bullet(int id_bullet, int ix, int iy);
    // Getter �� Setter ����
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