#include <graphics.h>		// ����ͼ�ο�ͷ�ļ�
#include <conio.h>



//C���������ʮ���⣬��������
//5. ������
//����ģ�� 45 �ȷ�����С��



//ģ�� 45 �ȷ�����С��
void PinBall()
{
	float vy = 2;
	float vx = 2;
	float x = rand() % 300;
	float y = rand() % 300;
	setlinecolor(BLACK);
	setfillcolor(WHITE);
	fillrectangle(0, 300, 300, 0);
	while (!_kbhit())
	{
		y += vy;
		x += vx;
		if (y >= 280 || y <= 20)
			vy = -vy;
		if (x >= 280 || x <= 20)
			vx = -vx;
		//����
		setlinecolor(GREEN);
		circle(x, y, 20);
		FlushBatchDraw();
		Sleep(10);
		//����
		setlinecolor(WHITE);
		circle(x, y, 20);
	}

}

int main()
{

	// ������СΪ 1000 * 1000 �Ļ�ͼ����
	initgraph(1000, 1000);

	// ����ԭ�� (0, 0) ��Y��Ĭ������Ϊ����
	setbkcolor(WHITE);
	setorigin(300, 300);
	BeginBatchDraw();
	PinBall();

	EndBatchDraw();
	Sleep(2000);//��ʱ2s
	//_getch();				// �����������
	closegraph();			// �رջ�ͼ����
	return 0;
}
