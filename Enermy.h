#pragma once
//近战相关属性
struct Remote_related_attributes
{
	//是否纠缠
	bool entagle;
	//啃咬伤害
	int gnaw_damage;
};
//远程相关属性
struct Melee_related_attributes
{
	//是否到达目的地
	bool destination;
	//子弹编号，(多少帧射击一次）
	int id_bullet, rate;
	//距离下次射击还有多少帧
	int nextshoot = 0;
	//特殊行动规则
	int Special_rules;
};
//敌人
class Enermy
{
private:
	//是否存在
	bool exist;
	//是否BOSS
	bool BOSS;
	//编号
	int id;
	//血量
	int blood;
	//横向速度
	int xspeed;
	//纵向速度
	int yspeed;
	//横坐标
	int x;
	//纵坐标
	int y;
	//y多少帧动一次
	int yrate;
	//大小，决定碰撞
	int size;
	//类型，近战/远程
	int type;
	//护盾值
	int shield;
	//接触伤害
	int touch_damage;
	//提高积分
	int point;
	//动作编号
	int actionid;
	//下一次y动还剩帧数
	int nexty = 30;
	//y方向移动方式modeofmovey 1：一直向下穿过边界从上方下来 2：一直向上穿过编辑从下方上来 3:停在生成y
	int modeofmovey;
	//减速时长
	int deceleration = 0;
	//没有即近战又远程的怪，暂时用联合体
	union
	{
		struct Melee_related_attributes M;
		struct Remote_related_attributes R;
	};
public:
	//无参构造，不存在该敌人
	Enermy();
	void initialization(int id_enermy, int ix, int iy, int level);

	bool isExist() const { return exist; }
	bool isBoss() const { return BOSS; }
	int getId() const { return id; }
	int getBlood() const { return blood; }
	int getXSpeed() const { return xspeed; }
	int getYSpeed() const { return yspeed; }
	int getX() const { return x; }
	int getY() const { return y; }
	int getYRate() const { return yrate; }
	int getSize() const { return size; }
	int getType() const { return type; }
	int getShield() const { return shield; }
	int getTouchDamage() const { return touch_damage; }
	int getPoint() const { return point; }
	int getActionId() const { return actionid; }
	int getNextY() const { return nexty; }
	int getBulletId() const { return M.id_bullet; }
	int getRate() const { return M.rate; }
	int getNextShoot() const { return M.nextshoot; }
	int getModeOfMovey() const { return modeofmovey; }
	int getDeceleration() const { return deceleration; }
	void setExist(bool newExist) { exist = newExist; }
	void setBoss(bool newBoss) { BOSS = newBoss; }
	void setId(int newId) { id = newId; }
	void setBlood(int newBlood) { blood = newBlood; }
	void setXSpeed(int newXSpeed) { xspeed = newXSpeed; }
	void setYSpeed(int newYSpeed) { yspeed = newYSpeed; }
	void setX(int newX) { x = newX; }
	void setY(int newY) { y = newY; }
	void setYRate(int newYRate) { yrate = newYRate; }
	void setSize(int newSize) { size = newSize; }
	void setType(int newType) { type = newType; }
	void setShield(int newShield) { shield = newShield; }
	void setTouchDamage(int newTouchDamage) { touch_damage = newTouchDamage; }
	void setPoint(int newPoint) { point = newPoint; }
	void setActionId(int newActionId) { actionid = newActionId; }
	void setNextY(int newNextY) { nexty = newNextY; }
	void setBulletId(int id_bullet) { M.id_bullet = id_bullet; }
	void setRate(int rate) { M.rate = rate; }
	void setNextShoot(int nextshoot) { M.nextshoot = nextshoot; }
	void setModeOfMovey(int newmodeofmovey) { modeofmovey = newmodeofmovey; }
	void setDeceleration(int newdeceleration) { deceleration = newdeceleration; }
};