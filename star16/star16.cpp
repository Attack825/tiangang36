//C语言天罡三十六题，进阶九题
//天捷星
//任务：打字母游戏
#include <graphics.h>
#include <time.h>
#include <conio.h>
#include <stdio.h>
#define SCREEN_WIDTH    700
#define SCREEN_HEIGHT   700
#define MaxNum  1000


// 游戏类
class Game
{
public:
	void drawMap() const;						// 绘制地图
	void drawPrompt() const;					// 绘制得分的数据
	// 添加游戏时间
	void addGameTime(clock_t start, clock_t end)
	{
		this->gameTime = ((double)end - start) / CLK_TCK;
	}
	void addTrueNum()
	{
		trueNum += 1;
	}
	void addFalseNum()
	{
		falseNum += 1;
	}

private:
	int trueNum = 0;                       // 正确数量
	int falseNum = 0;                      // 错误数量
	double gameTime = 0;						// 游戏时间
};


// 绘制地图
void Game::drawMap() const
{
	setcolor(BLACK);
	// 绘制边框
	roundrect(50, 50, SCREEN_WIDTH - 50, SCREEN_HEIGHT - 50, 10, 10);
	rectangle(60, 60, SCREEN_WIDTH / 3 * 2, SCREEN_HEIGHT - 60);
	// 数据显示框
	rectangle(SCREEN_WIDTH / 3 * 2 + 30, 140, SCREEN_WIDTH / 3 * 2 + 150, 180);
	rectangle(SCREEN_WIDTH / 3 * 2 + 30, 240, SCREEN_WIDTH / 3 * 2 + 150, 280);
	rectangle(SCREEN_WIDTH / 3 * 2 + 30, 340, SCREEN_WIDTH / 3 * 2 + 150, 380);
	rectangle(SCREEN_WIDTH / 3 * 2 + 30, 440, SCREEN_WIDTH / 3 * 2 + 150, 480);
	// 设置字体
	settextstyle(30, 0, _T("宋体"));
	settextcolor(BLACK);
	// 显示数据名称
	LPCTSTR a = "游戏时间";
	outtextxy(SCREEN_WIDTH / 3 * 2 + 30, 100, a);
	LPCTSTR b = "正确次数";
	outtextxy(SCREEN_WIDTH / 3 * 2 + 30, 200, b);
	LPCTSTR c = "正确率";
	outtextxy(SCREEN_WIDTH / 3 * 2 + 30, 300, c);
	LPCTSTR d = "打字速度";
	outtextxy(SCREEN_WIDTH / 3 * 2 + 30, 400, d);

}


// 绘制得分的数据
void Game::drawPrompt() const
{
	settextstyle(30, 0, _T("Consolas"));
	//游戏时间
	TCHAR gtime[5];
	_stprintf_s(gtime, _T("%.lf"), this->gameTime);		// 高版本 VC 推荐使用 _stprintf_s 函数
	outtextxy(SCREEN_WIDTH / 3 * 2 + 50, 150, gtime);
	//正确次数
	TCHAR tnum[5];
	_stprintf_s(tnum, _T("%d"), this->trueNum);		// 高版本 VC 推荐使用 _stprintf_s 函数
	outtextxy(SCREEN_WIDTH / 3 * 2 + 50, 250, tnum);
	//正确率
	TCHAR trate[5];
	if (this->trueNum == 0)
	{
		_stprintf_s(trate, _T("%.2lf"), 0.00);
	}
	else {
		_stprintf_s(trate, _T("%.2lf"), this->trueNum * 1.0 / (this->trueNum + this->falseNum));		// 高版本 VC 推荐使用 _stprintf_s 函数
	}outtextxy(SCREEN_WIDTH / 3 * 2 + 50, 350, trate);
	//打字速度
	TCHAR v[5];
	if (this->trueNum == 0)
	{
		_stprintf_s(v, _T("%.2lf"), 0.00);
	}
	else {
		_stprintf_s(v, _T("%.2lf"), this->trueNum * 1.0 / this->gameTime);		// 高版本 VC 推荐使用 _stprintf_s 函数
	}
	outtextxy(SCREEN_WIDTH / 3 * 2 + 50, 450, v);

}

class Letter
{
public:
	Letter(Game& game);	// 初始化函数
	void move();									// 移动函数
	void draw() const;															// 绘制函数
	void clear() const;															// 清除函数
	bool checkCollision() const;			// 碰撞检查
	TCHAR getCh() const
	{
		return this->ch;
	}

private:
	int x;
	int y;
	TCHAR ch;
	COLORREF color;					// 字母填充颜色
	Game& game;						// Game 引用对象

};


// 初始化函数
Letter::Letter(Game& game) :game(game)
{
	srand((unsigned)time(NULL));
	int letterX[3] = { SCREEN_WIDTH / 3 - 140,SCREEN_WIDTH / 3,SCREEN_WIDTH / 3 + 140 };
	this->x = letterX[rand() % 3];
	this->y = 70;
	this->ch = _T(rand() % 26 + 'A');
	this->color = BLACK;

}

//检查碰撞
bool Letter::checkCollision() const
{
	if (this->y >= SCREEN_HEIGHT - 150)
	{
		return true;
	}
	return false;
}


// 移动函数
void Letter::move()
{
	this->y += 10;
}
// 绘制函数
void Letter::draw() const
{
	settextcolor(this->color);
	settextstyle(50, 0, _T("Consolas"));
	outtextxy(this->x, this->y, this->ch);

}
// 清除函数
void Letter::clear() const
{
	settextcolor(WHITE);
	settextstyle(50, 0, _T("Consolas"));
	outtextxy(this->x, this->y, &this->ch);
}

void main()
{

	initgraph(SCREEN_WIDTH, SCREEN_HEIGHT);
	setbkcolor(WHITE);
	cleardevice();
	Game game;
	game.drawMap();
	game.drawPrompt();
	clock_t start, end;
	start = clock();

	// 初始化字母
	Letter* letter[MaxNum];
	for (int i = 0; i < MaxNum; i++)
	{
		letter[i] = new Letter(game);
	}
	int count = 0;
	// 游戏循环
	BeginBatchDraw();
	ExMessage msg;
	while (true)
	{
		end = clock();
		game.addGameTime(start, end);
		game.drawPrompt();
		letter[count]->draw();

		if (letter[count]->checkCollision())
		{
			letter[count]->clear();
			delete letter[count];
			letter[count] = new Letter(game);
			MessageBox(GetHWnd(), "游戏结束！", "提示", MB_ICONWARNING);
			return;
		}
		else
		{
			if (peekmessage(&msg, EX_KEY) && msg.message == WM_KEYDOWN)  // 如果按键
			{
				if (msg.vkcode == letter[count]->getCh())  // 如果按键与字母相同
				{
					letter[count]->clear();
					delete letter[count];
					letter[count] = new Letter(game);
					game.addTrueNum();
				}
				else
				{
					game.addFalseNum();
				}
			}

			letter[count]->clear();
			letter[count]->move();
			letter[count]->draw();

		}

		Sleep(100);
		FlushBatchDraw();
	}

	EndBatchDraw();


	//Sleep(2000);
	closegraph();
}