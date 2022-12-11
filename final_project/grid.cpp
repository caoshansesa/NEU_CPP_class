#include "grid.hpp"
#include <cstdlib>
#include <ncurses.h>

grid_t *init_grid(int upper_left_x, int upper_left_y, int width, int height)
{
    grid_t *grid;
    grid = (grid_t *)malloc(sizeof(grid_t));
    grid->upper_left_x = upper_left_x;
    grid->upper_left_y = upper_left_y;
    grid->width = width;
    grid->height = height;
    grid->draw_char = '#';
    return (grid);
}

void draw_grid(grid_t *grid)
{
    int row_counter, column_counter;
    // Draw left side of grid
    for (column_counter = grid->upper_left_y; column_counter <= (grid->upper_left_y + grid->height); column_counter++)
    {
        mvprintw(column_counter, grid->upper_left_x, "%c", grid->draw_char);
    }

    // Draw right side of grid
    for (column_counter = grid->upper_left_y; column_counter <= (grid->upper_left_y + grid->height); column_counter++)
    {
        mvprintw(column_counter, (grid->upper_left_x + grid->width), "%c", grid->draw_char);
    }

    // Draw Bottom of grid
    for (row_counter = grid->upper_left_x; row_counter <= (grid->upper_left_x + grid->width); row_counter++)
    {
        mvprintw(grid->upper_left_y + grid->height, row_counter, "%c", grid->draw_char);
    }

    // Draw Top of grid
    for (row_counter = grid->upper_left_x; row_counter <= (grid->upper_left_x + grid->width); row_counter++)
    {
        mvprintw(grid->upper_left_y, row_counter, "%c", grid->draw_char);
    }
}

void clear_inside_grid(grid_t *grid)
{
    int colum_index = grid->upper_left_x;
    for (int i = grid->upper_left_x + 1; i < (grid->width + grid->upper_left_x); i++)
    {

        int row_counter, column_counter;
        for (column_counter = grid->upper_left_y + 1; column_counter <= (grid->upper_left_y + grid->height);
             column_counter++)
        {
            mvprintw(column_counter, i, " ", grid->draw_char);
        }
    }
}

int mssleep(long miliseconds)
{
    struct timespec rem;
    struct timespec req = {
        (int)(miliseconds / 1000),     /* secs (Must be Non-Negative) */
        (miliseconds % 1000) * 1000000 /* nano (Must be in range of 0 to 999999999) */
    };

    return nanosleep(&req, &rem);
}
