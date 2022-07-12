void ing(float n)						// 로딩 (n * 1 초)
{
	int i;
	gotoxy(2, 27);
	for (i = 1; i <= 10; i++)
	{
		printf("◇");
		Sleep(25 * n);
		printf("♤");
		Sleep(25 * n);
		printf("♡");
		Sleep(25 * n);
		printf("♧");
		Sleep(25 * n);
	}
	printf("◇");
	Sleep(25 * n);
}