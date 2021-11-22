#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<time.h>



void menuOne(); 
void singlePlayerGame(); 
void playerChoice(); 
void defineStrength(); 
void hit(); 
void restartSinglePlayerGame();
void stand(); 
void initialiseDeck(); 
void displayDeck(); 
void dealerTurn(); 
void dealerHit(); 


int menuScreen = 0, cardsDrawn = 0;
int playerOnePoints = 0, dealerPoints = 0, activePlayer = 0;
int dealerCardRevealed = 0;

struct deck { //structure to initilise deck of cards easier
	char* strength;
	char suit[20];
};

typedef struct deck Deck;
//filled arrays which will be used to initilise deck
char* strength[13] = { "Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King" };
char suit[4][20] = { "Clubs", "Diamonds", "Hearts", "Spades" };

void randomiseDeck(Deck[]); //used to shuffle the deck
Deck deck[52] = { "", "" }; 

void main() {

	printf("****Welcome to BlackJack****\n");
	printf("Type the corresponding Number to contuine\n");

	initialiseDeck(); //making deck
	randomiseDeck(deck); //shuffling

	menuOne(); //from this function everything else is called from

}

void menuOne()
{

	printf("1: Start Game\n");
	printf("2: Voltar ao Menu\n"); 

	int option;
	scanf("%d", &option);

	switch (option)
	{
	case 1:
		singlePlayerGame();
		break;

	case 2:
		//Codigo pra voltar ao menu
		break;

	default:
		printf("\n");
		menuOne();
		break;
	}
}

void singlePlayerGame()
{


	cardsDrawn = 0;
	playerOnePoints = 0;
	dealerPoints = 0;
	dealerCardRevealed = 0;

	printf("****Instrucoes****\n");
	printf("1.  Pedir\n");
	printf("2. Ficar\n");
	printf("****Instrucoes****\n\n");

	printf("Dealer has drawn \n");
	activePlayer = 0;
	displayDeck(); //card 0
	defineStrength();
	cardsDrawn++; //cards drawn = 1
	printf("Face-Down Card\n");
	printf("Dealer has %d points shown\n\n", dealerPoints);
	defineStrength();
	cardsDrawn++; //cards drawn = 2
	

	printf("Player One has: \n");
	activePlayer = 1;
	displayDeck(); // card 2
	defineStrength();
	cardsDrawn++; //cards drawm = 3



	printf("You have %d points\n\n", playerOnePoints);

	if (dealerPoints == 21 && playerOnePoints == 21) {
		printf("Dealer reveals BlackJack and it is a tie\n");
		restartSinglePlayerGame();
	}
	else if (dealerPoints == 21) {
		printf("Dealer reveals BlackJack and wins\n");
		restartSinglePlayerGame();
	}
	else if (playerOnePoints == 21) {
		printf("Player One wins with BlackJack\n");
		restartSinglePlayerGame();
	}


	playerChoice();

}

void playerChoice()
{
	int option;
	
		printf("It is your turn\n");
		scanf("%d", &option);
		
	switch (option) {
		case 1:
			hit();
			break;
		case 2:
			stand();
			break;
		default:
			hit();
			break;
		}
}


void defineStrength()
{
	if (activePlayer == 0) {
		if (strcmp(deck[cardsDrawn].strength, "Deuce") == 0) {
			dealerPoints += 2;
		}
		else if (strcmp(deck[cardsDrawn].strength, "Three") == 0) {
			dealerPoints += 3;
		}
		else if (strcmp(deck[cardsDrawn].strength, "Four") == 0) {
			dealerPoints += 4;
		}
		else if (strcmp(deck[cardsDrawn].strength, "Five") == 0) {
			dealerPoints += 5;
		}
		else if (strcmp(deck[cardsDrawn].strength, "Six") == 0) {
			dealerPoints += 6;
		}
		else if (strcmp(deck[cardsDrawn].strength, "Seven") == 0) {
			dealerPoints += 7;
		}
		else if (strcmp(deck[cardsDrawn].strength, "Eight") == 0) {
			dealerPoints += 8;
		}
		else if (strcmp(deck[cardsDrawn].strength, "Nine") == 0) {
			dealerPoints += 9;
		}
		else if (strcmp(deck[cardsDrawn].strength, "Ten") == 0) {
			dealerPoints += 10;
		}
		else if (strcmp(deck[cardsDrawn].strength, "Jack") == 0) {
			dealerPoints += 10;
		}
		else if (strcmp(deck[cardsDrawn].strength, "Queen") == 0) {
			dealerPoints += 10;
		}
		else if (strcmp(deck[cardsDrawn].strength, "King") == 0) {
			dealerPoints += 10;
		}
		else if (strcmp(deck[cardsDrawn].strength, "Ace") == 0) {
			dealerPoints += 1;

		}
	}
	else if (activePlayer == 1) {
		if (strcmp(deck[cardsDrawn].strength, "Deuce") == 0) {
			playerOnePoints += 2;
		}
		else if (strcmp(deck[cardsDrawn].strength, "Three") == 0) {
			playerOnePoints += 3;
		}
		else if (strcmp(deck[cardsDrawn].strength, "Four") == 0) {
			playerOnePoints += 4;
		}
		else if (strcmp(deck[cardsDrawn].strength, "Five") == 0) {
			playerOnePoints += 5;
		}
		else if (strcmp(deck[cardsDrawn].strength, "Six") == 0) {
			playerOnePoints += 6;
		}
		else if (strcmp(deck[cardsDrawn].strength, "Seven") == 0) {
			playerOnePoints += 7;
		}
		else if (strcmp(deck[cardsDrawn].strength, "Eight") == 0) {
			playerOnePoints += 8;
		}
		else if (strcmp(deck[cardsDrawn].strength, "Nine") == 0) {
			playerOnePoints += 9;
		}
		else if (strcmp(deck[cardsDrawn].strength, "Ten") == 0) {
			playerOnePoints += 10;
		}
		else if (strcmp(deck[cardsDrawn].strength, "Jack") == 0) {
			playerOnePoints += 10;
		}
		else if (strcmp(deck[cardsDrawn].strength, "Queen") == 0) {
			playerOnePoints += 10;
		}
		else if (strcmp(deck[cardsDrawn].strength, "King") == 0) {
			playerOnePoints += 10;
		}
		else if (strcmp(deck[cardsDrawn].strength, "Ace") == 0) {
			playerOnePoints += 1;
		}
	}
}

void restartSinglePlayerGame()
{
	int option;

	randomiseDeck(deck);
	printf("\n1. Another game\n");
	printf("2. Main Menu\n");
	scanf("%d", &option);

	switch (option)
	{
	case 1:
		singlePlayerGame();
		break;
	case 2:
		menuOne();
	default:
		singlePlayerGame();
		break;
	}
}

void dealerTurn()
{
	activePlayer = 0;

	if (dealerCardRevealed == 0) {
		printf("Dealer reveals : ");
		printf("%5s of %-12s\n", deck[1].strength, deck[1].suit);
		dealerCardRevealed = 1;
	}

	if (dealerPoints <= playerOnePoints) {
			dealerHit();
	}
	

	else if (dealerPoints > 21) {
			printf("Dealer goes Bust, you win with : %d\n", playerOnePoints);
			restartSinglePlayerGame();
					//ADICIONAR PONTOS

	}
	else if (dealerPoints > playerOnePoints){
			printf("Dealer Wins with: %d\n", dealerPoints);
			restartSinglePlayerGame();
						//RETIRAR PONTOS

	}
	
}

void dealerHit()
{
	printf("Dealer has : %d\n", dealerPoints);
	printf("Dealer has drawn\n");
	displayDeck();
	defineStrength();
	cardsDrawn++;

	if (dealerPoints <  playerOnePoints) {
		dealerHit();
	}
	else {
		dealerTurn();
	}
}

void stand()
{
		printf("You choose to stand, your final score for the round is : %d\n", playerOnePoints);
		dealerTurn();
}

void hit()
{
		displayDeck();
		defineStrength();
		cardsDrawn++;
		printf("You have %d points\n\n", playerOnePoints);

		if (playerOnePoints > 21) {
			printf("You have bust, Dealer wins\n");
			restartSinglePlayerGame();
		}
		else if (playerOnePoints == 21) {
			stand();
		}
		else if (playerOnePoints < 21) {
			playerChoice();
		}

}

void displayDeck() {
	printf("%5s of %-12s\n", deck[cardsDrawn].strength, deck[cardsDrawn].suit);
}

void randomiseDeck(Deck deck[])
{
	int indexSwap = 0;
	Deck temp = { "", "" };
	srand(time(NULL));
	int i;
	for (i = 0; i < 52; i++) {
		indexSwap = rand() % (52);
		temp = deck[i];
		deck[i] = deck[indexSwap];
		deck[indexSwap] = temp;
	} //creating a temperorary structure deck to store the changed index
}

void initialiseDeck()
{
	int i;
	for ( i = 0; i < 52; i++) {
		deck[i].strength = strength[i % 13];
		strncpy(deck[i].suit, suit[i / 13], 9);
	}
}
