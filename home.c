/* void House()
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

} */