/* void Gold_inf()								// 설명
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
} */