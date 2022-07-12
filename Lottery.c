/* // 로또 함수
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
} */