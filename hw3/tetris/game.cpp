/* game.cpp ---
 *
 * Filename: game.cpp
 * Description:
 * Author: Bryce
 * Maintainer: Adeel Bhutta
 * Created: Tue Sep  6 11:08:59 2016
 * Last-Updated: 01-10-2021
 *           By: Adeel Bhutta
 *     Update #: 20
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
#include "game.hpp"

#include <ncurses.h>
#include <unistd.h>

#include <cstdlib>
#include <cstring>
#include <ctime>
#include <string>

#include "key.hpp"
#include "tetris.hpp"
#include "tetromino.hpp"
#include "well.hpp"

char str[80] = {0};
int lives = 1;
time_t time_start = time(NULL);
int score = 0;
void init_game(void) { int x, y; }

void game_over() {
  // start get user name: new window
  char mesg[] = "GAME OVER, the score is :";
  int x, y;
  initscr();
  getmaxyx(stdscr, y, x);
  mvprintw(y / 2 + y / 4, (x - strlen(mesg)) / 2, "%s%d", mesg, score);
  nodelay(stdscr, true);
  noecho();
  napms(1000);
  endwin();
  refresh();
}

void get_name() {
  // start get user name: new window
  char mesg[] = "Welcome to Tetris, please enter your NAME: ";
  int x, y;
  initscr();
  getmaxyx(stdscr, y, x);
  mvprintw(y / 2, (x - strlen(mesg)) / 2, "%s", mesg);
  getstr(str);
  nodelay(stdscr, true);
  noecho();
  endwin();
  refresh();
}

int game(void) {
  static int state = INIT;
  tetromino_t *next = NULL;
  tetromino_t *current = NULL;
  well_t *w;
  int x, y;
  int c;
  int arrow;
  struct timespec tim = {
      0, 1000000};  // Each execution of while(1) is approximately 1mS
  struct timespec tim_ret;
  int move_counter = 0;
  int move_timeout = BASE_FALL_RATE;
  int display_y =
      WELL_HEIGHT / 8;  // display_x to help us place the panel on the side
  int display_x = WELL_WIDTH + (WELL_WIDTH / 8);

  while (1) {
    if (next) {
      mvprintw(w->upper_left_y + (display_y * 2), w->upper_left_x + display_x,
               "Next Tetromino:");
    }
    switch (state) {
      case INIT:  // Initialize the game, only run one time
        initscr();
        nodelay(stdscr, TRUE);   // Do not wait for characters using getch.
        noecho();                // Do not echo input characters
        getmaxyx(stdscr, y, x);  // Get the screen dimensions
        w = init_well(((x / 2) - (WELL_WIDTH / 2)), 1, WELL_WIDTH, WELL_HEIGHT);
        draw_well(w);
        srand(time(NULL));  // Seed the random number generator with the time.
        // Used in create tet.
        state = ADD_PIECE;
        break;
      case ADD_PIECE:  // Add a new piece to the game
        if (next) {
          undisplay_tetromino(next);  // need to alwar
          move_timeout = (rand() % BASE_FALL_RATE) +
                         10;  // Random drop rate for each piece
          next->upper_left_x = w->width / 2 + w->upper_left_x;
          next->upper_left_y = w->upper_left_y;
          current = next;
          if (check_collision(current) ==
              COLLIDE) {  // check for check_collision, meaning we could not
                          // move the piece any more, so lose a life and start
                          // again
            lives--;
            state = CALL_GAME_AGAIN;
            break;
          }
          next = create_tetromino(w->upper_left_x + display_x,
                                  w->upper_left_y + (display_y * 3));
        } else {
          current = create_tetromino(w->upper_left_x + (w->width / 2),
                                     w->upper_left_y);
          next = create_tetromino(w->upper_left_x + display_x,
                                  w->upper_left_y + (display_y * 3));
        }

        display_tetromino(current);
        display_tetromino(next);
        state = MOVE_PIECE;
        break;
      case MOVE_PIECE:  // Move the current piece
        if ((arrow = read_escape(&c)) != NOCHAR) {
          switch (arrow) {
            case UP:  // For each of the cases, un-dispaly and move then display
                      // again
              mvprintw(10, 10, "UP            ");
              undisplay_tetromino(current);
              rotate_cw(current);
              display_tetromino(current);
              break;
            case DOWN:
              mvprintw(10, 10, "DOWN          ");
              undisplay_tetromino(current);
              rotate_ccw(current);
              display_tetromino(current);
              break;
            case LEFT:
              mvprintw(10, 10, "LEFT          ");
              undisplay_tetromino(current);
              move_tet(current, current->upper_left_x - (WELL_WIDTH / 10),
                       current->upper_left_y);
              display_tetromino(current);
              break;
            case RIGHT:
              mvprintw(10, 10, "RIGHT         ");
              undisplay_tetromino(current);
              move_tet(current, current->upper_left_x + (WELL_WIDTH / 10),
                       current->upper_left_y);
              display_tetromino(current);
              break;
            case REGCHAR:
              mvprintw(10, 10, "REGCHAR 0x%02x", c);
              if (c == 'q' || c == 'x') {  // quit by pressing q or x
                state = EXIT;
              } else if (c == 'p') {  // hit p, will pause the game, hit p
                                      // again, it will resume
                state = PAUSE;
              } else if (c == ' ') {
                move_timeout = DROP_RATE;  // press space to change to a faster
                                           // tet drop rate
                mvprintw(10, 10, "SPACE 0x%02x", c);
              }
              break;
          }
        }
        if (move_counter++ >=
            move_timeout) {  // drop tetromino in regular speed
          move_counter = 0;
          undisplay_tetromino(current);
          int ret = move_tet(current, current->upper_left_x,
                             current->upper_left_y + 1);
          display_tetromino(current);
          if (ret == MOVE_FAILED) {  // if Move fails, you reach the bottom of
                                     // the well or hit another piece
            state = ADD_PIECE;       // Add another piece and continue
          }
        }
        break;
      case CALL_GAME_AGAIN:  // As long as you have life, then start another
                             // round, otherwise, GAME_OVER
        if (lives > 0) {
          clear();
          endwin();
          refresh();
          state = INIT;
        } else {
          state = GAME_OVER;
        }
        break;

      case PAUSE:
        mvprintw(20, 20, "PAUSE");
        int read_back_dummy;
        if ((read_back_dummy = read_escape(&c)) !=
            NOCHAR) {  // similar to cin, wait for the next input and if the
                       // input is 'p', start to move piece again
          if (c == 'p') {
            time_start = time(NULL);
            state = MOVE_PIECE;
          }

          else if (c == 'q') {
            state = EXIT;
          }
        }
        break;
      case EXIT:
        endwin();
        return (0);
        break;

      case GAME_OVER:
        game_over();

        break;
    }

    refresh();
    nanosleep(&tim, &tim_ret);
  }
}

/* game.cpp ends here */
