#pragma once
class Player
{
private:
    //人物编号
    int id;
    //人物血量
    int blood;
    //速度
    int speed;
    //x位置
    int x = 40;
    //纵坐标
    int y = 800;
    //大小
    int size;
    //子弹编号
    int id_bullet;
    //射速
    int rate;
    //最大生命值
    int maxblood;
    //护盾值
    int shield;
    //能力冷却时间
    int powerCD;
    //下一次射击还剩帧数
    int nextshoot = 0;
    //下一次能力使用还剩帧数
    int nextpower = 0;
    //能力3出发所需杀人数；
    int needkill;
    //能力持续时间
    int duration;
    //能力编号
    //1、20秒1护盾，10%闪避
    //2、不受触碰伤害影响，也不能通过接触击杀敌人
    //3、受伤后获得4s无敌时间，在无敌时间中杀死4个以上敌人即可回复1点血量,每多一个多回一滴
    //4、大幅提高射速，持续4秒，CD60秒
    //5、全屏减速10s，清除子弹，cd60
    //6、对冰冻敌人造成2倍伤害
    int power;
    //角色图片
    IMAGE img_role;
    //黑底
    IMAGE img0;
public:
    /*
        功能：直接根据角色编号初始化玩家
        参数：角色编号
    */
    void role(int id_role);
    // 角色编号的 getter 和 setter
    int getId() const { return id; }
    void setId(int id_) { id = id_; }

    // 血量的 getter 和 setter
    int getBlood() const { return blood; }
    void setBlood(int blood_) { blood = blood_; }

    // 速度的 getter 和 setter
    int getSpeed() const { return speed; }
    void setSpeed(int speed_) { speed = speed_; }

    // x 坐标的 getter 和 setter
    int getX() const { return x; }
    void setX(int x_) { x = x_; }

    // y 坐标的 getter 和 setter
    int getY() const { return y; }
    void setY(int y_) { y = y_; }

    // 大小的 getter 和 setter
    int getSize() const { return size; }
    void setSize(int size_) { size = size_; }

    // 子弹编号的 getter 和 setter
    int getBulletId() const { return id_bullet; }
    void setBulletId(int id_bullet_) { id_bullet = id_bullet_; }

    // 射速的 getter 和 setter
    int getRate() const { return rate; }
    void setRate(int rate_) { rate = rate_; }

    // 最大生命值的 getter 和 setter
    int getMaxBlood() const { return maxblood; }
    void setMaxBlood(int maxblood_) { maxblood = maxblood_; }

    // 护盾值的 getter 和 setter
    int getShield() const { return shield; }
    void setShield(int shield_) { shield = shield_; }

    // 能力冷却时间的 getter 和 setter
    int getPowerCD() const { return powerCD; }
    void setPowerCD(int powerCD_) { powerCD = powerCD_; }

    // 下一次射击还剩帧数的 getter 和 setter
    int getNextShoot() const { return nextshoot; }
    void setNextShoot(int nextshoot_) { nextshoot = nextshoot_; }

    // 下一次能力使用还剩帧数的 getter 和 setter
    int getNextPower() const { return nextpower; }
    void setNextPower(int nextpower_) { nextpower = nextpower_; }

    // 能力编号的 getter 和 setter
    int getPower() const { return power; }
    void setPower(int power_) { power = power_; }

    // 角色图片的 getter 和 setter
    IMAGE getimg() const { return img_role; }
    void setimg(IMAGE img) { img_role = img; }

    // 黑底的 getter 和 setter
    IMAGE getimg0() const { return img0; }
    void setimg0(IMAGE img) { img0 = img; }

    // 能力3参数的 getter 和 setter
    int getNeedKill() const { return needkill; }
    void setNeedKill(int _needkill) { needkill = _needkill; }

};