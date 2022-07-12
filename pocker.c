/* // 게임
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

			/*if (Type[1] == Type[2] && Type[1] == Type[3] && Type[1] == Type[4] && Type[1] == Type[5]) // 플러시
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
} */