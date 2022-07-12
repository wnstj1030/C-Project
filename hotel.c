/* 	// 호텔 함수
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
 */