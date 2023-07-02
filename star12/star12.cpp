// �������ƣ��ǿ�
// ���뻷����Visual C++ 6.0��EasyX_20200902
// �����£�2009-2-22
//
#include <graphics.h>
#include <time.h>
#include <conio.h>
#define MAXSTAR 200	// ��������

struct STAR
{
	double x;
	int y;
	double step;
	int color;
};

STAR star[MAXSTAR];

// ��ʼ������
void InitStar(int i)
{
	star[i].x = 0;
	star[i].y = rand() % 480;
	star[i].step = (rand() % 5000) / 1000.0 + 1;
	star[i].color = (int)(star[i].step * 255 / 6.0 + 0.5);	// �ٶ�Խ�죬��ɫԽ��
	star[i].color = RGB(star[i].color, star[i].color, star[i].color);
}

// �ƶ�����
void MoveStar(int i)
{
	// ����ԭ��������
	putpixel((int)star[i].x, star[i].y, 0);

	// ������λ��
	star[i].x += star[i].step;
	if (star[i].x > 640)	InitStar(i);

	// ��������
	putpixel((int)star[i].x, star[i].y, star[i].color);
}

// ������
int main1()
{
	srand((unsigned)time(NULL)); // �������
	initgraph(640, 480);	// ��ͼ�δ���

	// ��ʼ����������
	for (int i = 0; i < MAXSTAR; i++)
	{
		InitStar(i);
		star[i].x = rand() % 640;
	}

	// �����ǿգ���������˳�
	while (!_kbhit())
	{
		for (int i = 0; i < MAXSTAR; i++)
			MoveStar(i);
		Sleep(20);
	}

	closegraph();    // �ر�ͼ�δ���
	return 0;
}