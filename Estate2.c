/* void Real_Estate()
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
} */