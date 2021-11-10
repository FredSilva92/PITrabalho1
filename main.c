#include <stdio.h>
#include <stdlib.h> 
#include <stdbool.h>

void menuinicial();

void main() {
	int ch;
	char utilizador[15];
	printf("\n \t --- Bem Vindo ao IPCA Games Arch! --- \n Introduza o seu nome de Utilizador: \n");
	scanf(" % s", &utilizador);

	//Tens de fazer o coiso de armazenar e criar os dados do utilizador

	while ((ch = getchar()) != '\n' && ch != EOF); //para aparecer a mensagem e so passar qnd clica enter
	printf("\n\nPressione Enter para continuar.");
	while ((ch = getchar()) != '\n' && ch != EOF);
	system("cls"); 
	menuinicial();
}


void menuinicial()
{
	int opcao;
	system("cls");
	printf("Menu:\n\n");
	printf("1. A tua Pontuação\n");
	printf("2. Pontuações Globais\n");
	printf("3. Adivinha o numero.\n");
	printf("4. Adivinha a carta.\n");
	printf("5. Vinte e um.\n");
	printf("6. Jogo do Galo.\n");
	printf("7. Jogo do Galo vs CPU.\n");
	printf("8. Jogo da Forca.\n");
	printf("9. Quatro em Linha.\n");
	printf("10. Quatro em Linha vs CPU.\n");


	printf("0. Sair\n");
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
	case 9:;
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