#include"Enviroment.h"
Bullet::Bullet(int id_bullet, int ix, int iy)
{
	x = ix, y = iy, id = id_bullet;
	switch (id_bullet)
	{
		//ʾ������ƺ��ٸ���
	case 1:
		//��ͨ�����ӵ�1
		damage = 1, speed = 10, sizex = 6, sizey = 12;
		loadimage(&img, _T(".\\src\\bullet10.png"));
		loadimage(&img0, _T(".\\src\\bullet10black.png"));
		break;
	case 2:
		//��ͨ�����ӵ�2
		damage = 1, speed = 15, sizex = 28, sizey = 11;
		loadimage(&img, _T(".\\src\\bullet11.png"));
		loadimage(&img0, _T(".\\src\\bullet11black.png"));
		break;
	case 3:
		//��Ӣ�����ӵ�1
		damage = 2, speed = 18, sizex = 30, sizey = 30;
		loadimage(&img, _T(".\\src\\bullet9.png"));
		loadimage(&img0, _T(".\\src\\bullet9black.png"));
		break;
	case 4:
		//��Ӣ�ӵ�2
		damage = 1, speed = 25, sizex = 20, sizey = 20;
		loadimage(&img, _T(".\\src\\bullet7.png"));
		loadimage(&img0, _T(".\\src\\bullet7black.png"));
		break;
	case 5:
		//��Ӣ�ӵ�3
		damage = 3, speed = 16, sizex = 22, sizey = 22;
		loadimage(&img, _T(".\\src\\bullet8.png"));
		loadimage(&img0, _T(".\\src\\bullet8black.png"));
		break;
	case 101:
		//��ɫ�ӵ�1
		damage = 10, speed = 7, sizex = 12, sizey = 6;
		loadimage(&img, _T(".\\src\\bullet1.png"));
		loadimage(&img0, _T(".\\src\\bullet1black.png"));
		break;
	case 102:
		//��ɫ�ӵ�2��8%��ɱ�ӵ�
		damage = 40, speed = 5, sizex = 14, power = 1, sizey = 14;
		loadimage(&img, _T(".\\src\\bullet2.png"));
		loadimage(&img0, _T(".\\src\\bullet2black.png"));
		break;
	case 103:
		//��ɫ�ӵ�3
		damage = 15, speed = 10, sizex = 11, sizey = 11;
		loadimage(&img, _T(".\\src\\bullet3.png"));
		loadimage(&img0, _T(".\\src\\bullet3black.png"));
		break;
	case 104:
		damage = 10, speed = 10, sizex = 10, sizey = 10, power = 2;
		loadimage(&img, _T(".\\src\\bullet4.png"));
		loadimage(&img0, _T(".\\src\\bullet4black.png"));
		break;
	case 105:
		damage = 40, speed = 6, sizex = 28, sizey = 20, power = 2;
		loadimage(&img, _T(".\\src\\bullet5.png"));
		loadimage(&img0, _T(".\\src\\bullet5black.png"));
		break;
	case 106:
		damage = 999, speed = 15, sizex = 20, sizey = 32;
		loadimage(&img, _T(".\\src\\bullet6.png"));
		loadimage(&img0, _T(".\\src\\bullet6black.png"));
		break;
		//......
	}
}
