#include "engine.h"
#include "LifReader.h"
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

#define MAX_BUFFER 1000

void readLifeFile(const char* filepath, Grid* grid, int x_offset, int y_offset){

    printf("Retrieving File at %s", filepath);

    FILE* file = fopen(filepath, "r");
    if (file == NULL){
        fprintf(stderr, "Could not open File\n");
        return;
    }

    char buffer[MAX_BUFFER];
    int x, y;
    int readingPattern = 0;

    while (fgets(buffer, MAX_BUFFER, file)) {
        if (buffer[0] == '#' && sscanf(buffer, "#P %d %d", &x, &y) == 2) {
            //printf("Pattern start at coordinates: %d, %d\n", x, y);
            readingPattern = 1;
            continue;
        }

        if (readingPattern) {
            if (buffer[0] == '#' || buffer[0] == '\n') {
                readingPattern = 0;
                continue;
            }

            for (int i = 0; buffer[i] != '\0' && buffer[i] != '\n'; i++) {
                if (buffer[i] == '*') {
                    int x_cord = x + x_offset + i;
                    int y_cord = y + y_offset;
                    if (x_cord >= 0 && x_cord < grid->width && y_cord >= 0 && y_cord < grid->height) {
                        grid->cells[x_cord][y_cord] = 1;
                    }
                }
            }
            y++;
        }
    }

    fclose(file);
}

void availableFiles(char *directory){
    DIR *d;
    struct dirent *ent;

    if((d = opendir(directory)) != NULL){
        while((ent = readdir(d)) != NULL){
            printf("%s \n", ent->d_name);
        }
        closedir(d);
    }
        
}