#include "src/engine.h"
#include "src/LifReader.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <dirent.h>
#include <string.h>

void usage(char *argv[]){
    printf("Usage: \n"
            "-h: show help \n"
            "\n"
            "Arguments for selection: \n"
            "-d D: Dimension of the field (DxD) \n"
            "-t T: Type of pattern you want to use \n"
            "Available patterns: \n");
    availableFiles("/files");
    exit(0);
}

void availableFiles(char *directory){
    DIR *d;
    struct dirent *ent;

    if(d = opendir(directory) != NULL){
        while((ent = readdir(d)) != NULL){
            printf("%s \n", ent->d_name);
        }
        closedir(d);
    }
        
}

int main(int argc, char *argv[]){
    int dimension;
    char type;

    int opt;
    while((opt = getopt(argc, argv, "hd:t:")) != -1){
        switch (opt) {
            case 'd':
                dimension = atoi(optarg);
                break;
            case 't':
                type = *optarg;
            case 'h':
                usage(argv);
        }
    }

    return 0;
}