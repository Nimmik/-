#pragma once
#include <stdio.h>
#include <Windows.h>
#include "etc.h"

void play(int* arr, int y, int x, int num);
void drawMap(int* arr, int y, int x);
int getSurround(int* arr, int y, int x, int nowY, int nowX);
void getBlank(int* arr, int* map, int y, int x, int nowY, int nowX);
int checkEnd(int* arr, int* map, int y, int x, int num);

void game(int* arr, int level) {
	int x = 9, y = 9, num = 10;
	if (level == 2) {
		x = 16; y = 16, num = 32;
	}
	else if(level == 3){
		x = 30; y = 16, num = 60;
	}
	InitMap(arr, y, x, num);
	Sleep(34);
	play(arr, y, x, num);
	printf("\n");
	system("pause");
}

void play(int* arr, int y, int x, int num) {
	int* map = (int*)malloc(sizeof(int)*y*x);
	int cursorX = 0, cursorY = 0;
	for (int i = 0; i < x*y; i++) {
		map[i] = 10;
	}
	drawMap(map, y, x);
	while (1) {
		if (GetAsyncKeyState(VK_LEFT) & 0x0001){
			if (cursorX > 0){
				cursorX = cursorX - 1;
			}
		}
		if (GetAsyncKeyState(VK_RIGHT) & 0x0001)
			if (cursorX < x-1){
				cursorX = cursorX + 1;
			}
		if (GetAsyncKeyState(VK_DOWN) & 0x0001)
			if (cursorY < y-1){
				cursorY = cursorY + 1;
			}
		if (GetAsyncKeyState(VK_UP) & 0x0001)
			if (cursorY > 0){
				cursorY = cursorY - 1;
			}
		gotoxy(cursorY, cursorX*2);

		if (GetAsyncKeyState(VK_SPACE) & 0x0001) {
			if (map[cursorY*x + cursorX] == 10) {
				map[cursorY*x + cursorX] = 11;
			}
			else{
				map[cursorY*x + cursorX] = 10;
			}
			drawMap(map, y, x);
		}

		if (GetAsyncKeyState(VK_RETURN) & 0x0001) {
			if(map[cursorY*x + cursorX] == 10){
				if (arr[cursorY*x + cursorX] == 0) {
					getBlank(arr, map, y, x, cursorY, cursorX);
				}
				else {
					printf("※");
					gotoxy(y + 1, 0);
					printf("지뢰 발견");
					break;
				}
			}
			drawMap(map, y, x);
			if (checkEnd(arr, map, y, x, num)) {
				gotoxy(y + 1, 0);
				printf("게임을 끝내셧습니다\n");
				break;
			}
		}
	}
	free(map);
}

void drawMap(int* arr, int y, int x) {
	system("cls");
	printf("%d", sizeof(arr));
	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++) {
			gotoxy(i, j * 2);
			if (arr[i*x + j] == 0) {
				printf(" ");
			}
			else if (arr[i*x + j] < 9) {
				printf("%d", arr[i*x + j]);
			}
			else if (arr[i*x + j] == 10)
				printf("■");
			else if (arr[i*x + j] == 11)
				printf("★");
		}
	}
}

int getSurround(int* arr, int y, int x, int nowY, int nowX) {
	int sum = 0;
	for (int i = -1; i < 2; i++) {
		for (int j = -1; j < 2; j++) {
			if((nowX+j) >= 0 && (nowY+i) >= 0 && (nowX+j) < x && (nowY+i) < y)
			sum += arr[(nowY + i)*x + (nowX + j)];
		}
	}
	return sum;
}

void getBlank(int* arr, int* map, int y, int x, int nowY, int nowX) {
	int surround = getSurround(arr, y, x, nowY, nowX);
	map[(nowY*x) + nowX] = surround;
	if (surround == 0) {
		if(nowY > 0 && nowX > 0 && map[(nowY-1)*x + (nowX-1)] == 10)
			getBlank(arr, map, y, x, nowY - 1, nowX - 1);
		if (nowY > 1 && map[(nowY - 1)*x + (nowX)] == 10)
			getBlank(arr, map, y, x, nowY - 1, nowX);
		if (nowY > 1 && nowX < x - 1 && map[(nowY - 1)*x + (nowX + 1)] == 10)
			getBlank(arr, map, y, x, nowY - 1, nowX + 1);
		if (nowY < y - 1 && nowX > 1 && map[(nowY + 1)*x + (nowX - 1)] == 10)
			getBlank(arr, map, y, x, nowY + 1, nowX - 1);
		if (nowY < y - 1 && map[(nowY + 1)*x + (nowX )] == 10)
			getBlank(arr, map, y, x, nowY + 1, nowX);
		if (nowY < y - 1 && nowX < x - 1 && map[(nowY + 1)*x + (nowX + 1)] == 10)
			getBlank(arr, map, y, x, nowY + 1, nowX + 1);
		if (nowX < x - 1 && map[(nowY)*x + (nowX + 1)] == 10)
			getBlank(arr, map, y, x, nowY, nowX + 1);
		if (nowX > 1 && map[(nowY)*x + (nowX - 1)] == 10)
			getBlank(arr, map, y, x, nowY, nowX - 1);
	}
}

int checkEnd(int* arr, int* map, int y, int x, int num) {
	int count = 0;
	int right = 0;
	for (int i = 0; i < x*y; i++) {
		if (map[i] == 10) {
			count++;
		}
	}
	if (count == 0) {
		for (int i = 0; i < x*y; i++) {
			if (arr[i] == 1 && map[i] == 11) {
				right++;
			}
		}
	}
	if (num == right) {
		return 1;
	}
	return 0;
}