#include <stdio.h>	// gotoxy(0, 28);
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <conio.h>
#include<string.h>
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")
#include <math.h>

float Money = 3000.00;									// 화폐 (만)
int HP = 100;										// 체력 게이지
int Gold_Have = 0;									// 금괴 보유
int Saving[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };	// 저금
int House_Have = 0;									// 집 보유
int k = 1;
int m = 1;
int Day = 1;										// 날짜 카운팅
float l = 0;
// 아이템
int Drink = 0;			// 최대 체력 증가
int Whistle = 0;		// 호루라기
int Day_f = 1;

// 화면 그리기
void Edge();
void Title();
void Status();
void Map_1();
void Big_Clear();
void Long_Clear();
void Small_Clear();
void Loading_Clear();
void Full_Clear();

void Set_Color(int Text);


// 초기 메뉴
void First_Menu();
void First_inf();

// 공통
int YN();
void ing(float n);
void gotoxy(int x, int y);
int Ten_Square(int num);
int Ten_Divide(int num);


// 게임
	// 포커
void Poker_Room();
void Poker_Room_inf();
void Show(int x, int y, int N, int T, int i);
void Poker_Five_Draw_1();
void Poker_Five_Draw_1_inf();
void ShowCard(int N[], int T[], int C[]);

// 로또
void Lottery();
void Lottery_inf();

// 금 거래소
void Gold_Store(float Price, int* Have);
void Gold_inf();
void Gold_Change(float* Price, int* Big);

// 경마장
void Race();
void Race_inf();
int Race_Start(int Select);

// 시설
	// 호텔
void Hotel();

// 부동산
void Real_Estate();
void Real_Estate_inf();

// 집
void House();

void cur();
//////////////////////////////////////////////////////////////////////////////// 코드 시작

// 그리기
void Edge()
{
	int i;

	for (i = 0; i <= 42; i++)			// 메인 가로
	{
		gotoxy(i * 2, 0);
		printf("%c%c", 0xa2, 0xcc);

		gotoxy(i * 2, 20);
		printf("%c%c", 0xa2, 0xcc);

		gotoxy(i * 2, 26);
		printf("%c%c", 0xa2, 0xcc);

		gotoxy(i * 2, 28);
		printf("%c%c", 0xa2, 0xcc);
	}

	for (i = 0; i <= 28; i++)				// 메인 세로
	{
		gotoxy(0, i);
		printf("%c%c", 0xa2, 0xcc);

		gotoxy(84, i);
		printf("%c%c", 0xa2, 0xcc);
	}

	for (i = 0; i < 10; i++)			// 선택 가로
	{
		gotoxy(88 + i * 2, 20);
		printf("%c%c", 0xa2, 0xcc);

		gotoxy(88 + i * 2, 26);
		printf("%c%c", 0xa2, 0xcc);
	}

	for (i = 0; i < 6; i++)				// 선택 세로
	{
		gotoxy(88, 20 + i);
		printf("%c%c", 0xa2, 0xcc);

		gotoxy(106, 20 + i);
		printf("%c%c", 0xa2, 0xcc);
	}
}

void Title()
{
	int i, j;

	i = 0xa1;
	j = 0xe1;

	// Gamble		
	// 1	
	Set_Color(1);
	gotoxy(2, 2);
	printf("      %c%c%c%c%c%c       %c%c      ", i, j, i, j, i, j, i, j);
	printf("%c%c%c%c        %c%c%c%c ", i, j, i, j, i, j, i, j);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c %c%c", i, j, i, j, i, j, i, j, i, j, i, j, i, j);
	printf("         %c%c%c%c%c%c%c%c%c%c%c%c\n", i, j, i, j, i, j, i, j, i, j, i, j);

	Sleep(70);

	Set_Color(1);
	gotoxy(2, 3);
	printf("     %c%c     %c%c    %c%c %c%c    ", i, j, i, j, i, j, i, j);
	printf("%c%c %c%c      %c%c %c%c ", i, j, i, j, i, j, i, j);
	printf("%c%c        %c%c %c%c", i, j, i, j, i, j);
	printf("         %c%c       \n", i, j);

	Sleep(70);

	Set_Color(2);
	gotoxy(2, 4);
	printf("    %c%c            %c%c %c%c    ", i, j, i, j, i, j);
	printf("%c%c %c%c     %c%c  %c%c ", i, j, i, j, i, j, i, j);
	printf("%c%c     %c%c%c%c  %c%c", i, j, i, j, i, j, i, j);
	printf("         %c%c       \n", i, j);

	Sleep(70);

	Set_Color(2);
	gotoxy(2, 5);
	printf("   %c%c            %c%c    %c%c  ", i, j, i, j, i, j);
	printf("%c%c  %c%c    %c%c  %c%c ", i, j, i, j, i, j, i, j);
	printf("%c%c   %c%c%c%c    %c%c", i, j, i, j, i, j, i, j);
	printf("         %c%c       \n", i, j);

	// 5	
	Sleep(70);

	Set_Color(3);
	gotoxy(2, 6);
	printf("  %c%c     %c%c%c%c%c%c  %c%c%c%c%c%c%c%c  ", i, j, i, j, i, j, i, j, i, j, i, j, i, j, i, j);
	printf("%c%c  %c%c   %c%c   %c%c ", i, j, i, j, i, j, i, j);
	printf("%c%c %c%c%c%c      %c%c", i, j, i, j, i, j, i, j);
	printf("         %c%c%c%c%c%c%c%c%c%c%c%c\n", i, j, i, j, i, j, i, j, i, j, i, j);

	Sleep(70);

	Set_Color(3);
	gotoxy(2, 7);
	printf("   %c%c       %c%c  %c%c     %c%c  ", i, j, i, j, i, j, i, j);
	printf("%c%c   %c%c  %c%c   %c%c ", i, j, i, j, i, j, i, j);
	printf("%c%c   %c%c%c%c    %c%c", i, j, i, j, i, j, i, j);
	printf("         %c%c       \n", i, j);

	Sleep(70);

	Set_Color(4);
	gotoxy(2, 8);
	printf("    %c%c     %c%c  %c%c      %c%c  ", i, j, i, j, i, j, i, j);
	printf("%c%c   %c%c %c%c    %c%c ", i, j, i, j, i, j, i, j);
	printf("%c%c     %c%c%c%c  %c%c", i, j, i, j, i, j, i, j);
	printf("         %c%c       \n", i, j);

	Sleep(70);

	Set_Color(4);
	gotoxy(2, 9);
	printf("     %c%c   %c%c   %c%c       %c%c ", i, j, i, j, i, j, i, j);
	printf("%c%c    %c%c%c%c    %c%c ", i, j, i, j, i, j, i, j);
	printf("%c%c        %c%c %c%c", i, j, i, j, i, j);
	printf("         %c%c       \n", i, j);

	// 9	
	Sleep(70);

	Set_Color(5);
	gotoxy(2, 10);
	printf("      %c%c%c%c%c%c  %c%c        %c%c ", i, j, i, j, i, j, i, j, i, j);
	printf("%c%c     %c%c     %c%c ", i, j, i, j, i, j);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c ", i, j, i, j, i, j, i, j, i, j, i, j);
	printf("%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c\n", i, j, i, j, i, j, i, j, i, j, i, j, i, j, i, j, i, j, i, j, i, j);

	// Town
	// 11	
	Sleep(70);

	Set_Color(5);
	gotoxy(2, 12);
	printf("   %c%c%c%c%c%c%c%c%c%c%c%c      %c%c %c%c          ", i, j, i, j, i, j, i, j, i, j, i, j, i, j, i, j);
	printf("           %c%c      %c%c      %c%c", i, j, i, j, i, j);
	printf("%c%c %c%c%c%c    %c%c\n",i, j, i, j, i, j, i, j);

	Sleep(70);

	Set_Color(6);
	gotoxy(2, 13);
	printf("        %c%c         %c%c     %c%c        ", i, j, i, j, i, j);
	printf("            %c%c    %c%c%c%c    %c%c ", i, j, i, j, i, j, i, j);
	printf("%c%c %c%c %c%c   %c%c\n",i, j, i, j, i, j, i, j);

	Sleep(70);

	Set_Color(6);
	gotoxy(2, 14);
	printf("        %c%c        %c%c       %c%c       ", i, j, i, j, i, j);
	printf("            %c%c    %c%c%c%c    %c%c ", i, j, i, j, i, j, i, j);
	printf("%c%c %c%c %c%c   %c%c\n",i, j, i, j, i, j, i, j);

	// 14	
	Sleep(70);

	Set_Color(7);
	gotoxy(2, 15);
	printf("        %c%c       %c%c         %c%c       ", i, j, i, j, i, j);
	printf("            %c%c  %c%c  %c%c  %c%c  ", i, j, i, j, i, j, i, j);
	printf("%c%c %c%c  %c%c  %c%c\n",i, j, i, j, i, j, i, j);

	Sleep(70);

	Set_Color(7);
	gotoxy(2, 16);
	printf("        %c%c        %c%c       %c%c       ", i, j, i, j, i, j);
	printf("             %c%c  %c%c  %c%c  %c%c  ", i, j, i, j, i, j, i, j);
	printf("%c%c %c%c   %c%c %c%c\n",i,j, i, j, i, j, i, j);

	Sleep(70);

	Set_Color(8);
	gotoxy(2, 17);
	printf("        %c%c         %c%c     %c%c        ", i, j, i, j, i, j);
	printf("              %c%c%c%c    %c%c%c%c   ", i, j, i, j, i, j, i, j);
	printf("%c%c %c%c   %c%c %c%c\n",i,j, i, j, i, j, i, j);

	// 17	
	Sleep(70);

	Set_Color(8);
	gotoxy(2, 18);
	printf("        %c%c           %c%c %c%c          ", i, j, i, j, i, j);
	printf("               %c%c      %c%c    ", i, j, i, j);
	printf("%c%c %c%c    %c%c%c%c\n", i, j, i, j, i, j, i, j);


	Set_Color(15);
	Sleep(300);
	gotoxy(30, 23);
	printf("방향키와 <spacebar> or <enter>로 조작 !");
}

void Status()
{
	gotoxy(88, 1); printf("%d일 째\n", Day);

	gotoxy(88, 3); printf("                         ");
	gotoxy(88, 3); printf("현재 보유 %.2lf 만 원", Money);

	gotoxy(88, 4); printf("HP : %d     ", HP);

	gotoxy(88, 5); printf("금괴 %d개 보유중", Gold_Have);
}

void Map_1_Draw()
{
	int i = 0xa1;
	int j = 0xac;
	//윗 줄	
	gotoxy(2, 2);
	i = 0xa1, j = 0xac;
	printf("    ________            ________                ________           ________ ");
	gotoxy(2, 3);
	printf("   /        %c%c         /        %c%c             /        %c%c        /        %c%c    ", i, j, i, j, i, j, i, j);
	gotoxy(2, 4);
	printf("  /           %c%c      /           %c%c          /           %c%c     /           %c%c  ", i, j, i, j, i, j, i, j);
	gotoxy(2, 5);
	printf(" /              %c%c   /              %c%c       /              %c%c  /              %c%c", i, j, i, j, i, j, i, j);
	gotoxy(2, 6);
	printf(" |    카드게임   |   |     복권방    |       |   골드 상점   |  |     말게임    |");
	gotoxy(2, 7);
	printf(" |               |   |               |       |               |  |               |");
	gotoxy(2, 8);
	i = 0xa2, j = 0xc6;
	printf(" |______%c%c________|   |______%c%c________|       |______%c%c________|  |_______%c%c_______|", i, j, i, j, i, j, i, j);
	gotoxy(2, 9);
	i = 0xa1, j = 0xd9;
	printf("        %c%c                  %c%c                      %c%c                  %c%c", i, j, i, j, i, j, i, j);

	//아랫 줄
	gotoxy(2, 12);
	printf("  ______%c%c_______     ______%c%c_______         ______%c%c_______    _______%c%c______", i, j, i, j, i, j, i, j);
	gotoxy(2, 13);
	i = 0xa2, j = 0xc6;
	printf(" |      %c%c        |   |      %c%c        |       |      %c%c        |  |       %c%c       |", i, j, i, j, i, j, i, j);
	gotoxy(2, 14);
	printf(" |               |   |               |       |               |  |               |");
	gotoxy(2, 15);
	printf(" |      호텔     |   |       집      |       |     부동산    |  |   가벼워지기  |");
	gotoxy(2, 16);
	i = 0xa1, j = 0xac;
	printf(" %c%c              /   %c%c              /       %c%c              /  %c%c              /", i, j, i, j, i, j, i, j);
	gotoxy(2, 17);
	printf("   %c%c           /      %c%c           /          %c%c           /     %c%c           /", i, j, i, j, i, j, i, j);
	gotoxy(2, 18);
	printf("     %c%c________/         %c%c________/             %c%c________/        %c%c________/", i, j, i, j, i, j, i, j);
}

void Big_Clear()
{
	gotoxy(2, 1); printf("                                                                                  ");
	gotoxy(2, 2); printf("                                                                                  ");
	gotoxy(2, 3); printf("                                                                                  ");
	gotoxy(2, 4); printf("                                                                                  ");
	gotoxy(2, 5); printf("                                                                                  ");
	gotoxy(2, 6); printf("                                                                                  ");
	gotoxy(2, 7); printf("                                                                                  ");
	gotoxy(2, 8); printf("                                                                                  ");
	gotoxy(2, 9); printf("                                                                                  ");
	gotoxy(2, 10); printf("                                                                                  ");
	gotoxy(2, 11); printf("                                                                                  ");
	gotoxy(2, 12); printf("                                                                                  ");
	gotoxy(2, 13); printf("                                                                                  ");
	gotoxy(2, 14); printf("                                                                                  ");
	gotoxy(2, 15); printf("                                                                                  ");
	gotoxy(2, 16); printf("                                                                                  ");
	gotoxy(2, 17); printf("                                                                                  ");
	gotoxy(2, 18); printf("                                                                                  ");
	gotoxy(2, 19); printf("                                                                                  ");
}

void Long_Clear()
{
	gotoxy(2, 21); printf("                                                                                  ");
	gotoxy(2, 22); printf("                                                                                  ");
	gotoxy(2, 23); printf("                                                                                  ");
	gotoxy(2, 24); printf("                                                                                  ");
	gotoxy(2, 25); printf("                                                                                  ");
}

void Small_Clear()
{
	gotoxy(90, 21); printf("                ");
	gotoxy(90, 22); printf("                ");
	gotoxy(90, 23); printf("                ");
	gotoxy(90, 24); printf("                ");
	gotoxy(90, 25); printf("                ");
}

void Loading_Clear()
{
	gotoxy(2, 27); printf("                                                                                  ");
}

void Full_Clear()
{
	Big_Clear();
	Long_Clear();
	Small_Clear();
	Loading_Clear();
	Status();
}

void Set_Color(int Text)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Text | 0);
}



// 메인
int main()							// 메인 함수
{
	SetConsoleTitle(TEXT("GAMBLE TO WIN!!!"));
	int M_S;
	int Map = 1;
	int Map_1[21][43] = {
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}, // 벽
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,1,1,1,1,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,1,1,1,1,1,0,0,0,1},
	{1,0,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,0,0,1},
	{1,0,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,0,1},
	{1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,2,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,2,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, // 홀
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, // 홀
	{1,0,1,1,1,2,1,1,1,1,0,0,1,1,1,2,1,1,1,1,0,0,0,0,1,1,1,2,1,1,1,1,0,0,1,1,1,2,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1},
	{1,0,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,0,1},
	{1,0,0,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}  // 벽
	};

	int i, j;

	float Gold_Price = 1000;
	int Gold_B = 0;
	int x = 42;
	int y = 11;

	int Move;
	int Select;

	srand(time(NULL));
	cur();
	Set_Color(15);				// 글씨 색 흰색
	PlaySound(TEXT("마피아 브금.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	system("mode con cols=115 lines=29");	// 화면 크기 조절
	system("cls");
	Edge();

	First_Menu();					// 메인 메뉴에서 게임 설명 선택 가능

	while (1)
	{
		Day_f = 1;

		Full_Clear();

		if (0 < Gold_B && Gold_B < 3)				// 금괴 대폭락
		{
			gotoxy(3, 24);
			printf("금괴의 값이 폭락하는 중입니다!!\n\n");
		}
		if (Gold_B == 10)
		{
			gotoxy(3, 24);
			printf("금괴의 값이 갑자기 뛰었습니다!!!\n\n");
			Gold_B = 0;
		}

		if (Map == 1)				// 맵 1일 때 화면 그리기
		{
			i = 0xa1, j = 0xd9;
			gotoxy(40, 0);			// 별
			printf("%c%c%c%c%c%c", i, j, i, j, i, j);
			gotoxy(40, 20);
			Map_1_Draw();
		}

		M_S = 0;					// 메뉴 초기화

		gotoxy(x, y);
		printf("%c%c", 0xa1, 0xdc);

		while (M_S == 0)				// 메뉴 인식
		{
			Status();

			gotoxy(0, 28);
			Move = getch();

			if (Move == 27)				// ESC 입력시 종료
				exit(0);

			if (Move == 224)				// 방향키 인식
			{
				Move = getch();
				gotoxy(x, y);			// 지우기
				printf("  ");

				switch (Move)
				{
				case 72:			// 위
					if (Map == 1)
					{
						if (Map_1[y - 1][x / 2] != 1)
							y -= 1;
					}
					break;

				case 75:			// 왼쪽
					if (Map == 1)
					{
						if (Map_1[y][(x / 2) - 1] != 1)
							x -= 2;
					}
					break;

				case 77:			// 오른쪽
					if (Map == 1)
					{
						if (Map_1[y][(x / 2) + 1] != 1)
							x += 2;
					}
					break;

				case 80:			// 아래
					if (Map == 1)
					{
						if (Map_1[y + 1][x / 2] != 1)
							y += 1;
					}
					break;

				default:
					break;
				}
			}
			gotoxy(x, y);
			printf("%c%c", 0xa1, 0xdc);
			if (20 <= x / 2 && x / 2 <= 22 && y == 0)				// 위 쪽 통로
			{
				if (Map == 1)
				{
					gotoxy(3, 22);
					printf("게임을 포기해 종료하시겠습니까?");

					i = YN();

					if (i == 1) {
						system("cls");
						PlaySound(TEXT("루우우.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
						printf("BQBBBQBBBBBBBBQBQBQBQBQBQBBBBBQBQBQBQBQBQBQBQBQBQBQBQBQBBBQBQBBBQBQBQBQBQBQBBBQBQBQBQBQBQBQBQBQBQBQBQBQBQBQBBBQBQ\n");
						printf("BQBBBQBBBBBBBBBQBQBQBBBBBBBQBBBQBBBQBQBQBQBBBQBBBQBQBQBQBQBQBQBQBQBBBQBBBQBQBBBQBQBQBQBBBQBQBBBQBQBQBQBQBQBQBBBBB\n");
						printf("BQBBBQBBBBBBBBQBQBBBQBQBQBBBQBQBBBQBBBQBBBQBQBQBQBQBBBQBQBQBQBBBQBQBBBQBBBQBQBBBBBQBQBBBBBQBBBQBBBQBBBQBBBQBBBQBQ\n");
						printf("BQBBBQBBBBBBBBBQBQBQBBBQBBBBBQBBBBBQBBBBBQBBBQBQBQBQBQBQBQBBBQBQBBBBBQBBBQBBBQBBBQBQBQBQBBBQBBBBBQBBBQBQBBBQBQBQB\n");
						printf("BQBBBQBBBBBBBBBBQBBBQBQBQBQBBBQBQBQBQBQBQBQBQBBBBBQBQBBBQBQBQBBBQBBBBBQBQBBBBBQBQBQBQBBBQBBBQBQBBBBBQBQBQBQBQBQBQ\n");
						printf("BQBBBQBBBBBBBBBQBQBBBQBBBBBBBBBQBQBQBQBQBQBQBQBQBBBQBBBQBQBQBBBQBQBQBQBQBBBBBBBBBBBQBBBQBBBBBQBQBBBQBBBQBQBQBQBQB\n");
						printf("BQBBBQBBBBBBBBBBQBQBQBBBBBQBQBQBQBBBBBBBQBQBBBBBQBBBQBBBQBQBBBQBQBBBQBQBBBQBQBQBQBQBBBQBQBQBBBQBQBBBQBBBQBQBQBQBQ\n");
						printf("BQBBBQBBBBBBBBBQBQBQBBBBBQBQBBBQBQBBBQBQBQBBBQBQBQBQBBBQBQBBBBBBBBBBBBBBBBBQBQBQBQBQBBBBBQBQBQBBBBBQBQBBBQBQBQBBB\n");
						printf("BQBBBQBBBBBBBBBBQBQBQBBBQBBBQBQBQBBBBBBBQBQBQBBBQBQBQBBBQBBBBBQBQBQBBBBBBBQBQBBBBBBBBBQBQBQBQBBBQBQBQBQBBBBBBBQBQ\n");
						printf("BQBBBQBBBBBBBBBBBBBBBBBQBQBQBBBQBQBQBQBBBQBQBQBQBQBBBQBBBBBBBBBBBBBBBBBQBBBQBQBBBQBBBQBBBBBQBBBBBBBQBBBBBBBQBQBQB\n");
						printf("BQBBBQBBBBBBBBBBQBBBQBQBQBQBBBBBBBQBBBQBBBBBQBBBQBQBBBBBBBBBBBQBQBBBBBBBBBQBBBBBQBQBBBBBBBBBBBBBQBBBBBQBBBQBBBQBQ\n");
						printf("BQBBBQBBBBBBBBBQBQBBBQBQBBBBBBBBBQBBBBBBBQBBBBBQBBBBBQBBBBBQBBBQBBBBBBBBBBBBBBBQBBBBBBBBBBBBBQBBBBQBBQBQBQBQBQBQB\n");
						printf("QBBBQBBBBBBBBQBQBBBQBBBBBBB6;:r6BBBBBsUBBQBS2BBBBKsBR77;i:OBQQBBBOr:iDBB1JBBBB7EBJ7ri:wBOcr;rwBBBQBQBQBQBQBQBBBQB\n");
						printf("BQBBBQBBBBBBBBBBBBBQBQBQBBB: :L  QBBBa  ZQBB. 5BBB  B7 7ci:ZBQBBBL ,L. sBr RBBr BQ ,Li:wBr r7i  BBQQBQBBBQBQBQBQB\n");
						printf("BQBBBQBBBBBBBBBBQBQBQBQBQBO vBBBBBBBQ ;: BBB,  BB   BJ BQBBBBBQBB :BBB: BB .BB :BB pBBBBBL BQB; MBMBBBQBBBQBBBQBQ\n");
						printf("BQBBBQBBBBBBBBBQBQBBBBBBBBX QBP;75BB7 RK JBB,...r ; B1 ...BBBBBBR 5BBBw BBS B7 BBQ  . OBBL ..  BBBBQBQBQBBBQBQBQB\n");
						printf("BQBBBQBBBBBBBBBBQBBBQBQBBBg 7BB: :BB  :;  BB :B  BX QJ BBBBBBBBBB :BBB. BBB   LBQR QBBBBQL BBi BQBBBQBQBQBQBQBQBB\n");
						printf("BQBBBQBBBBBBBBBBBBBBBQBQBBB; :L  BB  QBQB .B  B7.Br B7 :i:.7BQBBBJ .r. UBBBP  BBBD  r:,;Br BBB  BQQBBBBQBQBQBQBBB\n");
						printf("BQBBBQBBBBBBBBQBQBBBQBQBQQBBD7:LBBBLGBBBBDsBaXBBBBEJBRsc77;1BBBBBBgr;rMBQBBB2gBBBBJs7riLBDsBQBDcRBMBQBBBQBBBQBQBB\n");
						printf("BQBBBQBBBBBBBBBQBBBQBQBQBBBQBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBQBBBBBQBQBBBBBBBBBBBQBQBQBQBBBBBQB\n");
						printf("BQBBBQBBBBBBBBQBQBBBQBQBQBBBBBBBBBBBBBQBBBBBBBBBBBBBBBQBBBBBQBQBBBBBBBBBQBQBBBBBBBBBBBBBBBBBBBBBBBBBBBQBQBBBBBQBB\n");
						printf("BQBBBQBBBBBBBBBQBQBQBBBQBBBQBQBQBQBQBBBQBQBBBBBBBQBQBQBBBQBQBBBBBQBQBBBQBQBBBBBQBQBBBBBBBBBQBQBBBQBQBQBBBQBQBQBBB\n");
						printf("BQBBBQBBBBBBBBQBQBBBQBQBQBQBQBQBQBQBQBQBQBBBBBBBBBQBQBQBQBBBQBBBQBQBQBQBBBQBQBQBQBQBBBQBQBQBBBBBQBQBQBQBBBBBQBQBB\n");
						printf("BQBBBQBBBBBBBBBBBBBBBQBQBBBBBQBQBBBBBQBQBBBQBQBQBQBBBQBBBBBQBQBQBQBQBQBBBQBQBQBQBBBQBQBQBQBBBQBQBQBBBQBBBBBQBQBQB\n");
						printf("BQBBBQBBBBBBBBQBBBQBQBBBQBQBQBQBBBBBQBBBQBQBQBBBQBBBQBQBQBBBBBBBBBBBQBQBBBQBQBQBQBQBBBQBBBQBQBBBQBBBQBBBBBQBQBQBB\n");
						printf("BQBBBQBBBBBBBBBQBBBQBBBBBQBQBQBQBQBQBQBQBQBQBQBBBBBQBQBQBQBBBQBBBQBQBQBQBQBQBQBQBQBBBBBQBBBQBQBBBQBQBQBQBBBQBQBQB\n");
						printf("BQBBBQBBBBBBBBBBBBQBQBQBQBQBQBBBBBBBQBQBQBBBQBBBQBQBQBBBQBQBBBQBQBQBBBBBBBQBBBBBQBBBQBQBQBQBBBBBBBBBBBQBQBQBBBBBQ\n");
						printf("BQBBBQBBBBBBBBBBBQBQBQBBBBBQBQBQBQBQBBBQBBBQBQBQBBBQBQBQBBBQBQBQBQBQBBBBBQBQBQBQBQBQBQBBBBBQBQBQBBBBBQBQBBBQBQBQB\n");
						printf("BQBBBQBBBBBBBBQBBBBBQBQBQBBBBBQBQBQBQBQBBBQBQBQBQBQBQBQBBBBBBBQBQBBBBBQBBBQBQBQBBBQBQBBBQBQBQBQBQBBBQBBBBBQBQBQBQ\n");
						printf("BQBBBQBBBBBBBBBQBQBQBQBQBQBBBQBQBQBQBQBBBBBQBQBBBQBQBBBBBQBQBQBQBQBQBQBQBQBBBBBQBQBQBBBQBQBQBBBQBQBQBQBQBQBQBBBQB\n");
						printf("BQBBBQBBBBBBBBQBQBBBQBQBQBQBBBQBQBQBBBBBQBQBQBQBQBQBQBQBBBQBQBQBBBQBQBQBBBQBBBQBQBBBQBBBBBQBQBBBBBQBBBQBQBQBBBQBB\n");
						Sleep(5000);
						exit(0);
					}
					if (i == 2)
					{
						Long_Clear();
						y += 2;

						i = 0xa1, j = 0xd9;

						gotoxy(40, 0);			// 별
						printf("%c%c%c%c%c%c", i, j, i, j, i, j);

						gotoxy(x, y);
						printf("%c%c", 0xa1, 0xdc);
					}
				}


			}

			if (x / 2 == 5 && y == 9)
				M_S = 1;

			else if (x / 2 == 15 && y == 9)
				M_S = 2;

			else if (x / 2 == 27 && y == 9)
				M_S = 3;

			else if (x / 2 == 37 && y == 9)
				M_S = 4;

			else if (x / 2 == 5 && y == 12)
				M_S = 5;

			else if (x / 2 == 15 && y == 12)
				M_S = 6;

			else if (x / 2 == 27 && y == 12)
				M_S = 7;

			else if (x / 2 == 37 && y == 12)
				M_S = 8;

			else if (x / 2 == 1 && y == 18)
				M_S = 66;

			else if (x / 2 == 1 && y == 19)
				M_S = 77;
			else {
				if (Money > 10000) {
					system("cls");
					PlaySound(TEXT("예에에.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
					printf(", ............... . ... . . .....     ,         ... ... ..,   . ... ...       .,.     ........... .\n");
					printf(". .. .,. ... ..... ..              ....        .,... ... .   ...              .,.. .   .......   .. \n");
					printf(", ... ..  ........                  ...         .  ....       .                   ...     .. .,.  . \n");
					printf(". .,.. ..,........  :BBBBBQBBBBBBBR  .. 7BBBg      . .  KBB1      2BMBBBBBBBgK7.   . . ....  ... .. \n");
					printf(", ,,,   .,,.... ..  LBBBQQBQBBBBBBD     OBBQBB    ....  QBB5      BBBBMQBBBQBQBB6:    ... ......... \n");
					printf(". ,,..   .........  7BBB             .  SBQ6HBQ.   ...  GBB2  ..  OBBa       :5BBBE,  ............. \n");
					printf(". . ..,.... .,....  7QBB      .         HBB7 BBB:   .   OBBs  ..  gBBK         .DBBQr  ............ \n");
					printf("   ....,...,,,.. .  rBBB     .,.   . .  XBQ2 pQBB,   .  EBB1  ..  GBBZ           MBBB. ..,......... \n");
					printf(". ,.. . ..,...,..   cQBB           ...  HBBa  gBBQ.     OBBJ      gQB6    .   ,. ;BQB7 ............ \n");
					printf(". ....   .,,.. .... 7BRB12SHXPS6E: ...  HBBP   MBBQ.    GBQJ   .  DBBp   .   ,,, .BBQZ   .......... \n");
					printf(". ......  .,,.  ... 7BQQMRBBBBBBB; ...  HBBP    pBBB;   GQBJ  ..  DBBK    ..:,,.  BMBO  . ......... \n");
					printf(", .............,..  rBQB          ....  aBBG     JBBB,  EBB2  ,.  EBBE   ,,,...  .BQBK  .... .....,.\n");
					printf(", ,.......  .....   7QBB.   ..  .....   HBBp   .  aBBL  EBBJ  ,.  DQBp  ,,. . .  iBMBr .,...... ....\n");
					printf(". ........ .  ....  rBQB   ..:.  ...    aBBZ  .,.  PBBr aBBJ  ..  OBBG  .. ..    QBBQ  ............ \n");
					printf(", ............,...  7BBB     ..     .   XBBK ....   6BB:1BBJ  ..  DBBH          RBBB:  .,.......... \n");
					printf(". ...... ..,.,....  7BQB            ..  SBBp ......  MBBGMB2  ..  gBBX      .;1BBBS,   ..,.,,..,.,..\n");
					printf(", ..... ....... .   JBBBBBBBBBBBBBB. .. EBBR  .,,... :BBBBBX  ..  BBBQBQBBBBBBBQK.    . . ..,...... \n");
					printf(". .......,.. ..  .  :BRMQBBBBBBBBBB. .  wBQU   ...... .ERQBr  ..  JBgMQBBBBRpJ;    ................ \n");
					printf(", .......,. ... . ..                 ..         . . .       .   .                 . ... ..,........ \n");
					printf(",........... .   ...     .   .     ...  %d일만에 통과 성공!!,. .         ..,.. . ....... ,,..... .. \n", Day_f);
					printf(",.:. .. .       ...      .,.. . .......     . . ......     .. ...         ..,.,   ... .  ..   ..,.. \n");
					getch();
					return 0;
				}
				else if (HP == 0 && Money == 0) {
					system("cls");
					PlaySound(TEXT("루우우.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
					printf("BQBBBQBBBBBBBBQBQBQBQBQBQBBBBBQBQBQBQBQBQBQBQBQBQBQBQBQBBBQBQBBBQBQBQBQBQBQBBBQBQBQBQBQBQBQBQBQBQBQBQBQBQBQBBBQBQ\n");
					printf("BQBBBQBBBBBBBBBQBQBQBBBBBBBQBBBQBBBQBQBQBQBBBQBBBQBQBQBQBQBQBQBQBQBBBQBBBQBQBBBQBQBQBQBBBQBQBBBQBQBQBQBQBQBQBBBBB\n");
					printf("BQBBBQBBBBBBBBQBQBBBQBQBQBBBQBQBBBQBBBQBBBQBQBQBQBQBBBQBQBQBQBBBQBQBBBQBBBQBQBBBBBQBQBBBBBQBBBQBBBQBBBQBBBQBBBQBQ\n");
					printf("BQBBBQBBBBBBBBBQBQBQBBBQBBBBBQBBBBBQBBBBBQBBBQBQBQBQBQBQBQBBBQBQBBBBBQBBBQBBBQBBBQBQBQBQBBBQBBBBBQBBBQBQBBBQBQBQB\n");
					printf("BQBBBQBBBBBBBBBBQBBBQBQBQBQBBBQBQBQBQBQBQBQBQBBBBBQBQBBBQBQBQBBBQBBBBBQBQBBBBBQBQBQBQBBBQBBBQBQBBBBBQBQBQBQBQBQBQ\n");
					printf("BQBBBQBBBBBBBBBQBQBBBQBBBBBBBBBQBQBQBQBQBQBQBQBQBBBQBBBQBQBQBBBQBQBQBQBQBBBBBBBBBBBQBBBQBBBBBQBQBBBQBBBQBQBQBQBQB\n");
					printf("BQBBBQBBBBBBBBBBQBQBQBBBBBQBQBQBQBBBBBBBQBQBBBBBQBBBQBBBQBQBBBQBQBBBQBQBBBQBQBQBQBQBBBQBQBQBBBQBQBBBQBBBQBQBQBQBQ\n");
					printf("BQBBBQBBBBBBBBBQBQBQBBBBBQBQBBBQBQBBBQBQBQBBBQBQBQBQBBBQBQBBBBBBBBBBBBBBBBBQBQBQBQBQBBBBBQBQBQBBBBBQBQBBBQBQBQBBB\n");
					printf("BQBBBQBBBBBBBBBBQBQBQBBBQBBBQBQBQBBBBBBBQBQBQBBBQBQBQBBBQBBBBBQBQBQBBBBBBBQBQBBBBBBBBBQBQBQBQBBBQBQBQBQBBBBBBBQBQ\n");
					printf("BQBBBQBBBBBBBBBBBBBBBBBQBQBQBBBQBQBQBQBBBQBQBQBQBQBBBQBBBBBBBBBBBBBBBBBQBBBQBQBBBQBBBQBBBBBQBBBBBBBQBBBBBBBQBQBQB\n");
					printf("BQBBBQBBBBBBBBBBQBBBQBQBQBQBBBBBBBQBBBQBBBBBQBBBQBQBBBBBBBBBBBQBQBBBBBBBBBQBBBBBQBQBBBBBBBBBBBBBQBBBBBQBBBQBBBQBQ\n");
					printf("BQBBBQBBBBBBBBBQBQBBBQBQBBBBBBBBBQBBBBBBBQBBBBBQBBBBBQBBBBBQBBBQBBBBBBBBBBBBBBBQBBBBBBBBBBBBBQBBBBQBBQBQBQBQBQBQB\n");
					printf("QBBBQBBBBBBBBQBQBBBQBBBBBBB6;:r6BBBBBsUBBQBS2BBBBKsBR77;i:OBQQBBBOr:iDBB1JBBBB7EBJ7ri:wBOcr;rwBBBQBQBQBQBQBQBBBQB\n");
					printf("BQBBBQBBBBBBBBBBBBBQBQBQBBB: :L  QBBBa  ZQBB. 5BBB  B7 7ci:ZBQBBBL ,L. sBr RBBr BQ ,Li:wBr r7i  BBQQBQBBBQBQBQBQB\n");
					printf("BQBBBQBBBBBBBBBBQBQBQBQBQBO vBBBBBBBQ ;: BBB,  BB   BJ BQBBBBBQBB :BBB: BB .BB :BB pBBBBBL BQB; MBMBBBQBBBQBBBQBQ\n");
					printf("BQBBBQBBBBBBBBBQBQBBBBBBBBX QBP;75BB7 RK JBB,...r ; B1 ...BBBBBBR 5BBBw BBS B7 BBQ  . OBBL ..  BBBBQBQBQBBBQBQBQB\n");
					printf("BQBBBQBBBBBBBBBBQBBBQBQBBBg 7BB: :BB  :;  BB :B  BX QJ BBBBBBBBBB :BBB. BBB   LBQR QBBBBQL BBi BQBBBQBQBQBQBQBQBB\n");
					printf("BQBBBQBBBBBBBBBBBBBBBQBQBBB; :L  BB  QBQB .B  B7.Br B7 :i:.7BQBBBJ .r. UBBBP  BBBD  r:,;Br BBB  BQQBBBBQBQBQBQBBB\n");
					printf("BQBBBQBBBBBBBBQBQBBBQBQBQQBBD7:LBBBLGBBBBDsBaXBBBBEJBRsc77;1BBBBBBgr;rMBQBBB2gBBBBJs7riLBDsBQBDcRBMBQBBBQBBBQBQBB\n");
					printf("BQBBBQBBBBBBBBBQBBBQBQBQBBBQBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBQBBBBBQBQBBBBBBBBBBBQBQBQBQBBBBBQB\n");
					printf("BQBBBQBBBBBBBBQBQBBBQBQBQBBBBBBBBBBBBBQBBBBBBBBBBBBBBBQBBBBBQBQBBBBBBBBBQBQBBBBBBBBBBBBBBBBBBBBBBBBBBBQBQBBBBBQBB\n");
					printf("BQBBBQBBBBBBBBBQBQBQBBBQBBBQBQBQBQBQBBBQBQBBBBBBBQBQBQBBBQBQBBBBBQBQBBBQBQBBBBBQBQBBBBBBBBBQBQBBBQBQBQBBBQBQBQBBB\n");
					printf("BQBBBQBBBBBBBBQBQBBBQBQBQBQBQBQBQBQBQBQBQBBBBBBBBBQBQBQBQBBBQBBBQBQBQBQBBBQBQBQBQBQBBBQBQBQBBBBBQBQBQBQBBBBBQBQBB\n");
					printf("BQBBBQBBBBBBBBBBBBBBBQBQBBBBBQBQBBBBBQBQBBBQBQBQBQBBBQBBBBBQBQBQBQBQBQBBBQBQBQBQBBBQBQBQBQBBBQBQBQBBBQBBBBBQBQBQB\n");
					printf("BQBBBQBBBBBBBBQBBBQBQBBBQBQBQBQBBBBBQBBBQBQBQBBBQBBBQBQBQBBBBBBBBBBBQBQBBBQBQBQBQBQBBBQBBBQBQBBBQBBBQBBBBBQBQBQBB\n");
					printf("BQBBBQBBBBBBBBBQBBBQBBBBBQBQBQBQBQBQBQBQBQBQBQBBBBBQBQBQBQBBBQBBBQBQBQBQBQBQBQBQBQBBBBBQBBBQBQBBBQBQBQBQBBBQBQBQB\n");
					printf("BQBBBQBBBBBBBBBBBBQBQBQBQBQBQBBBBBBBQBQBQBBBQBBBQBQBQBBBQBQBBBQBQBQBBBBBBBQBBBBBQBBBQBQBQBQBBBBBBBBBBBQBQBQBBBBBQ\n");
					printf("BQBBBQBBBBBBBBBBBQBQBQBBBBBQBQBQBQBQBBBQBBBQBQBQBBBQBQBQBBBQBQBQBQBQBBBBBQBQBQBQBQBQBQBBBBBQBQBQBBBBBQBQBBBQBQBQB\n");
					printf("BQBBBQBBBBBBBBQBBBBBQBQBQBBBBBQBQBQBQBQBBBQBQBQBQBQBQBQBBBBBBBQBQBBBBBQBBBQBQBQBBBQBQBBBQBQBQBQBQBBBQBBBBBQBQBQBQ\n");
					printf("BQBBBQBBBBBBBBBQBQBQBQBQBQBBBQBQBQBQBQBBBBBQBQBBBQBQBBBBBQBQBQBQBQBQBQBQBQBBBBBQBQBQBBBQBQBQBBBQBQBQBQBQBQBQBBBQB\n");
					printf("BQBBBQBBBBBBBBQBQBBBQBQBQBQBBBQBQBQBBBBBQBQBQBQBQBQBQBQBBBQBQBQBBBQBQBQBBBQBBBQBQBBBQBBBBBQBQBBBBBQBBBQBQBQBBBQBB\n");
					Sleep(5000);
					exit(0);
				}
			}
			//	gotoxy(90, 13);
			//	printf("M_S = %d", M_S);
		}

		if (Map == 1)
		{
			gotoxy(2, 21);
			switch (M_S)
			{
			case 1:														// 포커방
				if (Money < 1)
				{
					Day--;
					printf("베팅 최소 금액보다 보유 금액이 적어 입장할 수 없습니다.");
					ing(1);
					break;
				}
				else {
					printf("포커방에 입장합니다.");
					ing(1);
					Poker_Room();
				}
				y += 1;
				break;

			case 2:
				if (Money < 10)
				{
					Day--;
					printf("로또 가격보다 보유 금액이 적어 입장할 수 없습니다.");	// 복권방
					ing(1);
					break;
				}
				else {
					printf("복권방에 입장합니다.");
					ing(1);
					Lottery();
				}
				y += 1;
				break;

			case 3:
				printf("금 거래소에 입장합니다.");
				ing(1);
				Gold_Store(Gold_Price, &Gold_Have);

				y += 1;
				break;

			case 4:
				if (Money < 1)
				{
					Day--;
					printf("베팅 최소 금액보다 보유 금액이 적어 입장할 수 없습니다.");
					ing(1);
					break;
				}
				else {
					printf("경마장에 입장합니다.");
					ing(1);
					Race();
				}
				y += 1;
				break;

			case 5:														// 호텔
				if (HP == 100)
				{
					Day--;
					printf("HP가 부족할때만 찾아오세요.");
					ing(1);
				}
				else if (Money < 100)
				{
					Day--;
					printf("호텔 비용보다 보유 금액이 적어 입장할 수 없습니다.");
					ing(1);
				}
				else {
					printf("호텔에 입장합니다.");
					ing(1);
					Hotel();
				}
				y -= 1;
				break;

			case 6:
				if (House_Have == 0)
				{
					printf("집을 아직 구매하지 않았습니다.");
					Day_f = 2;
					ing(1);
				}

				if (House_Have == 1)
				{
					printf("집에 입장합니다.");
					ing(1);
					House();
				}

				y -= 1;
				break;
			case 7:
				printf("부동산에 입장합니다.");
				ing(1);
				Real_Estate();

				y -= 1;
				break;

			case 8:														// 장기
				if (Money < 100)
				{
					if (HP < 50) {
						printf("지금 부품을  때시면 죽을 수도 있습니다.\n");
						printf("%c%c       -HP가 부족합니다.-\n", 0Xa2, 0Xcc);
						Day_f--;
						getch();
					}
					else if (k == 0) {
						printf("더 이상 땔 부품이  없습니다.\n");
						Day_f--;
						getch();
					}
					else {

						HP -= 50;
						if (HP > (100 + (Drink * 30)))
							HP = 100 + (Drink * 30);
						Money += 100;
						printf("로봇공학자가 부품을 때면서 HP가 감소되었습니다.\n");
						printf("불법으로 부품을 팔아 100만 원을 얻었습니다.");
						Day--;
						getch();
					}
				}
				else
				{
					printf("돈이 없을 때만 찾아갑시다.");
					Day_f = 2;
				}
				ing(1);

				y -= 1;
				break;
			case 55:
				HP -= 20;
				if (HP < 0)
					HP = 0;
				Day_f = 2;
				break;

			case 66:
				Money += 1000;
				Day_f = 2;
				break;

			case 77:
				break;

			case 99:														// 게임 종료
				printf("게임을 종료합니다.");
				ing(1);
				exit(0);

			default:
				Day_f = 2;
			}
		}
		Edge();
		printf("\n\n");

		if (HP == 0 && Whistle != 0)						// 호루라기 사용
		{
			Big_Clear();
			Small_Clear();
			Long_Clear();
			Loading_Clear();
			gotoxy(2, 1);
			printf("HP가 0입니다..\n");
			gotoxy(2, 2);
			printf("비틀거리면서 걸어가다가 깡패를 만났습니다.");
			Sleep(1500);
			gotoxy(2, 5);
			printf("호루라기를 불러 도움을 청합니다.");
			Sleep(1500);
			i = rand() % 5 + 1;

			if (i <= 4)
			{
				gotoxy(2, 7);
				printf("'이봐 거기 뭐야!'\n");
				Sleep(1000);
				gotoxy(2, 8);
				printf("사람들이 와주었습니다.\n");
				Sleep(1000);
				gotoxy(2, 9);
				printf("깡패가 호다닥 도망갑니다.\n");
				Sleep(1500);
			}
			else
			{
				gotoxy(2, 7);
				printf("아무도 오지 않았습니다...\n");
				Sleep(1000);
				gotoxy(2, 8);
				printf("깡패에게 돈을 빼앗겼습니다\n");


				if (Money > 200)
				{
					i = (Money / 2);
					gotoxy(2, 11);
					printf("- %d만 원....\n", i);
					Money -= i;
				}
				ing(2);
			}
			Edge();
			Whistle--;
			HP = 10;

		}
		if (HP == 0)										// HP 0
		{
			Big_Clear();
			Small_Clear();
			Long_Clear();
			Loading_Clear();
			m = rand() % 4;
			gotoxy(2, 1);
			printf("HP가 0입니다..\n");
			Sleep(3000);
			gotoxy(2, 2);
			printf("비틀거리면서 걸어가다가 깡패한테 돈을 빼앗겼습니다..\n");
			Sleep(3000);

			if (m == 0) {
				i = Money;
				gotoxy(2, 5);
				printf("- %d만원....\n", i);
				Money = 0;
			}
			else{
				i = (Money / 2);
				gotoxy(2, 5);
				printf("- %d만 원....\n", i);
				Money -= i;
			}
			Sleep(1500);
			Whistle++;
			ing(2);
			Edge();
			HP = 10;
			if (m == 0) HP = 0;
		}

		int Bank_Storage_Main = 0;						// 저금한 금액
		for (i = 1; i <= 9; i++)
		{
			if (Saving[i] == 1)
				Bank_Storage_Main += Ten_Square(i);
		}


		if (Day_f == 1)												// 건물에 들어갔다가 나오면 하루 지남
		{
			Day++;
			Gold_Change(&Gold_Price, &Gold_B);					// 금값 변동
			Money += (Bank_Storage_Main / 10);						// 이자 추가
		}
	}
	return 0;
}


// 초기 메뉴	
void First_Menu()					// 메뉴
{
	int i = 1;					// 메뉴 선택
	int key = 0;					// 키 인식

	while (1)
	{
		system("cls");
		Edge();
		Title();

		gotoxy(38, 14);
		printf("시작 %c%c", 0xa1, 0xdb);
		gotoxy(38, 15);
		printf("설명 %c%c", 0xa1, 0xdb);
		gotoxy(38, 16);
		printf("종료 %c%c", 0xa1, 0xdb);

		while (1)
		{
			gotoxy(44, 13 + i);
			printf("\b%c%c", 0xa1, 0xdc);

			gotoxy(0, 28);
			key = getch();
			if (key == 224)
			{
				key = getch();
				gotoxy(44, 13 + i);
				printf("\b%c%c", 0xa1, 0xdb);
				switch (key)
				{
				case 72:
					if (i > 1)
						i--;

					break;

				case 80:
					if (i < 3)
						i++;

					break;

				default:
					break;
				}
			}

			if (key == 32 || key == 13)
				break;
		}

		if (i == 1)
		{
			ing(1);
			break;
		}

		if (i == 2)
		{
			ing(0.5);
			First_inf();
		}

		if (i == 3)
		{
			ing(0.3);
			exit(0);
		}
	}
}

void First_inf()					// 초기 설명
{
	int Page = 1;
	int key;
	int Change = 1;

	system("cls");
	Edge();

	gotoxy(30, 22);
	printf("%c%c %c%c로 페이지 넘기기", 0xa1, 0xe7, 0xa1, 0xe6);
	gotoxy(30, 24);
	printf("스페이스 바, 엔터 키로 게임으로 돌아가기");

	while (1)
	{
		if (Change == 1)
		{
			Big_Clear();

			if (Page == 1)
			{
				Change = 0;

				gotoxy(3, 2);
				printf("이게임은 돈을 모아 마을을 탈출하는 게임입니다.");
				gotoxy(3, 3);
				printf("여러 가지 게임과 편의 시설들을 선택할 수 있습니다.");

				int i = 0xa1;
				gotoxy(3, 5);
				printf("%c%c %c%c %c%c %c%c 방향키를 이용해 맵을 돌아다닐 수 있으며", i, 0xe8, i, 0xe9, i, 0xe7, i, 0xe6);
				gotoxy(3, 6);
				printf("<spacebar> or <enter>를 눌러 메뉴를 열 수 있습니다.");
				gotoxy(3, 7);
				printf("벽과 건물을 뚫고 다닐 수 없으며");
				gotoxy(3, 8);
				printf("건물 앞의 문으로 가면 건물로 입장할 수 있습니다.");

				gotoxy(3, 10);
				printf("첫 번째 맵의 위로 가면 마을을 나갈 수 있습니다.");

				gotoxy(3, 15);
				printf("게임들의 기본적인 설명은 건물 안에 들어가 확인할 수 있습니다.");

				gotoxy(75, 19);
				printf("Page 1/2");
			}

			if (Page == 2)
			{
				Change = 0;

				gotoxy(3, 2);
				printf("건물을 들어갔다가 나올 때마다 하루가 흘러갑니다.");
				gotoxy(3, 3);
				printf("주식과 금괴의 가격은 하루마다 변동합니다.");
				gotoxy(3, 5);
				printf("여러 가지 행동을 할 때마다 HP가 감소하는데");
				gotoxy(3, 7);
				printf("HP가 0이 되면 깡패에게 돈을 빼앗깁니다.");
				gotoxy(3, 8);
				printf("빼앗기는 돈은 기본적으로 100만 원이며");
				gotoxy(3, 9);
				printf("보유 금액이 200만 원을 넘어갈 경우 절반을 빼앗깁니다.");

				gotoxy(3, 11);
				printf("호텔이나 집에서 휴식해 HP를 채울 수 있습니다.");

				gotoxy(3, 12);
				printf("만약 돈이 다 떨어졌을 경우 장기를 팔아 기본 자금을 다시 마련할 수 있습니다.");

				gotoxy(75, 19);
				printf("Page 2/2");
			}
		}
		gotoxy(0, 28);
		key = getch();
		if (key == 224)
		{
			key = getch();
			if (key == 75)
			{
				if (1 < Page && Page < 3)
				{
					Page--;
					Change = 1;
				}
			}
			if (key == 77)
			{
				if (1 <= Page && Page < 2)
				{
					Page++;
					Change = 1;
				}
			}
		}

		if (key == 32 || key == 13)
			break;
	}
	ing(0.5);
}



// 공통 알고리즘
int YN()							// Yes or No
{
	int i = 1;
	int key;

	int A;

	gotoxy(91, 23);
	printf("Yes      No %c%c", 0xa1, 0xdb);

	while (1)
	{
		gotoxy(88 + i * 8, 23);
		printf("\b%c%c", 0xa1, 0xdc);
		gotoxy(2, 21);

		gotoxy(0, 28);
		key = getch();
		if (key == 224)
		{
			key = getch();
			gotoxy(88 + i * 8, 23);
			printf("\b%c%c", 0xa1, 0xdb);
			switch (key)
			{
			case 75:
				if (i == 2)
					i--;

				break;

			case 77:
				if (i == 1)
					i++;

				break;

			default:
				break;
			}
		}

		if (key == 32 || key == 13)
			break;
	}

	return i;
}

void cur() {
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = 1;
	cursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}
void ing(float n)						// 로딩 (n * 1 초)
{
	int i;
	gotoxy(2, 27);
	for (i = 1; i <= 10; i++)
	{
		printf("◇");
		Sleep(25 * n);
		printf("♤");
		Sleep(25 * n);
		printf("♡");
		Sleep(25 * n);
		printf("♧");
		Sleep(25 * n);
	}
	printf("◇");
	Sleep(25 * n);
}

void gotoxy(int x, int y)			// gotoxy
{
	COORD Pos;
	Pos.X = x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

int Ten_Square(int num)
{
	int i;
	int TEN = 1;

	for (i = 1; i <= num; i++)
		TEN = (TEN * 10);

	return TEN;
}

int Ten_Divide(int num)
{
	int i;

	for (i = 0; 1 < num; i++)
		num = (num / 10);

	return i;
}



// 게임
	// 포커 함수
void Poker_Room()
{


	int i = 1;					// 메뉴 선택
	int key = 0;					// 키 인식
	int re = 0;
	int time = 0;
	int up = -1;
	int j = 0;


	int Number, Type;

	while (re < 2)
	{
		Full_Clear();
		PlaySound(TEXT("로스트아크.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
		if (re == 0)
		{
			gotoxy(3, 22); printf("포커방에 입장하였습니다.");
		}

		if (re == 1)
		{
			gotoxy(3, 22); printf("포커방 홀로 돌아왔습니다.");
		}

		Sleep(500);
		gotoxy(35, 23); printf("%c%c %c%c 로 이동 , <spacebar> or <enter>로 선택", 0xa1, 0xe8, 0xa1, 0xe9);
		gotoxy(3, 24); printf("무엇을 하시겠습니까?");


		gotoxy(24, 14);
		printf("파이브 드로우 포커 %c%c", 0xa1, 0xdb);
		gotoxy(38, 15);
		printf("설명 %c%c", 0xa1, 0xdb);
		gotoxy(36, 16);
		printf("나가기 %c%c", 0xa1, 0xdb);

		gotoxy(13, 3); printf("┏━━━━━━┓ ");
		gotoxy(13, 4); printf("┃ ?    ┃ ");
		gotoxy(13, 5); printf("┃      ┃ ");
		gotoxy(13, 6); printf("┃      ┃ ");
		gotoxy(13, 7); printf("┃   ?  ┃ ");
		gotoxy(13, 8); printf("┃      ┃ ");
		gotoxy(13, 9); printf("┃      ┃ ");
		gotoxy(13, 10); printf("┃     ?┃ ");
		gotoxy(13, 11); printf("┗━━━━━━┛ ");

		gotoxy(23, 3); printf("┏━━━━━━┓ ");
		gotoxy(23, 4); printf("┃ ?    ┃ ");
		gotoxy(23, 5); printf("┃      ┃ ");
		gotoxy(23, 6); printf("┃      ┃ ");
		gotoxy(23, 7); printf("┃   ?  ┃ ");
		gotoxy(23, 8); printf("┃      ┃ ");
		gotoxy(23, 9); printf("┃      ┃ ");
		gotoxy(23, 10); printf("┃     ?┃ ");
		gotoxy(23, 11); printf("┗━━━━━━┛ ");

		gotoxy(33, 3); printf("┏━━━━━━┓ ");
		gotoxy(33, 4); printf("┃ ?    ┃ ");
		gotoxy(33, 5); printf("┃      ┃ ");
		gotoxy(33, 6); printf("┃      ┃ ");
		gotoxy(33, 7); printf("┃   ?  ┃ ");
		gotoxy(33, 8); printf("┃      ┃ ");
		gotoxy(33, 9); printf("┃      ┃ ");
		gotoxy(33, 10); printf("┃     ?┃ ");
		gotoxy(33, 11); printf("┗━━━━━━┛ ");

		gotoxy(43, 3); printf("┏━━━━━━┓ ");
		gotoxy(43, 4); printf("┃ ?    ┃ ");
		gotoxy(43, 5); printf("┃      ┃ ");
		gotoxy(43, 6); printf("┃      ┃ ");
		gotoxy(43, 7); printf("┃   ?  ┃ ");
		gotoxy(43, 8); printf("┃      ┃ ");
		gotoxy(43, 9); printf("┃      ┃ ");
		gotoxy(43, 10); printf("┃     ?┃ ");
		gotoxy(43, 11); printf("┗━━━━━━┛ ");

		gotoxy(53, 3); printf("┏━━━━━━┓ ");
		gotoxy(53, 4); printf("┃ ?    ┃ ");
		gotoxy(53, 5); printf("┃      ┃ ");
		gotoxy(53, 6); printf("┃      ┃ ");
		gotoxy(53, 7); printf("┃   ?  ┃ ");
		gotoxy(53, 8); printf("┃      ┃ ");
		gotoxy(53, 9); printf("┃      ┃ ");
		gotoxy(53, 10); printf("┃     ?┃ ");
		gotoxy(53, 11); printf("┗━━━━━━┛ ");

		while (1)
		{
			gotoxy(44, 13 + i);
			printf("\b%c%c", 0xa1, 0xdc);

			gotoxy(0, 28);
			if (kbhit())
			{
				gotoxy(0, 28); key = getch();
				if (key == 224)
				{
					key = getch();
					gotoxy(44, 13 + i);
					printf("\b%c%c", 0xa1, 0xdb);
					switch (key)
					{
					case 72:
						if (i > 1)
							i--;
						break;

					case 80:
						if (i < 3)
							i++;
						break;

					default:
						break;
					}
				}
				if (key == 32 || key == 13)
					break;
			}
			else
			{
				time++;


				if (time == 300)
				{
					Number = rand() % 14 + 1;
					Type = rand() % 4 + 1;
					Show(45, 11, Number, Type, 1);
				}

				if (time == 1300)
				{
					Number = rand() % 14 + 1;
					Type = rand() % 4 + 1;
					Show(35, 11, Number, Type, 1);
				}
				if (time == 2300)
				{
					Number = rand() % 14 + 1;
					Type = rand() % 4 + 1;
					Show(25, 11, Number, Type, 1);
				}

				if (time == 3300)
				{
					Number = rand() % 14 + 1;
					Type = rand() % 4 + 1;
					Show(15, 11, Number, Type, 1);
				}

				if (time == 4300)
				{
					Number = rand() % 14 + 1;
					Type = rand() % 4 + 1;
					Show(5, 11, Number, Type, 1);
				}
				if (time == 5000)
					time = 0;
			}
		}

		switch (i)					// 메뉴에 따른 이동
		{
		case 1:
			ing(1);
			Poker_Five_Draw_1();
			re = 1;
			break;

		case 2:
			ing(0.5);
			Poker_Room_inf();
			break;

		case 3:
			Long_Clear();
			gotoxy(3, 22); printf("포커방에서 퇴장합니다.");
			ing(0.3);
			PlaySound(TEXT("마피아 브금.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
			re = 2;
			break;
		}
	}
}

void Show(int x, int y, int N, int T, int i)
{
	gotoxy(x + 10, y - 7);				// 위 문양 출력
	if (T == 1)
		printf("%c%c", 0xa2, 0xbc);
	else if (T == 2)
	{
		Set_Color(12);
		printf("%c%c", 0xa2, 0xbe);
	}
	else if (T == 3)
	{
		Set_Color(12);
		printf("%c%c", 0xa1, 0xdf);
	}
	else if (T == 4)
		printf("%c%c", 0xa2, 0xc0);

	gotoxy(x + 3 + 10, y + 4 + i + i - 7);			// 아래 문양 출력
	if (T == 1)
		printf("%c%c", 0xa2, 0xbc);
	else if (T == 2)
		printf("%c%c", 0xa2, 0xbe);
	else if (T == 3)
		printf("%c%c", 0xa1, 0xdf);
	else if (T == 4)
		printf("%c%c", 0xa2, 0xc0);

	gotoxy(x + 12, y + 2 + i - 7);					// 숫자
	if (N <= 10)
	{
		gotoxy(x + 12, y + 2 + i - 7);
		printf("%2d", N);
	}
	else if (N == 11)
		printf(" J");
	else if (N == 12)
		printf(" Q");
	else if (N == 13)
		printf(" K");
	else if (N == 14)
		printf(" A");

	Set_Color(15);
}

void Poker_Room_inf()
{
	int Page = 1;
	int key;
	int Change = 1;

	Full_Clear();

	gotoxy(30, 22);
	printf("%c%c %c%c로 페이지 넘기기", 0xa1, 0xe7, 0xa1, 0xe6);
	gotoxy(30, 24);
	printf("<spacebar> or <enter>로 게임으로 돌아가기");

	while (1)
	{
		if (Change == 1)
		{
			Big_Clear();

			if (Page == 1)
			{
				Change = 0;

				gotoxy(3, 2);
				printf("포커방에서는 다양한 규칙의 포커 게임을 할 수 있습니다.");
				gotoxy(3, 4);
				printf("방향키와 <spacebar> or <enter>를 사용합니다.");

				gotoxy(3, 6);
				printf("파이브 드로우 포커는 혼자서 족보와 패를 비교해 게임을 하는 1인용과");
				gotoxy(3, 7);
				printf("                     딜러와 패를 비교해 게임을 하는 2인용이 있습니다.");


				gotoxy(3, 18);
				printf("포커 게임 한 판당 HP가 6씩 감소합니다.");

				gotoxy(75, 19);
				printf("Page 1/3");
			}

			if (Page == 2)
			{
				Change = 0;

				gotoxy(3, 2);
				printf("이 게임은 족보만 보고 숫자의 높낮이는 보지 않습니다.");
				gotoxy(3, 3);
				printf("아래는 이 게임의 족보입니다.");

				gotoxy(3, 5);
				printf("노 페어 : 아래에 언급되는 어느 족보에도 해당되지 않는 경우.");
				gotoxy(3, 6);
				printf("          베팅 한 만큼 돈을 잃습니다.");
				gotoxy(3, 8);
				printf("원 페어 : 숫자가 같은 카드 2장이 존재.");
				gotoxy(3, 9);
				printf("          베팅 한 금액의 0.5배를 돌려받습니다.");
				gotoxy(3, 11);
				printf("투 페어 : 원 페어가 2쌍 존재.");
				gotoxy(3, 12);
				printf("          베팅 한 금액의 0.9배를 돌려받습니다.");
				gotoxy(3, 14);
				printf("트리플 : 숫자가 같은 카드 3장이 존재.");
				gotoxy(3, 15);
				printf("         베팅 한 금액의 3배를 얻습니다.");
				gotoxy(3, 17);
				printf("스트레이트 : 숫자가 연속된 카드 5장.");
				gotoxy(3, 18);
				printf("             베팅 한 금액의 20배를 얻습니다.");

				gotoxy(75, 19);
				printf("Page 2/3");
			}

			if (Page == 3)
			{
				Change = 0;

				gotoxy(3, 2);
				printf("플러시 : 숫자 상관없이 무늬가 같은 카드 5장.");
				gotoxy(3, 3);
				printf("         베팅 한 금액의 8배를 얻습니다.");
				gotoxy(3, 5);
				printf("풀 하우스 : 트리플과 원 페어가 같이 존재.");
				gotoxy(3, 6);
				printf("           베팅 한 금액의 10배를 얻습니다~");
				gotoxy(3, 8);
				printf("포카드 : 숫자가 같은 카드 4장.");
				gotoxy(3, 9);
				printf("         베팅 한 금액의 30배를 얻습니다 ~~!!");

				gotoxy(75, 19);
				printf("Page 3/3");
			}
		}

		gotoxy(0, 28);
		key = getch();
		if (key == 224)
		{
			key = getch();
			if (key == 75)
			{
				if (1 < Page && Page <= 3)
				{
					Page--;
					Change = 1;
				}
			}
			if (key == 77)
			{
				if (1 <= Page && Page < 3)
				{
					Page++;
					Change = 1;
				}
			}
		}

		if (key == 32 || key == 13)
			break;
	}
	ing(0.5);
}

void Poker_Five_Draw_1()							// 파이브 드로우 포커 1
{
	int Number[6];						// 받는 카드
	int Type[6];

	int i, j, l;
	int key;

	int Poker_Count = 1;				// 포커 카운팅
	int Poker_re = 1;					// 포커 리


	Full_Clear();

	gotoxy(3, 22);
	printf("파이브 드로우 포커를 시작합니다.");

	gotoxy(0, 28);
	Sleep(0);

	gotoxy(3, 24);
	printf("설명을 보시겠습니까?");

	i = YN();						// 설명
	if (i == 1)
		Poker_Five_Draw_1_inf();

	while (Poker_re == 1)			// 반복 게임
	{
		int T_Number[6] = { 0, 0, 0, 0, 0, 0 };		// 버린 카드 초기화
		int T_Type[6] = { 0, 0, 0, 0, 0, 0 };

		int Card[6] = { 0, 0, 0, 0, 0, 0 };
		int point = 0;								// 점수 매 판 초기화	
		int Change[6] = { 0, 0, 0, 0, 0, 0 };			// 체인지 매 판 초기화
		int bet1 = 0;							// 베팅
		int bet2 = 0;

		Full_Clear();
		Status();

		for (i = 1; i <= 5; i++)			// 처음 카드 받기
		{
			for (j = 0; j < 70; j++)
			{
				if (73 - j != 67 - 15 * (5 - i))
				{
					Sleep(6 - ((5 - i) * 0.5));	// 4

					gotoxy(73 - j, 8); printf("┏━━━━━━┓ ");
					gotoxy(73 - j, 9); printf("┃ ?    ┃ ");
					gotoxy(73 - j, 10); printf("┃      ┃ ");
					gotoxy(73 - j, 11); printf("┃   ?  ┃ ");
					gotoxy(73 - j, 12); printf("┃      ┃ ");
					gotoxy(73 - j, 13); printf("┃     ?┃ ");
					gotoxy(73 - j, 14); printf("┗━━━━━━┛ ");
				}
				else
					break;
			}
		}

		while (1)							// 첫 번째 베팅
		{
			Long_Clear();
			Small_Clear();

			gotoxy(3, 21); printf("%d 번째 게임입니다.", Poker_Count);
			gotoxy(0, 28);
			Sleep(500);
			gotoxy(3, 23); printf("얼마를 베팅하시겠습니까?");
			gotoxy(3, 24); printf(" (단위:만) (0이면 취소) ");

			gotoxy(70, 22); printf("%c%c %c%c %c%c  1", 0xa1, 0xe8, 0xa1, 0xe9, 0xa1, 0xbe);
			gotoxy(70, 23); printf("%c%c %c%c %c%c 50", 0xa1, 0xe7, 0xa1, 0xe6, 0xa1, 0xbe);

			gotoxy(91, 22); printf("베팅1");


			while (1)							// 베팅 키 인식
			{
				gotoxy(97, 22); printf("%d", bet1);
				gotoxy(0, 28);
				key = getch();
				if (key == 224)
				{
					key = getch();
					gotoxy(97, 22); printf("         ");

					switch (key)
					{
					case 72:
						if (0 <= bet1 && bet1 < floor(Money))	
							bet1++; //위쪽키
						break;

					case 75:
						if (bet1 <= 50)
							bet1 = 0;
						else if (50 <= bet1 && bet1 <= floor(Money))
							bet1 -= 50; //왼쪽키
						break;

					case 77:
						if (floor(Money) - 50 < bet1)
							bet1 = floor(Money);
						else if (0 <= bet1 && bet1 <= floor(Money) - 50)
							bet1 += 50;//오른쪽키
						break;

					case 80:
						if (1 <= bet1 && bet1 <= floor(Money))
							bet1--;//아래쪽키
						break;

					default:
						break;
					}
				}

				if (key == 13 || key == 32)
					break;
			}

			Long_Clear();
			if (bet1 == 0)						// 베팅 취소
			{
				Small_Clear();
				gotoxy(3, 22);
				printf("파이브 드로우 포커를 그만 하시겠습니까?");
				i = YN();

				if (i == 1)
					break;
				if (i == 2)
					continue;
			}
			else
			{
				Money -= bet1;
				Status();
				break;
			}
		}

		if (i == 1)
			break;

		for (i = 1; i <= 5; i++)					// 카드 뽑기
		{
			Number[i] = rand() % 9 + 6;
			Type[i] = rand() % 4 + 1;

			for (j = 1; i - j > 0; j++)		// 중복 체크
			{
				if (Number[i] == Number[i - j] && Type[i] == Type[i - j])
					i--;
			}
		}

		ShowCard(Number, Type, Change);				// 받은 카드 출력
		for (i = 1; i <= 5; i++)					// Change 값 초기화
			Change[i] = 0;

		for (i = 1; i <= 5; i++)					// 카드 바꾸기 동그라미 출력
		{
			gotoxy(12 + 15 * (i - 1), 18); printf("%c%c", 0xa1, 0xdb);

			gotoxy(79, 16); printf("완료");
			gotoxy(80, 18); printf("%c%c", 0xa1, 0xdb);
		}

		gotoxy(13, 23);
		printf("%c%c %c%c 를 이용해 움직이고 스페이스바나 엔터키를 이용해 선택", 0xa1, 0xe7, 0xa1, 0xe6);

		i = 1;
		while (1)							// 카드 바꾸기 키 인식
		{
			if (i <= 5)
			{
				gotoxy(13 + 15 * (i - 1), 18); printf("\b%c%c", 0xa1, 0xdc);
				gotoxy(2, 21);
			}
			else if (i == 6)
			{
				gotoxy(81, 18); printf("\b%c%c", 0xa1, 0xdc);
			}

			gotoxy(0, 28);
			key = getch();
			if (key == 224)
			{
				key = getch();
				if (i <= 5)
				{
					gotoxy(13 + 15 * (i - 1), 18); printf("\b%c%c", 0xa1, 0xdb);
				}
				else if (i == 6)
				{
					gotoxy(81, 18); printf("\b%c%c", 0xa1, 0xdb);
				}

				switch (key)
				{
				case 75:
					if (1 < i && i <= 6)
						i--;
					break;

				case 77:
					if (1 <= i && i < 6)
						i++;
					break;

				default:
					break;
				}
			}

			if (key == 13 || key == 32)
			{
				if (i <= 5)
				{
					if (Change[i] == 0)
					{
						Change[i] = 1;
						gotoxy(12 + 15 * (i - 1), 16);
						printf("%c%c", 0xa1, 0xee);
					}
					else if (Change[i] == 1)
					{
						Change[i] = 0;
						gotoxy(12 + 15 * (i - 1), 16);
						printf("  ");
					}
				}
				if (i == 6)
					break;
			}
		}

		gotoxy(2, 16); printf("                                                                                  ");
		gotoxy(2, 18); printf("                                                                                  ");

		for (i = 1; i <= 5; i++)				// 카드 버리기
		{
			if (Change[i] == 1)
			{
				int a, b;

				switch (Type[i])
				{
				case 1:
					a = 0xa2; b = 0xbc;
					break;

				case 2:
					a = 0xa2; b = 0xbe;
					break;

				case 3:
					a = 0xa1; b = 0xdf;
					break;

				case 4:
					a = 0xa2; b = 0xc0;
					break;
				}

				for (j = 0; j < 15; j++)
				{

					Sleep(20);	// 20

					if (15 - j > 0)
					{
						gotoxy(8 + 15 * (i - 1), 15 - j); printf("          ");


						if (14 - j > 0)
						{
							gotoxy(8 + 15 * (i - 1), 14 - j); printf("┗━━━━━━┛ ");

							if (13 - j > 0)
							{
								gotoxy(8 + 15 * (i - 1), 13 - j); printf("┃      ┃ ");

								if (Type[i] == 1 || Type[i] == 4)					// 검은 아래 문양
								{
									gotoxy(14 + 15 * (i - 1), 13 - j);
									printf("%c%c", a, b);
								}

								if (Type[i] == 2 || Type[i] == 3)					// 빨간 아래 문양
								{
									Set_Color(12);

									gotoxy(14 + 15 * (i - 1), 13 - j);
									printf("%c%c", a, b);

									Set_Color(15);
								}

								if (12 - j > 0)
								{
									gotoxy(8 + 15 * (i - 1), 12 - j); printf("┃      ┃ ");

									if (11 - j > 0)
									{
										gotoxy(8 + 15 * (i - 1), 11 - j); printf("┃      ┃ ");

										if (Type[i] == 1 || Type[i] == 4)			// 하얀 숫자 출력		
										{
											gotoxy(12 + 15 * (i - 1), 11 - j);
											if (Number[i] <= 10)
												printf("%2d", Number[i]);
											if (Number[i] == 11)
												printf("J");
											if (Number[i] == 12)
												printf("Q");
											if (Number[i] == 13)
												printf("K");
											if (Number[i] == 14)
												printf("A");
										}

										if (Type[i] == 2 || Type[i] == 3)			// 빨간 숫자 출력		
										{
											Set_Color(12);

											gotoxy(12 + 15 * (i - 1), 11 - j);
											if (Number[i] <= 10)
												printf("%2d", Number[i]);
											if (Number[i] == 11)
												printf("J");
											if (Number[i] == 12)
												printf("Q");
											if (Number[i] == 13)
												printf("K");
											if (Number[i] == 14)
												printf("A");

											Set_Color(15);
										}

										if (10 - j > 0)
										{
											gotoxy(8 + 15 * (i - 1), 10 - j); printf("┃      ┃ ");

											if (9 - j > 0)
											{
												gotoxy(8 + 15 * (i - 1), 9 - j); printf("┃      ┃ ");

												if (Type[i] == 1 || Type[i] == 4)	// 하얀 위 문양
												{
													gotoxy(10 + 15 * (i - 1), 9 - j);
													printf("%c%c", a, b);
												}
												if (Type[i] == 2 || Type[i] == 3)	// 빨간 위 문양
												{
													Set_Color(12);

													gotoxy(10 + 15 * (i - 1), 9 - j);
													printf("%c%c", a, b);

													Set_Color(15);
												}

												if (8 - j > 0)
												{
													gotoxy(8 + 15 * (i - 1), 8 - j); printf("┏━━━━━━┓ ");
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}

		for (i = 1; i <= 5; i++)				// 새로 뽑기, 중복 체크, 카드 가져오기
		{

			if (Change[i] == 1)
			{
				int a;

				T_Number[i] = Number[i];
				T_Type[i] = Type[i];

				do								// 새로 뽑기
				{
					a = 0;

					Number[i] = rand() % 9 + 6;
					Type[i] = rand() % 4 + 1;

					for (j = 1; j <= 5; j++)
					{
						if (i != j)
						{
							if (Number[i] == Number[j] && Type[i] == Type[j])
								a = 1;
						}
					}

					for (j = 1; j <= 5; j++)
					{
						if (Number[i] == T_Number[j] && Type[i] == T_Type[j])	// T
							a = 1;
					}

				} while (a != 0);

				for (i = 1; i <= 5; i++)				// 카드 가져오기
				{
					if (Change[i] == 1)
					{
						for (j = 1; j < 15; j++)
						{

							Sleep(25);	// 25

							if (8 - j > 0)
							{
								gotoxy(8 + 15 * (i - 1), j + 7); printf("┗━━━━━━┛ ");

								if (9 - j > 0)
								{
									gotoxy(8 + 15 * (i - 1), j + 6); printf("┃     ?┃ ");

									if (10 - j > 0)
									{
										gotoxy(8 + 15 * (i - 1), j + 5); printf("┃      ┃ ");

										if (11 - j > 0)
										{
											gotoxy(8 + 15 * (i - 1), j + 4); printf("┃   ?  ┃");

											if (12 - j > 0)
											{
												gotoxy(8 + 15 * (i - 1), j + 3); printf("┃      ┃ ");

												if (13 - j > 0)
												{
													gotoxy(8 + 15 * (i - 1), j + 2); printf("┃ ?    ┃ ");

													if (14 - j > 0)
													{
														gotoxy(8 + 15 * (i - 1), j + 1); printf("┏━━━━━━┓ ");

														if (15 - j > 0)
														{
															gotoxy(8 + 15 * (i - 1), j); printf("          ");
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}

		while (1)							// 두 번째 베팅
		{
			Long_Clear();

			gotoxy(3, 21); printf("두 번째 베팅시간입니다.");
			gotoxy(3, 23); printf("얼마를 베팅하시겠습니까?");
			gotoxy(3, 24); printf(" (단위:만) (0이면 취소) ");

			gotoxy(70, 22); printf("%c%c %c%c %c%c  1", 0xa1, 0xe8, 0xa1, 0xe9, 0xa1, 0xbe);
			gotoxy(70, 23); printf("%c%c %c%c %c%c 50", 0xa1, 0xe7, 0xa1, 0xe6, 0xa1, 0xbe);

			gotoxy(91, 24); printf("베팅2");


			while (1)							// 베팅 키 인식
			{
				gotoxy(97, 24); printf("%d", bet2);
				gotoxy(0, 28);
				key = getch();
				if (key == 224)
				{
					key = getch();
					gotoxy(97, 24); printf("         ");

					switch (key)
					{
					case 72:
						if (0 <= bet2 && bet2 < floor(Money))	// floor 은 버림 함수
							bet2++;
						break;

					case 75:
						if (bet2 <= 50)
							bet2 = 0;
						else if (50 <= bet2 && bet2 <= floor(Money))
							bet2 -= 50;
						break;

					case 77:
						if (floor(Money) - 50 < bet2)
							bet2 = floor(Money);
						else if (0 <= bet2 && bet2 <= floor(Money) - 50)
							bet2 += 50;
						break;

					case 80:
						if (1 <= bet2 && bet2 <= floor(Money))
							bet2--;
						break;

					default:
						break;
					}
				}

				if (key == 13 || key == 32)
					break;
			}
			Money -= bet2;
			Status();
			break;
		}

		ShowCard(Number, Type, Change);	// 바꾼 카드 출력

		// 점수 체크 시작
		{

			/* if(N[1] == 10 && N[2] == 11 && N[3] == 12 && N[4] == 13 && N[5] == 14)	// 백 스트레이트
			p += 20; */

			if (Type[1] == Type[2] && Type[1] == Type[3] && Type[1] == Type[4] && Type[1] == Type[5]) // 플러시
			{
				Card[1] = 1;
				Card[2] = 1;
				Card[3] = 1;
				Card[4] = 1;
				Card[5] = 1;

				point += 10;
			}

			{									// 스트레이트
				for (i = 1; i <= 4; i++)			// 내림차순 버블 정렬 사용
				{
					for (j = 1; j <= 5 - i; j++)
					{
						if (Number[j] < Number[j + 1])
						{
							int t = Number[j];
							Number[j] = Number[j + 1];
							Number[j + 1] = t;

							t = Type[j];
							Type[j] = Type[j + 1];
							Type[j + 1] = t;
						}
					}
				}

				if ((Number[1] - 1) == Number[2])	// 점점 작아지는지 확인				
				{
					if ((Number[2] - 1) == Number[3])
					{
						if ((Number[3] - 1) == Number[4])
						{
							if ((Number[4] - 1) == Number[5])
							{
								Card[1] = 1;
								Card[2] = 1;
								Card[3] = 1;
								Card[4] = 1;
								Card[5] = 1;

								point += 20;
							}
						}
					}
				}
			}

			for (i = 1; i <= 4; i++)	// 페어 종류 ~ 풀하우스
			{
				for (j = 1; (i + j) <= 5; j++)
				{
					if (Number[i] == Number[i + j])
					{
						Card[i] = 1;
						Card[i + j] = 1;
						point++;
					}
				}
			}
		}

		gotoxy(2, 15); printf("                                                                                  ");
		gotoxy(2, 17); printf("                                                                                  ");

		Long_Clear();
		Small_Clear();

		gotoxy(91, 22); printf("최종 베팅 금액");
		gotoxy(95, 24); printf("%.2lf", (bet1 + bet2 * 0.8));

		i = Card[1] + Card[2] + Card[3] + Card[4] + Card[5];
		gotoxy(0, 28); getch();

		if (point != 0)						// 결과 창
		{
			{												// 결과 출력 창 그리기
				gotoxy(42 - (6 * i) - 1, 6); printf("┏");		// 맨 위
				for (j = 1; j <= 6 * i; j++)
				{
					printf("━━");
				}
				printf("┓");

				for (j = 7; j <= 15; j++)
				{
					gotoxy(42 - (6 * i) - 1, j); printf("┃");
					for (int p = 1; p <= 6 * i; p++)
					{
						printf("  ");
					}
					printf("┃");
				}

				gotoxy(42 - (6 * i) - 1, 16); printf("┗");	// 맨 아래
				for (j = 1; j <= 6 * i; j++)
				{
					printf("━━");
				}
				printf("┛");
			}

			{												// 결과 출력 카드(문양)
				l = 1;

				for (j = 1; j <= 5; j++)
				{
					if (Card[j] == 1)
					{
						gotoxy(42 - (6 * i) + (12 * (l - 1)) + 4, 10);		// 위 문양
						if (Type[j] == 1)
							printf("%c%c", 0xa2, 0xbc);
						else if (Type[j] == 2)
						{
							Set_Color(12);
							printf("%c%c", 0xa2, 0xbe);
						}
						else if (Type[j] == 3)
						{
							Set_Color(12);
							printf("%c%c", 0xa1, 0xdf);
						}
						else if (Type[j] == 4)
							printf("%c%c", 0xa2, 0xc0);

						gotoxy(42 - (6 * i) + (12 * (l - 1)) + 8, 14);		// 아래 문양
						if (Type[j] == 1)
							printf("%c%c", 0xa2, 0xbc);
						else if (Type[j] == 2)
							printf("%c%c", 0xa2, 0xbe);
						else if (Type[j] == 3)
							printf("%c%c", 0xa1, 0xdf);
						else if (Type[j] == 4)
							printf("%c%c", 0xa2, 0xc0);


						gotoxy(42 - (6 * i) + (12 * (l - 1)) + 7, 12);		// 숫자
						if (Number[j] <= 10)
							printf("%d", Number[j]);
						else if (Number[j] == 11)
							printf("J");
						else if (Number[j] == 12)
							printf("Q");
						else if (Number[j] == 13)
							printf("K");
						else if (Number[j] == 14)
							printf("A");

						l++;
					}

					Set_Color(15);
				}
			}
		}

		switch (point)						// 결과
		{
		case 0:
			gotoxy(3, 22); printf("노 페어입니다.");
			gotoxy(3, 24); printf("배팅금 %d 만 원을 잃었습니다.", (bet1 + bet2));
			break;

		case 1:
			gotoxy(39, 7); printf("원 페어..");
			gotoxy(3, 22); printf("원 페어입니다.");
			Money += (float)((bet1 + 0.8 * bet2) * 0.5);
			gotoxy(3, 24); printf("%.2lf 만 원을 돌려받았습니다.", ((bet1 + 0.8 * bet2) * 0.5));
			break;

		case 2:
			gotoxy(39, 7); printf("투 페어");
			gotoxy(3, 22); printf("투 페어입니다.");
			Money += (float)((bet1 + 0.8 * bet2) * 0.9);
			gotoxy(3, 24); printf("%.2lf 만 원을 돌려받았습니다.", ((bet1 + 0.8 * bet2) * 0.9));
			break;

		case 3:
			gotoxy(39, 7); printf("트리플~");
			gotoxy(3, 22); printf("트리플입니다.");
			Money += (float)((bet1 + 0.8 * bet2) * 3);
			gotoxy(3, 24); printf("%.2lf 만 원을 획득했습니다.", ((bet1 + 0.8 * bet2) * 3.0));
			break;

		case 4:
			gotoxy(39, 7); printf("풀 하우스~~~");
			gotoxy(3, 22); printf("풀 하우스입니다.");
			Money += (float)((bet1 + 0.8 * bet2) * 10);
			gotoxy(3, 24); printf("%.2lf 만 원을 획득했습니다.", ((bet1 + 0.8 * bet2) * 10.0));
			break;

		case 13:
			gotoxy(39, 7); printf("풀 하우스~~~");
			gotoxy(3, 22); printf("풀 하우스입니다.");
			Money += (float)((bet1 + 0.8 * bet2) * 10);
			gotoxy(3, 24); printf("%.2lf 만 원을 획득했습니다.", ((bet1 + 0.8 * bet2) * 10.0));
			break;

		case 6:
			gotoxy(39, 7); printf("포 카드~~!!!!");
			gotoxy(3, 22); printf("포 카드입니다.");
			Money += (float)((bet1 + 0.8 * bet2) * 30);
			gotoxy(3, 24); printf("%.2lf 만 원을 획득했습니다.", ((bet1 + 0.8 * bet2) * 30.0));
			break;

		case 16:
			gotoxy(39, 7); printf("포 카드~~!!!!");
			gotoxy(3, 22); printf("포 카드입니다.");
			Money += (float)((bet1 + 0.8 * bet2) * 30);
			gotoxy(3, 24); printf("%.2lf 만 원을 획득했습니다.", ((bet1 + 0.8 * bet2) * 30.0));
			break;

		case 10:
			gotoxy(39, 7); printf("플러시~~");
			gotoxy(3, 22); printf("플러시입니다.");
			Money += (float)((bet1 + 0.8 * bet2) * 8);
			gotoxy(3, 24); printf("%.2lf 만 원을 획득했습니다.", ((bet1 + 0.8 * bet2) * 8.0));
			break;

		case 11:
			gotoxy(39, 7); printf("플러시~~");
			gotoxy(3, 22); printf("플러시입니다.");
			Money += (float)((bet1 + 0.8 * bet2) * 8);
			gotoxy(3, 24); printf("%.2lf 만 원을 획득했습니다.", ((bet1 + 0.8 * bet2) * 8.0));
			break;

		case 12:
			gotoxy(39, 7); printf("플러시~~");
			gotoxy(3, 22); printf("플러시입니다.");
			Money += (float)((bet1 + 0.8 * bet2) * 8);
			gotoxy(3, 24); printf("%.2lf 만 원을 획득했습니다.", ((bet1 + 0.8 * bet2) * 8.0));
			break;

		case 20:
			gotoxy(39, 7); printf("스트레이트~~");
			gotoxy(3, 22); printf("스트레이트입니다.");
			Money += (float)((bet1 + 0.8 * bet2) * 20);
			gotoxy(3, 24); printf("%.2lf 만 원을 획득했습니다.", ((bet1 + 0.8 * bet2) * 20.0));
			break;
		}

		gotoxy(0, 28); getch();
		Long_Clear();

		if (Money == 0)						// 0원
		{
			gotoxy(3, 21); printf("포커방에서 돈을 전부 잃으셨습니다 ㅠㅠ\n");
			Sleep(1000);
			break;
		}
		else if (Money < 1)
		{
			gotoxy(3, 21); printf("베팅 최소 금액보다 보유 금액이 모자랍니다....\n");
			Sleep(1000);
			break;
		}

		HP -= 6;
		if (HP <= 0)							// 체력
		{
			HP = 0;
			gotoxy(3, 21); printf("HP가 0이 되었습니다...\n");
			Sleep(1000);
			break;
		}

		Status();
		gotoxy(3, 22); printf("다시 하시겠습니까?");

		Small_Clear();
		while (1)							// 리
		{

			Poker_re = YN();
			if (Poker_re == 1 || Poker_re == 2)
				break;
		}

		Poker_Count++;
	}

	gotoxy(3, 24); printf("포커방 메인홀로 돌아갑니다.");
	ing(1);
}

void ShowCard(int N[], int T[], int C[])	// 카드 출력
{
	for (int i = 1; i <= 5; i++)
	{
		int a = 0;

		Set_Color(15);

		if (C[1] == 0 && C[2] == 0 && C[3] == 0 && C[4] == 0 && C[5] == 0)
		{
			C[1] = 1;									// 만약 카드 교체 전이면 전부 출력
			C[2] = 1;
			C[3] = 1;
			C[4] = 1;
			C[5] = 1;
		}

		if (C[i] == 1)									// 카드 교체 후엔 교체한 카드만 새로 출력
		{
			gotoxy(10 + 15 * (i - 1), 9);				// 위 문양 출력
			if (T[i] == 1)
				printf("%c%c", 0xa2, 0xbc);
			else if (T[i] == 2)
			{
				Set_Color(12);
				printf("%c%c", 0xa2, 0xbe);
			}
			else if (T[i] == 3)
			{
				Set_Color(12);
				printf("%c%c", 0xa1, 0xdf);
			}
			else if (T[i] == 4)
				printf("%c%c", 0xa2, 0xc0);

			gotoxy(13 + 15 * (i - 1), 13);			// 아래 문양 출력
			if (T[i] == 1)
				printf("%c%c", 0xa2, 0xbc);
			else if (T[i] == 2)
				printf("%c%c", 0xa2, 0xbe);
			else if (T[i] == 3)
				printf("%c%c", 0xa1, 0xdf);
			else if (T[i] == 4)
				printf("%c%c", 0xa2, 0xc0);

			gotoxy(12 + 15 * (i - 1), 11);			// 번호 출력
			if (N[i] <= 10)
				printf("\b%2d ", N[i]);
			if (N[i] == 11)
				printf("J ");
			if (N[i] == 12)
				printf("Q ");
			if (N[i] == 13)
				printf("K ");
			if (N[i] == 14)
				printf("A ");

			gotoxy(0, 28);
			Sleep(350);		// 350
		}
	}
	Set_Color(15);
}

void Poker_Five_Draw_1_inf()						// 파이브 드로우 포커 1 설명
{
	int Page = 1;
	int key;
	int Change = 1;

	Full_Clear();

	gotoxy(30, 22);
	printf("%c%c %c%c로 페이지 넘기기", 0xa1, 0xe7, 0xa1, 0xe6);
	gotoxy(30, 24);
	printf("스페이스 바, 엔터 키로 게임으로 돌아가기");

	while (1)
	{
		if (Change == 1)
		{
			Big_Clear();

			if (Page == 1)
			{
				Change = 0;

				gotoxy(3, 2);
				printf("이 게임은 5장을 받고 확인한 후 바꾸고 싶은 장 수만큼 한 번에 바꾼 후");
				gotoxy(3, 3);
				printf("족보와 패를 비교해 베팅 한 만큼의 돈을 얻는 1인용 파이브 카드 드로우 포커입니다.");

				gotoxy(3, 6);
				printf("게임 진행 과정");
				gotoxy(3, 8);
				printf("카드를 받고 첫 번째 베팅을 합니다.");
				gotoxy(3, 9);
				printf("그 후 바꿀 카드를 선택합니다.");
				gotoxy(3, 11);
				printf("새로 카드를 받고 오픈하기 전에 두 번째 베팅을 합니다.");
				gotoxy(3, 12);
				printf("이 두 번째 베팅은 베팅한 만큼 보유 금액에서 빠져나가지만");
				gotoxy(3, 13);
				printf("최종 베팅 금액에는 0.8배로 취급됩니다.");
				gotoxy(3, 15);
				printf("즉 최종 베팅 금액은 (첫 번째 베팅 금액 + 0.8 * 두 번째 베팅 금액)입니다.");


				gotoxy(3, 18);
				printf("포커 게임 한 판당 HP가 6씩 감소합니다.");

				gotoxy(75, 19);
				printf("Page 1/3");
			}

			if (Page == 2)
			{
				Change = 0;

				gotoxy(3, 2);
				printf("이 게임은 족보만 보고 숫자의 높낮이는 보지 않습니다.");
				gotoxy(3, 3);
				printf("아래는 이 게임의 족보입니다.");

				gotoxy(3, 5);
				printf("노 페어 : 아래에 언급되는 어느 족보에도 해당되지 않는 경우.");
				gotoxy(3, 6);
				printf("          베팅 한 만큼 돈을 잃습니다.");
				gotoxy(3, 8);
				printf("원 페어 : 숫자가 같은 카드 2장이 존재.");
				gotoxy(3, 9);
				printf("          베팅 한 금액의 0.5배를 돌려받습니다.");
				gotoxy(3, 11);
				printf("투 페어 : 원 페어가 2쌍 존재.");
				gotoxy(3, 12);
				printf("          베팅 한 금액의 0.9배를 돌려받습니다.");
				gotoxy(3, 14);
				printf("트리플 : 숫자가 같은 카드 3장이 존재.");
				gotoxy(3, 15);
				printf("         베팅 한 금액의 3배를 얻습니다.");
				gotoxy(3, 17);
				printf("스트레이트 : 숫자가 연속된 카드 5장.");
				gotoxy(3, 18);
				printf("             베팅 한 금액의 20배를 얻습니다.");

				gotoxy(75, 19);
				printf("Page 2/3");
			}

			if (Page == 3)
			{
				Change = 0;

				gotoxy(3, 2);
				printf("플러시 : 숫자 상관없이 무늬가 같은 카드 5장.");
				gotoxy(3, 3);
				printf("         베팅 한 금액의 8배를 얻습니다.");
				gotoxy(3, 5);
				printf("풀 하우스 : 트리플과 원 페어가 같이 존재.");
				gotoxy(3, 6);
				printf("           베팅 한 금액의 10배를 얻습니다~");
				gotoxy(3, 8);
				printf("포카드 : 숫자가 같은 카드 4장.");
				gotoxy(3, 9);
				printf("         베팅 한 금액의 30배를 얻습니다 ~~!!");

				gotoxy(75, 19);
				printf("Page 3/3");
			}
		}

		//	printf("스트레이트 플러시 : 숫자가 연속되고 무늬가 같은 카드 5장\n");
		//	printf("로열 스트레이트 플러시 : 무늬가 같은 A, K, Q, J, 10\n");

		gotoxy(0, 28);
		key = getch();
		if (key == 224)
		{
			key = getch();
			if (key == 75)
			{
				if (1 < Page && Page <= 3)
				{
					Page--;
					Change = 1;
				}
			}
			if (key == 77)
			{
				if (1 <= Page && Page < 3)
				{
					Page++;
					Change = 1;
				}
			}
		}

		if (key == 32 || key == 13)
			break;
	}
	ing(0.5);
}


// 로또 함수
void Lottery()									// 로또
{
	int Lottery_re = 1;
	int Lottery[6];

	int i;
	PlaySound(TEXT("복권방.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	Big_Clear();
	Long_Clear();
	Loading_Clear();
	gotoxy(2, 1);
	printf("복권방에 입장했습니다");
	Sleep(500);
	gotoxy(2, 3);
	printf("설명을 보시겠습니까?");
	while (1)								// 설명
	{
		i = YN();

		if (i == 1)
			Lottery_inf();

		if (i == 1 || i == 2)
			break;
	}

	while (Lottery_re == 1)					// 반복 게임
	{
		Big_Clear();
		Long_Clear();
		Loading_Clear();
		gotoxy(2, 1);
		printf("현재 보유 %.2lf 만 원 \n", Money);
		gotoxy(2, 2);
		printf("HP : %d\n\n", HP);
		gotoxy(2, 3);
		printf("5개 한장에 10만 원\n");
		gotoxy(2, 21);
		printf("구매 ?");
		while (1)
		{
			Small_Clear();
			gotoxy(90, 23);
			i = YN();
			if (i == 1 || i == 2)
				break;
		}

		if (i == 2)							// 안 사면 나감
			break;
		Money -= 10;

		for (i = 1; i <= 5; i++)				// 랜덤		
			Lottery[i] = rand() % 1000 + 1;

		for (i = 1; i <= 5; i++)				// 등수 출력
		{
			if (Lottery[i] <= 450)
			{
				gotoxy(2, 4+i); printf("꽝\n");
			}

			else if (Lottery[i] <= 749)
			{
				gotoxy(2, 4 + i); printf("6등\n");
				Money += 0.5;
			}

			else if (Lottery[i] <= 909)
			{
				gotoxy(2, 4 + i); printf("5등\n");
				Money += 3;
			}

			else if (Lottery[i] <= 959)
			{
				gotoxy(2, 4 + i); printf("4등\n");
				Money += 8;
			}

			else if (Lottery[i] <= 989)
			{
				gotoxy(2, 4 + i); printf("3등~\n");
				Money += 50;
			}

			else if (Lottery[i] <= 999)
			{
				gotoxy(2, 4 + i); printf("2등~~\n");
				Money += 300;
			}

			else if (Lottery[i] == 1000)
			{
				gotoxy(2, 4 + i); printf("1등~~~!!\n");
				Money += 1000;
			}
		}

		if (Money < 10)						// 돈 없음
		{
			gotoxy(2, 21);
			printf("로또 가격보다 보유 금액이 적습니다 ㅠㅠ\n");
			Sleep(2000);
			break;
		}
		HP -= 3;
		Status();
		if (HP <= 0)							// 체력
		{
			HP = 0;
			Status();
			gotoxy(2, 21);
			printf("HP가 0이 되었습니다...\n");
			Sleep(2000);
			break;
		}

		gotoxy(2, 13);
		printf("게임 후 보유 %.2lf 만 원 \n", Money);
		gotoxy(2, 14);
		printf("HP : %d\n\n", HP);
		while (1)							// 리
		{
			Long_Clear();
			gotoxy(2, 21);
			
			printf("다시 하시겠습니까?\n");
			Small_Clear();
			gotoxy(90, 23);
			Lottery_re = YN();
			if (Lottery_re == 1 || Lottery_re == 2)
				break;
		}
	}
	Long_Clear();
	gotoxy(2, 21);
	printf("복권방을 퇴장합니다");
	ing(3);
	PlaySound(TEXT("마피아 브금.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
}

void Lottery_inf()							// 설명
{
	Small_Clear();
	Big_Clear();
	Long_Clear();
	Loading_Clear();
	gotoxy(2, 1);
	printf("5개에 한 장인 종이를 10만 원에 살 수 있습니다.\n");
	gotoxy(2, 3);
	printf("아래는 각 등수에 걸릴 확률과 당첨금입니다.\n\n");
	gotoxy(2, 5);
	printf("1등 0.1 %%  1000만 원\n");
	gotoxy(2, 6);
	printf("2등 1   %%   300만 원\n");
	gotoxy(2, 7);
	printf("3등 3   %%    50만 원\n");
	gotoxy(2, 8);
	printf("4등 5   %%     8만 원\n");
	gotoxy(2, 9);
	printf("5등 11  %%     3만 원\n");
	gotoxy(2, 10);
	printf("6등 25  %%   0.5만 원\n\n");
	gotoxy(2, 11);
	printf("꽝  54.9%%\n\n");
	gotoxy(2, 13);
	printf("로또 한 장을 긁는데 HP가 3 소모됩니다.\n\n\n");
	gotoxy(2, 15);
	printf("아무 버튼이나 눌러 복권방으로\n");
	getch();
	Sleep(100);
}


// 금 거래소 함수
void Gold_Store(float Price, int* Have)			// 금 거래소
{
	int Gold_re = 1;
	int trade = 0;

	int i;

	Big_Clear();
	Long_Clear();
	Loading_Clear();
	Small_Clear();
	gotoxy(2, 1);
	printf("금 거래소에 입장했습니다\n\n");
	Sleep(500);
	gotoxy(2, 21);
	printf("설명을 보시겠습니까?\n");
	while (1)								// 설명
	{
		i = YN();

		if (i == 1)
			Gold_inf();

		if (i == 1 || i == 2)
			break;
	}


	while (Gold_re == 1)
	{
		Big_Clear();
		Long_Clear();
		Loading_Clear();
		Small_Clear();
		gotoxy(2, 1);
		printf("현재 보유 %.2lf 만 원 \n", Money);
		gotoxy(2, 2);
		printf("HP : %d\n", HP);
		gotoxy(2, 3);
		printf("금괴 %d개 보유중\n\n", *Have);
		gotoxy(2, 4);
		printf("현재 금괴 1개의 구매 가격은 %.2lf 만 원\n", Price);
		gotoxy(2, 5);
		printf("                판매 가격은 %.2lf 만 원입니다\n\n", Price * 0.8);

		while (1)								// 선택
		{
			gotoxy(2, 7);
			printf("구매 1, 판매 2, 나가기 3 : ");
			scanf("%d", &i);

			if (i == 1 || i == 2 || i == 3)
				break;
			else continue;
		}



		switch (i)								// 각각 구매 판매 나가기
		{
		case 1:								// 구매	
			if (Money < Price)			// 돈이 없을 경우 구매 불가
			{
				gotoxy(2, 11);
				printf("현재 금괴의 가격보다 보유 금액이 적어 구매할 수 없습니다.");
				ing(2);
				break;
			}
			while (1)
			{
				i = (Money / Price);
				gotoxy(2, 11);
				printf("%d개까지 구매 가능합니다.", i);
				gotoxy(2, 12);
				printf("몇 개 구매하시겠습니까? (0 입력시 취소)\n");
				gotoxy(2, 13);
				printf("구매 : ");
				scanf("%d", &trade);

				if (trade == 0)
					break;
				if (trade <= i)
					break;
				gotoxy(2, 15);
				printf("돈이 모자라 그만큼 살 수 없습니다 !\n");
				ing(2);
			}

			Money -= (float)(Price * trade);
			*Have += trade;
			HP -= (trade * 3);

			if (trade != 0) {
				gotoxy(2, 15);
				printf("%.2lf 만 원으로 %d개 구매하셨습니다.\n", Price * trade, trade);
			}
			break;

		case 2:								// 판매
			if (*Have == 0)						// 가지고 있는 게 없으면 돌아감
			{
				gotoxy(2, 11);
				printf("보유중인 금괴가 없습니다..");
				ing(0.8);
				continue;
			}

			while (1)
			{
				gotoxy(2, 11);
				printf("몇 개 판매하시겠습니까? (0 입력시 취소)\n");
				gotoxy(2, 12);
				printf("판매 : ");
				scanf("%d", &trade);

				if (trade <= *Have)
					break;
			}

			if (trade == 0)
				break;

			Money += (float)(Price * trade);
			*Have -= trade;
			HP -= (trade * 3);
			gotoxy(2, 15);
			printf("%d개를 판매해", trade);
			gotoxy(2, 16);
			printf("% .2lf 만 원을 받으셨습니다.\n",Price * trade);

			break;

		case 3:
			Gold_re = 2;
		}

		if (HP <= 0)							// 체력
		{
			HP = 0;
			gotoxy(2, 21);
			printf("HP가 0이 되었습니다...\n");
			Sleep(2000);
			break;
		}

		while (i != 3)							// 금 거래소 리
		{
			i = YN();

			if (i == 1)
				Gold_re = 2;

			if (i == 1 || i == 2)
				break;
		}
	}
	Long_Clear();
	gotoxy(2, 21);
	printf("금 거래소를 퇴장합니다");
	ing(3);
}

void Gold_Change(float* Price, int* Big)		// 금괴 가격 변동
{
	int i = 0;
	int P_M;

	int one;			// 100의 자리
	int two;			// 10의 자리
	int three;			// 1의 자리
	float four;			// 0.1의 자리
	float five;			// 0.01의 자리

	float total = 0;

	if (*Big == 0)						// 대폭락
		i = rand() % 10 + 1;

	if (i == 10)							// ----
		*Big = 3;
	if (i == 3)
		*Big = 10;


	if (*Big == 0)						// 무난하게 랜덤
	{
		i = rand() % 11 + 1;

		if (i % 2 == 1)
			P_M = 1;
		if (i % 2 == 0)
			P_M = -1;
	}

	one = rand() % 3;
	two = rand() % 10;
	three = rand() % 10;
	four = rand() % 10;
	five = rand() % 10;


	if (*Big != 0)					// 대폭락
	{
		if (*Big <= 3)				// ----
		{
			one = 2;
			P_M = -1;
			*Big -= 1;
		}

		if (*Big == 10)				// ++++
		{
			one = 5;
			P_M = 1;
		}

	}

	total += (float)(P_M) * ((one * 100) + (two * 10) + (three * 1) + (four * 0.1) + (five * 0.01));

	*Price += total;
	if (*Price < 500)
		*Price = 500;
}

void Gold_inf()								// 설명
{
	Big_Clear();
	Long_Clear();
	Loading_Clear();
	Small_Clear();
	gotoxy(2, 1);
	printf("처음 금괴 한 개의 가격은 1000만 원이지만\n");
	gotoxy(2, 2);
	printf("날이 지날 때마다 랜덤하게 금괴의 가격이 변동합니다.\n");
	gotoxy(2, 3); 
	printf("금괴의 가격은 500만 원 아래로는 내려가지 않습니다.\n");
	gotoxy(2, 4); 
	printf("변동 가격은 -299.99 ~ +299.99 중 랜덤으로 선택됩니다.\n\n");
	gotoxy(2, 5); 
	printf("낮은 확률로 금괴 대폭락 이벤트가 발생합니다.\n");
	gotoxy(2, 6); 
	printf("발생할 경우 3일 동안 금괴의 가격이 3~400만 원씩 떨어집니다.\n");
	gotoxy(2, 7); 
	printf("갑자기 가격이 뛰는 경우도 있습니다.\n");
	gotoxy(2, 8); 
	printf("금괴의 가격은 금 거래소에서만 확인할 수 있습니다.\n");
	gotoxy(2, 9); 
	printf("팔 때는 수수료 때문에 0.8배로 파실 수 있습니다\n\n");
	gotoxy(2, 10);
	printf("한 개의 금괴를 사고팔 때마다 HP가 3씩 감소합니다.\n\n\n");
	gotoxy(2, 12);
	printf("아무 버튼이나 눌러 금 거래소로\n");
	getch();
	Sleep(100);
}


// 경마장 함수
void Race()										// 경마장
{
	int i;

	int Race_re = 1;
	int Race_Count = 1;				// 경마 카운팅

	int Horse_Select;
	int Horse_Win = 0;
	int WW = 0;

	int bet;

	PlaySound(TEXT("경마장.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	Big_Clear();
	Small_Clear();
	Long_Clear();
	Loading_Clear();
	gotoxy(2, 1);
	printf("경마장에 입장했습니다\n\n");
	Sleep(500);
	gotoxy(2, 21);
	printf("설명을 보시겠습니까?\n");
	while (1)								// 설명
	{
		i = YN();

		if (i == 1)
			Race_inf();

		if (i == 1 || i == 2)
			break;
	}

	while (Race_re == 1)
	{
		WW = 0;

		Big_Clear();
		Small_Clear();
		Long_Clear();
		Loading_Clear();
		gotoxy(2, 1);
		printf("현재 보유 %.2lf 만 원 \n", Money);
		gotoxy(2, 2); 
		printf("HP : %d\n\n", HP);
		gotoxy(2, 3);
		printf("%d번 째 게임입니다.\n", Race_Count);
		gotoxy(2, 4);
		printf("몇 번 말을 선택하시겠습니까?\n");					// 말 선택
		while (1)
		{
			gotoxy(2, 5);
			printf("<1번말> <2번말> <3번말>");
			gotoxy(2, 6);
			printf("                               ");
			gotoxy(2, 6);
			printf("(0 입력시 취소) : ");
			scanf("%d", &Horse_Select);

			if (0 <= Horse_Select && Horse_Select <= 3)
				break;
			else continue;
		}
		if (Horse_Select == 0) break;
		gotoxy(2, 8);
		printf("%d번 말에 얼마나 베팅하시겠습니까?\n", Horse_Select);					// 베팅
		while (1)
		{
			gotoxy(2, 9); 
			printf("(0입력시 취소) : ");
			scanf("%d", &bet);

			if (0 <= bet && bet <= Money)
				break;
		}
		if (bet == 0)
			break;
		Money -= bet;
		Horse_Win = Race_Start(Horse_Select);
		gotoxy(2, 10);
		if (Horse_Win <= 3)
			printf("%d번 말이 1등입니다.", Horse_Win);
		if (Horse_Win == 12)
			printf("1번 말과 2번 말이 공동 1등입니다.");
		if (Horse_Win == 13)
			printf("1번 말과 3번 말이 공동 1등입니다.");
		if (Horse_Win == 23)
			printf("2번 말과 3번 말이 공동 1등입니다.");
		if (Horse_Win == 33)
			printf("1번 말과 2번 말과 3번 말이 공동 1등입니다.");
		printf("\n\n\n");

		gotoxy(2, 11);
		if (Horse_Select == 1 && Horse_Win == 12)		// 공동 1등
		{
			printf("1등 말을 맞추셨습니다 !!\n");
			gotoxy(2, 12); 
			printf("1번말의 배당 : 3배\n");
			gotoxy(2, 13);
			printf("%.1f만원을 배팅하여 추가로 %.2f 만 원을 획득했습니다 !\n\n", float(bet), float(bet * 3) - bet);
			Money += (float)(bet * 3);
			WW = 1;
		}

		else if (Horse_Select == 1 && Horse_Win == 13)
		{
			printf("1등 말을 맞추셨습니다 !!\n");
			gotoxy(2, 12);
			printf("1번말의 배당 : 3배\n");
			gotoxy(2, 13);
			printf("%.1f만원을 배팅하여 추가로 %.2f 만 원을 획득했습니다 !\n\n", float(bet), float(bet * 3) - bet);
			Money += (float)(bet * 3);
			WW = 1;
		}

		else if (Horse_Select == 2 && Horse_Win == 12)
		{
			printf("1등 말을 맞추셨습니다 !!\n");
			gotoxy(2, 12);
			printf("2번말의 배당 : 2배\n");
			gotoxy(2, 13);
			printf("%.1f만원을 배팅하여 추가로 %.2f 만 원을 획득했습니다 !\n\n", float(bet), float(bet * 2) - bet);
			Money += (float)(bet * 2);
			WW = 1;
		}

		else if (Horse_Select == 2 && Horse_Win == 23)
		{
			printf("1등 말을 맞추셨습니다 !!\n");
			gotoxy(2, 12);
			printf("2번말의 배당 : 2배\n");
			gotoxy(2, 13);
			printf("%.1f만원을 배팅하여 추가로 %.2f 만 원을 획득했습니다 !\n\n", float(bet), float(bet * 2) - bet);
			Money += (float)(bet * 2);
			WW = 1;
		}

		else if (Horse_Select == 3 && Horse_Win == 13)
		{
			printf("1등 말을 맞추셨습니다 !!\n");
			gotoxy(2, 12);
			printf("3번말의 배당 : 1.5배\n");
			gotoxy(2, 13);
			printf("%.1f만원을 배팅하여 추가로 %.2f 만 원을 획득했습니다 !\n\n", float(bet), float(bet * 1.5) - bet);
			Money += (float)(bet * 1.5);
			WW = 1;
		}

		else if (Horse_Select == 3 && Horse_Win == 23)
		{
			printf("1등 말을 맞추셨습니다 !!\n");
			gotoxy(2, 12);
			printf("3번말의 배당 : 1.5배\n");
			gotoxy(2, 13);
			printf("%.1f만원을 배팅하여 추가로 %.2f 만 원을 획득했습니다 !\n\n", float(bet),float(bet*1.5)-bet);
			Money += float(bet*1.5);
			WW = 1;
		}

		if (Horse_Select == Horse_Win)
		{
			WW = 0;
			if (Horse_Select == 1)						// 1번 승	
			{
				printf("1등 말을 맞추셨습니다 !!\n");
				gotoxy(2, 12);
				printf("1번말의 배당 : 3배\n");
				gotoxy(2, 13);
				printf("%.1f만원을 배팅하여 추가로 %.2f 만 원을 획득했습니다 !\n\n", float(bet), float(bet * 1.5) - bet);
				Money += (float)(bet * 3);
				WW = 1;
			}

			if (Horse_Select == 2)						// 2번 승
			{
				printf("1등 말을 맞추셨습니다 !!\n");
				gotoxy(2, 12); 
				printf("2번말의 배당 : 2배\n");
				gotoxy(2, 13);
				printf("%.1f만원을 배팅하여 추가로 %.2f 만 원을 획득했습니다 !\n\n", float(bet), float(bet * 2) - bet);
				Money += (float)(bet * 2);
				WW = 1;
			}

			if (Horse_Select == 3)						// 3번 승
			{
				printf("1등 말을 맞추셨습니다 !!\n");
				gotoxy(2, 12);
				printf("3번말의 배당 : 1.5배\n");
				gotoxy(2, 13);
				printf("%.1f만원을 배팅하여 추가로 %.2f 만 원을 획득했습니다 !\n\n", float(bet), float(bet * 1.5) - bet);
				Money += (float)(bet * 1.5);
				WW = 1;
			}
		}
		if (Horse_Select == 3 && Horse_Win == 33) {
			printf("1등 말을 맞추셨습니다 !!\n");
			gotoxy(2, 12);
			printf("3번말의 배당 : 1.5배\n");
			gotoxy(2, 13);
			printf("%.1f만원을 배팅하여 추가로 %.2f 만 원을 획득했습니다 !\n\n", float(bet), float(bet * 1.5) - bet);
			Money += (float)(bet * 1.5);
			WW = 1;
		}
		else if (Horse_Select == 2 && Horse_Win == 33) {
			printf("1등 말을 맞추셨습니다 !!\n");
			gotoxy(2, 12);
			printf("2번말의 배당 : 2배\n");
			gotoxy(2, 13);
			printf("%.1f만원을 배팅하여 추가로 %.2f 만 원을 획득했습니다 !\n\n", float(bet), float(bet * 1.5) - bet);
			Money += (float)(bet * 2);
			WW = 1;
		}
		else if (Horse_Select == 1 && Horse_Win == 33) {
			printf("1등 말을 맞추셨습니다 !!\n");
			gotoxy(2, 12);
			printf("1번말의 배당 : 3배\n");
			gotoxy(2, 13);
			printf("%.1f만원을 배팅하여 추가로 %.2f 만 원을 획득했습니다 !\n\n", float(bet), float(bet * 1.5) - bet);
			Money += (float)(bet * 3);
			WW = 1;
		}
		if (WW == 0)
		{
			gotoxy(2, 11);
			printf("1등 말을 맞추지 못하였습니다..\n\n");			// 패배
		}

		HP -= 5;

		if (Money == 0)									// 0원
		{
			gotoxy(2, 15);
			printf("경마장에서 돈을 전부 잃으셨습니다 ㅠㅠ\n");
			Status();
			Sleep(2000);
			break;
		}
		else if (Money < 1)
		{
			gotoxy(2, 15);
			printf("베팅 최소 금액보다 보유 금액이 모자랍니다....\n");
			Status();
			Sleep(2000);
			break;
		}
		if (HP <= 0) {
			HP = 0;
			gotoxy(2, 21);
			printf("HP가 0입니다...");
			Sleep(1300);
			break;
		}
		gotoxy(2, 16);
		printf("게임 후 보유 %.2lf 만 원 \n", Money);
		gotoxy(2, 17);
		printf("HP : %d\n", HP);
		Status();
		while (1)							// 리
		{
			gotoxy(2, 21);
			printf("다시 하시겠습니까?\n");
			Race_re = YN();
			if (Race_re == 1 || Race_re == 2)
				break;
		}
		if(Race_re==1)
			PlaySound(TEXT("경마장.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
		Race_Count++;
	}
	gotoxy(2, 21);
	printf("경마장을 퇴장합니다");
	ing(3);
	PlaySound(TEXT("마피아 브금.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
}

void Race_inf()								// 설명
{
	Big_Clear();
	Small_Clear();
	Long_Clear();
	Loading_Clear();
	gotoxy(2, 1);
	printf("세 마리의 말 중에 어떤 말이 가장 먼저 들어오나 맞추는 게임입니다.\n");
	gotoxy(2, 2);
	printf("트랙은 총 30칸으로 이루어져 있으며");
	gotoxy(2, 3);
	printf("2초마다 0~5칸씩 랜덤으로 움직입니다.\n");
	gotoxy(2, 4);
	printf("좀 더 빠르게 들어오는 말이 1위 판정을 가집니다.\n");
	gotoxy(2, 5);
	printf("동시에 들어올 경우 공동 1위로 칩니다.\n\n");
	gotoxy(2, 7);
	printf("각각 말은 턴당 최대 속도가 조금 다릅니다.\n");
	gotoxy(2, 9);
	printf("1번 말은 0~4칸\n");
	gotoxy(2, 10);
	printf("2번 말은 0~5칸\n");
	gotoxy(2, 11); 
	printf("3번 말은 0~6칸\n");
	gotoxy(2, 13);
	printf("1등 말을 맞출 경우 각각 베팅 금액의 3배, 2배, 1.5배를 획득합니다.\n\n");
	gotoxy(2, 14);
	printf("경마 한 게임당 HP가 5씩 감소합니다.\n\n");
	gotoxy(2, 16);
	printf("아무 버튼이나 눌러 경마장으로\n");
	getch();
	Sleep(100);
}

int Race_Start(int Select)					// 경마 시작
{
	int i;
	int j;
	int Win = 0;

	//	int HM;
	int Horse[4] = { 0, 0, 0, 0 };

	PlaySound(TEXT("환호.wav"), NULL, SND_FILENAME | SND_ASYNC);
	while (Win == 0)
	{
		int Fast[4] = { 0, 0, 0, 0 };

		Big_Clear();
		Small_Clear();
		Long_Clear();
		Loading_Clear();								// 보드 초기화

		gotoxy(2, 1);
		printf("S----------------------------F\n");	// 30칸

		for (i = 1; i <= 3; i++)
		{
			if (i == 1)												// 1번 말은
			{
				Fast[1] = rand() % 5;									// 0칸 ~ 4칸
				Horse[1] += Fast[1];
				if (Fast[1] != 0 && Fast[1] != 4)
					Fast[1] = 1;
			}
			if (i == 2)												// 2번 말은
			{
				Fast[2] = rand() % 6;									// 0칸 ~ 5칸
				Horse[2] += Fast[2];
				if (Fast[2] != 0 && Fast[2] != 5)
					Fast[2] = 1;
			}
			if (i == 3)												// 3번 말은
			{
				Fast[3] = rand() % 7;									// 0칸 ~ 6칸
				Horse[3] += Fast[3];
				if (Fast[3] != 0 && Fast[3] != 6)
					Fast[3] = 1;
			}
			gotoxy(2, 1+i);
			for (j = 1; j <= Horse[i]; j++)							// 칸 이동
				printf(" ");
			if (Horse[i] >= 30)										// 결승 선은 못 넘음
			{
				for (j = 30; j <= Horse[i]; j++)
					printf("\b");
			}

			printf("%d", i);

			if (Horse[i] >= 29)										// 결승 선 통과
				printf("★\n");
		}
		gotoxy(2, 5);
		printf("S----------------------------F");	// 30칸	
		if (Horse[1] >= 29 || Horse[2] >= 29 || Horse[3] >= 29)		// 승리 조건
		{
			if (Horse[1] >= 29) Horse[1] = 29;
			if (Horse[2] >= 29) Horse[2] = 29;
			if (Horse[3] >= 29) Horse[3] = 29;
			if (Horse[1] == Horse[2] && Horse[1]==29)							// 1&2 공동
				Win = 12;

			if (Horse[1] == Horse[3] && Horse[1] == 29)							// 1&3 공동
				Win = 13;

			if (Horse[2] == Horse[3] && Horse[2] == 29)							// 2&3 공동
				Win = 23;

			if (Horse[2] == Horse[3] && Horse[3] == Horse[1])
				Win = 33;

			if (Horse[1] > Horse[2] && Horse[1] > Horse[3])		// 1번 말 승리
				Win = 1;

			if (Horse[2] > Horse[1] && Horse[2] > Horse[3])		// 2번 말 승리
				Win = 2;

			if (Horse[3] > Horse[1] && Horse[3] > Horse[2])		// 3번 말 승리
				Win = 3;
		}

		for (i = 1; i <= 3; i++)
		{
			if (Win == 0 && Fast[i] > 3) {
				gotoxy(2, 6);
				printf("%d번 말이 빠르게 질주합니다 !!", i);
			}
			else if (Win == 0 && Fast[i] == 0){
				gotoxy(2, 7);
				printf("%d번 말이 기어갑니다....\n", i);
			}
		}
		Sleep(850);										// 라운드마다 확인
	}

	return Win;
}



// 시설
	// 호텔 함수
void Hotel()
{
	int Hotel_Count = 0;		// 호텔 날짜 카운팅
	int i;
	l = 0;
	Big_Clear();
	Long_Clear();
	Loading_Clear();
	gotoxy(2, 1);
	printf("호텔에 입장했습니다\n\n");
	Sleep(500);

	gotoxy(2, 2);
	printf("현재 보유 %.2lf 만 원 \n", Money);
	gotoxy(2, 3);
	printf("HP : %d\n", HP);
	gotoxy(2, 21);
	printf("호텔에서 휴식을 취하시겠습니까?\n");
	gotoxy(2, 5);
	printf("하루 쉬고 HP+50, 돈 - 100 만\n");
	while (1)
	{
		i = YN();

		if (i == 1)
		{	
			Long_Clear();
			gotoxy(2, 21);
			printf("휴식중...");
			ing(1);
			Day++;
			Status();
			Loading_Clear();
			HP += 50;
			if (HP > 100)
				HP = 100;

			Money -= 100;

			
			Long_Clear();
		}

		if (i == 2)
			break;

		if (Money < 100)
		{
			gotoxy(2, 21);
			printf("돈이 없어서 호텔에 더 머무를 수 없습니다.\n");
			break;
		}
		else if (HP == 100) {
			l = 1;
			break;
		}
		Big_Clear();
		Long_Clear();
		Loading_Clear();
		gotoxy(2, 1);
		printf("호텔에 입장했습니다\n\n");

		gotoxy(2, 2);
		printf("현재 보유 %.2lf 만 원 \n", Money);
		gotoxy(2, 3);
		printf("HP : %d\n", HP);
		gotoxy(2, 5);
		printf("하루 쉬고 HP+50, 돈 - 100 만\n");
		gotoxy(2, 21);
		printf("하루 더 쉬시겠습니까?\n");
		Status();
	}
	if (l == 1) {
		Big_Clear();
		Long_Clear();
		Loading_Clear();
		gotoxy(2, 1);
		gotoxy(2, 1);
		printf("현재 보유 %.2lf 만 원 \n", Money);
		gotoxy(2, 2);
		printf("HP : %d\n", HP);
		gotoxy(2, 4);
		printf("하루 쉬고 HP+50, 돈 - 100 만\n");
		gotoxy(2, 21);
		printf("HP가 모두 회복되었습니다. ");
		Day++;
		Status();
		Sleep(850);
		Loading_Clear();
		
	}
	Long_Clear();
	gotoxy(2, 21);
	printf("호텔에서 퇴장합니다");
	ing(3);

}
// 부동산
void Real_Estate()
{
	int i;
	int Real_Estate_re = 1;

	Big_Clear();
	Long_Clear();
	Loading_Clear();
	Status();
	gotoxy(2, 1);
	printf("부동산에 입장했습니다\n\n");
	Sleep(500);
	gotoxy(2, 3);
	printf("설명을 보시겠습니까?\n");
	while (1)								// 설명
	{
		i = YN();

		if (i == 1)
			Real_Estate_inf();

		if (i == 1 || i == 2)
			break;
	}

	while (Real_Estate_re == 1)
	{
		Big_Clear();
		Edge();
		gotoxy(2, 1);
		printf("현재 보유 %.2lf 만 원\n\n", Money);
		switch (House_Have)
		{
		case 0:								// 집 구매
			gotoxy(2, 3);
			printf("집을 구매하시겠습니까?\n");
			gotoxy(2, 4);
			printf("가격 2000 만 원\n");
			while (1)						// 선택
			{
				i = YN();

				if (i == 1 || i == 2)
					break;
			}

			if (i == 1)
			{
				if (Money < 2000)
				{
					gotoxy(2, 21);
					printf("돈이 모자라 집을 구매할 수 없습니다.\n");
					ing(1);
				}
				if (Money >= 2000)
				{
					gotoxy(2, 21);
					printf("2000 만 원으로 집을 구매하였습니다.\n");
					ing(1);
					House_Have = 1;
					Money -= 2000;
				}
			}
			break;

		case 1:
			gotoxy(2, 3);
			printf("집을 판매하시겠습니까?\n");
			gotoxy(2, 4);
			printf("가격 2000 만 원\n");
			while (1)						// 판매
			{
				i = YN();

				if (i == 1 || i == 2)
					break;
			}
			if (i == 1)
			{
				gotoxy(2, 21);
				printf("집을 판매해 2000 만 원을 획득했습니다.\n");
				ing(1);
				House_Have = 0;
				Money += 2000;
			}
			break;
		}
		Big_Clear();
		Long_Clear();
		Loading_Clear();
		Edge();
		gotoxy(2, 1);
		printf("부동산을 퇴장하시겠습니까 ? \n");
		while (1)							// 부동산 리
		{
			i = YN();

			if (i == 1)
				Real_Estate_re = 2;

			if (i == 1 || i == 2)
				break;
		}
	}
	Loading_Clear();
	gotoxy(2, 23);
	printf("부동산을 퇴장합니다");
	ing(1);
	system("cls");
}

void Real_Estate_inf()
{
	Big_Clear();
	Small_Clear();
	Long_Clear();
	Status();
	Edge();
	gotoxy(2, 1);
	printf("부동산에서는 자신만의 집을 구매할 수 있습니다.\n");
	gotoxy(2, 3);
	printf("집은 한 종류밖에 없습니다.\n");
	gotoxy(2, 5);
	printf("돈이 없을 때 집을 팔 수도 있습니다.\n\n");
	gotoxy(2, 7);
	printf("집은 HP를 최대로 회복시켜줍니다.\n\n");
	gotoxy(2, 9);
	printf("아무 버튼이나 눌러 부동산으로\n");
	getch();
	Sleep(100);
}

// 집
void House()
{
	int i;
	Small_Clear();
	Long_Clear();
	Loading_Clear();
	Big_Clear();
	gotoxy(2, 1);
	printf("집에 들어왔습니다");
	Sleep(500);
	gotoxy(2, 2);
	printf("현재 보유 %.2lf 만 원 \n", Money);
	gotoxy(2, 3);
	printf("HP : %d", HP);
	gotoxy(2, 4);
	printf("최대 HP : 100");
	gotoxy(2, 21);
	printf("집에서 휴식을 취하시겠습니까?\n");
	while (1)
	{
		i = YN();

		if (i == 1)
		{
			Long_Clear();
			gotoxy(2, 21);
			printf("휴식중...");
			ing(3);
			HP = 100;
		}

		break;
	}
	Status;
	Long_Clear();
	Loading_Clear();
	Small_Clear();
	gotoxy(2, 21);
	printf("충분한 휴식을 취했습니다.");
	Sleep(1200);
	Long_Clear();
	gotoxy(2, 21);
	printf("집에서 나갑니다");
	ing(3);

}