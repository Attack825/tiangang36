#include <graphics.h>		// ����ͼ�ο�ͷ�ļ�
#include <conio.h>
#include <math.h>


//C���������ʮ���⣬��������
//�����
//���񣺻���׼���죨����ͼ��


//��������Ǻ�����ɫ
void fillstar(int x, int y, int R, int degree, COLORREF color = WHITE)
{
	double rad = 3.1415926 / 180;                    //ÿ�ȵĻ���ֵ
	double r = R * sin(18 * rad) / cos(36 * rad);    //����Ƕ���ĳ���
	POINT RVertex[5], rVertex[5];
	for (int k = 0; k < 5; k++)                      //��ȡ����
	{
		RVertex[k] = { int(x - (R * cos((90 + k * 72 + degree) * rad))), int(y - (R * sin((90 + k * 72 + degree) * rad))) };
		rVertex[k] = { int(x - (r * cos((90 + 36 + k * 72 + degree) * rad))), int(y - (r * sin((90 + 36 + k * 72 + degree) * rad))) };
	}
	setlinecolor(BLACK);                             //��ɫ
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
	double rad = 3.1415926 / 180;                    //ÿ�ȵĻ���ֵ
	setfillcolor(RGB(255, 0, 0));
	//y��Ĭ������Ϊ��
	fillrectangle(0, 200, 300, 0);
	fillstar(50, 50, 30, 0, YELLOW);
	fillstar(100, 20, 10, 270 - atan(3 / 5) / rad, YELLOW);
	fillstar(120, 40, 10, 270 - atan(1 / 7) / rad, YELLOW);
	fillstar(120, 70, 10, 270 + atan(2 / 7) / rad, YELLOW);
	fillstar(100, 90, 10, 270 + atan(4 / 5) / rad, YELLOW);

}

int main()
{

	// ������СΪ 800 * 600 �Ļ�ͼ����
	initgraph(1000, 1000);

	// ����ԭ�� (0, 0) ��Y��Ĭ������Ϊ����
	setorigin(300, 300);

	// ʹ�ð�ɫ��䱳��
	setbkcolor(WHITE);
	cleardevice();

	RedFlag();
	//fillstar(0,0,100,0,YELLOW);


	Sleep(2000);//��ʱ2s
	//_getch();				// �����������
	closegraph();			// �رջ�ͼ����
	return 0;


}


