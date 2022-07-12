/* // 메인
int main()							// 메인 함수
{
	SetConsoleTitle(TEXT("GAMBLE TO WIN!!!"));
	int M_S;
	int Map = 1;
	int Map_1[21][43] = {
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}, // 벽
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,1,1,1,1,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,1,1,1,1,1,0,0,0,1},
	{1,0,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,0,0,1},
	{1,0,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,0,1},
	{1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,2,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,2,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, // 홀
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, // 홀
	{1,0,1,1,1,2,1,1,1,1,0,0,1,1,1,2,1,1,1,1,0,0,0,0,1,1,1,2,1,1,1,1,0,0,1,1,1,2,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1},
	{1,0,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,0,1},
	{1,0,0,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}  // 벽
	};

	int i, j;

	float Gold_Price = 1000;
	int Gold_B = 0;
	int x = 42;
	int y = 11;

	int Move;
	int Select;

	srand(time(NULL));
	cur();
	Set_Color(15);				// 글씨 색 흰색
	PlaySound(TEXT("마피아 브금.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	system("mode con cols=115 lines=29");	// 화면 크기 조절
	system("cls");
	Edge();

	First_Menu();					// 메인 메뉴에서 게임 설명 선택 가능

	while (1)
	{
		Day_f = 1;

		Full_Clear();

		if (0 < Gold_B && Gold_B < 3)				// 금괴 대폭락
		{
			gotoxy(3, 24);
			printf("금괴의 값이 폭락하는 중입니다!!\n\n");
		}
		if (Gold_B == 10)
		{
			gotoxy(3, 24);
			printf("금괴의 값이 갑자기 뛰었습니다!!!\n\n");
			Gold_B = 0;
		}

		if (Map == 1)				// 맵 1일 때 화면 그리기
		{
			i = 0xa1, j = 0xd9;
			gotoxy(40, 0);			// 별
			printf("%c%c%c%c%c%c", i, j, i, j, i, j);
			gotoxy(40, 20);
			Map_1_Draw();
		}

		M_S = 0;					// 메뉴 초기화

		gotoxy(x, y);
		printf("%c%c", 0xa1, 0xdc);

		while (M_S == 0)				// 메뉴 인식
		{
			Status();

			gotoxy(0, 28);
			Move = getch();

			if (Move == 27)				// ESC 입력시 종료
				exit(0);

			if (Move == 224)				// 방향키 인식
			{
				Move = getch();
				gotoxy(x, y);			// 지우기
				printf("  ");

				switch (Move)
				{
				case 72:			// 위
					if (Map == 1)
					{
						if (Map_1[y - 1][x / 2] != 1)
							y -= 1;
					}
					break;

				case 75:			// 왼쪽
					if (Map == 1)
					{
						if (Map_1[y][(x / 2) - 1] != 1)
							x -= 2;
					}
					break;

				case 77:			// 오른쪽
					if (Map == 1)
					{
						if (Map_1[y][(x / 2) + 1] != 1)
							x += 2;
					}
					break;

				case 80:			// 아래
					if (Map == 1)
					{
						if (Map_1[y + 1][x / 2] != 1)
							y += 1;
					}
					break;

				default:
					break;
				}
			}
			gotoxy(x, y);
			printf("%c%c", 0xa1, 0xdc);
			if (20 <= x / 2 && x / 2 <= 22 && y == 0)				// 위 쪽 통로
			{
				if (Map == 1)
				{
					gotoxy(3, 22);
					printf("게임을 포기해 종료하시겠습니까?");

					i = YN();

					if (i == 1) {
						system("cls");
						PlaySound(TEXT("루우우.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
						printf("BQBBBQBBBBBBBBQBQBQBQBQBQBBBBBQBQBQBQBQBQBQBQBQBQBQBQBQBBBQBQBBBQBQBQBQBQBQBBBQBQBQBQBQBQBQBQBQBQBQBQBQBQBQBBBQBQ\n");
						printf("BQBBBQBBBBBBBBBQBQBQBBBBBBBQBBBQBBBQBQBQBQBBBQBBBQBQBQBQBQBQBQBQBQBBBQBBBQBQBBBQBQBQBQBBBQBQBBBQBQBQBQBQBQBQBBBBB\n");
						printf("BQBBBQBBBBBBBBQBQBBBQBQBQBBBQBQBBBQBBBQBBBQBQBQBQBQBBBQBQBQBQBBBQBQBBBQBBBQBQBBBBBQBQBBBBBQBBBQBBBQBBBQBBBQBBBQBQ\n");
						printf("BQBBBQBBBBBBBBBQBQBQBBBQBBBBBQBBBBBQBBBBBQBBBQBQBQBQBQBQBQBBBQBQBBBBBQBBBQBBBQBBBQBQBQBQBBBQBBBBBQBBBQBQBBBQBQBQB\n");
						printf("BQBBBQBBBBBBBBBBQBBBQBQBQBQBBBQBQBQBQBQBQBQBQBBBBBQBQBBBQBQBQBBBQBBBBBQBQBBBBBQBQBQBQBBBQBBBQBQBBBBBQBQBQBQBQBQBQ\n");
						printf("BQBBBQBBBBBBBBBQBQBBBQBBBBBBBBBQBQBQBQBQBQBQBQBQBBBQBBBQBQBQBBBQBQBQBQBQBBBBBBBBBBBQBBBQBBBBBQBQBBBQBBBQBQBQBQBQB\n");
						printf("BQBBBQBBBBBBBBBBQBQBQBBBBBQBQBQBQBBBBBBBQBQBBBBBQBBBQBBBQBQBBBQBQBBBQBQBBBQBQBQBQBQBBBQBQBQBBBQBQBBBQBBBQBQBQBQBQ\n");
						printf("BQBBBQBBBBBBBBBQBQBQBBBBBQBQBBBQBQBBBQBQBQBBBQBQBQBQBBBQBQBBBBBBBBBBBBBBBBBQBQBQBQBQBBBBBQBQBQBBBBBQBQBBBQBQBQBBB\n");
						printf("BQBBBQBBBBBBBBBBQBQBQBBBQBBBQBQBQBBBBBBBQBQBQBBBQBQBQBBBQBBBBBQBQBQBBBBBBBQBQBBBBBBBBBQBQBQBQBBBQBQBQBQBBBBBBBQBQ\n");
						printf("BQBBBQBBBBBBBBBBBBBBBBBQBQBQBBBQBQBQBQBBBQBQBQBQBQBBBQBBBBBBBBBBBBBBBBBQBBBQBQBBBQBBBQBBBBBQBBBBBBBQBBBBBBBQBQBQB\n");
						printf("BQBBBQBBBBBBBBBBQBBBQBQBQBQBBBBBBBQBBBQBBBBBQBBBQBQBBBBBBBBBBBQBQBBBBBBBBBQBBBBBQBQBBBBBBBBBBBBBQBBBBBQBBBQBBBQBQ\n");
						printf("BQBBBQBBBBBBBBBQBQBBBQBQBBBBBBBBBQBBBBBBBQBBBBBQBBBBBQBBBBBQBBBQBBBBBBBBBBBBBBBQBBBBBBBBBBBBBQBBBBQBBQBQBQBQBQBQB\n");
						printf("QBBBQBBBBBBBBQBQBBBQBBBBBBB6;:r6BBBBBsUBBQBS2BBBBKsBR77;i:OBQQBBBOr:iDBB1JBBBB7EBJ7ri:wBOcr;rwBBBQBQBQBQBQBQBBBQB\n");
						printf("BQBBBQBBBBBBBBBBBBBQBQBQBBB: :L  QBBBa  ZQBB. 5BBB  B7 7ci:ZBQBBBL ,L. sBr RBBr BQ ,Li:wBr r7i  BBQQBQBBBQBQBQBQB\n");
						printf("BQBBBQBBBBBBBBBBQBQBQBQBQBO vBBBBBBBQ ;: BBB,  BB   BJ BQBBBBBQBB :BBB: BB .BB :BB pBBBBBL BQB; MBMBBBQBBBQBBBQBQ\n");
						printf("BQBBBQBBBBBBBBBQBQBBBBBBBBX QBP;75BB7 RK JBB,...r ; B1 ...BBBBBBR 5BBBw BBS B7 BBQ  . OBBL ..  BBBBQBQBQBBBQBQBQB\n");
						printf("BQBBBQBBBBBBBBBBQBBBQBQBBBg 7BB: :BB  :;  BB :B  BX QJ BBBBBBBBBB :BBB. BBB   LBQR QBBBBQL BBi BQBBBQBQBQBQBQBQBB\n");
						printf("BQBBBQBBBBBBBBBBBBBBBQBQBBB; :L  BB  QBQB .B  B7.Br B7 :i:.7BQBBBJ .r. UBBBP  BBBD  r:,;Br BBB  BQQBBBBQBQBQBQBBB\n");
						printf("BQBBBQBBBBBBBBQBQBBBQBQBQQBBD7:LBBBLGBBBBDsBaXBBBBEJBRsc77;1BBBBBBgr;rMBQBBB2gBBBBJs7riLBDsBQBDcRBMBQBBBQBBBQBQBB\n");
						printf("BQBBBQBBBBBBBBBQBBBQBQBQBBBQBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBQBBBBBQBQBBBBBBBBBBBQBQBQBQBBBBBQB\n");
						printf("BQBBBQBBBBBBBBQBQBBBQBQBQBBBBBBBBBBBBBQBBBBBBBBBBBBBBBQBBBBBQBQBBBBBBBBBQBQBBBBBBBBBBBBBBBBBBBBBBBBBBBQBQBBBBBQBB\n");
						printf("BQBBBQBBBBBBBBBQBQBQBBBQBBBQBQBQBQBQBBBQBQBBBBBBBQBQBQBBBQBQBBBBBQBQBBBQBQBBBBBQBQBBBBBBBBBQBQBBBQBQBQBBBQBQBQBBB\n");
						printf("BQBBBQBBBBBBBBQBQBBBQBQBQBQBQBQBQBQBQBQBQBBBBBBBBBQBQBQBQBBBQBBBQBQBQBQBBBQBQBQBQBQBBBQBQBQBBBBBQBQBQBQBBBBBQBQBB\n");
						printf("BQBBBQBBBBBBBBBBBBBBBQBQBBBBBQBQBBBBBQBQBBBQBQBQBQBBBQBBBBBQBQBQBQBQBQBBBQBQBQBQBBBQBQBQBQBBBQBQBQBBBQBBBBBQBQBQB\n");
						printf("BQBBBQBBBBBBBBQBBBQBQBBBQBQBQBQBBBBBQBBBQBQBQBBBQBBBQBQBQBBBBBBBBBBBQBQBBBQBQBQBQBQBBBQBBBQBQBBBQBBBQBBBBBQBQBQBB\n");
						printf("BQBBBQBBBBBBBBBQBBBQBBBBBQBQBQBQBQBQBQBQBQBQBQBBBBBQBQBQBQBBBQBBBQBQBQBQBQBQBQBQBQBBBBBQBBBQBQBBBQBQBQBQBBBQBQBQB\n");
						printf("BQBBBQBBBBBBBBBBBBQBQBQBQBQBQBBBBBBBQBQBQBBBQBBBQBQBQBBBQBQBBBQBQBQBBBBBBBQBBBBBQBBBQBQBQBQBBBBBBBBBBBQBQBQBBBBBQ\n");
						printf("BQBBBQBBBBBBBBBBBQBQBQBBBBBQBQBQBQBQBBBQBBBQBQBQBBBQBQBQBBBQBQBQBQBQBBBBBQBQBQBQBQBQBQBBBBBQBQBQBBBBBQBQBBBQBQBQB\n");
						printf("BQBBBQBBBBBBBBQBBBBBQBQBQBBBBBQBQBQBQBQBBBQBQBQBQBQBQBQBBBBBBBQBQBBBBBQBBBQBQBQBBBQBQBBBQBQBQBQBQBBBQBBBBBQBQBQBQ\n");
						printf("BQBBBQBBBBBBBBBQBQBQBQBQBQBBBQBQBQBQBQBBBBBQBQBBBQBQBBBBBQBQBQBQBQBQBQBQBQBBBBBQBQBQBBBQBQBQBBBQBQBQBQBQBQBQBBBQB\n");
						printf("BQBBBQBBBBBBBBQBQBBBQBQBQBQBBBQBQBQBBBBBQBQBQBQBQBQBQBQBBBQBQBQBBBQBQBQBBBQBBBQBQBBBQBBBBBQBQBBBBBQBBBQBQBQBBBQBB\n");
						Sleep(5000);
						exit(0);
					}
					if (i == 2)
					{
						Long_Clear();
						y += 2;

						i = 0xa1, j = 0xd9;

						gotoxy(40, 0);			// 별
						printf("%c%c%c%c%c%c", i, j, i, j, i, j);

						gotoxy(x, y);
						printf("%c%c", 0xa1, 0xdc);
					}
				}


			}

			if (x / 2 == 5 && y == 9)
				M_S = 1;

			else if (x / 2 == 15 && y == 9)
				M_S = 2;

			else if (x / 2 == 27 && y == 9)
				M_S = 3;

			else if (x / 2 == 37 && y == 9)
				M_S = 4;

			else if (x / 2 == 5 && y == 12)
				M_S = 5;

			else if (x / 2 == 15 && y == 12)
				M_S = 6;

			else if (x / 2 == 27 && y == 12)
				M_S = 7;

			else if (x / 2 == 37 && y == 12)
				M_S = 8;

			else if (x / 2 == 1 && y == 18)
				M_S = 66;

			else if (x / 2 == 1 && y == 19)
				M_S = 77;
			else {
				if (Money > 10000) {
					system("cls");
					PlaySound(TEXT("예에에.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
					printf(", ............... . ... . . .....     ,         ... ... ..,   . ... ...       .,.     ........... .\n");
					printf(". .. .,. ... ..... ..              ....        .,... ... .   ...              .,.. .   .......   .. \n");
					printf(", ... ..  ........                  ...         .  ....       .                   ...     .. .,.  . \n");
					printf(". .,.. ..,........  :BBBBBQBBBBBBBR  .. 7BBBg      . .  KBB1      2BMBBBBBBBgK7.   . . ....  ... .. \n");
					printf(", ,,,   .,,.... ..  LBBBQQBQBBBBBBD     OBBQBB    ....  QBB5      BBBBMQBBBQBQBB6:    ... ......... \n");
					printf(". ,,..   .........  7BBB             .  SBQ6HBQ.   ...  GBB2  ..  OBBa       :5BBBE,  ............. \n");
					printf(". . ..,.... .,....  7QBB      .         HBB7 BBB:   .   OBBs  ..  gBBK         .DBBQr  ............ \n");
					printf("   ....,...,,,.. .  rBBB     .,.   . .  XBQ2 pQBB,   .  EBB1  ..  GBBZ           MBBB. ..,......... \n");
					printf(". ,.. . ..,...,..   cQBB           ...  HBBa  gBBQ.     OBBJ      gQB6    .   ,. ;BQB7 ............ \n");
					printf(". ....   .,,.. .... 7BRB12SHXPS6E: ...  HBBP   MBBQ.    GBQJ   .  DBBp   .   ,,, .BBQZ   .......... \n");
					printf(". ......  .,,.  ... 7BQQMRBBBBBBB; ...  HBBP    pBBB;   GQBJ  ..  DBBK    ..:,,.  BMBO  . ......... \n");
					printf(", .............,..  rBQB          ....  aBBG     JBBB,  EBB2  ,.  EBBE   ,,,...  .BQBK  .... .....,.\n");
					printf(", ,.......  .....   7QBB.   ..  .....   HBBp   .  aBBL  EBBJ  ,.  DQBp  ,,. . .  iBMBr .,...... ....\n");
					printf(". ........ .  ....  rBQB   ..:.  ...    aBBZ  .,.  PBBr aBBJ  ..  OBBG  .. ..    QBBQ  ............ \n");
					printf(", ............,...  7BBB     ..     .   XBBK ....   6BB:1BBJ  ..  DBBH          RBBB:  .,.......... \n");
					printf(". ...... ..,.,....  7BQB            ..  SBBp ......  MBBGMB2  ..  gBBX      .;1BBBS,   ..,.,,..,.,..\n");
					printf(", ..... ....... .   JBBBBBBBBBBBBBB. .. EBBR  .,,... :BBBBBX  ..  BBBQBQBBBBBBBQK.    . . ..,...... \n");
					printf(". .......,.. ..  .  :BRMQBBBBBBBBBB. .  wBQU   ...... .ERQBr  ..  JBgMQBBBBRpJ;    ................ \n");
					printf(", .......,. ... . ..                 ..         . . .       .   .                 . ... ..,........ \n");
					printf(",........... .   ...     .   .     ...  %d일만에 통과 성공!!,. .         ..,.. . ....... ,,..... .. \n", Day_f);
					printf(",.:. .. .       ...      .,.. . .......     . . ......     .. ...         ..,.,   ... .  ..   ..,.. \n");
					getch();
					return 0;
				}
				else if (HP == 0 && Money == 0) {
					system("cls");
					PlaySound(TEXT("루우우.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
					printf("BQBBBQBBBBBBBBQBQBQBQBQBQBBBBBQBQBQBQBQBQBQBQBQBQBQBQBQBBBQBQBBBQBQBQBQBQBQBBBQBQBQBQBQBQBQBQBQBQBQBQBQBQBQBBBQBQ\n");
					printf("BQBBBQBBBBBBBBBQBQBQBBBBBBBQBBBQBBBQBQBQBQBBBQBBBQBQBQBQBQBQBQBQBQBBBQBBBQBQBBBQBQBQBQBBBQBQBBBQBQBQBQBQBQBQBBBBB\n");
					printf("BQBBBQBBBBBBBBQBQBBBQBQBQBBBQBQBBBQBBBQBBBQBQBQBQBQBBBQBQBQBQBBBQBQBBBQBBBQBQBBBBBQBQBBBBBQBBBQBBBQBBBQBBBQBBBQBQ\n");
					printf("BQBBBQBBBBBBBBBQBQBQBBBQBBBBBQBBBBBQBBBBBQBBBQBQBQBQBQBQBQBBBQBQBBBBBQBBBQBBBQBBBQBQBQBQBBBQBBBBBQBBBQBQBBBQBQBQB\n");
					printf("BQBBBQBBBBBBBBBBQBBBQBQBQBQBBBQBQBQBQBQBQBQBQBBBBBQBQBBBQBQBQBBBQBBBBBQBQBBBBBQBQBQBQBBBQBBBQBQBBBBBQBQBQBQBQBQBQ\n");
					printf("BQBBBQBBBBBBBBBQBQBBBQBBBBBBBBBQBQBQBQBQBQBQBQBQBBBQBBBQBQBQBBBQBQBQBQBQBBBBBBBBBBBQBBBQBBBBBQBQBBBQBBBQBQBQBQBQB\n");
					printf("BQBBBQBBBBBBBBBBQBQBQBBBBBQBQBQBQBBBBBBBQBQBBBBBQBBBQBBBQBQBBBQBQBBBQBQBBBQBQBQBQBQBBBQBQBQBBBQBQBBBQBBBQBQBQBQBQ\n");
					printf("BQBBBQBBBBBBBBBQBQBQBBBBBQBQBBBQBQBBBQBQBQBBBQBQBQBQBBBQBQBBBBBBBBBBBBBBBBBQBQBQBQBQBBBBBQBQBQBBBBBQBQBBBQBQBQBBB\n");
					printf("BQBBBQBBBBBBBBBBQBQBQBBBQBBBQBQBQBBBBBBBQBQBQBBBQBQBQBBBQBBBBBQBQBQBBBBBBBQBQBBBBBBBBBQBQBQBQBBBQBQBQBQBBBBBBBQBQ\n");
					printf("BQBBBQBBBBBBBBBBBBBBBBBQBQBQBBBQBQBQBQBBBQBQBQBQBQBBBQBBBBBBBBBBBBBBBBBQBBBQBQBBBQBBBQBBBBBQBBBBBBBQBBBBBBBQBQBQB\n");
					printf("BQBBBQBBBBBBBBBBQBBBQBQBQBQBBBBBBBQBBBQBBBBBQBBBQBQBBBBBBBBBBBQBQBBBBBBBBBQBBBBBQBQBBBBBBBBBBBBBQBBBBBQBBBQBBBQBQ\n");
					printf("BQBBBQBBBBBBBBBQBQBBBQBQBBBBBBBBBQBBBBBBBQBBBBBQBBBBBQBBBBBQBBBQBBBBBBBBBBBBBBBQBBBBBBBBBBBBBQBBBBQBBQBQBQBQBQBQB\n");
					printf("QBBBQBBBBBBBBQBQBBBQBBBBBBB6;:r6BBBBBsUBBQBS2BBBBKsBR77;i:OBQQBBBOr:iDBB1JBBBB7EBJ7ri:wBOcr;rwBBBQBQBQBQBQBQBBBQB\n");
					printf("BQBBBQBBBBBBBBBBBBBQBQBQBBB: :L  QBBBa  ZQBB. 5BBB  B7 7ci:ZBQBBBL ,L. sBr RBBr BQ ,Li:wBr r7i  BBQQBQBBBQBQBQBQB\n");
					printf("BQBBBQBBBBBBBBBBQBQBQBQBQBO vBBBBBBBQ ;: BBB,  BB   BJ BQBBBBBQBB :BBB: BB .BB :BB pBBBBBL BQB; MBMBBBQBBBQBBBQBQ\n");
					printf("BQBBBQBBBBBBBBBQBQBBBBBBBBX QBP;75BB7 RK JBB,...r ; B1 ...BBBBBBR 5BBBw BBS B7 BBQ  . OBBL ..  BBBBQBQBQBBBQBQBQB\n");
					printf("BQBBBQBBBBBBBBBBQBBBQBQBBBg 7BB: :BB  :;  BB :B  BX QJ BBBBBBBBBB :BBB. BBB   LBQR QBBBBQL BBi BQBBBQBQBQBQBQBQBB\n");
					printf("BQBBBQBBBBBBBBBBBBBBBQBQBBB; :L  BB  QBQB .B  B7.Br B7 :i:.7BQBBBJ .r. UBBBP  BBBD  r:,;Br BBB  BQQBBBBQBQBQBQBBB\n");
					printf("BQBBBQBBBBBBBBQBQBBBQBQBQQBBD7:LBBBLGBBBBDsBaXBBBBEJBRsc77;1BBBBBBgr;rMBQBBB2gBBBBJs7riLBDsBQBDcRBMBQBBBQBBBQBQBB\n");
					printf("BQBBBQBBBBBBBBBQBBBQBQBQBBBQBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBQBBBBBQBQBBBBBBBBBBBQBQBQBQBBBBBQB\n");
					printf("BQBBBQBBBBBBBBQBQBBBQBQBQBBBBBBBBBBBBBQBBBBBBBBBBBBBBBQBBBBBQBQBBBBBBBBBQBQBBBBBBBBBBBBBBBBBBBBBBBBBBBQBQBBBBBQBB\n");
					printf("BQBBBQBBBBBBBBBQBQBQBBBQBBBQBQBQBQBQBBBQBQBBBBBBBQBQBQBBBQBQBBBBBQBQBBBQBQBBBBBQBQBBBBBBBBBQBQBBBQBQBQBBBQBQBQBBB\n");
					printf("BQBBBQBBBBBBBBQBQBBBQBQBQBQBQBQBQBQBQBQBQBBBBBBBBBQBQBQBQBBBQBBBQBQBQBQBBBQBQBQBQBQBBBQBQBQBBBBBQBQBQBQBBBBBQBQBB\n");
					printf("BQBBBQBBBBBBBBBBBBBBBQBQBBBBBQBQBBBBBQBQBBBQBQBQBQBBBQBBBBBQBQBQBQBQBQBBBQBQBQBQBBBQBQBQBQBBBQBQBQBBBQBBBBBQBQBQB\n");
					printf("BQBBBQBBBBBBBBQBBBQBQBBBQBQBQBQBBBBBQBBBQBQBQBBBQBBBQBQBQBBBBBBBBBBBQBQBBBQBQBQBQBQBBBQBBBQBQBBBQBBBQBBBBBQBQBQBB\n");
					printf("BQBBBQBBBBBBBBBQBBBQBBBBBQBQBQBQBQBQBQBQBQBQBQBBBBBQBQBQBQBBBQBBBQBQBQBQBQBQBQBQBQBBBBBQBBBQBQBBBQBQBQBQBBBQBQBQB\n");
					printf("BQBBBQBBBBBBBBBBBBQBQBQBQBQBQBBBBBBBQBQBQBBBQBBBQBQBQBBBQBQBBBQBQBQBBBBBBBQBBBBBQBBBQBQBQBQBBBBBBBBBBBQBQBQBBBBBQ\n");
					printf("BQBBBQBBBBBBBBBBBQBQBQBBBBBQBQBQBQBQBBBQBBBQBQBQBBBQBQBQBBBQBQBQBQBQBBBBBQBQBQBQBQBQBQBBBBBQBQBQBBBBBQBQBBBQBQBQB\n");
					printf("BQBBBQBBBBBBBBQBBBBBQBQBQBBBBBQBQBQBQBQBBBQBQBQBQBQBQBQBBBBBBBQBQBBBBBQBBBQBQBQBBBQBQBBBQBQBQBQBQBBBQBBBBBQBQBQBQ\n");
					printf("BQBBBQBBBBBBBBBQBQBQBQBQBQBBBQBQBQBQBQBBBBBQBQBBBQBQBBBBBQBQBQBQBQBQBQBQBQBBBBBQBQBQBBBQBQBQBBBQBQBQBQBQBQBQBBBQB\n");
					printf("BQBBBQBBBBBBBBQBQBBBQBQBQBQBBBQBQBQBBBBBQBQBQBQBQBQBQBQBBBQBQBQBBBQBQBQBBBQBBBQBQBBBQBBBBBQBQBBBBBQBBBQBQBQBBBQBB\n");
					Sleep(5000);
					exit(0);
				}
			}
			//	gotoxy(90, 13);
			//	printf("M_S = %d", M_S);
		}

		if (Map == 1)
		{
			gotoxy(2, 21);
			switch (M_S)
			{
			case 1:														// 포커방
				if (Money < 1)
				{
					Day--;
					printf("베팅 최소 금액보다 보유 금액이 적어 입장할 수 없습니다.");
					ing(1);
					break;
				}
				else {
					printf("포커방에 입장합니다.");
					ing(1);
					Poker_Room();
				}
				y += 1;
				break;

			case 2:
				if (Money < 10)
				{
					Day--;
					printf("로또 가격보다 보유 금액이 적어 입장할 수 없습니다.");	// 복권방
					ing(1);
					break;
				}
				else {
					printf("복권방에 입장합니다.");
					ing(1);
					Lottery();
				}
				y += 1;
				break;

			case 3:
				printf("금 거래소에 입장합니다.");
				ing(1);
				Gold_Store(Gold_Price, &Gold_Have);

				y += 1;
				break;

			case 4:
				if (Money < 1)
				{
					Day--;
					printf("베팅 최소 금액보다 보유 금액이 적어 입장할 수 없습니다.");
					ing(1);
					break;
				}
				else {
					printf("경마장에 입장합니다.");
					ing(1);
					Race();
				}
				y += 1;
				break;

			case 5:														// 호텔
				if (HP == 100)
				{
					Day--;
					printf("HP가 부족할때만 찾아오세요.");
					ing(1);
				}
				else if (Money < 100)
				{
					Day--;
					printf("호텔 비용보다 보유 금액이 적어 입장할 수 없습니다.");
					ing(1);
				}
				else {
					printf("호텔에 입장합니다.");
					ing(1);
					Hotel();
				}
				y -= 1;
				break;

			case 6:
				if (House_Have == 0)
				{
					printf("집을 아직 구매하지 않았습니다.");
					Day_f = 2;
					ing(1);
				}

				if (House_Have == 1)
				{
					printf("집에 입장합니다.");
					ing(1);
					House();
				}

				y -= 1;
				break;
			case 7:
				printf("부동산에 입장합니다.");
				ing(1);
				Real_Estate();

				y -= 1;
				break;

			case 8:														// 장기
				if (Money < 100)
				{
					if (HP < 50) {
						printf("지금 부품을  때시면 죽을 수도 있습니다.\n");
						printf("%c%c       -HP가 부족합니다.-\n", 0Xa2, 0Xcc);
						Day_f--;
						getch();
					}
					else if (k == 0) {
						printf("더 이상 땔 부품이  없습니다.\n");
						Day_f--;
						getch();
					}
					else {

						HP -= 50;
						if (HP > (100 + (Drink * 30)))
							HP = 100 + (Drink * 30);
						Money += 100;
						printf("로봇공학자가 부품을 때면서 HP가 감소되었습니다.\n");
						printf("불법으로 부품을 팔아 100만 원을 얻었습니다.");
						Day--;
						getch();
					}
				}
				else
				{
					printf("돈이 없을 때만 찾아갑시다.");
					Day_f = 2;
				}
				ing(1);

				y -= 1;
				break;
			case 55:
				HP -= 20;
				if (HP < 0)
					HP = 0;
				Day_f = 2;
				break;

			case 66:
				Money += 1000;
				Day_f = 2;
				break;

			case 77:
				break;

			case 99:														// 게임 종료
				printf("게임을 종료합니다.");
				ing(1);
				exit(0);

			default:
				Day_f = 2;
			}
		}
		Edge();
		printf("\n\n");

		if (HP == 0 && Whistle != 0)						// 호루라기 사용
		{
			Big_Clear();
			Small_Clear();
			Long_Clear();
			Loading_Clear();
			gotoxy(2, 1);
			printf("HP가 0입니다..\n");
			gotoxy(2, 2);
			printf("비틀거리면서 걸어가다가 깡패를 만났습니다.");
			Sleep(1500);
			gotoxy(2, 5);
			printf("호루라기를 불러 도움을 청합니다.");
			Sleep(1500);
			i = rand() % 5 + 1;

			if (i <= 4)
			{
				gotoxy(2, 7);
				printf("'이봐 거기 뭐야!'\n");
				Sleep(1000);
				gotoxy(2, 8);
				printf("사람들이 와주었습니다.\n");
				Sleep(1000);
				gotoxy(2, 9);
				printf("깡패가 호다닥 도망갑니다.\n");
				Sleep(1500);
			}
			else
			{
				gotoxy(2, 7);
				printf("아무도 오지 않았습니다...\n");
				Sleep(1000);
				gotoxy(2, 8);
				printf("깡패에게 돈을 빼앗겼습니다\n");


				if (Money > 200)
				{
					i = (Money / 2);
					gotoxy(2, 11);
					printf("- %d만 원....\n", i);
					Money -= i;
				}
				ing(2);
			}
			Edge();
			Whistle--;
			HP = 10;

		}
		if (HP == 0)										// HP 0
		{
			Big_Clear();
			Small_Clear();
			Long_Clear();
			Loading_Clear();
			m = rand() % 4;
			gotoxy(2, 1);
			printf("HP가 0입니다..\n");
			Sleep(3000);
			gotoxy(2, 2);
			printf("비틀거리면서 걸어가다가 깡패한테 돈을 빼앗겼습니다..\n");
			Sleep(3000);

			if (m == 0) {
				i = Money;
				gotoxy(2, 5);
				printf("- %d만원....\n", i);
				Money = 0;
			}
			else{
				i = (Money / 2);
				gotoxy(2, 5);
				printf("- %d만 원....\n", i);
				Money -= i;
			}
			Sleep(1500);
			Whistle++;
			ing(2);
			Edge();
			HP = 10;
			if (m == 0) HP = 0;
		}

		int Bank_Storage_Main = 0;						// 저금한 금액
		for (i = 1; i <= 9; i++)
		{
			if (Saving[i] == 1)
				Bank_Storage_Main += Ten_Square(i);
		}


		if (Day_f == 1)												// 건물에 들어갔다가 나오면 하루 지남
		{
			Day++;
			Gold_Change(&Gold_Price, &Gold_B);					// 금값 변동
			Money += (Bank_Storage_Main / 10);						// 이자 추가
		}
	}
	return 0;
} */