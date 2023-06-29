#include <graphics.h>		// 引用图形库头文件
#include <conio.h>
#include <iostream> //控制台输入输出


//C语言天罡三十六题，基础九题
//天魁星，绘制七巧版图案

void draw() {

	setlinecolor(BLACK);
	setfillcolor(WHITE);
	fillrectangle(0, 0, 400, 400);

	setlinecolor(BLACK);
	line(0, 0, 300, 300);
	line(300, 300, 100, 300);
	line(400, 0, 0, 400);
	line(300, 100, 400, 200);
	line(400, 200, 200, 400);

	setfillcolor(GREEN);
	floodfill(2, 1, BLACK);

	setfillcolor(BLUE);
	floodfill(100, 399, BLACK);

	setfillcolor(RGB(255, 165, 0));
	floodfill(1, 2, BLACK);

	setfillcolor(RGB(255, 255, 0));//黄色
	floodfill(201, 200, BLACK);

	setfillcolor(RGB(255, 0, 0));//红色
	floodfill(399, 399, BLACK);

	setfillcolor(RGB(128, 0, 128));//紫色
	floodfill(200, 201, BLACK);

	setfillcolor(RGB(165, 42, 42));//棕色
	floodfill(399, 101, BLACK);


}


void demo()
{
	setlinecolor(BLACK);
	line(15, 15, 50, 50);   // 绘制直线
	line(50, 50, 15, 100);
	line(15, 100, 15, 15);

	setfillcolor(BLUE);      // 设置填充颜色
	setlinecolor(BLACK);     //设置线条颜色
	fillcircle(100, 100, 6);//填充圆形图案

	setfillcolor(YELLOW);				// 身体填充黄色);
	floodfill(30, 50, BLACK, 0); // 填充颜色
}


int main()
{

	// 创建大小为 800 * 600 的绘图窗口
	initgraph(1000, 1000);

	// 设置原点 (0, 0) （Y轴默认向下为正）
	setorigin(300, 300);

	// 使用白色填充背景
	setbkcolor(WHITE);
	cleardevice();

	draw();



	Sleep(2000);//定时2s
	//_getch();				// 按任意键继续
	closegraph();			// 关闭绘图窗口
	return 0;


}
