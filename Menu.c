/* // 초기 메뉴	
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
} */