#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include "files.h"

#define MAX_SCORES 100
#define FOLDER "leaderboard"

void createFile(char playerName[]) {
    FILE *myFile;
    char folder[] = "/leaderboard/";

    char path[100] = FOLDER;

    strcat(path, "/");
    strcat(path, playerName);
    strcat(path, ".txt");

    mkdir(FOLDER, 0777);

    myFile = fopen(path, "ab");

    fclose(myFile);
}

int* readFile(char game[], int *records) {

    DIR* myDir;
    struct dirent* in_file;
    
    int scoresToSave[MAX_SCORES];

    if (NULL == (myDir = opendir("leaderboard/"))) 
    {
        printf("Error : Failed to open input directory \n");
        return NULL;
    } else {
        printf("Dir name: \n");
    }

    int size = 0;

    while ((in_file = readdir(myDir))) {
        FILE* entry_file;
        char line[100];

        char* fileName = in_file->d_name;

        if (!strcmp(fileName, ".") || !strcmp(fileName, ".."))
            continue;
        
        char path[100] = FOLDER;

        strcat(path, "/");
        strcat(path, fileName);

        printf("File name: %s\n", fileName);

        entry_file = fopen(path, "r");

        if (entry_file == NULL)
        {
            printf("Error : Failed to open entry file - \n");

            continue;
        }

        while (fgets(line, BUFSIZ, entry_file) != NULL)
        {   
            char *name = strtok(line, " ");

            if(!strcmp(game, name)) 
                continue;

            char *point = strtok(NULL, " ");

            scoresToSave[size] = atoi(point);

            size++;
        }

        /* When you finish with the file, close it */
        fclose(entry_file);
    }

    *records = size;
    
    return scoresToSave;
};