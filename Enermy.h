#pragma once
//��ս�������
struct Remote_related_attributes
{
	//�Ƿ����
	bool entagle;
	//��ҧ�˺�
	int gnaw_damage;
};
//Զ���������
struct Melee_related_attributes
{
	//�Ƿ񵽴�Ŀ�ĵ�
	bool destination;
	//�ӵ���ţ�(����֡���һ�Σ�
	int id_bullet, rate;
	//�����´�������ж���֡
	int nextshoot = 0;
	//�����ж�����
	int Special_rules;
};
//����
class Enermy
{
private:
	//�Ƿ����
	bool exist;
	//�Ƿ�BOSS
	bool BOSS;
	//���
	int id;
	//Ѫ��
	int blood;
	//�����ٶ�
	int xspeed;
	//�����ٶ�
	int yspeed;
	//������
	int x;
	//������
	int y;
	//y����֡��һ��
	int yrate;
	//��С��������ײ
	int size;
	//���ͣ���ս/Զ��
	int type;
	//����ֵ
	int shield;
	//�Ӵ��˺�
	int touch_damage;
	//��߻���
	int point;
	//�������
	int actionid;
	//��һ��y����ʣ֡��
	int nexty = 30;
	//y�����ƶ���ʽmodeofmovey 1��һֱ���´����߽���Ϸ����� 2��һֱ���ϴ����༭���·����� 3:ͣ������y
	int modeofmovey;
	//����ʱ��
	int deceleration = 0;
	//û�м���ս��Զ�̵Ĺ֣���ʱ��������
	union
	{
		struct Melee_related_attributes M;
		struct Remote_related_attributes R;
	};
public:
	//�޲ι��죬�����ڸõ���
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