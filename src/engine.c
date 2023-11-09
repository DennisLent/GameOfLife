#include "engine.h"
#include <SDL2/SDL.h>

typedef struct {
    int** cells;
    int width;
    int height;
} Grid;

Grid initializeGrid(int width, int height){
    Grid grid;
    grid.height = height;
    grid.width = width;

    grid.cells = (int**)malloc(width * sizeof(int*));
    for(int i=0; i<width; i++){
        grid.cells[i] = (int*)malloc(height * sizeof(int*));
        for(int j=0; j<height; j++){
            grid.cells[i][j] = 0;
        }
    }
    return grid;

}

void updateGrid(Grid* grid){}

void renderGrid(Grid* grid){}

void freeGrid(Grid* grid){
    for(int i=0; i<grid->width; i++){
        free(grid->cells[i]);
    }
    free(grid->cells);
}

