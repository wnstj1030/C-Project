void Real_Estate_inf()
{
	Big_Clear();
	Small_Clear();
	Long_Clear();
	Status();
	Edge();
	gotoxy(2, 1);
	printf("부동산에서는 자신만의 집을 구매할 수 있습니다.\n");
	gotoxy(2, 3);
	printf("집은 한 종류밖에 없습니다.\n");
	gotoxy(2, 5);
	printf("돈이 없을 때 집을 팔 수도 있습니다.\n\n");
	gotoxy(2, 7);
	printf("집은 HP를 최대로 회복시켜줍니다.\n\n");
	gotoxy(2, 9);
	printf("아무 버튼이나 눌러 부동산으로\n");
	getch();
	Sleep(100);
}