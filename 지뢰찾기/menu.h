#pragma once
#include "game.h"

int menu() {
	int select;
	int caseNum1 = 0;

	int easy[9][9]; //easy[y][x]
	int normal[16][16];
	int hard[16][30];
	system("cls");

	puts("===================== 지뢰찾기 =====================");
	puts("1. 게임 시작");
	puts("2. 게임 방법 설명");
	puts("3. 최고 점수 확인");
	puts("4. 게임 종료\n");
	printf("번호 입력 : ");
	scanf("%d", &select);

	switch (select) {
	case 1:
		while (caseNum1==0) {
			system("cls");
			puts("===== 난이도 선택 =====");
			puts("1. 쉬움 : 9 X 9");
			puts("2. 보통 : 16 X 16");
			puts("3. 어려움 : 16 X 30");
			puts("4. 메인 메뉴로 돌아가기");
			puts("");
			printf("번호 입력 : ");
			scanf("%d", &select);

			//게임 난이도 선택
			switch (select) {
			case 1:
				getchar();
				game(easy, 1);
				break;
			case 2:
				getchar();
				game(normal, 2);
				break;
			case 3:
				getchar();
				game(hard, 3);
				break;
			case 4:
				caseNum1 = 4;
				break;
			default:
				puts("번호를 잘못 입력 하셨습니다.");
				puts("다시 입력하여 주세요.");
				system("pause");
				break;
			}
		}
		if (caseNum1 == 1)
			return 1;
		else if (caseNum1 == 2)
			return 2;
		else if (caseNum1 == 3)
			return 3;
		else if (caseNum1 == 4)
			caseNum1 = 0;
		else {
			puts("치명적인 오류가 발생하였습니다.");
			puts("메인 메뉴로 돌아갑니다.");
			caseNum1 = 0;
		}
		break;
	case 2:
		//설명
		system("cls");
		printf("지뢰 찾기 게임.");
		system("pause");
		break;
	case 3:
		//최고 점수 확인
	case 4:
		return 10;
	default:
		puts("번호를 잘못 입력 하셨습니다.");
		puts("다시 입력하여 주세요.");
		system("pause");
	}
}