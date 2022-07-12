void Map_1_Draw()
{
	int i = 0xa1;
	int j = 0xac;
	//윗 줄	
	gotoxy(2, 2);
	i = 0xa1, j = 0xac;
	printf("    ________            ________                ________           ________ ");
	gotoxy(2, 3);
	printf("   /        %c%c         /        %c%c             /        %c%c        /        %c%c    ", i, j, i, j, i, j, i, j);
	gotoxy(2, 4);
	printf("  /           %c%c      /           %c%c          /           %c%c     /           %c%c  ", i, j, i, j, i, j, i, j);
	gotoxy(2, 5);
	printf(" /              %c%c   /              %c%c       /              %c%c  /              %c%c", i, j, i, j, i, j, i, j);
	gotoxy(2, 6);
	printf(" |    카드게임   |   |     복권방    |       |   골드 상점   |  |     말게임    |");
	gotoxy(2, 7);
	printf(" |               |   |               |       |               |  |               |");
	gotoxy(2, 8);
	i = 0xa2, j = 0xc6;
	printf(" |______%c%c________|   |______%c%c________|       |______%c%c________|  |_______%c%c_______|", i, j, i, j, i, j, i, j);
	gotoxy(2, 9);
	i = 0xa1, j = 0xd9;
	printf("        %c%c                  %c%c                      %c%c                  %c%c", i, j, i, j, i, j, i, j);

	//아랫 줄
	gotoxy(2, 12);
	printf("  ______%c%c_______     ______%c%c_______         ______%c%c_______    _______%c%c______", i, j, i, j, i, j, i, j);
	gotoxy(2, 13);
	i = 0xa2, j = 0xc6;
	printf(" |      %c%c        |   |      %c%c        |       |      %c%c        |  |       %c%c       |", i, j, i, j, i, j, i, j);
	gotoxy(2, 14);
	printf(" |               |   |               |       |               |  |               |");
	gotoxy(2, 15);
	printf(" |      호텔     |   |       집      |       |     부동산    |  |   가벼워지기  |");
	gotoxy(2, 16);
	i = 0xa1, j = 0xac;
	printf(" %c%c              /   %c%c              /       %c%c              /  %c%c              /", i, j, i, j, i, j, i, j);
	gotoxy(2, 17);
	printf("   %c%c           /      %c%c           /          %c%c           /     %c%c           /", i, j, i, j, i, j, i, j);
	gotoxy(2, 18);
	printf("     %c%c________/         %c%c________/             %c%c________/        %c%c________/", i, j, i, j, i, j, i, j);
}