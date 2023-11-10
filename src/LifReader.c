#include "engine.h"
#include "LifReader.h"
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

#define MAX_BUFFER 1000

void readLifeFile(const char* filename, Grid* grid, int x_offset, int y_offset){
    FILE* file = fopen(filename, "r");
    if (file == NULL){
        fprintf(stderr, "Could not open File %s \n", filename);
        return;
    }

    char buffer[MAX_BUFFER];
    int x, y;
    while(fgets(buffer, MAX_BUFFER, file)){
        if(buffer[0] == '#'){
            continue;
        }

        //check coordinates
        if(sscanf(buffer, '#P %d %d', &x, &y) == 2){
            //starting coordinates
            x += x_offset;
            y += y_offset;

            //coordinates used for global iteration
            int X = x;
            int Y = y;

            while (fgets(buffer, MAX_BUFFER, file) && buffer[0] != '#'){
                for(int i = 0; buffer[i] != '\0' && buffer[i] != '\n'; i++){
                    if(buffer[i] == '*'){
                        int x_cord = X + i;
                        int y_cord = Y;
                        if (x_cord >= 0 && x_cord < grid->width && y_cord >= 0 && y_cord < grid->height){
                            grid->cells[x_cord][y_cord] = 1;
                        }
                    }
                }
                Y++;
            }
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