#include <graphics.h>
#include <time.h>
#include <conio.h>

#define SCREEN_WIDTH    1024
#define SCREEN_HEIGHT   768
#define MAXSTAR         400



class Star
{
public:
    Star() {}
    ~Star() {}

    void Init();
    void Move();

private:
    double  m_x = 0;
    int     m_y;
    double  m_step;
    int     m_color;

};


void Star::Init()
{
    if (m_x == 0)
    {
        m_x = rand() % SCREEN_WIDTH;
    }
    else
    {
        m_x = 0;
    }

    m_y = rand() % SCREEN_HEIGHT;
    m_step = (rand() % 5000) / 1000.0 + 1;
    m_color = (int)(m_step * 255 / 6.0 + 0.5);  // �ٶ�Խ�죬��ɫԽ��
    m_color = RGB(m_color, m_color, m_color);
}

void Star::Move()
{
    // ����ԭ��������
    putpixel((int)m_x, m_y, 0);

    // ������λ��
    m_x += m_step;
    if (m_x > SCREEN_WIDTH)
        this->Init();

    // ��������
    putpixel((int)m_x, m_y, m_color);
}


void main()
{
    srand((unsigned)time(NULL));

    initgraph(SCREEN_WIDTH, SCREEN_HEIGHT);

    Star star[MAXSTAR];
    for (int i = 0; i < MAXSTAR; i++)
    {
        star[i].Init();
    }

    while (!kbhit())
    {
        for (int i = 0; i < MAXSTAR; i++)
            star[i].Move();

        Sleep(30);
    }

    closegraph();
}