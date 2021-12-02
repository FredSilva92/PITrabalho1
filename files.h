#define MAX_SCORES 100
#define RECORDS_TO_SHOW 10

struct Record
{
    char* player;
    char* game;
    char* score;
};


int readFile(int *totalRecords, struct Record* records);

void saveFile(char playerName[], char gameName[], int score);

void setPlayerPoints(char gameName[], struct Record records[]);

void setGamePoints(char playerName[], struct Record records[]);