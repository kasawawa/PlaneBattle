#pragma once
class Player
{
private:
    //������
    int id;
    //����Ѫ��
    int blood;
    //�ٶ�
    int speed;
    //xλ��
    int x = 40;
    //������
    int y = 800;
    //��С
    int size;
    //�ӵ����
    int id_bullet;
    //����
    int rate;
    //�������ֵ
    int maxblood;
    //����ֵ
    int shield;
    //������ȴʱ��
    int powerCD;
    //��һ�������ʣ֡��
    int nextshoot = 0;
    //��һ������ʹ�û�ʣ֡��
    int nextpower = 0;
    //����3��������ɱ������
    int needkill;
    //��������ʱ��
    int duration;
    //�������
    //1��20��1���ܣ�10%����
    //2�����ܴ����˺�Ӱ�죬Ҳ����ͨ���Ӵ���ɱ����
    //3�����˺���4s�޵�ʱ�䣬���޵�ʱ����ɱ��4�����ϵ��˼��ɻظ�1��Ѫ��,ÿ��һ�����һ��
    //4�����������٣�����4�룬CD60��
    //5��ȫ������10s������ӵ���cd60
    //6���Ա����������2���˺�
    int power;
    //��ɫͼƬ
    IMAGE img_role;
    //�ڵ�
    IMAGE img0;
public:
    /*
        ���ܣ�ֱ�Ӹ��ݽ�ɫ��ų�ʼ�����
        ��������ɫ���
    */
    void role(int id_role);
    // ��ɫ��ŵ� getter �� setter
    int getId() const { return id; }
    void setId(int id_) { id = id_; }

    // Ѫ���� getter �� setter
    int getBlood() const { return blood; }
    void setBlood(int blood_) { blood = blood_; }

    // �ٶȵ� getter �� setter
    int getSpeed() const { return speed; }
    void setSpeed(int speed_) { speed = speed_; }

    // x ����� getter �� setter
    int getX() const { return x; }
    void setX(int x_) { x = x_; }

    // y ����� getter �� setter
    int getY() const { return y; }
    void setY(int y_) { y = y_; }

    // ��С�� getter �� setter
    int getSize() const { return size; }
    void setSize(int size_) { size = size_; }

    // �ӵ���ŵ� getter �� setter
    int getBulletId() const { return id_bullet; }
    void setBulletId(int id_bullet_) { id_bullet = id_bullet_; }

    // ���ٵ� getter �� setter
    int getRate() const { return rate; }
    void setRate(int rate_) { rate = rate_; }

    // �������ֵ�� getter �� setter
    int getMaxBlood() const { return maxblood; }
    void setMaxBlood(int maxblood_) { maxblood = maxblood_; }

    // ����ֵ�� getter �� setter
    int getShield() const { return shield; }
    void setShield(int shield_) { shield = shield_; }

    // ������ȴʱ��� getter �� setter
    int getPowerCD() const { return powerCD; }
    void setPowerCD(int powerCD_) { powerCD = powerCD_; }

    // ��һ�������ʣ֡���� getter �� setter
    int getNextShoot() const { return nextshoot; }
    void setNextShoot(int nextshoot_) { nextshoot = nextshoot_; }

    // ��һ������ʹ�û�ʣ֡���� getter �� setter
    int getNextPower() const { return nextpower; }
    void setNextPower(int nextpower_) { nextpower = nextpower_; }

    // ������ŵ� getter �� setter
    int getPower() const { return power; }
    void setPower(int power_) { power = power_; }

    // ��ɫͼƬ�� getter �� setter
    IMAGE getimg() const { return img_role; }
    void setimg(IMAGE img) { img_role = img; }

    // �ڵ׵� getter �� setter
    IMAGE getimg0() const { return img0; }
    void setimg0(IMAGE img) { img0 = img; }

    // ����3������ getter �� setter
    int getNeedKill() const { return needkill; }
    void setNeedKill(int _needkill) { needkill = _needkill; }

};