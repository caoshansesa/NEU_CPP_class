/* well.cpp ---
 *
 * Filename: well.cpp
 * Description:
 * Author: Bryce
 * Maintainer: Adeel Bhutta
 * Created: Tue Sep  6 11:08:59 2016
 * Last-Updated: 01-10-2021
 *           By: Adeel Bhutta
 *     Update #: 0
 * Keywords:
 * Compatibility:
 *
 */

/* Commentary:
 *
 *
 *
 */

/* Change log:
 *
 *
 */

/* Copyright (c) 2016 IUB
 *
 * All rights reserved.
 *
 * Additional copyrights may follow
 */

/* Code: */

#include "well.hpp"

#include <ncurses.h>

#include <cstdlib>

well_t *init_well(int upper_left_x, int upper_left_y, int width, int height) {
  well_t *w;
  w = (well_t *)malloc(sizeof(well_t));
  w->upper_left_x = upper_left_x;
  w->upper_left_y = upper_left_y;
  w->width = width;
  w->height = height;
  w->draw_char = '#';
  w->color[0] = 0;
  w->color[1] = 0;
  w->color[2] = 0;
  return (w);
}

void draw_well(well_t *w) {
  int row_counter, column_counter;
  // Draw left side of well
  for (column_counter = w->upper_left_y;
       column_counter <= (w->upper_left_y + w->height); column_counter++) {
    mvprintw(column_counter, w->upper_left_x, "%c", w->draw_char);
  }

  // Draw right side of well
  for (column_counter = w->upper_left_y;
       column_counter <= (w->upper_left_y + w->height); column_counter++) {
    mvprintw(column_counter, (w->upper_left_x + w->width), "%c", w->draw_char);
  }

  // Draw Bottom of well
  for (row_counter = w->upper_left_x;
       row_counter <= (w->upper_left_x + w->width); row_counter++) {
    mvprintw(w->upper_left_y + w->height, row_counter, "%c", w->draw_char);
  }
}

well_t *changeWellSize(int upper_left_x, int upper_left_y, int width,
                       int height, well_t *w) {
  w->upper_left_x = upper_left_x;
  w->upper_left_y = upper_left_y;
  if (width < 10)
    w->width = 10;
  else
    w->width = width;

  w->height = height;

  return (w);
}

void undraw_well(well_t *w) {
  int row_counter, column_counter;
  // Undraw left side of well
  for (column_counter = w->upper_left_y;
       column_counter <= (w->upper_left_y + w->height); column_counter++) {
    mvprintw(column_counter, w->upper_left_x, " ", w->draw_char);
  }

  // Undraw right side of well
  for (column_counter = w->upper_left_y;
       column_counter <= (w->upper_left_y + w->height); column_counter++) {
    mvprintw(column_counter, (w->upper_left_x + w->width), " ", w->draw_char);
  }

  // Undraw Bottom of well
  for (row_counter = w->upper_left_x;
       row_counter <= (w->upper_left_x + w->width); row_counter++) {
    mvprintw(w->upper_left_y + w->height, row_counter, " ", w->draw_char);
  }
}
int prune_well(well_t *well) {
  int scored_lined_to_be_removed = 0;
  int current_well_height = well->height;
  int well_first_x = well->upper_left_x + 1;
  int current_well_width = well->width - 1;
  int well_first_y = well->upper_left_y;

  int space_teller = 0;
  int line;
  int y = 0, x = 0;
  chtype row_buf[current_well_height][current_well_width + 1];
  for (int y = 0; y < current_well_height; y++) {
    line = y + well_first_y;
    mvinchnstr(line, well_first_x, row_buf[y],
               current_well_width);  // read back all the well dot
    for (int x = 0; x < current_well_width; x++) {
      if (row_buf[y][x] == ' ')  // read in one line
      {
        space_teller = 1;
        break;
      }
    }
    if (space_teller == 0)  // if whole line are filled with the spcail case.
                            // means the line has reach to the end
    {
      scored_lined_to_be_removed += 1;
      mvprintw(line, well_first_x, "%*c", current_well_width, ' ');
      drop_lines(well, line);
    }
    space_teller = 0;
  }
  refresh();

  return scored_lined_to_be_removed;
}

void drop_lines(well_t *well,
                int del_line)  // del_line is the line will get deleted
{
  int first_y = well->upper_left_y;
  int height = del_line - first_y;
  int width = well->width - 1;
  int first_x = well->upper_left_x + 1;

  // chtype row_buf[height][width + 1];
  chtype sign;
  int line = del_line - 1;
  int y = 0, x = 0;
  int color = 7;
  init_pair(color, color, color);
  for (; line > first_y + 1; line--) {
    for (x = 0; x < width; x++) {
      sign = mvinch(line, first_x + x);
      if (sign != ' ') {
        attron(COLOR_PAIR(color));
        mvprintw(line + 1, first_x + x, "%c", sign);
        attroff(COLOR_PAIR(color));
      } else
        mvprintw(line + 1, first_x + x, "%c", sign);
    }
    y++;
  }
}
