//C���������ʮ���⣬���׾���
//��Ӣ��
//���� �����
//����ͨ�����̿���һ��С�����������ƶ�

#include <graphics.h>
#include <time.h>
#include <conio.h>
#include<iostream>

#define SCREEN_WIDTH    1024
#define SCREEN_HEIGHT   768
struct Player // �ṹ�壬���ڼ�¼���λ��
{
	int x;
	int y;
};
Player player; // ���ȫ�ֱ���


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

void update()  // ÿ֡��������
{
	if (kbhit())  // �������
	{
		int input = _getch(); // ��ȡ����
		if (input == 'a' || input == 'A' || input == 75) // ����
		{
			player.x--; // Ŀ��λ�������λ�õ����
		}
		else if (input == 'd' || input == 'D' || input == 77) // ����
		{
			player.x++; // Ŀ��λ�������λ�õ��ұ� 
		}
		else if (input == 's' || input == 'S' || input == 80) // ����
		{
			player.y++; // Ŀ��λ�������λ�õ��±� 
		}
		else if (input == 'w' || input == 'W' || input == 72) // ����
		{
			player.y--; // Ŀ��λ�������λ�õ��ϱ� 
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
	while (1)  // ��Ϸ��ѭ��
	{
		DrawBK();
		update();   // ����
	}
	EndBatchDraw();

	closegraph();
}
