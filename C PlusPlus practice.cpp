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

void SetConsoleView(); // 콘솔창 크기 조정하기
void gotoXY(int x, int y); // X좌표와 Y좌표 조정하기
void DinoSour(int Dinoleg); // 공룡그림 그리기
char KeyInput(); // 문자를 받는 함수

int DinolegsSwing = true; // 공룡의 다리 초깃값을 true로 놓고 함수에 대입

void CursorView()
{
    CONSOLE_CURSOR_INFO cursorInfo = { 0, };
    cursorInfo.dwSize = 1; //커서 굵기 (1 ~ 100)
    cursorInfo.bVisible = FALSE; //커서 Visible TRUE(보임) FALSE(숨김)
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

int main(void)
{
    int count = 0;
    int TreeX2_Flag = 0; // 두번째 트리가 나오는 주기 설정
    int DinosourHigh = DinoY; // 공룡의 높이를 11로 지정
    int TreeX1 = TreeDistance; //첫번째 나무의 거리를 80으로 지정
    int TreeX2 = TreeDistance; // 두번째 나무의 거리를 80으로 지정
    int Jumping = false; // 처음 점프의 값을 false를 두고 시작
    int Bottom = true; // 공룡이 바닥에 있어야만 점프를 뛸 수 있음
    int JumpingLevel = false; // 점프의 최댓값에 다했다면 내려가기 위한 변수
    SetConsoleView();
    CursorView();

        while (true)
        {
            if (KeyInput() == 'j'&&Bottom) //만약 w를 입력하고 공룡이 바닥에 위치한다면 점프 가능
            {
                Bottom = false; //점프를 한다면 bottom이 거짓으로 변한다.
                Jumping = true;
                count++;
            }
            
            if (Jumping)
            {
                DinosourHigh--;
            }

            if (DinosourHigh == 2) //만약 공룡이 일정 높이가 된다면 내려가야함 (공룡 높이의 한계)
            {
                JumpingLevel = true;
            }
            
            if (JumpingLevel) 
            {
                DinosourHigh = DinoY; // 점프 높이를 DinoY(11)로 초기화
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
        gotoxy(30,-11); printf("                                             ■■■  \n");
        gotoxy(30,-12); printf("                                             ■  ■  \n");
        gotoxy(20,-13); printf("                                             ■■■  \n");
        gotoxy(20,-14); printf("                                             ■■■  \n");
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
