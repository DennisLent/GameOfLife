#include "engine.h"
#include <SDL2/SDL.h>

typedef struct {
    int** cells;
    int width;
    int height;
} Grid;

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

void updateGrid(Grid* grid){}

void renderGrid(Grid* grid){}

void freeGrid(Grid* grid){
    for(int i=0; i<grid->width; i++){
        free(grid->cells[i]);
    }
    free(grid->cells);
}

