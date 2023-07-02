#include <graphics.h>		// ����ͼ�ο�ͷ�ļ�
#include <conio.h>
#include <math.h>
#include<string>
//C���������ʮ���⣬��������
//��Ӣ��
//����ģ��ָ����ʽ���ӱ�
//��Լʱ��



const double PI = 3.141592654;	// ����Բ����



void DrawPolygon(int x, int y, int sides, int radius) {
	int angle = 360 / sides; // ÿ���ǵĶ���
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
	double rad = PI / 180;                    //ÿ�ȵĻ���ֵ
	POINT RVertex[8];
	for (int k = 0; k < 8; k++)                      //��ȡ����
	{
		RVertex[k] = { int(x - (R * cos((90 + k * 45 + degree) * rad))), int(y - (R * sin((90 + k * 45 + degree) * rad))) };
	}
	setlinestyle(PS_SOLID | PS_JOIN_BEVEL, 10);
	setlinecolor(BLACK);                             //��ɫ
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

	// ��ʾ����ϸ��
	settextcolor(BLACK);				// ����������ɫ
	setbkmode(TRANSPARENT);				// ���ñ���ɫΪ͸��
	for (int n = 0; n < 12; n++)
	{
		// ��ʾ����
		TCHAR s[10];
		_stprintf(s, _T("%d"), 12 - n);       // �߰汾 VC �Ƽ�ʹ�� _stprintf_s ����
		// �������塢��С�����
		settextstyle(48, 0, _T("Consolas"));

		// �����ַ������Ϳ�����
		int w, h;
		w = textwidth(s);
		h = textheight(s);
		outtextxy(int(200 * cos(n * 2 * PI / 12 + PI / 2) - w / 2),
			-int(200 * sin(n * 2 * PI / 12 + PI / 2) + h / 2),
			s);
	}
}

//����
void Dial()
{
	//DrawPolygon(0, 0, 8, 100);
	DrawBK(0, 0, 300, 22.5);
}


//����ʱ��
void Clock(int h, int m, int s)
{
	// ����ʾ��ǰʱ�������С����
	setlinecolor(LIGHTGRAY);	// ���ñ߿���ɫΪǳ��ɫ
	setfillcolor(WHITE);		// ���������ɫΪ��ɫ
	fillrectangle(-40 - 13, 50, -40 + 13, 50 + 26);
	fillrectangle(-13, 50, 13, 50 + 26);
	fillrectangle(40 - 13, 50, 40 + 13, 50 + 26);

	// ��ʾ��ǰʱ��
	settextstyle(24, 0, _T("Consolas"));
	TCHAR a[10];

	int w;
	_stprintf(a, _T("%d"), h);	w = textwidth(a);	outtextxy(-40 - w / 2, 50, a);
	_stprintf(a, _T("%d"), m);	w = textwidth(a);	outtextxy(-w / 2, 50, a);
	_stprintf(a, _T("%d"), s);	w = textwidth(a);	outtextxy(40 - w / 2, 50, a);
}


//����
void Needle(int h, int m, int s)
{
	double a = PI / 2 - (2 * PI * h / 12 + 2 * PI * 1 / 12 * m / 60);	// ʱ�����߻���
	double b = PI / 2 - (2 * PI * m / 60 + 2 * PI * 1 / 60 * s / 60);	// �������߻���
	double c = PI / 2 - 2 * PI * s / 60;								// �������߻���

	setlinecolor(WHITE);
	setlinestyle(PS_SOLID, 9);											// �����߿�Ϊ������
	line(0, 0, int(50 * cos(a)), int(-50 * sin(a)));					// ��ʱ��

	setlinestyle(PS_SOLID, 6);											// �����߿�Ϊ������
	line(0, 0, int(90 * cos(b)), int(-90 * sin(b)));					// ������

	setlinestyle(PS_SOLID, 3);											// �����߿�Ϊ������
	line(int(20 * cos(c + PI)), -int(20 * sin(c + PI)), int(100 * cos(c)), -int(100 * sin(c)));	// ������
}




int main()
{

	// ������СΪ 1000 * 1000 �Ļ�ͼ����
	initgraph(1000, 1000);

	// ����ԭ�� (0, 0) ��Y��Ĭ������Ϊ����
	setorigin(500, 500);
	// ʹ�ð�ɫ��䱳��
	setbkcolor(WHITE);
	cleardevice();
	BeginBatchDraw();		// ����������ͼ
	while (true)
	{
		// ����
		SYSTEMTIME ti;		// ����������浱ǰʱ��
		GetLocalTime(&ti);	// ��ȡ��ǰʱ��

		// �滭
		cleardevice();
		Dial();										// ������
		Clock(ti.wHour, ti.wMinute, ti.wSecond);	// ������ʱ��
		Needle(ti.wHour, ti.wMinute, ti.wSecond);	// ������

		// ��ʱ
		FlushBatchDraw();
		Sleep(1000);
	}

	_getch();
	EndBatchDraw();
	closegraph();
	return 0;

}
