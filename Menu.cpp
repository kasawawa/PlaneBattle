#include "Enviroment.h"

void Menu_View()
{
    if(bgm.isMusicPlaying())
		bgm.stopMusic();
    bgm.playmusic("./src/music/Login.mp3");
    Widget_xiaoxin widget(1600, 900);
    widget.init();
    widget.run();

	if(rtnFlag != -1)		////明雅流风//// (退-1)  无0  l1  m2  p3
		rtnFlag = 0;
}