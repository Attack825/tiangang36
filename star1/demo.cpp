#include <graphics.h>		// ����ͼ�ο�ͷ�ļ�
#include <conio.h>
#include <iostream> //����̨�������


//C���������ʮ���⣬��������
//����ǣ��������ɰ�ͼ��

void draw() {



}



int main()
{

	// ������СΪ 800 * 600 �Ļ�ͼ����
	initgraph(800, 600);

	// ����ԭ�� (0, 0) Ϊ��Ļ���루Y��Ĭ������Ϊ����
	setorigin(400, 300);

	// ʹ�ð�ɫ��䱳��
	setbkcolor(WHITE);
	cleardevice();


	setlinecolor(BLACK);
	line(15, 15, 50, 50);   // ����ֱ��
	line(50, 50, 15, 100);
	line(15, 100, 15, 15);

	setfillcolor(BLUE);      // ���������ɫ
	setlinecolor(BLACK);     //����������ɫ
	fillcircle(100, 100, 6);//���Բ��ͼ��

	setfillcolor(YELLOW);				// ���������ɫCK);
	floodfill(30, 50, BLACK, 0); // �����ɫ


	Sleep(2000);//��ʱ2s
	//_getch();				// �����������
	closegraph();			// �رջ�ͼ����
	return 0;


}
