#include "engine.h"
#include <SDL2/SDL.h>

struct Grid{
    int** cells;
    int width;
    int height;
};

Grid initializeGrid(int dimension){
    Grid grid;
    grid.height = dimension;
    grid.width = dimension;

    grid.cells = (int**)malloc(grid.width * sizeof(int*));
    for(int i=0; i<grid.width; i++){
        grid.cells[i] = (int*)malloc(grid.height * sizeof(int*));
        for(int j=0; j<grid.height; j++){
            grid.cells[i][j] = 0;
        }
    }
    return grid;

}

int convolution(Grid* grid, int i, int j){
    int aliveNeightbors = 0;

    //convolution
    for(int di = -1; di < 1; di++){
        for(int dj = -1; dj < 1; dj++){
            //skip middle
            if (di == 0 && dj == 0){
                continue;
            }

            int ni = i + di;
            int nj = j + dj;
            if(ni >= 0 && ni < grid->width && nj >= 0 && nj < grid->height){
                aliveNeightbors += grid->cells[ni][nj];
            }
            
        }
    }
    //was alive
    if(grid->cells[i][j] == 1){
        //over or underpopulation
        if (aliveNeightbors < 2 || aliveNeightbors > 3){
            return 0;
        }
        //cell lives
        else{
            return 1;
        }
    }
    //cell was dead
    else{
        //reborn
        if (aliveNeightbors == 3){
            return 1;
        }
        else{
            return 0;
        }
    }
}

void updateGrid(Grid* grid){
    int temp[grid->width][grid->height];

    //apply convolution
    for(int i = 0;i < grid->width;i++){
        for(int j = 0;j < grid->height;j++){
            temp[i][j] = convolution(grid, i, j);
        }
    }

    //update grid
    for(int i = 0;i < grid->width;i++){
        for(int j = 0;j < grid->height;j++){
            grid->cells[i][j] = temp[i][j];
        }
    }



}

void renderGrid(SDL_Renderer *renderer, Grid* grid){
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);

    //iterate grid
    for(int i=0;i<grid->width; i++){
        for(int j=0;j<grid->height; j++){
            
            //2 or 3 neighbors means cell is alive
            if (grid->cells[i][j] == 1){
                SDL_Rect rect = {i*10, j*10, 10, 10};
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                SDL_RenderFillRect(renderer, &rect);
            }
        }
    }

    //Update screen
    SDL_RenderPresent(renderer);

}

void freeGrid(Grid* grid){
    for(int i=0; i<grid->width; i++){
        free(grid->cells[i]);
    }
    free(grid->cells);
}

void printGrid(Grid* grid) {
    for (int i = 0; i < grid->height; i++) {
        for (int j = 0; j < grid->width; j++) {
            printf("%d ", grid->cells[j][i]);
        }
        printf("\n");
    }
}

void countAlive(Grid* grid) {
    int alive = 0;
    for (int i = 0; i < grid->height; i++) {
        for (int j = 0; j < grid->width; j++) {
            if (grid->cells[i][j] == 1){
                alive++;
            }
        }
        printf("alive cells: %d \n", alive);
    }
}

