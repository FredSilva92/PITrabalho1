#include <stdio.h>
#include <stdlib.h> 
#include <stdbool.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "files.h"
#include "games.h"

#define TOTAL_OPTIONS 11

struct Option {
    char* name;
    char* menuEntrance;
};

void menuinicial();

struct Option* getOptions();

void main() {
	int ch;
	char utilizador[15];
	int records;
	printf("\n \t --- Bem Vindo ao IPCA Games Arch! --- \n Introduza o seu nome de Utilizador: \n");
	scanf("%s", &utilizador);

    //int* scores = readFile("FourInLine", &records);


	while ((ch = getchar()) != '\n' && ch != EOF); //para aparecer a mensagem e so passar qnd clica enter
	printf("\n\nPressione Enter para continuar.");
	while ((ch = getchar()) != '\n' && ch != EOF);
	system("cls"); 
	menuinicial();

	int opcao = 9;

	scanf("%d", &opcao);

	switch (opcao)
	{
	case 1:;   
		break;
	case 2:;		
		break;
	case 3:; 
		break;
	case 4:;
		break;
	case 5:;
		break;
	case 6:;
		break;
	case 7:;
		break;
	case 8:;
		break;
	case 9:
		fourInLine(utilizador);
		break;
	case 10:;
		break;
	case 0: printf("A Fechar Programa!\n");
		exit(1);
		break;
	default: printf("Escolha invalida\n");
		exit(1);
		break;
	}
}

void menuinicial()
{
	system("cls");
	printf("Menu:\n\n");
	printf("1.    A tua Pontuacao\n");
	printf("2.    Pontuaoes Globais\n");
	printf("3.    Adivinha o numero.\n");
	printf("4.    Adivinha a carta.\n");
	printf("5.    Vinte e um.\n");
	printf("6.    Jogo do Galo.\n");
	printf("7.    Jogo do Galo vs CPU.\n");
	printf("8.    Jogo da Forca.\n");
	printf("9.    Quatro em Linha.\n");
	printf("10.   Quatro em Linha vs CPU.\n");


	printf("0.    Sair\n");
}

void setOptions() {
	struct Option options[TOTAL_OPTIONS];
	
	FILE *file = fopen("/resources/MenuOptions.txt", "r");

	if(file == NULL) {
		perror("File not found");
		exit(1);
	}

	char line[100];
	int i = 0;

	while (fgets(line, BUFSIZ, file) != NULL)
	{
		char *name = strtok(line, ";");
		char *menuEntrance = strtok(NULL, ";");

		options[i].name = name;
		options[i].menuEntrance = menuEntrance;
		
		i++;
	}

	fclose(file);
}