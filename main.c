#include <stdio.h>
#include <stdlib.h> 
#include <stdbool.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "files.h"

void menuinicial();
//void saveFile(char name[]);


void main() {
	int ch, i, j;
	char utilizador[15];
	int records;
	
	for (i = 1; i <= 12; i++) {
        for ( j = 1; j <= 20; j++) {
            if (i==5 && j==1){
            printf("#           IPCA GAMES ARCH           #");	}
			else if (i==8 && j==1){
            printf("#     INSIRA O SEU NOME DE JOGADOR    #");	}		
            else if (i == 1 || i == 12 || j == 1 || (j == 20 && i != 5 && i != 8 )){
                printf("# ");}
			
    		else{
                printf("  ");
            }
        }

        printf("\n");
    }
    
    printf("\n\n                ");
    
	scanf("%s", &utilizador);

   /* saveFile(utilizador);
      int* scores = readFile("FourInLine", &records);

	for(i = 0; i < records; i++) {
		printf("Val: %d\n", *scores);
		scores++;
	}*/

	while ((ch = getchar()) != '\n' && ch != EOF); //para aparecer a mensagem e so passar qnd clica enter
	printf("\n\n     Pressione Enter para continuar.");
	while ((ch = getchar()) != '\n' && ch != EOF);
	system("cls"); 
	menuinicial();
}


void menuinicial()
{
	int opcao;
	system("cls");
	printf("# # # # # # # # # # # # # # # # # # # #\n");
	printf("#                                     #\n");
	printf("#           IPCA GAMES ARCH           #\n");
	printf("#                                     #\n");
	printf("#    1.       A tua Pontuacao         #\n");
	printf("#    2.     Pontuacoes Globais        #\n");
	printf("#     3.     Adivinha o numero        #\n");
	printf("#     4.      Adivinha a carta        #\n");
	printf("#     5.         Vinte e um           #\n");
	printf("#     6.        Jogo do Galo          #\n");
	printf("#     7.     Jogo do Galo vs CPU      #\n");
	printf("#     8.       Jogo da Forca          #\n");
	printf("#     9.      Quatro em Linha         #\n");
	printf("#    10.   Quatro em Linha vs CPU     #\n");
	printf("#     0.            Sair              #\n");
	printf("#                                     #\n"); 
	printf("# # # # # # # # # # # # # # # # # # # #\n");
	
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

