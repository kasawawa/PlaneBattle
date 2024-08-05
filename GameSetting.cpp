#include "Enviroment.h"

void gamesetting() {
	//cleardevice();
	IMAGE img;
	loadimage(&img, "./src/picture/Menu.jpg",1600,900);
	Button returnMenu("����", 700, 600, 200, 100);
	returnMenu.setColors(RGB(200, 200, 200), RGB(220, 220, 220), RGB(180, 180, 180), BLACK);
	Button turnup("����+", 350, 295, 300, 100 );
	turnup.setColors(RGB(200, 200, 200), RGB(220, 220, 220), RGB(180, 180, 180), BLACK);
	Button turndown("����-", 950, 295, 300, 100);
	turndown.setColors(RGB(200, 200, 200), RGB(220, 220, 220), RGB(180, 180, 180), BLACK);
	Button soundon("��Ч��", 350, 445, 300, 100);
	soundon.setColors(RGB(200, 200, 200), RGB(220, 220, 220), RGB(180, 180, 180), BLACK);
	Button soundoff("��Ч��", 950, 445, 300, 100);
	soundoff.setColors(RGB(200, 200, 200), RGB(220, 220, 220), RGB(180, 180, 180), BLACK);

	bool running = true;

	BeginBatchDraw();
	while (running) {
		putimage(0, 0, &img);
		bgm.displayVolume();
		//��ť����
		returnMenu.draw();
		turnup.draw();
		turndown.draw();
		soundon.draw();
		soundoff.draw();


		while (peekmessage(&msg)) {
			if (msg.message == WM_CLOSE) {
				running = false;
				break;
			}
			//��ť״̬����
			turndown.update();
			turnup.update();
			returnMenu.update();
			soundon.update();
			soundoff.update();
			

			//��ť�߼��ж�
			if (returnMenu.wasClicked()) {
				bgm.resumeMusic();
				return;
			}
			if(turndown.wasClicked()){
				bgm.decrease();
			}
			if(turnup.wasClicked()){
				bgm.increase();
			}
			if(soundon.wasClicked()){
				//����Ч
				isSound=true;
			}
			if(soundoff.wasClicked()){
				//�ر���Ч
				isSound = false;
			}
		}
		FlushBatchDraw();
		Sleep(10);
	}
	EndBatchDraw();
}