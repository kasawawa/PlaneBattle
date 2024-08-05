#include"Enviroment.h"
void Player::role(int id_role)
{
	id = id_role, x = 40, y = bound_bottom / 2;
	switch (id_role)
	{
		//示例，设计后再更改

	case 1://毁灭大炮
		blood = 1, speed = 8, size = 40, id_bullet = 106, rate = 15, maxblood = 1, shield = 1;
		break;
	case 2://炸弹投手
		blood = 4, speed = 5, size = 15, id_bullet = 102, rate = 12, maxblood = 4, shield = 2;
		break;
	case 3://阴险坚果
		blood = 1, speed = 5, size = 18, id_bullet = 103, rate = 6, maxblood = 1, shield = 7, power = 1, powerCD = 500;
		break;
	case 4://幽灵射手
		blood = 10, speed = 15, size = 1, id_bullet = 101, rate = 5, maxblood = 10, shield = 5, power = 2;
		break;
	case 5://狂野射手
		blood = 4, speed = 10, size = 30, id_bullet = 101, rate = 25, maxblood = 4, shield = 2, power = 4, powerCD = 1600;
		break;
	case 6://蜗牛射手
		blood = 6, speed = 8, size = 20, id_bullet = 101, rate = 9, maxblood = 12, shield = 0, power = 3, powerCD = 100, needkill = 4;
		break;
	case 7://寒冰射手
		blood = 6, speed = 7, size = 12, id_bullet = 104, rate = 7, maxblood = 6, shield = 2, power = 6;
		break;
	case 8://冰瓜大炮
		blood = 3, speed = 5, size = 20, id_bullet = 105, rate = 20, maxblood = 2, shield = 3, power = 5, powerCD = 1000;
		break;
	case 9://究极毁灭菇
		blood = 10, speed = 15, size = 60, id_bullet = 106, rate = 20, maxblood = 10, shield = 10;
		//......
	}
}