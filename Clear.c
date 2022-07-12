void Big_Clear()
{
	gotoxy(2, 1); printf("                                                                                  ");
	gotoxy(2, 2); printf("                                                                                  ");
	gotoxy(2, 3); printf("                                                                                  ");
	gotoxy(2, 4); printf("                                                                                  ");
	gotoxy(2, 5); printf("                                                                                  ");
	gotoxy(2, 6); printf("                                                                                  ");
	gotoxy(2, 7); printf("                                                                                  ");
	gotoxy(2, 8); printf("                                                                                  ");
	gotoxy(2, 9); printf("                                                                                  ");
	gotoxy(2, 10); printf("                                                                                  ");
	gotoxy(2, 11); printf("                                                                                  ");
	gotoxy(2, 12); printf("                                                                                  ");
	gotoxy(2, 13); printf("                                                                                  ");
	gotoxy(2, 14); printf("                                                                                  ");
	gotoxy(2, 15); printf("                                                                                  ");
	gotoxy(2, 16); printf("                                                                                  ");
	gotoxy(2, 17); printf("                                                                                  ");
	gotoxy(2, 18); printf("                                                                                  ");
	gotoxy(2, 19); printf("                                                                                  ");
}

void Long_Clear()
{
	gotoxy(2, 21); printf("                                                                                  ");
	gotoxy(2, 22); printf("                                                                                  ");
	gotoxy(2, 23); printf("                                                                                  ");
	gotoxy(2, 24); printf("                                                                                  ");
	gotoxy(2, 25); printf("                                                                                  ");
}

void Small_Clear()
{
	gotoxy(90, 21); printf("                ");
	gotoxy(90, 22); printf("                ");
	gotoxy(90, 23); printf("                ");
	gotoxy(90, 24); printf("                ");
	gotoxy(90, 25); printf("                ");
}

void Loading_Clear()
{
	gotoxy(2, 27); printf("                                                                                  ");
}

void Full_Clear()
{
	Big_Clear();
	Long_Clear();
	Small_Clear();
	Loading_Clear();
	Status();
}
