#include <graphics.h>		// 引用图形库头文件
#include <conio.h>
#include <math.h>
#include<string>
//C语言天罡三十六题，基础九题
//天英星
//任务：模拟指针形式的钟表
//简约时钟



const double PI = 3.141592654;	// 定义圆周率



void DrawPolygon(int x, int y, int sides, int radius) {
	int angle = 360 / sides; // 每个角的度数
	int startX = x + radius * cos(0 * 3.14 / 180);
	int startY = y + radius * sin(0 * 3.14 / 180);
	int endX, endY;

	for (int i = 1; i <= sides; i++) {
		endX = x + radius * cos(i * angle * 3.14 / 180);
		endY = y + radius * sin(i * angle * 3.14 / 180);
		line(startX, startY, endX, endY);
		startX = endX;
		startY = endY;
	}
}
void DrawBK(int x, int y, int R, double degree)
{
	double rad = PI / 180;                    //每度的弧度值
	POINT RVertex[8];
	for (int k = 0; k < 8; k++)                      //求取坐标
	{
		RVertex[k] = { int(x - (R * cos((90 + k * 45 + degree) * rad))), int(y - (R * sin((90 + k * 45 + degree) * rad))) };
	}
	setlinestyle(PS_SOLID | PS_JOIN_BEVEL, 10);
	setlinecolor(BLACK);                             //上色
	for (int i = 0; i < 8; i++)
	{
		line(RVertex[i].x, RVertex[i].y, RVertex[(i + 1) % 8].x, RVertex[(i + 1) % 8].y);
	}
	setlinestyle(PS_SOLID | PS_JOIN_BEVEL, 2);
	setlinecolor(BLACK);
	for (int i = 0; i < 4; i++)
	{
		line(RVertex[2 * i].x, RVertex[2 * i].y, RVertex[(2 * i + 2) % 8].x, RVertex[(2 * i + 2) % 8].y);
		line(RVertex[2 * i + 1].x, RVertex[2 * i + 1].y, RVertex[(2 * i + 3) % 8].x, RVertex[(2 * i + 3) % 8].y);
	}
	line(RVertex[0].x, RVertex[0].y, RVertex[4].x, RVertex[4].y);
	line(RVertex[7].x, RVertex[7].y, RVertex[3].x, RVertex[3].y);
	setfillcolor(RGB(240,240,240));
	fillcircle(0, 0, 230);
	setfillcolor(WHITE);
	fillcircle(0, 0, 170);
	setlinecolor(BLACK);
	line(0, 170, 0, -170);
	line(10, 170, 10, -170);
	line(-10, 170, -10, -170);
	line(170, 0, -170, 0);
	line(170, 10, -170, 10);
	line(170, -10, -170, -10);
	setfillcolor(BLACK);
	fillcircle(0, 0, 100);

	// 显示表盘细节
	settextcolor(BLACK);				// 设置字体颜色
	setbkmode(TRANSPARENT);				// 设置背景色为透明
	for (int n = 0; n < 12; n++)
	{
		// 显示数字
		TCHAR s[10];
		_stprintf(s, _T("%d"), 12 - n);       // 高版本 VC 推荐使用 _stprintf_s 函数
		// 设置字体、大小及输出
		settextstyle(48, 0, _T("Consolas"));

		// 定义字符串长和宽，居中
		int w, h;
		w = textwidth(s);
		h = textheight(s);
		outtextxy(int(200 * cos(n * 2 * PI / 12 + PI / 2) - w / 2),
			-int(200 * sin(n * 2 * PI / 12 + PI / 2) + h / 2),
			s);
	}
}

//表盘
void Dial()
{
	//DrawPolygon(0, 0, 8, 100);
	DrawBK(0, 0, 300, 22.5);
}


//数字时钟
void Clock(int h, int m, int s)
{
	// 画显示当前时间的三个小矩形
	setlinecolor(LIGHTGRAY);	// 设置边框颜色为浅灰色
	setfillcolor(WHITE);		// 设置填充颜色为白色
	fillrectangle(-40 - 13, 50, -40 + 13, 50 + 26);
	fillrectangle(-13, 50, 13, 50 + 26);
	fillrectangle(40 - 13, 50, 40 + 13, 50 + 26);

	// 显示当前时间
	settextstyle(24, 0, _T("Consolas"));
	TCHAR a[10];

	int w;
	_stprintf(a, _T("%d"), h);	w = textwidth(a);	outtextxy(-40 - w / 2, 50, a);
	_stprintf(a, _T("%d"), m);	w = textwidth(a);	outtextxy(-w / 2, 50, a);
	_stprintf(a, _T("%d"), s);	w = textwidth(a);	outtextxy(40 - w / 2, 50, a);
}


//表针
void Needle(int h, int m, int s)
{
	double a = PI / 2 - (2 * PI * h / 12 + 2 * PI * 1 / 12 * m / 60);	// 时针所走弧度
	double b = PI / 2 - (2 * PI * m / 60 + 2 * PI * 1 / 60 * s / 60);	// 分针所走弧度
	double c = PI / 2 - 2 * PI * s / 60;								// 秒针所走弧度

	setlinecolor(WHITE);
	setlinestyle(PS_SOLID, 9);											// 设置线宽为九像素
	line(0, 0, int(50 * cos(a)), int(-50 * sin(a)));					// 画时针

	setlinestyle(PS_SOLID, 6);											// 设置线宽为六像素
	line(0, 0, int(90 * cos(b)), int(-90 * sin(b)));					// 画分针

	setlinestyle(PS_SOLID, 3);											// 设置线宽为三像素
	line(int(20 * cos(c + PI)), -int(20 * sin(c + PI)), int(100 * cos(c)), -int(100 * sin(c)));	// 画秒针
}




int main()
{

	// 创建大小为 1000 * 1000 的绘图窗口
	initgraph(1000, 1000);

	// 设置原点 (0, 0) （Y轴默认向下为正）
	setorigin(500, 500);
	// 使用白色填充背景
	setbkcolor(WHITE);
	cleardevice();
	BeginBatchDraw();		// 开启批量绘图
	while (true)
	{
		// 计算
		SYSTEMTIME ti;		// 定义变量保存当前时间
		GetLocalTime(&ti);	// 获取当前时间

		// 绘画
		cleardevice();
		Dial();										// 画表盘
		Clock(ti.wHour, ti.wMinute, ti.wSecond);	// 画数字时钟
		Needle(ti.wHour, ti.wMinute, ti.wSecond);	// 画表针

		// 延时
		FlushBatchDraw();
		Sleep(1000);
	}

	_getch();
	EndBatchDraw();
	closegraph();
	return 0;

}
