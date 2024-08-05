#include"Enviroment.h"

Enermy e[MAXENERMYNUM];
Player p;
bool win, lose;
std::list<Bullet> be;
std::list<Bullet> bp;
int level, numofkilled;
int BOSS_need_kill[MAXLEVELNUM] = { 30,50,70,90 };
std::vector<int> id_BOSS[MAXLEVELNUM] = { {1002},{1003},{1004},{1001} };
std::vector<int> id_quintessence[MAXLEVELNUM] = { {101,102},{101,102,103},{102,103,104},{103,104} };
std::vector<int> id_normalenermy[MAXLEVELNUM] = { {1,2} ,{1,2},{1,101,2},{1,101,2,102} };
int id_BOSS_start[MAXLEVELNUM];
int id_quintessence_start[MAXLEVELNUM];
int id_normalenermy_start[MAXLEVELNUM];
bool BOSS_has_created;
IMAGE bkground_game[MAXLEVELNUM];
IMAGE pause, pause0, pausepress;
std::vector<IMAGE> imgBOSS[MAXLEVELNUM];
std::vector<IMAGE> imgquintessence[MAXLEVELNUM];
std::vector<IMAGE> imgenormalenermy[MAXLEVELNUM];
std::vector<IMAGE> imgBOSS0[MAXLEVELNUM];
std::vector<IMAGE> imgquintessence0[MAXLEVELNUM];
std::vector<IMAGE> imgenormalenermy0[MAXLEVELNUM];
/*
	负责人：热爱主义
	功能：根据关卡编号打印关卡地图文件
	参数：当前关卡编号
	返回值：无
*/
void Map_put(int level)
{
	//找到图片之前以黑色作为背景
	//setbkcolor(BLACK);
	//cleardevice();
	putimage(0, 0, &bkground_game[level]);

}
/*
	负责人：热爱主义
	功能：打印敌人
	参数：无
	返回值：无
*/
void Enermy_put()
{
	//	找到图片之前使用以下代码
	for (int i = 0; i < MAXENERMYNUM; i++)
	{
		if (e[i].isExist() == 0)break;
		if (e[i].getDeceleration() > 0)
		{
			setfillcolor(LIGHTBLUE);
			solidrectangle(e[i].getX() - e[i].getSize(), e[i].getY() + e[i].getSize(), e[i].getX() + e[i].getSize(), 10 + e[i].getY() + e[i].getSize());
		}
	}
	//找到图片后使用以下代码
	for (int i = 0; i < MAXENERMYNUM; i++)
	{
		if (e[i].isExist() == 0)break;
		IMAGE img, img0;
		switch (e[i].getId())
		{
		case 1:
			loadimage(&img, _T(".\\src\\enermy1.png"));
			loadimage(&img0, _T(".\\src\\enermy1black.png"));
			break;
		case 2:
			loadimage(&img, _T(".\\src\\enermy2.png"));
			loadimage(&img0, _T(".\\src\\enermy2black.png"));
			break;
		case 101:
			loadimage(&img, _T(".\\src\\enermy3.png"));
			loadimage(&img0, _T(".\\src\\enermy3black.png"));
			break;
		case 102:
			loadimage(&img, _T(".\\src\\enermy4.png"));
			loadimage(&img0, _T(".\\src\\enerm4black.png"));
			break;
		case 103:
			loadimage(&img, _T(".\\src\\enermy7.jpeg"));
			loadimage(&img0, _T(".\\src\\enermy7black.jpeg"));
			break;
		case 104:
			loadimage(&img, _T(".\\src\\enermy9.png"));
			loadimage(&img0, _T(".\\src\\enermy9black.png"));
			break;
		case 1001:
			loadimage(&img, _T(".\\src\\enermy5.png"));
			loadimage(&img0, _T(".\\src\\enermy5black.png"));
			break;
		case 1002:
			loadimage(&img, _T(".\\src\\enermy6.png"));
			loadimage(&img0, _T(".\\src\\enermy6black.png"));
			break;
		case 1003:
			loadimage(&img, _T(".\\src\\enermy8.jpg"));
			loadimage(&img0, _T(".\\src\\enermy8black.jpg"));
			break;
		case 1004:
			loadimage(&img, _T(".\\src\\enermy10.jpg"));
			loadimage(&img0, _T(".\\src\\enermy10black.jpg"));
			break;
		}
		putimage(e[i].getX() - e[i].getSize(), e[i].getY() - e[i].getSize(), &img0, SRCAND);
		putimage(e[i].getX() - e[i].getSize(), e[i].getY() - e[i].getSize(), &img, SRCPAINT);
	}

}
/*
	负责人：
	功能：在p.getX(),p.getY()位置绘制玩家。p是一个全局变量
	参数：一个Player对象，代表玩家
	返回值：无
*/
void Player_put()
{
	//	找到图片之前使用以下代码
	//setfillcolor(GREEN);
	//solidrectangle(p.getX() - p.getSize(), p.getY() - p.getSize(), p.getX() + p.getSize(), p.getY() + p.getSize());
	//找到图片后使用以下代码
	if (p.getId() == 4)return;
	IMAGE img_role;
	IMAGE img0;
	switch (p.getId())
	{
	case 1://毁灭大炮
		loadimage(&img_role, _T(".\\src\\9.png"));
		loadimage(&img0, _T(".\\src\\9black.png"));
		break;
	case 2://炸弹投手
		loadimage(&img_role, _T(".\\src\\2.png"));
		loadimage(&img0, _T(".\\src\\2black.png"));
		break;
	case 3://阴险坚果
		loadimage(&img_role, _T(".\\src\\3.png"));
		loadimage(&img0, _T(".\\src\\3black.png"));
		break;
	case 4://幽灵射手
		break;
	case 5://狂野射手
		loadimage(&img_role, _T(".\\src\\5.png"));
		loadimage(&img0, _T(".\\src\\5black.png"));
		break;
	case 6://蜗牛射手
		loadimage(&img_role, _T(".\\src\\6.png"));
		loadimage(&img0, _T(".\\src\\6black.png"));
		break;
	case 7://寒冰射手
		loadimage(&img_role, _T(".\\src\\7.png"));
		loadimage(&img0, _T(".\\src\\7black.png"));
		break;
	case 8://冰瓜大炮
		loadimage(&img_role, _T(".\\src\\8.png"));
		loadimage(&img0, _T(".\\src\\8black.png"));
		break;
	case 9://究极毁灭
		loadimage(&img_role, _T(".\\src\\1.png"));
		loadimage(&img0, _T(".\\src\\1black.png"));
		break;
		//......
	}
	putimage(p.getX() - p.getSize(), p.getY() - p.getSize(), &img0, SRCAND);
	putimage(p.getX() - p.getSize(), p.getY() - p.getSize(), &img_role, SRCPAINT);
}
/*
	负责人：
	功能：绘制玩家的子弹
	参数：无
	返回值：无
*/
void Bullet_p_put()
{
	//	找到图片之前使用以下代码
/*	setfillcolor(WHITE);
	for (i = bp.begin(); i != bp.end(); i++)
	{
		solidellipse(i->getX() - 2 * (i->getSize()), i->getY() - i->getSize(), i->getX() + 2 * (i->getSize()), i->getY() + i->getSize());
	}*/
	//找到图片后使用以下代码
	IMAGE bulletimg;
	std::list<Bullet>::iterator i;
	for (i = bp.begin(); i != bp.end(); i++)
	{
		IMAGE img = i->getimg();
		IMAGE img0 = i->getimg0();
		putimage(i->getX() - i->getSizeX(), i->getY() - i->getSizeY(), &img0, SRCAND);
		putimage(i->getX() - i->getSizeX(), i->getY() - i->getSizeY(), &img, SRCPAINT);
	}

}
/*
	负责人：
	功能：绘制敌人的子弹
	参数：无
	返回值：无
*/
void Bullet_e_put()
{
	//	找到图片之前使用以下代码
	setfillcolor(BLUE);
	std::list<Bullet>::iterator i;
	for (i = be.begin(); i != be.end(); i++)
	{
		IMAGE img = i->getimg();
		IMAGE img0 = i->getimg0();
		putimage(i->getX() - i->getSizeX(), i->getY() - i->getSizeY(), &img0, SRCAND);
		putimage(i->getX() - i->getSizeX(), i->getY() - i->getSizeY(), &img, SRCPAINT);
	}
	//找到图片后使用以下代码
/*	IMAGE bulletimg;
	for (i = be.begin(); i != be.end(); i++)
	{
		switch (i->id)
		{
		case 1:
			loadimage(&bulletimg, _T(".\\bullete1"));
		case 2:
			loadimage(&bulletimg, _T(".\\bullete2"));
		}
	}
*/
}
/*
	负责人：
	功能：在左上角绘制玩家血量,格子
	参数：无
	返回值：无
*/
void blood_put()
{
	for (int i = 0; i < p.getBlood(); i++)
	{
		setfillcolor(RED);
		solidrectangle(100 + 15 * i, 10, 110 + 15 * i, 20);
	}
}
/*
	负责人：
	功能：在左上角绘制玩家护盾,格子
	参数：无
	返回值：无
*/
void shield_put()
{
	for (int i = 0; i < p.getShield(); i++)
	{
		setfillcolor(LIGHTGRAY);
		solidrectangle(100 + 15 * i, 25, 110 + 15 * i, 35);
	}
}
/*
	负责人：
	功能：绘制玩家超能力图标，包括冷却状态
	参数：无
	返回值：无
	说明：拓展功能，只是先放个函数声名
*/
//暂不写
void power_put()
{
	if (p.getPower() == 4 && p.getNextPower() >= 1500)
	{
		setfillcolor(RGB(255, 196, 161));
		solidrectangle(10, 5, 80, 40);
		setlinecolor(RGB(255, 204, 92));
		rectangle(10, 5, 80, 40);
		//setbkmode(TRANSPARENT);
		settextcolor(RED);
		settextstyle(32, 0, _T("黑体"));
		outtextxy(12, 5, _T("能力"));
		settextcolor(RED);
		outtextxy(10, 55, _T("FIRE!!!!"));
		return;
	}
	setfillcolor(RGB(199, 196, 161));
	solidrectangle(10, 5, 80, 40);
	setlinecolor(RGB(255, 204, 92));
	rectangle(10, 5, 80, 40);
	//setbkmode(TRANSPARENT);
	settextcolor(BLACK);
	settextstyle(32, 0, _T("黑体"));
	outtextxy(12, 5, _T("能力"));
	settextcolor(RGB(248, 248, 255));
	double powertime = (double)p.getNextPower() / 25.0;
	std::string sc_str = std::to_string(powertime);
	const char* outputtime = sc_str.c_str();
	settextstyle(32, 0, _T("consolas"));
	outtextxy(10, 55, outputtime);
}
/*
	负责人：
	功能：在顶部正中央绘制玩家分数值（实时）
	参数：分数值
	返回值：无
*/
void score_put(int score)
{
	settextcolor(RGB(240, 248, 255));
	std::string sc_str = std::to_string(score);
	const char* outputscore = sc_str.c_str();
	settextstyle(32, 0, _T("consolas"));
	outtextxy(770, 10, outputscore);
}
/*
	负责人：
	功能：绘制进度标识，与numofkilled占总敌人数比例有关
	参数：无
	返回值：无
	说明：
*/
//暂不写
void killed_put(int level)
{
	settextcolor(RGB(240, 248, 255));
	double kill = ((double)numofkilled / (double)BOSS_need_kill[level]) * 100;
	if (kill >= 100)kill = 100;
	std::string sc_str = std::to_string(kill);
	const char* outputscore = sc_str.c_str();
	settextstyle(32, 0, _T("consolas"));
	outtextxy(770, 30, outputscore);
	outtextxy(910, 30, _T("%"));
}
/*
	负责人：
	功能：绘制暂停标识
	参数：无
	返回值：无
	说明：
*/
void pause_put()
{
	putimage(bound_right - 120, 0, &pause, SRCAND);
	putimage(bound_right - 120, 0, &pause0, SRCPAINT);
}
/*
	负责人：
	功能：调用所有的***_put函数，完成场景绘制
	参数：无
	返回值：无
*/
void PutAll(int level, int score)
{
	Map_put(level);
	Player_put();
	Enermy_put();
	Bullet_e_put();
	Bullet_p_put();
	blood_put();
	shield_put();
	pause_put();
	power_put();
	score_put(score);
	killed_put(level);
}
/*
	负责人：热爱主义
	功能：读取玩家键盘操作以移动
	参数：无
	返回值：无
	说明：已经写好
*/
void move()
{
	if (GetAsyncKeyState(87) && p.getY() > 0)
	{
		p.setY(p.getY() - p.getSpeed());
		if (p.getY() < 0)p.setY(0);
	}
	if (GetAsyncKeyState(65) && p.getX() > 0)
	{
		p.setX(p.getX() - p.getSpeed());
		if (p.getX() < 0)p.setX(0);
	}
	if (GetAsyncKeyState(83) && p.getY() < bound_bottom)
	{
		p.setY(p.getY() + p.getSpeed());
		if (p.getY() > bound_bottom)p.setY(bound_bottom);
	}
	if (GetAsyncKeyState(68) && p.getX() < bound_right)
	{
		p.setX(p.getX() + p.getSpeed());
		if (p.getX() > bound_right)p.setX(bound_right);
	}
}
/*
	负责人：
	功能：读取玩家键盘输入，如果读取到空格键，根据p.id_bullet初始化p.rate个Bullet对象，
	将它们的x,y设置在p.x,p.y周围，并加入到vector bp中
	参数：无
	返回值：无
*/
void shoot()
{

	if (GetAsyncKeyState(VK_SPACE))
	{
		if (p.getId() == 5 && p.getNextPower() >= 1500)
		{
			int x = p.getX(), y = p.getY();
			Bullet b1(p.getBulletId(), x + 15, y + 40);
			Bullet b2(p.getBulletId(), x + 10, y + 20);
			Bullet b3(p.getBulletId(), x + 20, y - 10);
			Bullet b4(p.getBulletId(), x + 25, y - 30);
			bp.push_front(b1);
			bp.push_front(b2);
			bp.push_front(b3);
			bp.push_front(b4);
		}
		else if (p.getNextShoot() == 0)
		{
			int x = p.getX(), y = p.getY();
			if (p.getId() == 6)y += 10;
			else if (p.getId() == 9)
			{
				for (int i = 0; i < 15; i++)
				{
					Bullet b(p.getBulletId(), x, i * 60);
					bp.push_front(b);
				}
				p.setNextShoot(p.getRate());
				return;
			}
			else if (p.getId() == 2)y -= 14;
			else if (p.getId() == 3)
			{
				y += 3;
				x += 30;
			}
			else if (p.getId() == 5)
			{
				Bullet b1(p.getBulletId(), x + 15, y + 40);
				Bullet b2(p.getBulletId(), x + 10, y + 20);
				Bullet b3(p.getBulletId(), x + 20, y - 10);
				Bullet b4(p.getBulletId(), x + 25, y - 30);
				bp.push_front(b1);
				bp.push_front(b2);
				bp.push_front(b3);
				bp.push_front(b4);
				p.setNextShoot(p.getRate());
				return;
			}
			else if (p.getId() == 7)
			{
				y -= 7;
			}
			Bullet b(p.getBulletId(), x, y);
			bp.push_front(b);
			p.setNextShoot(p.getRate());
		}
	}
}
/*
	负责人：
	功能：调用move()、shoot()
	参数：无
	返回值：无
*/
bool act()
{

	if (GetAsyncKeyState(VK_ESCAPE))
	{
		bool re = pauseview();
		if (re)return 1;
	}
	if (GetAsyncKeyState('F'))
	{
		if (p.getPower() == 4 && p.getNextPower() == 0)
		{
			p.setNextPower(p.getPowerCD());
		}
		if (p.getPower() == 5 && p.getNextPower() == 0)
		{
			p.setNextPower(p.getPowerCD());
			for (int i = 0; i < MAXENERMYNUM; i++)
			{
				e[i].setDeceleration(750);
			}
			std::list<Bullet>::iterator i = be.begin();
			while (i != be.end())
			{
				be.erase(i++);
			}
		}
	}
	if (p.getNextShoot() > 0)p.setNextShoot(p.getNextShoot() - 1);
	move();
	shoot();
	return 0;
}
/*
	负责人：
	功能：判断敌人是否有护盾，有则扣除一点护盾并返回0。无则扣除damage*伤害吸收率（buff效果，扩展内容）
	如果此时敌人血量在零以上直接返回0
	如果此时敌人血量在零以下判断是否BOSS，若是将win改为1，并输入到文件中，否则将e[iter].exist改为0，返回1
	参数：需要判断的敌人在e数组里的编号，伤害值
	返回值：是否杀死敌人是敌人分数否0
*/
int e_blood_loss(int iter, int damage)
{
	if (e[iter].getShield())
	{
		e[iter].setShield(e[iter].getShield() - 1);
		return 0;
	}
	e[iter].setBlood(e[iter].getBlood() - damage);
	if (e[iter].getBlood() > 0)return 0;
	e[iter].setExist(0);
	if (e[iter].isBoss())
	{
		win = 1;
		//创建文件后使用以下代码
/*		freopen(".\\iswin.dat", "w", stdout);
		printf("1");
		fclose(stdout);
*/
	}
	if (p.getPower() == 3)
	{
		if (p.getNextPower() > 0)
		{
			p.setNeedKill(p.getNeedKill() - 1);
		}
	}
	return e[iter].getPoint();
}
/*
	负责人：
	功能：判断玩家是否有护盾，有则扣除一点护盾并返回0。无则扣除damage*伤害吸收率（buff效果，扩展内容）
	如果此时玩家血量在零以上直接返回1
	如果此时玩家血量在零以下将lose改为1返回1
	参数：无
	返回值：是否扣血
*/
bool p_blood_loss(int damage)
{
	if (p.getPower() == 3)
	{
		if (p.getNextPower() > 0)
		{
			return 0;
		}
		p.setBlood(p.getBlood() - damage);
		p.setNextPower(p.getPowerCD());
		p.setNeedKill(4);
		return 0;
	}
	if (p.getPower() == 1 && rand() % 100 < 10)
	{
		p.setShield(p.getShield() + 1);
		return 0;
	}
	if (p.getShield() > 0)
	{
		p.setShield(p.getShield() - 1);
		return 0;
	}
	p.setBlood(p.getBlood() - damage);
	if (p.getBlood() <= 0)
	{
		lose = 1;
	}
	return 1;
}
/*
	负责人：
	功能：定义int momentkilled，momentscore
	遍历e数组，对每一个敌人，查找纵坐标离其最近的所有玩家子弹（通过二分查找或某些预处理），
	判定这些子弹是否会与该敌人发生碰撞（碰撞具体逻辑待商量），如果碰撞则进行扣血判定调用e_blood_loss(int,int)，
	将其返回值加起来存放在momentscore中，将返回不为0的次数存入momentkilled中
	最后将momentkilled加入numofkilled返回momentscore
	参数：无
	返回值：分数
*/
int coll_e_bp()
{
	int momentkilled = 0, momentscore = 0;
	for (int i = 0; i < MAXENERMYNUM; i++)
	{
		//暂时直接全部遍历，有必要再写二分查找
		std::list<Bullet>::iterator iter;
		for (iter = bp.begin(); iter != bp.end(); )
		{
			if (iter->getX() - iter->getSizeX() > e[i].getX() + e[i].getSize() || iter->getX() + iter->getSizeX() < e[i].getX() - e[i].getSize())
			{
				iter++;
				continue;
			}
			if (iter->getY() - iter->getSizeY() > e[i].getY() + e[i].getSize() || iter->getY() + iter->getSizeY() < e[i].getY() - e[i].getSize())
			{
				iter++;
				continue;
			}
			int deltax = iter->getX() - e[i].getX(), deltay = iter->getY() - e[i].getY();
			int d_e_bp = sqrt(deltax * deltax + deltay * deltay);
			if (d_e_bp > iter->getSizeY() + e[i].getSize())
			{
				iter++;
				continue;
			}
			//碰撞了的子弹
			int damage;
			//子弹能力判定部分
			if (isSound) {
				audio.playSound("./src/music/coll.ogg" );
			}
			else {
				audio.stopSound();
			}
			//能力1
			if (iter->getPower() == 1 && (rand() % 100) < 10)damage = 999999999;
			else damage = iter->getDamage();
			if (p.getPower() == 6 && e[i].getDeceleration() > 0)damage *= 2;
			if (iter->getPower() == 2 && (rand() % 100) < 80 && e[i].getDeceleration() == 0)e[i].setDeceleration(125);
			int point = e_blood_loss(i, damage);
			momentscore += point;
			bp.erase(iter++);
			if (point)
			{
				numofkilled++;
				break;
			}
		}
	}
	numofkilled += momentkilled;
	return momentscore;
}
/*
	负责人：
	功能：定义int momentinjured
	判定在玩家周围（麻烦的话就所有）的子弹是否与玩家碰撞，如果碰撞则进行扣血判定调用p_blood_loss(int,int)，
	将该函数返回值加起来放入momentinjured
	参数：无
	返回值：-momentinjured*10
*/
int coll_p_be()
{
	int momentinjured = 0;
	std::list<Bullet>::iterator i;
	for (i = be.begin(); i != be.end();)
	{
		if (i->getX() - i->getSizeX() > p.getX() + p.getSize() || i->getX() + i->getSizeX() < p.getX() - p.getSize())
		{
			i++;
			continue;
		}
		if (i->getY() - i->getSizeY() > p.getY() + p.getSize() || i->getY() + i->getSizeY() < p.getY() - p.getSize())
		{
			i++;
			continue;
		}
		int deltax = i->getX() - p.getX(), deltay = i->getY() - p.getY();
		int d_e_be = sqrt(deltax * deltax + deltay * deltay);
		if (d_e_be > i->getSizeY() + p.getSize())
		{
			i++;
			continue;
		}
		if (i->getX() < p.getX())
		{
			i++;
			continue;
		}
		if (isSound) {
			audio.playSound("./src/music/coll.ogg");
		}
		else {
			audio.stopSound();
		}
		int point = p_blood_loss(i->getDamage());
		momentinjured += point;
		be.erase(i++);
	}
	return -momentinjured * 10;
}
/*
	负责人：
	功能：定义int momentinjured,momentkilled,momentscore
	判定在玩家周围（麻烦的话就所有）的敌人是否与玩家碰撞，如果碰撞则：
	如果该敌人为远程类型，
	对玩家进行扣血判定调用p_blood_loss(int)，damage参数为敌人的touch_damage，momentinjured+1,momentkilled+1,momentscore+=e[i].point若非BOSS则将其exist设置为0
	如果为近战类型，
	若已纠缠将对对玩家进行扣血判定调用p_blood_loss(int,int)，damage参数为敌人的gnaw_damage，momentinjured+1；
	若未纠缠将entangle设为1,调用p_blood_loss(int,int)，damage参数为敌人的touch_damage，momentinjured+1,
	参数：无
	返回值：moment
*/
int coll_p_e()
{
	if (p.getPower() == 2)return 0;
	int momentinjured = 0, momentkilled = 0, momentscore = 0;
	for (int i = 0; i < MAXENERMYNUM; i++)
	{
		int deltax = e[i].getX() - p.getX(), deltay = e[i].getY() - p.getY();
		int d_e_p = sqrt(deltax * deltax + deltay * deltay);
		if (d_e_p > e[i].getSize() + p.getSize())continue;
		if (isSound) {
			audio.playSound("./src/music/coll.ogg");
		}
		else {
			audio.stopSound();
		}
		momentinjured += p_blood_loss(e[i].getTouchDamage());
		if (e[i].isBoss())continue;
		momentkilled++;
		momentscore += e[i].getPoint();
		e[i].setExist(0);
		if (p.getPower() == 3)
		{
			if (p.getNextPower() > 0)
			{
				p.setNeedKill(p.getNeedKill() - 1);
			}
		}
	}
	numofkilled += momentkilled;
	return momentscore - 10 * momentinjured;
}

/*
	负责人：
	功能：如果该敌人exist=0return
	如果远程，向be中添加rate个Bullet(e[i].id_bullet)，如果destination==0，向目标点移动，具体移动方式待商量
	如果近战，如果entangled==1，保持y与玩家一致，x在玩家右边近处，否则向玩家移动
	更新敌人动作actionid
	参数：无
	返回值：无
	说明：
*/
void Enermy_update()
{
	for (int i = 0; i < MAXENERMYNUM; i++)
	{
		int iyspeed = e[i].getYSpeed();
		int ixspeed = e[i].getXSpeed();
		int iyrate = e[i].getYRate();
		int irate = e[i].getRate();
		if (e[i].getDeceleration() > 0)
		{
			iyspeed /= 2;
			ixspeed /= 2;
			irate *= 2;
			e[i].setDeceleration(e[i].getDeceleration() - 1);
		}
		if (e[i].isExist() == 0)continue;
		if (e[i].getActionId() == 1)e[i].setActionId(2);
		if (e[i].getActionId() == 2)e[i].setActionId(1);
		//y方向移动
		if (e[i].getNextY() == 0)
		{
			switch (e[i].getModeOfMovey())
			{
			case 1:
				e[i].setY(e[i].getY() + iyspeed);
				break;
			case 2:
				e[i].setY(e[i].getY() - iyspeed);
				break;
			case 3:
				break;
			}
			if (e[i].getY() >= bound_bottom)e[i].setY(10);
			if (e[i].getY() <= 0)e[i].setY(bound_bottom - 10);
			e[i].setNextY(iyrate);
		}
		else e[i].setNextY(e[i].getNextY() - 1);
		//x方向移动
		e[i].setX(e[i].getX() - ixspeed);
		if (e[i].getX() <= 0)
		{
			if (e[i].isBoss())
			{
				e[i].setX(bound_right);
				int yr = rand() % bound_bottom;
				e[i].setY(yr);
				continue;
			}
			e[i].setExist(0);
		}
		//射击
		if (e[i].getNextShoot() == 0)
		{
			Bullet b(e[i].getBulletId(), e[i].getX() - e[i].getSize(), e[i].getY());
			be.push_front(b);
			e[i].setNextShoot(irate);
		}
		else e[i].setNextShoot(e[i].getNextShoot() - 1);

	}
}
/*
	负责人：
	功能：根据时间更新玩家特殊能力CD
	参数：无
	返回值：无
	说明：特殊能力要不要做得再看
*/
void Power_update()
{
	if (p.getPower() == 1)
	{
		if (p.getNextPower() == 0)
		{
			p.setShield(p.getShield() + 1);
			p.setNextPower(p.getPowerCD());
		}
		else p.setNextPower(p.getNextPower() - 1);
	}
	if (p.getPower() == 3)
	{
		if (p.getNextPower() > 0)
		{
			p.setNextPower(p.getNextPower() - 1);
			if (p.getNextPower() == 0)
			{
				if (p.getNeedKill() <= 0)
				{
					p.setBlood(p.getBlood() + 1 - p.getNeedKill());
					if (p.getBlood() > p.getMaxBlood())p.setBlood(p.getMaxBlood());
				}
				if (p.getBlood() <= 0)
				{
					lose = 1;
				}
			}
		}
	}
	if (p.getPower() == 4)
	{
		if (p.getNextPower() > 0)p.setNextPower(p.getNextPower() - 1);
	}
	if (p.getPower() == 5)
	{
		if (p.getNextPower() > 0)p.setNextPower(p.getNextPower() - 1);
	}
}

/*
	负责人：
	功能：更新敌人子弹的位置，x全部减去一个speed，如果路径上碰到玩家则停留在玩家位置，如果小于0则删去
	参数：无
	返回值：无
*/
void Bullet_e_update()
{
	std::list<Bullet>::iterator i;
	for (i = be.begin(); i != be.end();)
	{
		//移动时间内不会接触到玩家的飞机
		if (i->getY() > p.getY() + p.getSize() || i->getY() < p.getY() - p.getSize())
		{
			i->setX(i->getX() - i->getSpeed());
			if (i->getX() <= 0)
			{
				be.erase(i++);
				continue;
			}
			i++;
			continue;
		}
		//一开始在右边，移动后还在右边
		if (i->getX() - i->getSpeed() > p.getX() + p.getSize()) i->setX(i->getX() - i->getSpeed());
		//一开始在右边，移动后在左边
		else if (i->getX() > p.getX() + p.getSize() && i->getX() - i->getSpeed() <= p.getX() + p.getSize())i->setX(p.getX());
		//一开始在左边，移动后出边界
		else if (i->getX() - i->getSpeed() <= 0)
		{
			be.erase(i++);
			continue;
		}
		//一开始在左边，移动后在界内
		else i->setX(i->getX() - i->getSpeed());
		i++;
	}
}

/*
	负责人：
	功能：更新玩家子弹的位置，x全部加上一个speed，如果路径上碰到敌人则停留在敌人位置，如果超过右边界则删去
	参数：无
	返回值：无
*/
void Bullet_p_update()
{
	std::list<Bullet>::iterator i;
	for (i = bp.begin(); i != bp.end();)
	{
		//遍历，寻找子弹路径上穿过的，最靠前的敌人
		int k = MAXENERMYNUM;
		for (int j = 0; j < MAXENERMYNUM; j++)
		{
			if (i->getY() > e[j].getY() + e[j].getSize() || i->getY() < e[j].getY() - e[j].getSize())continue;
			if (i->getX() < e[j].getX() - e[j].getSize() && i->getX() + i->getSpeed() >= e[j].getX() - e[j].getSize())k = min(k, j);
		}
		if (k == MAXENERMYNUM)
		{
			i->setX(i->getX() + i->getSpeed());
			if (i->getX() > bound_right)
			{
				bp.erase(i++);
				continue;
			}
		}
		else i->setX(e[k].getX());
		i++;
	}
}
/*
	负责人：
	功能：创造当前关卡的BOSS
	参数：无
	返回值：BOSS的id
*/
bool create_BOSS(int level)
{
	for (int i = 0; i < MAXENERMYNUM; i++)
	{
		if (e[i].isExist() == 0)
		{
			e[i].setNextShoot(0);
			int r = 1 + rand() % 3;
			e[i].setModeOfMovey(r);
			int idr = id_BOSS[level][(rand() % id_BOSS[level].size())];
			int yr = rand() % bound_bottom;
			e[i].initialization(idr, bound_right - 100, bound_bottom / 2, level);
			return 1;
		}
	}
	return 0;
}
/*
	负责人：
	功能：根据当前关卡数，地图上存在的怪物数，随机数决定生成什么怪物
	参数：无
	返回值：是否创建怪物
*/
bool create_enermy(int level)
{
	if (numofkilled >= BOSS_need_kill[level] && BOSS_has_created == 0)
	{
		BOSS_has_created = create_BOSS(level);
		if (BOSS_has_created)return 1;
		return 0;
	}
	for (int i = 0; i < MAXENERMYNUM; i++)
	{
		if (e[i].isExist() == 0)
		{
			e[i].setNextShoot(0);
			int r = 1 + rand() % 3;
			e[i].setModeOfMovey(r);
			double probability_q = (double)numofkilled / (double)BOSS_need_kill[level];
			if (probability_q >= 0.5)
			{
				bool isq = rand() >= (double)RAND_MAX * probability_q ? 0 : 1;
				if (isq)
				{
					int idr = id_quintessence[level][rand() % id_quintessence[level].size()];
					int yr = rand() % bound_bottom;
					e[i].initialization(idr, bound_right - 40, yr, level);
					return 1;
				}
			}
			int idr = id_normalenermy[level][rand() % id_normalenermy[level].size()];
			int yr = rand() % bound_bottom;
			e[i].initialization(idr, bound_right - 40, yr, level);
			return 1;
		}
	}
}
/*
	负责人：
	功能：调用所有update函数
	参数：无
	返回值：无
*/
void UpdateAll(int level)
{
	Power_update();
	Enermy_update();
	Bullet_e_update();
	Bullet_p_update();
	create_enermy(level);
}
/*
	负责人：
	功能：初始化关卡数据
	参数：无
	返回值：无
*/
void initgame(int level)
{
	win = lose = 0;
	numofkilled = 0;
	BOSS_has_created = 0;
	memset(e, 0, sizeof(e));
	bp.clear();
	be.clear();
	switch (level)
	{
	case 0:
		loadimage(&bkground_game[0], _T(".\\src\\bkground_level0.jpg"));
		break;
	case 1:
		loadimage(&bkground_game[1], _T(".\\src\\bkground_level1.jpg"));
		break;
	case 2:
		loadimage(&bkground_game[2], _T(".\\src\\bkground_level2.jpg"));
		break;
	case 3:
		loadimage(&bkground_game[3], _T(".\\src\\bkground_level3.jpg"));
		break;
	}
	loadimage(&pause, _T(".\\src\\pause.jpg"));
	loadimage(&pause0, _T(".\\src\\pause0.jpg"));
	loadimage(&pausepress, _T(".\\src\\pausepress.jpg"));
	p.setNextPower(0);
}
/*
	负责人：
	功能：使用特殊能力
	参数：无
	返回值：无
	说明：拓展功能
*/
//暂不写
//void usepower();

//游戏运行
int gameview(int level)
{
	p.role(Flag);
	p.setSpeed(p.getSpeed() + level * 2);
	time_t t;
	srand((unsigned)time(&t));
	initgame(level);
	int score = 0;
	clock_t clock_start = clock(), clock_previous = clock(), clock_now = clock();

	while (1)
	{
		BeginBatchDraw();

		ExMessage msg1;
		if (peekmessage(&msg1, EX_MOUSE))
		{
			if (msg1.x >= 1480 && msg1.x <= 1600 && msg1.y >= 0 && msg1.y <= 120)
			{
				putimage(1480, 0, &pause, SRCAND);
				putimage(1480, 0, &pausepress, SRCPAINT);
				if (msg1.lbutton)
				{
					if (pauseview())return score;
				}
			}
			if (msg1.x >= 10 && msg1.x <= 80 && msg1.y >= 5 && msg1.y <= 40)
			{
				setfillcolor(RGB(255, 196, 161));
				solidrectangle(10, 5, 80, 40);
				setlinecolor(RGB(255, 204, 92));
				rectangle(10, 5, 80, 40);
				//setbkmode(TRANSPARENT);
				settextcolor(RED);
				settextstyle(32, 0, _T("黑体"));
				outtextxy(12, 5, _T("能力"));
				if (msg1.lbutton && p.getNextPower() == 0)
				{
					if (p.getPower() == 4)
					{
						p.setNextPower(p.getPowerCD());
					}
					else if (p.getPower() == 5)
					{
						p.setNextPower(p.getPowerCD());
						for (int i = 0; i < MAXENERMYNUM; i++)
						{
							if (e[i].isExist() == 1)
							{
								e_blood_loss(i, 80);
								e[i].setDeceleration(750);
							}
						}
						std::list<Bullet>::iterator i = be.begin();
						while (i != be.end())
						{
							be.erase(i++);
						}
					}
				}
			}
		}
		clock_now = clock();
		//每秒25帧
		if (((double)(clock_now - clock_previous)) / CLOCKS_PER_SEC <= 0.04)continue;
		clock_previous = clock();
		if (act())return score;
		UpdateAll(level);
		score += coll_e_bp() + coll_p_be() + coll_p_e();
		PutAll(level, score);

		EndBatchDraw();

		if (win == 1)
		{
			winView(score, level);
			return score;
		}
		if (lose == 1)
		{
			loseView(score);
			return score;
		}
	}
}