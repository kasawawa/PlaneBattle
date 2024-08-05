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
	�����ˣ��Ȱ�����
	���ܣ����ݹؿ���Ŵ�ӡ�ؿ���ͼ�ļ�
	��������ǰ�ؿ����
	����ֵ����
*/
void Map_put(int level)
{
	//�ҵ�ͼƬ֮ǰ�Ժ�ɫ��Ϊ����
	//setbkcolor(BLACK);
	//cleardevice();
	putimage(0, 0, &bkground_game[level]);

}
/*
	�����ˣ��Ȱ�����
	���ܣ���ӡ����
	��������
	����ֵ����
*/
void Enermy_put()
{
	//	�ҵ�ͼƬ֮ǰʹ�����´���
	for (int i = 0; i < MAXENERMYNUM; i++)
	{
		if (e[i].isExist() == 0)break;
		if (e[i].getDeceleration() > 0)
		{
			setfillcolor(LIGHTBLUE);
			solidrectangle(e[i].getX() - e[i].getSize(), e[i].getY() + e[i].getSize(), e[i].getX() + e[i].getSize(), 10 + e[i].getY() + e[i].getSize());
		}
	}
	//�ҵ�ͼƬ��ʹ�����´���
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
	�����ˣ�
	���ܣ���p.getX(),p.getY()λ�û�����ҡ�p��һ��ȫ�ֱ���
	������һ��Player���󣬴������
	����ֵ����
*/
void Player_put()
{
	//	�ҵ�ͼƬ֮ǰʹ�����´���
	//setfillcolor(GREEN);
	//solidrectangle(p.getX() - p.getSize(), p.getY() - p.getSize(), p.getX() + p.getSize(), p.getY() + p.getSize());
	//�ҵ�ͼƬ��ʹ�����´���
	if (p.getId() == 4)return;
	IMAGE img_role;
	IMAGE img0;
	switch (p.getId())
	{
	case 1://�������
		loadimage(&img_role, _T(".\\src\\9.png"));
		loadimage(&img0, _T(".\\src\\9black.png"));
		break;
	case 2://ը��Ͷ��
		loadimage(&img_role, _T(".\\src\\2.png"));
		loadimage(&img0, _T(".\\src\\2black.png"));
		break;
	case 3://���ռ��
		loadimage(&img_role, _T(".\\src\\3.png"));
		loadimage(&img0, _T(".\\src\\3black.png"));
		break;
	case 4://��������
		break;
	case 5://��Ұ����
		loadimage(&img_role, _T(".\\src\\5.png"));
		loadimage(&img0, _T(".\\src\\5black.png"));
		break;
	case 6://��ţ����
		loadimage(&img_role, _T(".\\src\\6.png"));
		loadimage(&img0, _T(".\\src\\6black.png"));
		break;
	case 7://��������
		loadimage(&img_role, _T(".\\src\\7.png"));
		loadimage(&img0, _T(".\\src\\7black.png"));
		break;
	case 8://���ϴ���
		loadimage(&img_role, _T(".\\src\\8.png"));
		loadimage(&img0, _T(".\\src\\8black.png"));
		break;
	case 9://��������
		loadimage(&img_role, _T(".\\src\\1.png"));
		loadimage(&img0, _T(".\\src\\1black.png"));
		break;
		//......
	}
	putimage(p.getX() - p.getSize(), p.getY() - p.getSize(), &img0, SRCAND);
	putimage(p.getX() - p.getSize(), p.getY() - p.getSize(), &img_role, SRCPAINT);
}
/*
	�����ˣ�
	���ܣ�������ҵ��ӵ�
	��������
	����ֵ����
*/
void Bullet_p_put()
{
	//	�ҵ�ͼƬ֮ǰʹ�����´���
/*	setfillcolor(WHITE);
	for (i = bp.begin(); i != bp.end(); i++)
	{
		solidellipse(i->getX() - 2 * (i->getSize()), i->getY() - i->getSize(), i->getX() + 2 * (i->getSize()), i->getY() + i->getSize());
	}*/
	//�ҵ�ͼƬ��ʹ�����´���
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
	�����ˣ�
	���ܣ����Ƶ��˵��ӵ�
	��������
	����ֵ����
*/
void Bullet_e_put()
{
	//	�ҵ�ͼƬ֮ǰʹ�����´���
	setfillcolor(BLUE);
	std::list<Bullet>::iterator i;
	for (i = be.begin(); i != be.end(); i++)
	{
		IMAGE img = i->getimg();
		IMAGE img0 = i->getimg0();
		putimage(i->getX() - i->getSizeX(), i->getY() - i->getSizeY(), &img0, SRCAND);
		putimage(i->getX() - i->getSizeX(), i->getY() - i->getSizeY(), &img, SRCPAINT);
	}
	//�ҵ�ͼƬ��ʹ�����´���
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
	�����ˣ�
	���ܣ������Ͻǻ������Ѫ��,����
	��������
	����ֵ����
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
	�����ˣ�
	���ܣ������Ͻǻ�����һ���,����
	��������
	����ֵ����
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
	�����ˣ�
	���ܣ�������ҳ�����ͼ�꣬������ȴ״̬
	��������
	����ֵ����
	˵������չ���ܣ�ֻ���ȷŸ���������
*/
//�ݲ�д
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
		settextstyle(32, 0, _T("����"));
		outtextxy(12, 5, _T("����"));
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
	settextstyle(32, 0, _T("����"));
	outtextxy(12, 5, _T("����"));
	settextcolor(RGB(248, 248, 255));
	double powertime = (double)p.getNextPower() / 25.0;
	std::string sc_str = std::to_string(powertime);
	const char* outputtime = sc_str.c_str();
	settextstyle(32, 0, _T("consolas"));
	outtextxy(10, 55, outputtime);
}
/*
	�����ˣ�
	���ܣ��ڶ��������������ҷ���ֵ��ʵʱ��
	����������ֵ
	����ֵ����
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
	�����ˣ�
	���ܣ����ƽ��ȱ�ʶ����numofkilledռ�ܵ����������й�
	��������
	����ֵ����
	˵����
*/
//�ݲ�д
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
	�����ˣ�
	���ܣ�������ͣ��ʶ
	��������
	����ֵ����
	˵����
*/
void pause_put()
{
	putimage(bound_right - 120, 0, &pause, SRCAND);
	putimage(bound_right - 120, 0, &pause0, SRCPAINT);
}
/*
	�����ˣ�
	���ܣ��������е�***_put��������ɳ�������
	��������
	����ֵ����
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
	�����ˣ��Ȱ�����
	���ܣ���ȡ��Ҽ��̲������ƶ�
	��������
	����ֵ����
	˵�����Ѿ�д��
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
	�����ˣ�
	���ܣ���ȡ��Ҽ������룬�����ȡ���ո��������p.id_bullet��ʼ��p.rate��Bullet����
	�����ǵ�x,y������p.x,p.y��Χ�������뵽vector bp��
	��������
	����ֵ����
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
	�����ˣ�
	���ܣ�����move()��shoot()
	��������
	����ֵ����
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
	�����ˣ�
	���ܣ��жϵ����Ƿ��л��ܣ�����۳�һ�㻤�ܲ�����0������۳�damage*�˺������ʣ�buffЧ������չ���ݣ�
	�����ʱ����Ѫ����������ֱ�ӷ���0
	�����ʱ����Ѫ�����������ж��Ƿ�BOSS�����ǽ�win��Ϊ1�������뵽�ļ��У�����e[iter].exist��Ϊ0������1
	��������Ҫ�жϵĵ�����e������ı�ţ��˺�ֵ
	����ֵ���Ƿ�ɱ�������ǵ��˷�����0
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
		//�����ļ���ʹ�����´���
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
	�����ˣ�
	���ܣ��ж�����Ƿ��л��ܣ�����۳�һ�㻤�ܲ�����0������۳�damage*�˺������ʣ�buffЧ������չ���ݣ�
	�����ʱ���Ѫ����������ֱ�ӷ���1
	�����ʱ���Ѫ���������½�lose��Ϊ1����1
	��������
	����ֵ���Ƿ��Ѫ
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
	�����ˣ�
	���ܣ�����int momentkilled��momentscore
	����e���飬��ÿһ�����ˣ����������������������������ӵ���ͨ�����ֲ��һ�ĳЩԤ������
	�ж���Щ�ӵ��Ƿ����õ��˷�����ײ����ײ�����߼����������������ײ����п�Ѫ�ж�����e_blood_loss(int,int)��
	���䷵��ֵ�����������momentscore�У������ز�Ϊ0�Ĵ�������momentkilled��
	���momentkilled����numofkilled����momentscore
	��������
	����ֵ������
*/
int coll_e_bp()
{
	int momentkilled = 0, momentscore = 0;
	for (int i = 0; i < MAXENERMYNUM; i++)
	{
		//��ʱֱ��ȫ���������б�Ҫ��д���ֲ���
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
			//��ײ�˵��ӵ�
			int damage;
			//�ӵ������ж�����
			if (isSound) {
				audio.playSound("./src/music/coll.ogg" );
			}
			else {
				audio.stopSound();
			}
			//����1
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
	�����ˣ�
	���ܣ�����int momentinjured
	�ж��������Χ���鷳�Ļ������У����ӵ��Ƿ��������ײ�������ײ����п�Ѫ�ж�����p_blood_loss(int,int)��
	���ú�������ֵ����������momentinjured
	��������
	����ֵ��-momentinjured*10
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
	�����ˣ�
	���ܣ�����int momentinjured,momentkilled,momentscore
	�ж��������Χ���鷳�Ļ������У��ĵ����Ƿ��������ײ�������ײ��
	����õ���ΪԶ�����ͣ�
	����ҽ��п�Ѫ�ж�����p_blood_loss(int)��damage����Ϊ���˵�touch_damage��momentinjured+1,momentkilled+1,momentscore+=e[i].point����BOSS����exist����Ϊ0
	���Ϊ��ս���ͣ�
	���Ѿ������Զ���ҽ��п�Ѫ�ж�����p_blood_loss(int,int)��damage����Ϊ���˵�gnaw_damage��momentinjured+1��
	��δ������entangle��Ϊ1,����p_blood_loss(int,int)��damage����Ϊ���˵�touch_damage��momentinjured+1,
	��������
	����ֵ��moment
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
	�����ˣ�
	���ܣ�����õ���exist=0return
	���Զ�̣���be�����rate��Bullet(e[i].id_bullet)�����destination==0����Ŀ����ƶ��������ƶ���ʽ������
	�����ս�����entangled==1������y�����һ�£�x������ұ߽���������������ƶ�
	���µ��˶���actionid
	��������
	����ֵ����
	˵����
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
		//y�����ƶ�
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
		//x�����ƶ�
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
		//���
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
	�����ˣ�
	���ܣ�����ʱ����������������CD
	��������
	����ֵ����
	˵������������Ҫ��Ҫ�����ٿ�
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
	�����ˣ�
	���ܣ����µ����ӵ���λ�ã�xȫ����ȥһ��speed�����·�������������ͣ�������λ�ã����С��0��ɾȥ
	��������
	����ֵ����
*/
void Bullet_e_update()
{
	std::list<Bullet>::iterator i;
	for (i = be.begin(); i != be.end();)
	{
		//�ƶ�ʱ���ڲ���Ӵ�����ҵķɻ�
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
		//һ��ʼ���ұߣ��ƶ������ұ�
		if (i->getX() - i->getSpeed() > p.getX() + p.getSize()) i->setX(i->getX() - i->getSpeed());
		//һ��ʼ���ұߣ��ƶ��������
		else if (i->getX() > p.getX() + p.getSize() && i->getX() - i->getSpeed() <= p.getX() + p.getSize())i->setX(p.getX());
		//һ��ʼ����ߣ��ƶ�����߽�
		else if (i->getX() - i->getSpeed() <= 0)
		{
			be.erase(i++);
			continue;
		}
		//һ��ʼ����ߣ��ƶ����ڽ���
		else i->setX(i->getX() - i->getSpeed());
		i++;
	}
}

/*
	�����ˣ�
	���ܣ���������ӵ���λ�ã�xȫ������һ��speed�����·��������������ͣ���ڵ���λ�ã���������ұ߽���ɾȥ
	��������
	����ֵ����
*/
void Bullet_p_update()
{
	std::list<Bullet>::iterator i;
	for (i = bp.begin(); i != bp.end();)
	{
		//������Ѱ���ӵ�·���ϴ����ģ��ǰ�ĵ���
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
	�����ˣ�
	���ܣ����쵱ǰ�ؿ���BOSS
	��������
	����ֵ��BOSS��id
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
	�����ˣ�
	���ܣ����ݵ�ǰ�ؿ�������ͼ�ϴ��ڵĹ��������������������ʲô����
	��������
	����ֵ���Ƿ񴴽�����
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
	�����ˣ�
	���ܣ���������update����
	��������
	����ֵ����
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
	�����ˣ�
	���ܣ���ʼ���ؿ�����
	��������
	����ֵ����
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
	�����ˣ�
	���ܣ�ʹ����������
	��������
	����ֵ����
	˵������չ����
*/
//�ݲ�д
//void usepower();

//��Ϸ����
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
				settextstyle(32, 0, _T("����"));
				outtextxy(12, 5, _T("����"));
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
		//ÿ��25֡
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