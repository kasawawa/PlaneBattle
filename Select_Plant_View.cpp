#include "Enviroment.h"

void draw(const Button& button, const IMAGE& img) {
    putimage(0, 0, &img);  // ����ͼƬ��λ��
    button.draw(); // ʹ���µ�draw����
}

const int WHITEPNG = 0;//����׵׺�ͼ
const int BLACKPNG = 1;//����ڵ�ԭͼ
IMAGE Plants[10][2];

void loadImgResource() {
    loadimage(&Plants[0][WHITEPNG], "./src/ȫ�����_�������/ȫ�����_�������_�׵ײ���.png", 300, 300);
    loadimage(&Plants[0][BLACKPNG], "./src/ȫ�����_�������/ȫ�����_�������_�ڵװ���.png", 300, 300);
    loadimage(&Plants[1][WHITEPNG], "./src/������ɱ_ը��Ͷ��/������ɱ_ը��Ͷ��_�׵ײ���.png", 300, 300);
    loadimage(&Plants[1][BLACKPNG], "./src/������ɱ_ը��Ͷ��/������ɱ_ը��Ͷ��_�ڵװ���.png", 300, 300);
    loadimage(&Plants[2][WHITEPNG], "./src/��������_���ռ��/��������_���ռ��_�׵ײ���.png", 300, 300);
    loadimage(&Plants[2][BLACKPNG], "./src/��������_���ռ��/��������_���ռ��_�ڵװ���.png", 300, 300);
    //��������
    loadimage(&Plants[4][WHITEPNG], "./src/���ٸ߹�_��Ұ����/���ٸ߹�_��Ұ����_�׵ײ���.png", 300, 300);
    loadimage(&Plants[4][BLACKPNG], "./src/���ٸ߹�_��Ұ����/���ٸ߹�_��Ұ����_�ڵװ���.png", 300, 300);
    loadimage(&Plants[5][WHITEPNG], "./src/��������_��ţ����/��������_��ţ����_�׵ײ���.png", 300, 300);
    loadimage(&Plants[5][BLACKPNG], "./src/��������_��ţ����/��������_��ţ����_�ڵװ���.png", 300, 300);
    loadimage(&Plants[6][WHITEPNG], "./src/ƽƽ����_��������/ƽƽ����_��������_�׵ײ�ͼ.png", 300, 300);
    loadimage(&Plants[6][BLACKPNG], "./src/ƽƽ����_��������/ƽƽ����_��������_�ڵװ�ͼ.png", 300, 300);
    loadimage(&Plants[7][WHITEPNG], "./src/�ٶ�ʱ��_���ϴ���/�ٶ�ʱ��_���ϴ���_�׵ײ���.png", 300, 300);
    loadimage(&Plants[7][BLACKPNG], "./src/�ٶ�ʱ��_���ϴ���/�ٶ�ʱ��_���ϴ���_�ڵװ���.png", 300, 300);
    loadimage(&Plants[8][WHITEPNG], "./src/����֮��_����_�׵ײ���.png", 300, 300);
    loadimage(&Plants[8][BLACKPNG], "./src/����֮��_����_�ڵװ���.png", 300, 300);
}

//����������
void Select_Plant_view() {
    if (bgm.isMusicPlaying()) {
        bgm.stopMusic();
        bgm.playmusic("./src/music/Select.mp3");
    }
    Flag = -1;
    //cleardevice();
    // ��ʼ����
    IMAGE img;
    loadimage(&img, "./src/picture/Select_Plants.jpg");  // ʹ����б��
    loadImgResource();
    


    // ���ϽǵĲ˵�
    Button returnMenu("�˵�", 40, 25, 80, 40);
    returnMenu.setColors(RGB(200, 200, 200), RGB(220, 220, 220), RGB(180, 180, 180), BLACK);

    // ֲ��ѡ��ť
    Button plantButtons[10] = {
        Button("�������", 300, 50, 300, 120),
        Button("ը��Ͷ��", 300, 220, 300, 120),
        Button("���ռ��", 300, 390, 300, 120),
        Button("��������", 300, 560, 300, 120),
        Button("��Ұ����", 300, 730, 300, 120),
        Button("��ţ����", 800, 50, 300, 120),
        Button("��������", 800, 220, 300, 120),
        Button("���ϴ���", 800, 390, 300, 120),
        Button("���ɻ���", 800, 560, 300, 120),
        Button("�����ڴ�", 800, 730, 300, 120)
    };

    for (auto& button : plantButtons) {
        button.setColors(RGB(200, 200, 200), RGB(220, 220, 220), RGB(180, 180, 180), BLACK);
    }

    //��ʼ��ť
    Button Beginner("��ʼ��Ϸ", 1260, 750, 200, 100);
    Beginner.setColors(RGB(100, 150, 255), RGB(150, 200, 255), RGB(50, 100, 200), WHITE);

    bool running = true;
    int currentSelectedPlant = -1; // ��ǰѡ�е�ֲ��������-1��ʾû��ѡ��
    bool plantFlags[10] = { false }; // ���ڸ���ÿ��ֲ���ѡ��״̬
    std::string plantDescriptions[10] = {
        "��������ڡ� Сʱ�����Լ���������� �õܱܵ��˷��ӹ����� ���������� Ƣ�����Ȼ𱬣�",
        "��ը��Ͷ�֡�\n���Ǿ��Ĳ˲� \n����Ի��� ���Ը���һ������\n����������������Ϊ�ǿ�ӣ����\n�����Ե��𣿣�",
        "�����ռ����\nʲô�����˴��㣿\n������ô֪����\nû�������ڿ����𡭡�\n�����ޣ���һ˿�ϴ�����\n�����ԣ���ǹ¶�����ˣ���",
        "���������֡�\n�������ҿ������ҿ���\n���ҿ������ҿ�\n�����ҿ������ҿ�\n�����ҿ������ҿ���\n���ҿ������ҿ�������\n.............",
        "����Ұ���֡�\n��˵��������ȥ����ѧ\nƽ��ϲ��˵ʲô��\n�����о��ͷ��...\n����������˭��˫ǹ������𰸡�",
        "����ţ���֡�\n��ֻ��ţ����\n���ԣ������㶹���֣���\n��������׼��С�������\n��������Ϊ����һս��\n����ʱ��׼���š���\n(��Ȼ����ţ���ٶ�һ��Ҳ������)",
        "���������֡�\nһ��ϲ����Let it go��С���",
        "�����ϴ��ڡ�\nСʱ�������ϵ�ܺ�\n��������С�ĸ������ɢ\n�˺�Ը��˼��ɼ�\n����ʱ���ܹ���Զ\nͣ�������������ʱ�̣�",
        "�����ɻ��𹽡�\n��²�Ϊʲô�ǽ��ɣ���",
        "�������ڴ���",
    };

    bool showNoPlantSelectedMessage = false;
    bool sp = false;
    bool ssp = false;

    if (user.get_isAllPassed()) {
        sp = true;
    }

    while (running && !rtnFlag) {
		BeginBatchDraw();
        putimage(0, 0, &img);  // ���Ʊ���ͼƬ

		settextcolor(LIGHTGRAY);
		settextstyle(120, 0, "����");
		outtextxy(50, 160, "ֲ");
		outtextxy(50, 300, "��");
		outtextxy(50, 440, "ѡ");
		outtextxy(50, 580, "ȡ");

		settextcolor(LIGHTMAGENTA);
		settextstyle(40, 0, "����");
		std::string score = "��ʷ�÷�:��";
		score += std::to_string(user.get_History_Score());
		outtextxy(1200, 50, (score + "��").data());

        // �������а�ť
        returnMenu.draw();
        for (const auto& button : plantButtons) {
            button.draw();
        }
        Beginner.draw();

        // �����ѡ�е�ֲ�����������
        if (currentSelectedPlant != -1) {
            drawTextInRect(1200, 570, 300, 150, plantDescriptions[currentSelectedPlant]);
            putimage(1200, 200, &Plants[currentSelectedPlant][BLACKPNG], SRCPAINT);
            putimage(1200, 200, &Plants[currentSelectedPlant][WHITEPNG], SRCAND);
        }

        // ��ʾδѡ��ֲ�����ʾ
        if (showNoPlantSelectedMessage) {
            //setbkmode(TRANSPARENT);
            settextcolor(RGB(255, 0, 0));  // ��ɫ����
            settextstyle(150, 0, _T("����"));
            outtextxy(300, 400, _T("����ǰδѡ��ֲ��"));
        }

        if (ssp) {
            //setbkmode(TRANSPARENT);
            settextcolor(RGB(255, 0, 0));  // ��ɫ����
            settextstyle(100, 0, _T("����"));
            outtextxy(220, 400, _T("����δͨ�أ�����ʹ�øý�ɫ��"));
        }

        // ������Ϣ
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
                    plantFlags[i] = !plantFlags[i]; // �л�ѡ��״̬
                    if (currentSelectedPlant == i) {
                        currentSelectedPlant = -1; // ����ٴε��ͬһ��ֲ�ȡ��ѡ��
                        Flag = -1;
                        ssp = false;
                    }
                    else {
                        currentSelectedPlant = i; // ѡ���µ�ֲ��
                        Flag = i + 1;
                        ssp = false;
                    }
                    showNoPlantSelectedMessage = false; // ���ֲ�ﰴťʱ������ʾ
                }
            }

            if (returnMenu.wasClicked()) {
                if (bgm.isMusicPlaying()) {
                    bgm.stopMusic();
                    bgm.playmusic("./src/music/Login.mp3");
                }
                // �ص��˵�����
                running = false;
            }

            if (Beginner.wasClicked()) {
                // ��ת���ؿ�ѡ��
                if (Flag == -1) {
                    showNoPlantSelectedMessage = true;
                    ssp = false;
                }
                else if (currentSelectedPlant == 8 && (sp == true /* || sp == false */))  ///////////////////���ɻ��𹽣�����sp==false����ע��ȥ������ʹ��
                {
                    levelselectview();
					currentSelectedPlant = -1; // ѡ���µ�ֲ��
                }
                else if (currentSelectedPlant != 8 && currentSelectedPlant != 9) {
                    levelselectview();
                    currentSelectedPlant = -1; // ѡ���µ�ֲ��
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

        // �����"��ʼ��Ϸ"��ť����ʱ������ʾ
        if (msg.message == WM_LBUTTONDOWN && !Beginner.isPointInside(msg.x, msg.y)) {
            showNoPlantSelectedMessage = false;
        }
		EndBatchDraw(); // ����������ͼ
    }

	if (rtnFlag == 2)		////��������//// (��-1)  ��0  l1  m2  p3
		rtnFlag = 0;
}