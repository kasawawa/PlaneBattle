#include"Enviroment.h"

Enermy::Enermy() :exist(0)
{

}
void Enermy::initialization(int id_enermy, int ix, int iy, int level)
{
	x = ix, y = iy, id = id_enermy, exist = 1, deceleration = 0;
	switch (id_enermy)
	{
		//示例，设计后再更改
	case 1:
		blood = 30, xspeed = 6, size = 12, type = 0, point = 20, M.rate = 200, M.id_bullet = 1, touch_damage = 1, yrate = 0, yspeed = 2;
		break;
	case 2:
		blood = 60, xspeed = 4, size = 23, type = 0, point = 20, M.rate = 50, M.id_bullet = 1, touch_damage = 1, yrate = 0, yspeed = 3;
		break;
	case 101:
		blood = 120, xspeed = 6, size = 40, type = 0, point = 60, M.rate = 8, M.id_bullet = 1, touch_damage = 2, yrate = 0, yspeed = 4;
		break;
	case 102:
		blood = 200, xspeed = 8, size = 50, type = 0, point = 70, M.rate = 12, M.id_bullet = 2, touch_damage = 2, yrate = 0, yspeed = 5;
		break;
	case 103:
		blood = 300, xspeed = 3, size = 75, type = 0, point = 70, M.rate = 15, M.id_bullet = 2, touch_damage = 2, yrate = 0, yspeed = 3;
		break;
	case 104:
		blood = 150, xspeed = 9, size = 50, type = 0, point = 70, M.rate = 8, M.id_bullet = 2, touch_damage = 1, yrate = 0, yspeed = 8;
		break;
	case 1001:
		blood = 500, xspeed = 4, size = 100, type = 0, point = 120, M.rate = 6, M.id_bullet = 5, touch_damage = 2, yrate = 0, yspeed = 3, BOSS = 1, shield = 1;
		break;
	case 1002:
		blood = 400, xspeed = 6, size = 100, type = 0, point = 120, M.rate = 6, M.id_bullet = 4, touch_damage = 2, yrate = 0, yspeed = 5, BOSS = 1, shield = 4;
		break;
	case 1003:
		blood = 600, xspeed = 7, size = 100, type = 0, point = 140, M.rate = 8, M.id_bullet = 3, touch_damage = 2, yrate = 0, yspeed = 7, BOSS = 1, shield = 2;
		break;
	case 1004:
		blood = 700, xspeed = 5, size = 80, type = 0, point = 120, M.rate = 7, M.id_bullet = 3, touch_damage = 2, yrate = 0, yspeed = 4, BOSS = 1, shield = 1;
		//......
	}
}