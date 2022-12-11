#ifndef GRID_H
#define GRID_H

#include <ctime>
typedef struct grid
{
    int upper_left_x;
    int upper_left_y;
    int width;
    int height;
    char draw_char;
    char color[3];
} grid_t;

grid_t *init_grid(int, int, int, int);

void draw_grid(grid_t *);

void clear_inside_grid(grid_t *grid);

int mssleep(long miliseconds);

#endif
