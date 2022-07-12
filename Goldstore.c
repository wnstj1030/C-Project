/* // 금 거래소 함수
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
} */