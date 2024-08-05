#include"Enviroment.h"


int main() {
	initgraph(WIDTH, HEIGHT, EX_NOCLOSE);
	SetWindowPos(GetHWnd(), NULL, 60, 35, 0, 0, SWP_NOSIZE | SWP_NOZORDER);

	setbkcolor(LIGHTCYAN);
	setbkmode(TRANSPARENT);
	Login_View();

	closegraph();
	return 0;
}
