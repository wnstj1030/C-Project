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