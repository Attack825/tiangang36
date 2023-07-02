#include <graphics.h>		// 引用图形库头文件
#include <conio.h>
#include <math.h>
#include<string>
//C语言天罡三十六题，进阶九题
//天英星
//任务： 天富星
//任务：绘制下面两张传说中的视觉错觉图片

int main()
{

	// 创建大小为 1000 * 1000 的绘图窗口
	initgraph(620, 420);

	setbkcolor(WHITE);
	// 用背景色清空屏幕
	cleardevice();

	setfillcolor(BLACK);
	fillrectangle(0, 0, 600, 400);

	for (int i = 1; i < 9; i++)
	{
		setfillcolor(RGB(128, 128, 128));

		solidrectangle(0, 400 / 9 * i - 5, 600, 400 / 9 * i + 5);
	}
	for (int i = 1; i < 13; i++)
	{
		setfillcolor(RGB(128, 128, 128));
		solidrectangle(600 / 13 * i - 5, 0, 600 / 13 * i + 5, 400);
	}

	for (int i = 1; i < 9; i++)
		for (int j = 1; j < 13; j++)
		{
			setfillcolor(WHITE);
			fillcircle(600 / 13 * j, 400 / 9 * i, 6);
		}
	Sleep(20000);
	closegraph();
	return 0;

}
