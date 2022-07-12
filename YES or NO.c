/* // 공통 알고리즘
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
} */