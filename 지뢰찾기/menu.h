#pragma once
#include "game.h"

int menu() {
	int select;
	int caseNum1 = 0;

	int easy[9][9]; //easy[y][x]
	int normal[16][16];
	int hard[16][30];
	system("cls");

	puts("===================== ����ã�� =====================");
	puts("1. ���� ����");
	puts("2. ���� ��� ����");
	puts("3. �ְ� ���� Ȯ��");
	puts("4. ���� ����\n");
	printf("��ȣ �Է� : ");
	scanf("%d", &select);

	switch (select) {
	case 1:
		while (caseNum1==0) {
			system("cls");
			puts("===== ���̵� ���� =====");
			puts("1. ���� : 9 X 9");
			puts("2. ���� : 16 X 16");
			puts("3. ����� : 16 X 30");
			puts("4. ���� �޴��� ���ư���");
			puts("");
			printf("��ȣ �Է� : ");
			scanf("%d", &select);

			//���� ���̵� ����
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
				puts("��ȣ�� �߸� �Է� �ϼ̽��ϴ�.");
				puts("�ٽ� �Է��Ͽ� �ּ���.");
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
			puts("ġ������ ������ �߻��Ͽ����ϴ�.");
			puts("���� �޴��� ���ư��ϴ�.");
			caseNum1 = 0;
		}
		break;
	case 2:
		//����
		system("cls");
		printf("���� ã�� ����.");
		system("pause");
		break;
	case 3:
		//�ְ� ���� Ȯ��
	case 4:
		return 10;
	default:
		puts("��ȣ�� �߸� �Է� �ϼ̽��ϴ�.");
		puts("�ٽ� �Է��Ͽ� �ּ���.");
		system("pause");
	}
}