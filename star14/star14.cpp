//C语言天罡三十六题，进阶九题
//任务： 天伤星
//任务：康威生命游戏

#include <graphics.h>
#include <time.h>
#include <conio.h>
#define Dead false
#define Alive true
#define MaxLife 10100
#define SCREEN_WIDTH    700
#define SCREEN_HEIGHT   700

struct Cell          // 结构体，用于细胞位置
{
	bool life;
	int count;       //记录附近的存活数
};
Cell cell[110][110]; // 玩家全局变量

void InitCell()
{

	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 100; j++)
		{
			cell[i][j].count = 0;
		}

	cell[50][50].life = Alive;
	cell[51][51].life = Alive;
	cell[52][51].life = Alive;
	cell[52][50].life = Alive;
	cell[52][49].life = Alive;


}
void DrawBK() {

	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 100; j++)
		{
			if (cell[i][j].life)
			{
				// 边界检查
				if (i + 1 < 100 && j - 1 >= 0) {
					cell[i + 1][j - 1].count++;
				}
				if (j - 1 >= 0) {
					cell[i][j - 1].count++;
				}
				if (i - 1 >= 0) {
					cell[i - 1][j].count++;
				}
				if (i - 1 >= 0 && j + 1 < 100) {
					cell[i - 1][j + 1].count++;
				}
				if (i - 1 >= 0 && j - 1 >= 0) {
					cell[i - 1][j - 1].count++;
				}
				if (j + 1 < 100) {
					cell[i][j + 1].count++;
				}
				if (i + 1 < 100) {
					cell[i + 1][j].count++;
				}
				if (i + 1 < 100 && j + 1 < 100) {
					cell[i + 1][j + 1].count++;
				}
				setfillcolor(BLACK);
				fillrectangle(SCREEN_WIDTH / 100 * (i + 1), SCREEN_HEIGHT / 100 * (j + 1), SCREEN_WIDTH / 100 * (i + 1) + 4, SCREEN_HEIGHT / 100 * (j + 1) + 4);
			}
			else {
				setfillcolor(WHITE);
				fillrectangle(SCREEN_WIDTH / 100 * (i + 1), SCREEN_HEIGHT / 100 * (j + 1), SCREEN_WIDTH / 100 * (i + 1) + 4, SCREEN_HEIGHT / 100 * (j + 1) + 4);
			}
		}

	FlushBatchDraw();
	Sleep(1000);
}

void update()  // 每帧更新运行
{
	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 100; j++)
		{
			if (cell[i][j].life)
			{
				if (cell[i][j].count < 2 || cell[i][j].count>3)
					cell[i][j].life = Dead;
				else
					cell[i][j].life = Alive;
			}
			else
			{
				if (cell[i][j].count == 3)
					cell[i][j].life = Alive;
				else
					cell[i][j].life = Dead;
			}
			cell[i][j].count = 0;
		}
}


void main()
{

	initgraph(SCREEN_WIDTH, SCREEN_HEIGHT);

	setbkcolor(BLUE);
	cleardevice();
	InitCell();
	BeginBatchDraw();
	while (1)  // 游戏主循环
	{
		DrawBK();
		update();   // 更新
	}
	EndBatchDraw();

	closegraph();
}