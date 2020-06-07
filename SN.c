#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <Windows.h>

void draw_alpha(char* alpha, int round, int score)
{
	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0 + 12);
	printf("%d", round);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0 + 15);
	printf("R\n");
	printf("Score : %d\n\n", score);
	for (int i = 0; i < 16; i++)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0 + 15);
		printf(" ");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240 + 0);
		printf(" %c ", alpha[i]);
		if (!((i + 1) % 4)) printf("\n\n");
	}
}

void draw_board(int* boardn, int a, int b, int c, int round, int score)
{
	int i, j;
	char alpha[16] = { 'A','L','I','E','Y','O','U','M','S','T','N','R','H','D','G','K' };
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0 + 15);
	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0 + 12);
	printf("%d", round);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0 + 15);
	printf("R\n");
	printf("Score : %d\n\n", score);
	for (i = 0; i < 4; i++)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0 + 15);
		printf(" ");
		for (j = 0; j < 4; j++)
		{
			if (i * 4 + j == a || i * 4 + j == b || i * 4 + j == c)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 224 + 0);
				if (boardn[i * 4 + j] >= 0 && boardn[i * 4 + j] < 12)
				{
					if ((boardn[i * 4 + j] + 1) / 10) printf(" %d", boardn[i * 4 + j] + 1);
					else printf(" %d ", boardn[i * 4 + j] + 1);
				}
				else if (boardn[i * 4 + j] == 12) printf(" + ");
				else if (boardn[i * 4 + j] == 13) printf(" - ");
				else if (boardn[i * 4 + j] == 14) printf(" * ");
				else if (boardn[i * 4 + j] == 15) printf(" / ");
			}
			else
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240 + 0);
				printf(" %c ", alpha[i * 4 + j]);
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0 + 15);
			printf(" ");
		}
		printf("\n\n");
	}
}

void main(void)
{
	while (1)
	{
		srand(time(NULL));

		int boardn[16];
		int i, j;
		for (i = 0; i < 16; i++)
			boardn[i] = -1;

		int random;
		int same;
		i = 0;
		while (i < 16)
		{
			same = 0;
			random = rand() % 16;
			j = 0;
			while (j < i)
			{
				if (boardn[j] == random)
				{
					same = 1;
					break;
				}
				j++;
			}
			if (same) continue;
			boardn[i++] = random;
		}

		int round = 0;
		int score = 0;
		char newgame;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0 + 15);
		system("cls");
		printf("Press any key to start...");
		_getch();
		system("cls");
		printf("\n\n\n");
		for (i = 0; i < 16; i++)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0 + 15);
			printf(" ");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240 + 0);
			if (boardn[i] >= 0 && boardn[i] < 12)
			{
				if ((boardn[i] + 1) / 10)
					printf(" %d", boardn[i] + 1);
				else printf(" %d ", boardn[i] + 1);
			}
			else if (boardn[i] == 12) printf(" + ");
			else if (boardn[i] == 13) printf(" - ");
			else if (boardn[i] == 14) printf(" * ");
			else if (boardn[i] == 15) printf(" / ");
			if (!((i + 1) % 4)) printf("\n\n");
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0 + 15);
		for (i = 5; i > 0; i--)
		{
			printf("\b%d", i);
			Sleep(1000);
		}

		char alpha[16] = { 'A','L','I','E','Y','O','U','M','S','T','N','R','H','D','G','K' };
		char* input = (char*)calloc(sizeof(char), 3);
		char select[3];
		int num[67] = { -11,-10,-9,-8,-7,-6,-5,-4,-3,-2,-1,
						1,2,3,4,5,6,7,8,9,10,
						11,12,13,14,15,16,17,18,19,20,
						21,22,23,24,27,28,30,32,33,35,
						36,40,42,44,45,48,50,54,55,56,
						60,63,66,70,72,77,80,84,88,90,
						96,99,108,110,120,132 };
		int target[20];
		for (i = 0; i < 20; i++)
			target[i] = -1;
		int tar;
		int result;
		i = 0;
		while (i < 20)
		{
			same = 0;
			tar = rand() % 67;
			j = 0;
			while (j < i)
			{
				if (target[j] == tar)
				{
					same = 1;
					break;
				}
				j++;
			}
			if (same) continue;
			target[i++] = tar;
		}

		clock_t start;
		int timeover;
		for (i = 0; i < 20; i++)
		{
			timeover = 0;
			draw_alpha(alpha, ++round, score);
			fflush(stdin);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0 + 15);
			printf("Target number : ");
			Sleep(1000);
			printf("%d\n", num[target[i]]);
			while (1)
			{
				printf("Press any key to input...\n");
				if (getch())
				{
					printf("Input : ");
					start = clock();
					if ((clock() - start) / CLOCKS_PER_SEC > 5.0)
					{
						timeover = 1;
						break;
					}
					input[0] = _getch();
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240 + 0);
					printf(" %c ", input[0] - 32);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0 + 15);
					printf(" ");
					if ((clock() - start) / CLOCKS_PER_SEC > 5.0)
					{
						timeover = 1;
						break;
					}
					input[1] = _getch();
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240 + 0);
					printf(" %c ", input[1] - 32);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0 + 15);
					printf(" ");
					if ((clock() - start) / CLOCKS_PER_SEC > 5.0)
					{
						timeover = 1;
						break;
					}
					input[2] = _getch();
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240 + 0);
					printf(" %c ", input[2] - 32);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0 + 15);
					if ((clock() - start) / CLOCKS_PER_SEC > 5.0)
					{
						timeover = 1;
						break;
					}
				}
				break;
			}
			if (timeover) printf("\nTime over!\n");
			else
			{
				Sleep(1000);
				for (j = 0; j < 3; j++)
				{
					if (input[j] == 'a') select[j] = 0;
					else if (input[j] == 'l') select[j] = 1;
					else if (input[j] == 'i') select[j] = 2;
					else if (input[j] == 'e') select[j] = 3;
					else if (input[j] == 'y') select[j] = 4;
					else if (input[j] == 'o') select[j] = 5;
					else if (input[j] == 'u') select[j] = 6;
					else if (input[j] == 'm') select[j] = 7;
					else if (input[j] == 's') select[j] = 8;
					else if (input[j] == 't') select[j] = 9;
					else if (input[j] == 'n') select[j] = 10;
					else if (input[j] == 'r') select[j] = 11;
					else if (input[j] == 'h') select[j] = 12;
					else if (input[j] == 'd') select[j] = 13;
					else if (input[j] == 'g') select[j] = 14;
					else if (input[j] == 'k') select[j] = 15;
				}
				draw_board(boardn, select[0], select[1], select[2], round, score);
				printf("Target number : %d\n\n", num[target[i]]);
				printf(" ");
				for (j = 0; j < 3; j++)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240 + 0);
					printf(" %c ", input[j] - 32);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0 + 15);
					printf(" ");
				}
				printf("\n\n ");
				for (j = 0; j < 3; j++)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 224 + 0);
					if (boardn[select[j]] >= 0 && boardn[select[j]] < 12)
					{
						if ((boardn[select[j]] + 1) / 10) printf(" %d", boardn[select[j]] + 1);
						else printf(" %d ", boardn[select[j]] + 1);
					}
					else if (boardn[select[j]] == 12) printf(" + ");
					else if (boardn[select[j]] == 13) printf(" - ");
					else if (boardn[select[j]] == 14) printf(" * ");
					else if (boardn[select[j]] == 15) printf(" / ");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0 + 15);
					printf(" ");
				}
				if (boardn[select[0]] >= 0 && boardn[select[0]] <= 11 && boardn[select[1]] >= 12 && boardn[select[1]] <= 15 && boardn[select[2]] >= 0 && boardn[select[2]] <= 11)
				{
					printf("= ");
					if (boardn[select[1]] == 12) result = (boardn[select[0]] + 1) + (boardn[select[2]] + 1);
					else if (boardn[select[1]] == 13) result = (boardn[select[0]] + 1) - (boardn[select[2]] + 1);
					else if (boardn[select[1]] == 14) result = (boardn[select[0]] + 1) * (boardn[select[2]] + 1);
					else if (boardn[select[1]] == 15) result = (boardn[select[0]] + 1) / (boardn[select[2]] + 1);
					printf("%d\n\n", result);
					if (result == num[target[i]])
					{
						printf("Correct!\n");
						score++;
					}
					else printf("Wrong!\n");
				}
				else printf("\n\nWrong!\n");
			}
			Sleep(3000);
			fflush(stdin);
		}
		system("cls");
		printf("Score : %d\n\n", score);
		for (int i = 0; i < 16; i++)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0 + 15);
			printf(" ");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240 + 0);
			printf(" %c ", alpha[i]);
			if (!((i + 1) % 4)) printf("\n\n");
		}
		printf("\n");
		for (i = 0; i < 16; i++)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0 + 15);
			printf(" ");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 224 + 0);
			if (boardn[i] >= 0 && boardn[i] < 12)
			{
				if ((boardn[i] + 1) / 10)
					printf(" %d", boardn[i] + 1);
				else printf(" %d ", boardn[i] + 1);
			}
			else if (boardn[i] == 12) printf(" + ");
			else if (boardn[i] == 13) printf(" - ");
			else if (boardn[i] == 14) printf(" * ");
			else if (boardn[i] == 15) printf(" / ");
			if (!((i + 1) % 4)) printf("\n\n");
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0 + 15);
		printf("New game? ( O / X )");
		while (1)
		{
			newgame = _getch();
			if (newgame == 'o' || newgame == 'x') break;
		}
		if (newgame == 'x') break;
	}
}