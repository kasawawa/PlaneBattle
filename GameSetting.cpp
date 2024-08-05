#include "Enviroment.h"

void gamesetting() {
	//cleardevice();
	IMAGE img;
	loadimage(&img, "./src/picture/Menu.jpg",1600,900);
	Button returnMenu("返回", 700, 600, 200, 100);
	returnMenu.setColors(RGB(200, 200, 200), RGB(220, 220, 220), RGB(180, 180, 180), BLACK);
	Button turnup("音量+", 350, 295, 300, 100 );
	turnup.setColors(RGB(200, 200, 200), RGB(220, 220, 220), RGB(180, 180, 180), BLACK);
	Button turndown("音量-", 950, 295, 300, 100);
	turndown.setColors(RGB(200, 200, 200), RGB(220, 220, 220), RGB(180, 180, 180), BLACK);
	Button soundon("音效开", 350, 445, 300, 100);
	soundon.setColors(RGB(200, 200, 200), RGB(220, 220, 220), RGB(180, 180, 180), BLACK);
	Button soundoff("音效关", 950, 445, 300, 100);
	soundoff.setColors(RGB(200, 200, 200), RGB(220, 220, 220), RGB(180, 180, 180), BLACK);

	bool running = true;

	BeginBatchDraw();
	while (running) {
		putimage(0, 0, &img);
		bgm.displayVolume();
		//按钮绘制
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
			//按钮状态更新
			turndown.update();
			turnup.update();
			returnMenu.update();
			soundon.update();
			soundoff.update();
			

			//按钮逻辑判断
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
				//打开音效
				isSound=true;
			}
			if(soundoff.wasClicked()){
				//关闭音效
				isSound = false;
			}
		}
		FlushBatchDraw();
		Sleep(10);
	}
	EndBatchDraw();
}