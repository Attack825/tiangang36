#include <graphics.h>		// 引用图形库头文件
#include <conio.h>
#include <iostream> //控制台输入输出


//C语言天罡三十六题，基础九题
//天魁星，绘制七巧版图案

void draw() {



}



int main()
{

	// 创建大小为 800 * 600 的绘图窗口
	initgraph(800, 600);

	// 设置原点 (0, 0) 为屏幕中央（Y轴默认向下为正）
	setorigin(400, 300);

	// 使用白色填充背景
	setbkcolor(WHITE);
	cleardevice();


	setlinecolor(BLACK);
	line(15, 15, 50, 50);   // 绘制直线
	line(50, 50, 15, 100);
	line(15, 100, 15, 15);

	setfillcolor(BLUE);      // 设置填充颜色
	setlinecolor(BLACK);     //设置线条颜色
	fillcircle(100, 100, 6);//填充圆形图案

	setfillcolor(YELLOW);				// 身体填充蓝色CK);
	floodfill(30, 50, BLACK, 0); // 填充颜色


	Sleep(2000);//定时2s
	//_getch();				// 按任意键继续
	closegraph();			// 关闭绘图窗口
	return 0;


}
