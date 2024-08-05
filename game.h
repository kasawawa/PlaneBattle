#pragma once
/*
	负责人：热爱主义
	功能：根据关卡编号打印关卡地图文件
	参数：当前关卡编号
	返回值：无
*/
void Map_put(int level);
/*
	负责人：热爱主义
	功能：打印敌人
	参数：无
	返回值：无
*/
void Enermy_put();
/*
	负责人：
	功能：在p.getX(),p.getY()位置绘制玩家。p是一个全局变量
	参数：一个Player对象，代表玩家
	返回值：无
*/
void Player_put();
/*
	负责人：
	功能：绘制玩家的子弹
	参数：无
	返回值：无
*/
void Bullet_p_put();
/*
	负责人：
	功能：绘制敌人的子弹
	参数：无
	返回值：无
*/
void Bullet_e_put();
/*
	负责人：
	功能：在左上角绘制玩家血量,格子
	参数：无
	返回值：无
*/
void blood_put();
/*
	负责人：
	功能：在左上角绘制玩家护盾,格子
	参数：无
	返回值：无
*/
void shield_put();
/*
	负责人：
	功能：绘制玩家超能力图标，包括冷却状态
	参数：无
	返回值：无
	说明：拓展功能，只是先放个函数声名
*/
//暂不写
void power_put();
/*
	负责人：
	功能：在顶部正中央绘制玩家分数值（实时）
	参数：分数值
	返回值：无
*/
//暂不写
void score_put(int score);
/*
	负责人：
	功能：绘制进度标识，与numofkilled占总敌人数比例有关
	参数：无
	返回值：无
	说明：
*/
//暂不写
void killed_put();
void pause_put();
/*
	负责人：
	功能：调用所有的***_put函数，完成场景绘制
	参数：无
	返回值：无
*/
void PutAll(int level, int score);
/*
	负责人：热爱主义
	功能：读取玩家键盘操作以移动
	参数：无
	返回值：无
	说明：已经写好
*/
void move();
/*
	负责人：
	功能：读取玩家键盘输入，如果读取到空格键，根据p.id_bullet初始化p.rate个Bullet对象，
	将它们的x,y设置在p.x,p.y周围，并加入到vector bp中
	参数：无
	返回值：无
*/
void shoot();
/*
	负责人：
	功能：调用move()、shoot()
	参数：无
	返回值：无
*/
bool act();
/*
	负责人：
	功能：判断敌人是否有护盾，有则扣除一点护盾并返回0。无则扣除damage*伤害吸收率（buff效果，扩展内容）
	如果此时敌人血量在零以上直接返回0
	如果此时敌人血量在零以下判断是否BOSS，若是将win改为1，并输入到文件中，否则将e[iter].exist改为0，返回1
	参数：需要判断的敌人在e数组里的编号，伤害值
	返回值：是否杀死敌人是敌人分数否0
*/
int e_blood_loss(int iter, int damage);
/*
	负责人：
	功能：判断玩家是否有护盾，有则扣除一点护盾并返回0。无则扣除damage*伤害吸收率（buff效果，扩展内容）
	如果此时玩家血量在零以上直接返回1
	如果此时玩家血量在零以下将lose改为1返回1
	参数：无
	返回值：是否扣血
*/
bool p_blood_loss(int damage);
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
int coll_e_bp();
/*
	负责人：
	功能：定义int momentinjured
	判定在玩家周围（麻烦的话就所有）的子弹是否与玩家碰撞，如果碰撞则进行扣血判定调用p_blood_loss(int,int)，
	将该函数返回值加起来放入momentinjured
	参数：无
	返回值：-momentinjured*10
*/
int coll_p_be();
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
int coll_p_e();

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
void Enermy_update();
/*
	负责人：
	功能：根据时间更新玩家特殊能力CD
	参数：无
	返回值：无
	说明：特殊能力要不要做得再看
*/
void Power_update();

/*
	负责人：
	功能：更新敌人子弹的位置，x全部减去一个speed，如果路径上碰到玩家则停留在玩家位置，如果小于0则删去
	参数：无
	返回值：无
*/
void Bullet_e_update();

/*
	负责人：
	功能：更新玩家子弹的位置，x全部加上一个speed，如果路径上碰到敌人则停留在敌人位置，如果超过右边界则删去
	参数：无
	返回值：无
*/
void Bullet_p_update();
/*
	负责人：
	功能：创造当前关卡的BOSS
	参数：无
	返回值：BOSS的id
*/
bool create_BOSS(int level);
/*
	负责人：
	功能：根据当前关卡数，地图上存在的怪物数，随机数决定生成什么怪物
	参数：无
	返回值：是否创建怪物
*/
bool create_enermy(int level);
/*
	负责人：
	功能：调用所有update函数
	参数：无
	返回值：无
*/
void UpdateAll(int level);
/*
	负责人：
	功能：初始化关卡数据
	参数：无
	返回值：无
*/
void initgame();
/*
	负责人：
	功能：使用特殊能力
	参数：无
	返回值：无
	说明：拓展功能
*/
//暂不写
void usepower();
int gameview(int level);