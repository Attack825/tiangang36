//C语言天罡三十六题，进阶九题
//天英星
//任务： 天孤星
//任务：通过键盘控制一个小球上下左右移动

#include <graphics.h>
#include <time.h>
#include <conio.h>
#include<iostream>

#define SCREEN_WIDTH    1024
#define SCREEN_HEIGHT   768
struct Player // 结构体，用于记录玩家位置
{
	int x;
	int y;
};
Player player; // 玩家全局变量


void DrawBK() {

	setfillcolor(BLUE);
	fillrectangle(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
	for (int i = 1; i < 31; i++)
		for (int j = 1; j < 21; j++)
		{
			setfillcolor(WHITE);
			fillcircle(SCREEN_WIDTH / 31 * i, SCREEN_HEIGHT / 21 * j, 15);
		}
	setfillcolor(BLACK);
	fillcircle(SCREEN_WIDTH / 31 * player.x, SCREEN_HEIGHT / 21 * player.y, 15);
	FlushBatchDraw();
}

void update()  // 每帧更新运行
{
	if (kbhit())  // 如果按键
	{
		int input = _getch(); // 获取按键
		if (input == 'a' || input == 'A' || input == 75) // 向左
		{
			player.x--; // 目标位置在玩家位置的左边
		}
		else if (input == 'd' || input == 'D' || input == 77) // 向右
		{
			player.x++; // 目标位置在玩家位置的右边 
		}
		else if (input == 's' || input == 'S' || input == 80) // 向下
		{
			player.y++; // 目标位置在玩家位置的下边 
		}
		else if (input == 'w' || input == 'W' || input == 72) // 向上
		{
			player.y--; // 目标位置在玩家位置的上边 
		}

	}
}

void main()
{

	initgraph(SCREEN_WIDTH, SCREEN_HEIGHT);

	setbkcolor(WHITE);
	cleardevice();
	BeginBatchDraw();
	player.x = 10;
	player.y = 10;
	while (1)  // 游戏主循环
	{
		DrawBK();
		update();   // 更新
	}
	EndBatchDraw();

	closegraph();
}
