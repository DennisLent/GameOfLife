#include "src/engine.h"
#include "src/LifReader.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>

void usage(char *argv[]){
    printf("Usage: \n"
            "-h: show help \n"
            "\n"
            "Arguments for selection: \n"
            "-d D: Dimension of the field (DxD) \n"
            "-p P: Name of the Pattern you want to use \n"
            "Available patterns: \n");
    availableFiles("../files");
    exit(0);
}

int main(int argc, char *argv[]){
    int dimension;
    char pattern[1000];

    int opt;
    while((opt = getopt(argc, argv, "hd:p:")) != -1){
        switch (opt) {
            case 'd':
                dimension = atoi(optarg);
                break;
            case 'p':
                strncpy(pattern, optarg, 1000);
                pattern[1000 - 1] = '\0';
                break;
            case 'h':
                usage(argv);
                break;
            default:
                fprintf(stderr, "Invalid Option: %c \n", opt);
                usage(argv);
        }
    }

    if(dimension == 0 || pattern == '\0'){
        fprintf(stderr, "Dimension and pattern are required");
        usage(argv);
    }

    //SDL initializing
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        fprintf(stderr, "SDL initialization failed: %s\n", SDL_GetError());
        return 1;
    }
    SDL_Window *window = SDL_CreateWindow("Game of Life", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, dimension * 10, dimension * 10, SDL_WINDOW_SHOWN);
    if (!window) {
        fprintf(stderr, "SDL window creation failed: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        fprintf(stderr, "SDL renderer creation failed: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    Grid grid = initializeGrid(dimension);
    int offset = floor(dimension/2);
    readLifeFile(pattern, &grid, offset, offset);
    //printGrid(&grid);

    //main loop
    int running = 1;
    while(running){
        //countAlive(&grid);

        renderGrid(renderer, &grid);
        updateGrid(&grid);

        //quit loop
        SDL_Event key;
        while(SDL_PollEvent(&key)){
            if(key.type == SDL_QUIT){
                running = 0;
            }
        }

        SDL_Delay(1000);
    }

    freeGrid(&grid);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}