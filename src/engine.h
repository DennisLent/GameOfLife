#ifndef ENGINE_H
#define ENGINE_H

#include <SDL2/SDL.h>

typedef struct {
    int** cells;
    int width;
    int height;
} Grid;

Grid initializeGrid(int dimension);
int convolution(Grid* grid, int i, int j);
void updateGrid(Grid* grid);
void renderGrid(SDL_Renderer *renderer, Grid* grid);
void freeGrid(Grid* grid);

#endif /* ENGINE_H */