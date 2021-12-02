#include <stdio.h>
#include "utils.h"

void pressEnter() {
    int ch;
	while ((ch = getchar()) != '\n' && ch != EOF); //para aparecer a mensagem e so passar qnd clica enter
	printf("\n\nPressione Enter para continuar.");
	while ((ch = getchar()) != '\n' && ch != EOF);
};