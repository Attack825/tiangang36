#include <graphics.h>		// 引用图形库头文件
#include <conio.h>
#include <math.h>


//C语言天罡三十六题，基础九题
//天机星
//任务：画标准国旗（框线图）


//绘制五角星含有颜色
void fillstar(int x, int y, int R, int degree, COLORREF color = WHITE)
{
	double rad = 3.1415926 / 180;                    //每度的弧度值
	double r = R * sin(18 * rad) / cos(36 * rad);    //五角星短轴的长度
	POINT RVertex[5], rVertex[5];
	for (int k = 0; k < 5; k++)                      //求取坐标
	{
		RVertex[k] = { int(x - (R * cos((90 + k * 72 + degree) * rad))), int(y - (R * sin((90 + k * 72 + degree) * rad))) };
		rVertex[k] = { int(x - (r * cos((90 + 36 + k * 72 + degree) * rad))), int(y - (r * sin((90 + 36 + k * 72 + degree) * rad))) };
	}
	setlinecolor(BLACK);                             //上色
	for (int i = 0; i < 5; i++)
	{
		line(RVertex[i].x, RVertex[i].y, rVertex[i].x, rVertex[i].y);
		line(rVertex[i].x, rVertex[i].y, RVertex[(i + 1) % 5].x, RVertex[(i + 1) % 5].y);
	}
	setfillcolor(color);
	floodfill(x, y, BLACK);
}

void RedFlag()
{
	double rad = 3.1415926 / 180;                    //每度的弧度值
	setfillcolor(RGB(255, 0, 0));
	//y轴默认向下为正
	fillrectangle(0, 200, 300, 0);
	fillstar(50, 50, 30, 0, YELLOW);
	fillstar(100, 20, 10, 270 - atan(3 / 5) / rad, YELLOW);
	fillstar(120, 40, 10, 270 - atan(1 / 7) / rad, YELLOW);
	fillstar(120, 70, 10, 270 + atan(2 / 7) / rad, YELLOW);
	fillstar(100, 90, 10, 270 + atan(4 / 5) / rad, YELLOW);

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

	RedFlag();
	//fillstar(0,0,100,0,YELLOW);


	Sleep(2000);//定时2s
	//_getch();				// 按任意键继续
	closegraph();			// 关闭绘图窗口
	return 0;


}


