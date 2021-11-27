#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "games.h"

#define ROWS 6
#define COLUMS 7
#define FOUR 4
#define COLUMNS_TO_WIN 10

#define HEADER "  1   2   3   4   5   6   7  "
#define SPLITTER "|---|---|---|---|---|---|---|"

#define DISK1 'X'
#define DISK2 'O'

char scores[ROWS][COLUMS];
int columToWin[COLUMNS_TO_WIN];
int isComputer;

void board();
void play(char currentDisk);
void fillColumn(char currentDisk, int columnNumber);
int check(char currentDisk);
void playComputer(char currentDisk);
void saveColumnsToWin(int column);
void initColumsToWin();
int generateRandomInt(int min, int max);

void fourInLine() {
    
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLUMS; j++)
        {
            scores[i][j] = 0;
        }
    }
    initColumsToWin();
    board();

    char currentDisk = DISK1;
    int gameMode;

    printf("1. vs jogador\n");
    printf("2. vs cpu\n");


    while(1) {
        scanf("%d", &gameMode);

        if (gameMode == 2) {
            isComputer = 1;
            break;
        } else if (gameMode == 1) {
            break;
        }
    }

    while(1) {
        printf("Player %c, your turn!\n", currentDisk);

        if (currentDisk == DISK2 && isComputer == 1)
        {
            playComputer(currentDisk);
        } else {
            play(currentDisk);
        }

        
        printf("\n\n");
        board();

        if (check(currentDisk)) {
            printf("Jogar %c ganhou! Parabéns!\n", currentDisk);
            break;
        }

        if (currentDisk == DISK1) {
            currentDisk = DISK2;
        } else {
            currentDisk = DISK1;
        }
            
    }

}

void board() {

    printf("%s\n", HEADER);
    printf("%s\n", SPLITTER);

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLUMS; j++)
        {   
            int currentScore = scores[i][j];
            if (currentScore == 0)
                printf("|   ");
            else    
                printf("| %c ", scores[i][j]);
        }
        printf("|\n");
        printf("%s\n", SPLITTER);
    }
}

void play(char currentDisk) {
    int columnNumber;
    char *col;
    int chosen;
    

        printf("\nChoose bin: ");

        if(scanf("%d", &chosen) != 1) {
            printf("\nWrong column! Try again.\n\n");
            board();
            return;
        }

    while(1) {

        switch(chosen)
        {
            case 1:
                columnNumber = 0;
                break;
            case 2:
                columnNumber = 1;
                break;
            case 3:
                columnNumber = 2;
                break;
            case 4:
                columnNumber = 3;
                break;
            case 5:
                columnNumber = 4;
                break;
            case 6:
                columnNumber = 5;
                break;
            case 7:
                columnNumber = 6;
                break;
            default:
                //columnNumber = -1;
                printf("\nWrong column! Try again.\n\n");
                board();
                break;
        }
        // break out of while loop if the right letter was chosen:
        if ((columnNumber >= 0 && columnNumber <= 6) && (scores[0][columnNumber] == 0))
        {
            fillColumn(currentDisk, columnNumber);
            break;
        }
    }
}

void fillColumn(char currentDisk, int columnNumber) {
    for (int level = ROWS-1; level >= 0; level--)
    {
        if (scores[level][columnNumber] == 0)
        {
            scores[level][columnNumber] = currentDisk;
            break;
        }   
    }    
};

int check(char currentDisk) {

    // check rows

    for (int i = 0; i < ROWS; i++)
    {
        int count = 0;

        for(int j = 0; j < COLUMS; j++)
        {
            if (j == 4 && scores[i][j] != currentDisk) {
                count = 0;
                break;
            } else if (scores[i][j] == currentDisk) {
                count++;
            } else {
                count = 0;
            }

            if (count == 3 && isComputer == 1) {
                if (scores[i][j + 1] == 0) {
                    saveColumnsToWin(j + 1);
                }

                if (scores[i][j - 3] == 0) {
                    saveColumnsToWin(j - 3);
                }
                
            }

            if (count == 4) return 1;
            
        }
    }

    for (int i = 0; i < COLUMS; i++)
    {
        int count = 0;

        for(int j = 0; j < ROWS; j++)
        {
            if (scores[j][i] == currentDisk) {
                count++;
            } else {
                count = 0;
            }

            if (count == 3 && isComputer == 1 && i > 0 && scores[j][i - 1] == 0) {
                saveColumnsToWin(i);
            }

            if (count == 4) return 1;
            
        }
    }
    
    int diagToVerify = 6;

    int diagLeftRows = 2, diagLeftColums = 0, 
        diagRightRows = 3, diagRightColumns = 0;

    for (int i = 0; i < diagToVerify; i++) {
        // Diagonal left

        int leftCount = 0, rightCount = 0;;


        int rowsToCheck = diagLeftRows, columnsToCheck = diagLeftColums;
        while (rowsToCheck < 7 && columnsToCheck < 7) {

            if (scores[rowsToCheck][columnsToCheck] == currentDisk) {
                leftCount++;
            } else {
                leftCount = 0;
            }

            if (leftCount == 3 && isComputer == 1) {

                if (scores[rowsToCheck + 1][columnsToCheck + 1] == 0) {
                    saveColumnsToWin(columnsToCheck + 1);
                }

                if (scores[rowsToCheck - 3][columnsToCheck - 3] == 0) {
                    saveColumnsToWin(columnsToCheck - 3);
                }
            }

            if (leftCount == 4) return 1;

            rowsToCheck++;
            columnsToCheck++;
        }

        int secondRowsToCheck = diagRightRows; 
        int secondColumnsToCheck = diagRightColumns;
        while ( secondRowsToCheck > -1 && secondRowsToCheck < 6 &&  secondColumnsToCheck < 7) {

            if (scores[secondRowsToCheck][secondColumnsToCheck] == currentDisk) {
                rightCount++;
            } else {
                rightCount = 0;
            }

            if (leftCount == 3 && isComputer == 1) {
                if (scores[rowsToCheck - 1][columnsToCheck + 1] == 0) {
                    saveColumnsToWin(columnsToCheck + 1);
                }

                if (scores[rowsToCheck + 3][columnsToCheck - 3] == 0) {
                    saveColumnsToWin(columnsToCheck - 3);
                }
            }

            if (rightCount == 4) return 1;

            secondRowsToCheck--;
            secondColumnsToCheck++;

        }

        if (diagLeftRows == 0 && diagLeftColums == 0) {
            diagLeftColums++;
        }  else if (diagLeftRows > 0) {
            diagLeftRows--;
        }  else if (diagLeftColums > 0) {
            diagLeftColums++;
        } 

        // Diagonal right

        if (diagRightRows == 5 && diagRightColumns == 6) {
            diagRightColumns++;
        } else if (diagRightRows < 5) {
            diagRightRows++;
        } else if (diagRightColumns < 6) {
            diagRightColumns++;
        }
    } 

    
    return 0;
}

void saveColumnsToWin(int column) {
    for (int i = 0; i < 8; i++) {
        int col = columToWin[i];

        if (col == -1 && col != column) {
            columToWin[i] = column;
            break;
        };
    }
};

void playComputer(char currentDisk) {

    int columnToPlay;
    int hasColumnsToWin = 0;
    int chances = 0;
    int r;

    for (int i = 0; i < COLUMNS_TO_WIN; i++) {
        if (columToWin[i] == -1) {
            break;
        }
        chances++;
    }

    while (1)
    {
        r = generateRandomInt(0, 101);
        if (r > 25 && chances > 0) {

            if (chances == 1) {
                columnToPlay = columToWin[0];
            } else {
                int index = generateRandomInt(0, chances);
                columnToPlay = columToWin[index];
            }
            
        } else {
            columnToPlay = generateRandomInt(0, 6);
        }

        if (scores[0][columnToPlay] == 0)
        {
            fillColumn(currentDisk, columnToPlay);
            break;
        }
    }

    initColumsToWin();
}

void initColumsToWin() {
    for (int i = 0; i < COLUMNS_TO_WIN; i++) {
        columToWin[i] = -1;
    }
}

int generateRandomInt(int min, int max) {
    srand((unsigned)time(NULL));
    return min + rand() % (max - min);
}