#include "etc.h"
#include "menu.h"

void main() {
	int menuNum = 0;

	while (menuNum!=10) {
		menuNum = menu();
	}
}