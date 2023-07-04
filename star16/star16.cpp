//C���������ʮ���⣬���׾���
//�����
//���񣺴���ĸ��Ϸ
#include <graphics.h>
#include <time.h>
#include <conio.h>
#include <stdio.h>
#define SCREEN_WIDTH    700
#define SCREEN_HEIGHT   700
#define MaxNum  1000


// ��Ϸ��
class Game
{
public:
	void drawMap() const;						// ���Ƶ�ͼ
	void drawPrompt() const;					// ���Ƶ÷ֵ�����
	// �����Ϸʱ��
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
	int trueNum = 0;                       // ��ȷ����
	int falseNum = 0;                      // ��������
	double gameTime = 0;						// ��Ϸʱ��
};


// ���Ƶ�ͼ
void Game::drawMap() const
{
	setcolor(BLACK);
	// ���Ʊ߿�
	roundrect(50, 50, SCREEN_WIDTH - 50, SCREEN_HEIGHT - 50, 10, 10);
	rectangle(60, 60, SCREEN_WIDTH / 3 * 2, SCREEN_HEIGHT - 60);
	// ������ʾ��
	rectangle(SCREEN_WIDTH / 3 * 2 + 30, 140, SCREEN_WIDTH / 3 * 2 + 150, 180);
	rectangle(SCREEN_WIDTH / 3 * 2 + 30, 240, SCREEN_WIDTH / 3 * 2 + 150, 280);
	rectangle(SCREEN_WIDTH / 3 * 2 + 30, 340, SCREEN_WIDTH / 3 * 2 + 150, 380);
	rectangle(SCREEN_WIDTH / 3 * 2 + 30, 440, SCREEN_WIDTH / 3 * 2 + 150, 480);
	// ��������
	settextstyle(30, 0, _T("����"));
	settextcolor(BLACK);
	// ��ʾ��������
	LPCTSTR a = "��Ϸʱ��";
	outtextxy(SCREEN_WIDTH / 3 * 2 + 30, 100, a);
	LPCTSTR b = "��ȷ����";
	outtextxy(SCREEN_WIDTH / 3 * 2 + 30, 200, b);
	LPCTSTR c = "��ȷ��";
	outtextxy(SCREEN_WIDTH / 3 * 2 + 30, 300, c);
	LPCTSTR d = "�����ٶ�";
	outtextxy(SCREEN_WIDTH / 3 * 2 + 30, 400, d);

}


// ���Ƶ÷ֵ�����
void Game::drawPrompt() const
{
	settextstyle(30, 0, _T("Consolas"));
	//��Ϸʱ��
	TCHAR gtime[5];
	_stprintf_s(gtime, _T("%.lf"), this->gameTime);		// �߰汾 VC �Ƽ�ʹ�� _stprintf_s ����
	outtextxy(SCREEN_WIDTH / 3 * 2 + 50, 150, gtime);
	//��ȷ����
	TCHAR tnum[5];
	_stprintf_s(tnum, _T("%d"), this->trueNum);		// �߰汾 VC �Ƽ�ʹ�� _stprintf_s ����
	outtextxy(SCREEN_WIDTH / 3 * 2 + 50, 250, tnum);
	//��ȷ��
	TCHAR trate[5];
	if (this->trueNum == 0)
	{
		_stprintf_s(trate, _T("%.2lf"), 0.00);
	}
	else {
		_stprintf_s(trate, _T("%.2lf"), this->trueNum * 1.0 / (this->trueNum + this->falseNum));		// �߰汾 VC �Ƽ�ʹ�� _stprintf_s ����
	}outtextxy(SCREEN_WIDTH / 3 * 2 + 50, 350, trate);
	//�����ٶ�
	TCHAR v[5];
	if (this->trueNum == 0)
	{
		_stprintf_s(v, _T("%.2lf"), 0.00);
	}
	else {
		_stprintf_s(v, _T("%.2lf"), this->trueNum * 1.0 / this->gameTime);		// �߰汾 VC �Ƽ�ʹ�� _stprintf_s ����
	}
	outtextxy(SCREEN_WIDTH / 3 * 2 + 50, 450, v);

}

class Letter
{
public:
	Letter(Game& game);	// ��ʼ������
	void move();									// �ƶ�����
	void draw() const;															// ���ƺ���
	void clear() const;															// �������
	bool checkCollision() const;			// ��ײ���
	TCHAR getCh() const
	{
		return this->ch;
	}

private:
	int x;
	int y;
	TCHAR ch;
	COLORREF color;					// ��ĸ�����ɫ
	Game& game;						// Game ���ö���

};


// ��ʼ������
Letter::Letter(Game& game) :game(game)
{
	srand((unsigned)time(NULL));
	int letterX[3] = { SCREEN_WIDTH / 3 - 140,SCREEN_WIDTH / 3,SCREEN_WIDTH / 3 + 140 };
	this->x = letterX[rand() % 3];
	this->y = 70;
	this->ch = _T(rand() % 26 + 'A');
	this->color = BLACK;

}

//�����ײ
bool Letter::checkCollision() const
{
	if (this->y >= SCREEN_HEIGHT - 150)
	{
		return true;
	}
	return false;
}


// �ƶ�����
void Letter::move()
{
	this->y += 10;
}
// ���ƺ���
void Letter::draw() const
{
	settextcolor(this->color);
	settextstyle(50, 0, _T("Consolas"));
	outtextxy(this->x, this->y, this->ch);

}
// �������
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

	// ��ʼ����ĸ
	Letter* letter[MaxNum];
	for (int i = 0; i < MaxNum; i++)
	{
		letter[i] = new Letter(game);
	}
	int count = 0;
	// ��Ϸѭ��
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
			MessageBox(GetHWnd(), "��Ϸ������", "��ʾ", MB_ICONWARNING);
			return;
		}
		else
		{
			if (peekmessage(&msg, EX_KEY) && msg.message == WM_KEYDOWN)  // �������
			{
				if (msg.vkcode == letter[count]->getCh())  // �����������ĸ��ͬ
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