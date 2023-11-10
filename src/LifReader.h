#ifndef LIFREADER_H
#define LIFREADER_H

#include "engine.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER 1000

void readLifeFile(const char* filename, Grid* grid, int x_offset, int y_offset);

void availableFiles(char *directory);

#endif