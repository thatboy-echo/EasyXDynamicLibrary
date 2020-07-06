#define EASYX_STALIB_COMPAT // ´ò¿ª´úÂë¼æÈÝ
#include "../EasyX/EasyXDynamic.h"

int main()
{
	initgraph(640, 480);

	line(0, 0, getwidth() / 2 - 1, getheight() / 2 - 1);
	setfillcolor(RED);
	solidcircle(200, 200, 20);
	outtextxy(300, 300, TEXT("Hello World!"));

	Sleep(2000);
	closegraph();
}