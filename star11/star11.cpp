#include <graphics.h>		// ����ͼ�ο�ͷ�ļ�
#include <conio.h>
#include <math.h>
#include<string>
//C���������ʮ���⣬���׾���
//��Ӣ��
//���� �츻��
//���񣺻����������Ŵ�˵�е��Ӿ����ͼƬ

int main()
{

	// ������СΪ 1000 * 1000 �Ļ�ͼ����
	initgraph(620, 420);

	setbkcolor(WHITE);
	// �ñ���ɫ�����Ļ
	cleardevice();

	setfillcolor(BLACK);
	fillrectangle(0, 0, 600, 400);

	for (int i = 1; i < 9; i++)
	{
		setfillcolor(RGB(128, 128, 128));

		solidrectangle(0, 400 / 9 * i - 5, 600, 400 / 9 * i + 5);
	}
	for (int i = 1; i < 13; i++)
	{
		setfillcolor(RGB(128, 128, 128));
		solidrectangle(600 / 13 * i - 5, 0, 600 / 13 * i + 5, 400);
	}

	for (int i = 1; i < 9; i++)
		for (int j = 1; j < 13; j++)
		{
			setfillcolor(WHITE);
			fillcircle(600 / 13 * j, 400 / 9 * i, 6);
		}
	Sleep(20000);
	closegraph();
	return 0;

}
