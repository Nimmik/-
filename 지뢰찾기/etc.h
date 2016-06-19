#pragma once
#include <Windows.h>
#include <time.h>

void mixMap(int * a, int y, int x);

void gotoxy(int y, int x) {
	COORD Cur;
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

//¸Ê ÃÊ±âÈ­
//num = Number of Mines
void InitMap(int* a, int y, int x, int num) {
	for (int i = 0; i < y*x; i++) {
		if (num > 0) {
			*(a + i) = 1;
			num--;
		}
		else
			*(a + i) = 0;
	}
	Sleep(32);
	mixMap(a, y, x);
}

//Áö·ÚÀÇ À§Ä¡¸¦ ¼¯´Â´Ù
void mixMap(int * a, int y, int x) {
	srand(time(NULL));
	int randY;
	int randX;
	for (int j = 0; j < 10; j++) {
		for (int i = 0; i < y*x; i++) {
			randY = rand() % y;
			randX = rand() % x;
			int tmp = *(a + i);
			*(a+i) = *(a + (randY*x + randX));
			*(a + (randY*x + randX)) = tmp;
		}
	}
}