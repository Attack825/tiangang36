#include <graphics.h>		// 引用图形库头文件
#include <conio.h>



//C语言天罡三十六题，基础九题
//5. 天勇星
//任务：模拟 45 度反弹的小球。



//模拟 45 度反弹的小球
void PinBall()
{
	float vy = 2;
	float vx = 2;
	float x = rand() % 300;
	float y = rand() % 300;
	setlinecolor(BLACK);
	setfillcolor(WHITE);
	fillrectangle(0, 300, 300, 0);
	while (!_kbhit())
	{
		y += vy;
		x += vx;
		if (y >= 280 || y <= 20)
			vy = -vy;
		if (x >= 280 || x <= 20)
			vx = -vx;
		//画球
		setlinecolor(GREEN);
		circle(x, y, 20);
		FlushBatchDraw();
		Sleep(10);
		//擦球
		setlinecolor(WHITE);
		circle(x, y, 20);
	}

}

int main()
{

	// 创建大小为 1000 * 1000 的绘图窗口
	initgraph(1000, 1000);

	// 设置原点 (0, 0) （Y轴默认向下为正）
	setbkcolor(WHITE);
	setorigin(300, 300);
	BeginBatchDraw();
	PinBall();

	EndBatchDraw();
	Sleep(2000);//定时2s
	//_getch();				// 按任意键继续
	closegraph();			// 关闭绘图窗口
	return 0;
}
