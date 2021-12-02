#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include "files.h"

#define FOLDER "leaderboard"

void sortRecords(int totalRecords, struct Record records[]);

int readFile(int *totalRecords, struct Record* records) {
    int size = 0;
    FILE* myFile;
    char line[100];
    char path[100] = FOLDER;

    strcat(path, "/records.txt");

    printf("File name: %s\n", path);

    myFile = fopen(path, "r");

    if (myFile == NULL)
    {
        printf("Error : Failed to open file - \n");
        exit(1);
    }

    records[size].player = malloc(20 * sizeof(char));
    records[size].game = malloc(20 * sizeof(char));
    records[size].score = malloc(20 * sizeof(char));

    while(fscanf(myFile, "%s %s %s", records[size].player, records[size].game, records[size].score) != EOF) {
        size++;
        records[size].player = malloc(20 * sizeof(char));
        records[size].game = malloc(20 * sizeof(char));
        records[size].score = malloc(20 * sizeof(char));
    };

    fclose(myFile);
    
    *totalRecords = size;
    
    return 0;
}

void saveFile(char playerName[], char gameName[], int score) {
    FILE *myFile;

    char path[100] = FOLDER;

    strcat(path, "/records.txt");

    mkdir(FOLDER, 0777);

    myFile = fopen(path, "a");

    if(myFile == NULL) {
        perror("Not possible to open file");
        exit(1);
    }

    int c = fgetc(myFile);
    char* lineToWrite;
    if (c == EOF) {
        lineToWrite = "%s %s %d";
    } else {
        lineToWrite = "\n%s %s %d";
    }

    fprintf(myFile, lineToWrite, playerName, gameName, score);

    fclose(myFile);
}

void setPlayerPoints(char gameName[], struct Record records[]) {
    struct Record* recordsToSet = malloc(100 * sizeof(struct Record));
    struct Record* recordsToSend = malloc(100 * sizeof(struct Record));;

    int totalRecords;

    readFile(&totalRecords, recordsToSet);

    int recordsIndex = 0;

    for(int i = 0; i < totalRecords; i++) {
        if (strcmp(recordsToSet[i].game, gameName) == 0) {
            recordsToSend[recordsIndex] = recordsToSet[i];
            recordsIndex++;
        }
    }

    sortRecords(totalRecords, recordsToSend);

    for(int i = 0; i < RECORDS_TO_SHOW; i++) {
        printf("%s %s\n", recordsToSend[i].player, recordsToSend[i].score);
    }

    free(recordsToSet);
    free(recordsToSend);
}

void setGamePoints(char playerName[], struct Record records[]) {
    struct Record* recordsToSet = malloc(100 * sizeof(struct Record));
    struct Record* recordsToSend = malloc(100 * sizeof(struct Record));

    int totalRecords;

    readFile(&totalRecords, recordsToSet);

    int recordsIndex = 0;

    for(int i = 0; i < totalRecords; i++) {
        if (strcmp(recordsToSet[i].player, playerName) == 0) {
            recordsToSend[recordsIndex] = recordsToSet[i];
            recordsIndex++;
        }
    }

    sortRecords(totalRecords, recordsToSend);

    for(int i = 0; i < RECORDS_TO_SHOW; i++) {
        printf("%s %s\n", recordsToSend[i].player, recordsToSend[i].score);
    }

    free(recordsToSet);
    free(recordsToSend);
}

void sortRecords(int totalRecords, struct Record* records) {
    for (int i = 0; i < totalRecords; i++) {
        for (int j = i + 1; j < totalRecords; j++) {
            int prevScore = atoi(records[i].score);
            int nextScore = atoi(records[j].score);

            if (nextScore < prevScore) {
                struct Record tmp = records[i];
                records[i] = records[j];
                records[j] = tmp;
            }
        }
    }
}