#include <graphics.h>		// ����ͼ�ο�ͷ�ļ�
#include <conio.h>
#include <iostream> //����̨�������


//C���������ʮ���⣬��������
//����ǣ��������ɰ�ͼ��

void draw() {

	setlinecolor(BLACK);
	setfillcolor(WHITE);
	fillrectangle(0, 0, 400, 400);

	setlinecolor(BLACK);
	line(0, 0, 300, 300);
	line(300, 300, 100, 300);
	line(400, 0, 0, 400);
	line(300, 100, 400, 200);
	line(400, 200, 200, 400);

	setfillcolor(GREEN);
	floodfill(2, 1, BLACK);

	setfillcolor(BLUE);
	floodfill(100, 399, BLACK);

	setfillcolor(RGB(255, 165, 0));
	floodfill(1, 2, BLACK);

	setfillcolor(RGB(255, 255, 0));//��ɫ
	floodfill(201, 200, BLACK);

	setfillcolor(RGB(255, 0, 0));//��ɫ
	floodfill(399, 399, BLACK);

	setfillcolor(RGB(128, 0, 128));//��ɫ
	floodfill(200, 201, BLACK);

	setfillcolor(RGB(165, 42, 42));//��ɫ
	floodfill(399, 101, BLACK);


}


void demo()
{
	setlinecolor(BLACK);
	line(15, 15, 50, 50);   // ����ֱ��
	line(50, 50, 15, 100);
	line(15, 100, 15, 15);

	setfillcolor(BLUE);      // ���������ɫ
	setlinecolor(BLACK);     //����������ɫ
	fillcircle(100, 100, 6);//���Բ��ͼ��

	setfillcolor(YELLOW);				// ��������ɫ);
	floodfill(30, 50, BLACK, 0); // �����ɫ
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

	draw();



	Sleep(2000);//��ʱ2s
	//_getch();				// �����������
	closegraph();			// �رջ�ͼ����
	return 0;


}
