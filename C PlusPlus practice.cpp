#define TreeHigh 19
#define DinoY 11
#define TreeDistance 80
#define CRT_SECURE_NO_WARNINGS
#define CLS system("cls")

#include <Stdio.h>
#include <windows.h>
#include <stdbool.h>
#include <conio.h>
#include <time.h>

void SetConsoleView(); // �ܼ�â ũ�� �����ϱ�
void gotoXY(int x, int y); // X��ǥ�� Y��ǥ �����ϱ�
void DinoSour(int Dinoleg); // ����׸� �׸���
char KeyInput(); // ���ڸ� �޴� �Լ�

int DinolegsSwing = true; // ������ �ٸ� �ʱ갪�� true�� ���� �Լ��� ����

void CursorView()
{
    CONSOLE_CURSOR_INFO cursorInfo = { 0, };
    cursorInfo.dwSize = 1; //Ŀ�� ���� (1 ~ 100)
    cursorInfo.bVisible = FALSE; //Ŀ�� Visible TRUE(����) FALSE(����)
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

int main(void)
{
    int count = 0;
    int TreeX2_Flag = 0; // �ι�° Ʈ���� ������ �ֱ� ����
    int DinosourHigh = DinoY; // ������ ���̸� 11�� ����
    int TreeX1 = TreeDistance; //ù��° ������ �Ÿ��� 80���� ����
    int TreeX2 = TreeDistance; // �ι�° ������ �Ÿ��� 80���� ����
    int Jumping = false; // ó�� ������ ���� false�� �ΰ� ����
    int Bottom = true; // ������ �ٴڿ� �־�߸� ������ �� �� ����
    int JumpingLevel = false; // ������ �ִ񰪿� ���ߴٸ� �������� ���� ����
    SetConsoleView();
    CursorView();

        while (true)
        {
            if (KeyInput() == 'j'&&Bottom) //���� w�� �Է��ϰ� ������ �ٴڿ� ��ġ�Ѵٸ� ���� ����
            {
                Bottom = false; //������ �Ѵٸ� bottom�� �������� ���Ѵ�.
                Jumping = true;
                count++;
            }
            
            if (Jumping)
            {
                DinosourHigh--;
            }

            if (DinosourHigh == 2) //���� ������ ���� ���̰� �ȴٸ� ���������� (���� ������ �Ѱ�)
            {
                JumpingLevel = true;
            }
            
            if (JumpingLevel) 
            {
                DinosourHigh = DinoY; // ���� ���̸� DinoY(11)�� �ʱ�ȭ
            }

            if (DinosourHigh == 11)
            {
                JumpingLevel = false;
                Jumping = false;
                Bottom = true;
            }

            DinoSour(DinosourHigh);

            Sleep(100);
            CLS;


            printf("                                                     \n");
            printf("                                           SCORE : %d", count);
        }


}

void gotoxy(int x, int y)
{
    COORD pos = { x ,y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void DinoSour(int DinoX)
{
    
    gotoXY(0, DinoX);
    {
        gotoxy(30,-11); printf("                                             ����  \n");
        gotoxy(30,-12); printf("                                             ��  ��  \n");
        gotoxy(20,-13); printf("                                             ����  \n");
        gotoxy(20,-14); printf("                                             ����  \n");
    }

}


void SetConsoleView()
{
    system("mode con cols=100 lines=25");
    system("title Google DinoSour Game");
}

void gotoXY(int x, int y)
{
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}


char KeyInput()
{
    if (_kbhit()!=0)
    {
        return _getch();
    }
}
