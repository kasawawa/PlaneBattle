#include "Enviroment.h"

void draw(const Button& button, const IMAGE& img) {
    putimage(0, 0, &img);  // 加载图片的位置
    button.draw(); // 使用新的draw方法
}

const int WHITEPNG = 0;//代表白底黑图
const int BLACKPNG = 1;//代表黑底原图
IMAGE Plants[10][2];

void loadImgResource() {
    loadimage(&Plants[0][WHITEPNG], "./src/全屏打击_毁灭大炮/全屏打击_毁灭大炮_白底彩物.png", 300, 300);
    loadimage(&Plants[0][BLACKPNG], "./src/全屏打击_毁灭大炮/全屏打击_毁灭大炮_黑底白物.png", 300, 300);
    loadimage(&Plants[1][WHITEPNG], "./src/概率秒杀_炸弹投手/概率秒杀_炸弹投手_白底彩物.png", 300, 300);
    loadimage(&Plants[1][BLACKPNG], "./src/概率秒杀_炸弹投手/概率秒杀_炸弹投手_黑底白物.png", 300, 300);
    loadimage(&Plants[2][WHITEPNG], "./src/概率闪避_阴险坚果/概率闪避_阴险坚果_白底彩物.png", 300, 300);
    loadimage(&Plants[2][BLACKPNG], "./src/概率闪避_阴险坚果/概率闪避_阴险坚果_黑底白物.png", 300, 300);
    //幽灵射手
    loadimage(&Plants[4][WHITEPNG], "./src/急速高攻_狂野射手/急速高攻_狂野射手_白底彩物.png", 300, 300);
    loadimage(&Plants[4][BLACKPNG], "./src/急速高攻_狂野射手/急速高攻_狂野射手_黑底白物.png", 300, 300);
    loadimage(&Plants[5][WHITEPNG], "./src/防御反伤_蜗牛射手/防御反伤_蜗牛射手_白底彩物.png", 300, 300);
    loadimage(&Plants[5][BLACKPNG], "./src/防御反伤_蜗牛射手/防御反伤_蜗牛射手_黑底白物.png", 300, 300);
    loadimage(&Plants[6][WHITEPNG], "./src/平平无奇_寒冰射手/平平无奇_寒冰射手_白底彩图.png", 300, 300);
    loadimage(&Plants[6][BLACKPNG], "./src/平平无奇_寒冰射手/平平无奇_寒冰射手_黑底白图.png", 300, 300);
    loadimage(&Plants[7][WHITEPNG], "./src/速冻时间_冰瓜大炮/速冻时间_冰瓜大炮_白底彩物.png", 300, 300);
    loadimage(&Plants[7][BLACKPNG], "./src/速冻时间_冰瓜大炮/速冻时间_冰瓜大炮_黑底白物.png", 300, 300);
    loadimage(&Plants[8][WHITEPNG], "./src/禁忌之力_毁灭菇_白底彩物.png", 300, 300);
    loadimage(&Plants[8][BLACKPNG], "./src/禁忌之力_毁灭菇_黑底白物.png", 300, 300);
}

//“主函数”
void Select_Plant_view() {
    if (bgm.isMusicPlaying()) {
        bgm.stopMusic();
        bgm.playmusic("./src/music/Select.mp3");
    }
    Flag = -1;
    //cleardevice();
    // 开始绘制
    IMAGE img;
    loadimage(&img, "./src/picture/Select_Plants.jpg");  // 使用正斜杠
    loadImgResource();
    


    // 左上角的菜单
    Button returnMenu("菜单", 40, 25, 80, 40);
    returnMenu.setColors(RGB(200, 200, 200), RGB(220, 220, 220), RGB(180, 180, 180), BLACK);

    // 植物选择按钮
    Button plantButtons[10] = {
        Button("毁灭大炮", 300, 50, 300, 120),
        Button("炸弹投手", 300, 220, 300, 120),
        Button("阴险坚果", 300, 390, 300, 120),
        Button("幽灵射手", 300, 560, 300, 120),
        Button("狂野射手", 300, 730, 300, 120),
        Button("蜗牛射手", 800, 50, 300, 120),
        Button("寒冰射手", 800, 220, 300, 120),
        Button("冰瓜大炮", 800, 390, 300, 120),
        Button("禁忌毁灭菇", 800, 560, 300, 120),
        Button("敬请期待", 800, 730, 300, 120)
    };

    for (auto& button : plantButtons) {
        button.setColors(RGB(200, 200, 200), RGB(220, 220, 220), RGB(180, 180, 180), BLACK);
    }

    //开始按钮
    Button Beginner("开始游戏", 1260, 750, 200, 100);
    Beginner.setColors(RGB(100, 150, 255), RGB(150, 200, 255), RGB(50, 100, 200), WHITE);

    bool running = true;
    int currentSelectedPlant = -1; // 当前选中的植物索引，-1表示没有选中
    bool plantFlags[10] = { false }; // 用于跟踪每个植物的选中状态
    std::string plantDescriptions[10] = {
        "【毁灭大炮】 小时候因自己的疏忽大意 让弟弟被人贩子拐走了 最终性情大变 脾气极度火爆！",
        "【炸弹投手】\n我是卷心菜菜 \n扮猪吃虎嘛 可以跟我一起玩吗？\n（别信它鬼话，你以为那颗樱桃是\n用来吃的吗？）",
        "【阴险坚果】\n什么，有人打你？\n那我怎么知道？\n没看见我在看报吗……\n（噢噢，抱一丝认错人了\n哎不对，你枪露出来了！）",
        "【幽灵射手】\n看不见我看不见我看不\n见我看不见我看\n不见我看不见我看\n不见我看不见我看不\n见我看不见我看不见我\n.............",
        "【狂野射手】\n听说他曾经出去留过学\n平常喜欢说什么？\n好像有句口头禅...\n“关于我是谁，双枪会给出答案”",
        "【蜗牛射手】\n这只蜗牛……\n不对，那是豌豆射手！！\n瞧他那瞄准的小眼神儿…\n看来，他为了这一战，\n有在时刻准备着……\n(虽然是蜗牛但速度一点也不慢？)",
        "【寒冰射手】\n一个喜欢唱Let it go的小姑娘？",
        "【冰瓜大炮】\n小时候跟哥哥关系很好\n但后来不小心跟哥哥走散\n此后对哥哥思念成疾\n渴望时间能够永远\n停留在与哥哥的美好时刻！",
        "【禁忌毁灭菇】\n你猜猜为什么是禁忌？？",
        "【敬请期待】",
    };

    bool showNoPlantSelectedMessage = false;
    bool sp = false;
    bool ssp = false;

    if (user.get_isAllPassed()) {
        sp = true;
    }

    while (running && !rtnFlag) {
		BeginBatchDraw();
        putimage(0, 0, &img);  // 绘制背景图片

		settextcolor(LIGHTGRAY);
		settextstyle(120, 0, "楷体");
		outtextxy(50, 160, "植");
		outtextxy(50, 300, "物");
		outtextxy(50, 440, "选");
		outtextxy(50, 580, "取");

		settextcolor(LIGHTMAGENTA);
		settextstyle(40, 0, "楷体");
		std::string score = "历史得分:【";
		score += std::to_string(user.get_History_Score());
		outtextxy(1200, 50, (score + "】").data());

        // 绘制所有按钮
        returnMenu.draw();
        for (const auto& button : plantButtons) {
            button.draw();
        }
        Beginner.draw();

        // 如果有选中的植物，绘制其描述
        if (currentSelectedPlant != -1) {
            drawTextInRect(1200, 570, 300, 150, plantDescriptions[currentSelectedPlant]);
            putimage(1200, 200, &Plants[currentSelectedPlant][BLACKPNG], SRCPAINT);
            putimage(1200, 200, &Plants[currentSelectedPlant][WHITEPNG], SRCAND);
        }

        // 显示未选择植物的提示
        if (showNoPlantSelectedMessage) {
            //setbkmode(TRANSPARENT);
            settextcolor(RGB(255, 0, 0));  // 红色文字
            settextstyle(150, 0, _T("粗体"));
            outtextxy(300, 400, _T("您当前未选择植物"));
        }

        if (ssp) {
            //setbkmode(TRANSPARENT);
            settextcolor(RGB(255, 0, 0));  // 红色文字
            settextstyle(100, 0, _T("粗体"));
            outtextxy(220, 400, _T("您尚未通关，不能使用该角色！"));
        }

        // 处理消息
        if (peekmessage(&msg)) {
            if (msg.message == WM_CLOSE) {
                running = false;
                break;
            }

            returnMenu.update();
            Beginner.update();
            for (int i = 0; i < 10; ++i) {
                plantButtons[i].update();
                if (plantButtons[i].wasClicked()) {
                    plantFlags[i] = !plantFlags[i]; // 切换选中状态
                    if (currentSelectedPlant == i) {
                        currentSelectedPlant = -1; // 如果再次点击同一个植物，取消选择
                        Flag = -1;
                        ssp = false;
                    }
                    else {
                        currentSelectedPlant = i; // 选择新的植物
                        Flag = i + 1;
                        ssp = false;
                    }
                    showNoPlantSelectedMessage = false; // 点击植物按钮时隐藏提示
                }
            }

            if (returnMenu.wasClicked()) {
                if (bgm.isMusicPlaying()) {
                    bgm.stopMusic();
                    bgm.playmusic("./src/music/Login.mp3");
                }
                // 回到菜单界面
                running = false;
            }

            if (Beginner.wasClicked()) {
                // 跳转至关卡选择
                if (Flag == -1) {
                    showNoPlantSelectedMessage = true;
                    ssp = false;
                }
                else if (currentSelectedPlant == 8 && (sp == true /* || sp == false */))  ///////////////////禁忌毁灭菇，将（sp==false）的注释去掉即可使用
                {
                    levelselectview();
					currentSelectedPlant = -1; // 选择新的植物
                }
                else if (currentSelectedPlant != 8 && currentSelectedPlant != 9) {
                    levelselectview();
                    currentSelectedPlant = -1; // 选择新的植物
                }
                else {
                    if (currentSelectedPlant == 8) {
                        ssp = true;
                    }
                    else {
                        showNoPlantSelectedMessage = true;
                        ssp = false;
                    }
                }
            }
        }

        // 点击非"开始游戏"按钮区域时隐藏提示
        if (msg.message == WM_LBUTTONDOWN && !Beginner.isPointInside(msg.x, msg.y)) {
            showNoPlantSelectedMessage = false;
        }
		EndBatchDraw(); // 结束批量绘图
    }

	if (rtnFlag == 2)		////明雅流风//// (退-1)  无0  l1  m2  p3
		rtnFlag = 0;
}