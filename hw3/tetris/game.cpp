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
#include <unistd.h> 
#include <ncurses.h>
#include <ctime>
#include <cstdlib>
#include "game.hpp"
#include "well.hpp"
#include "tetris.hpp"
#include "tetromino.hpp"
#include "key.hpp"

void init_game(void) {
  int x,y;
}

int game(void) {
  static int state = INIT;
  tetromino_t *next = NULL;
  tetromino_t *current = NULL;
  well_t *w;
  int x,y;
  int c;
  int arrow;
  struct timespec tim = {0,1000000};  // Each execution of while(1) is approximately 1mS
  struct timespec tim_ret;
  int move_counter = 0;
  int random_fall;
  int fall_options[5] = {50, 1000, 250, 750, 500};
  int move_timeout = BASE_FALL_RATE;            
  int init_move = MOVE_OK;

  time_t time_start = time(NULL);
  time_t time_passed = 0; 
  while(1) {
    switch(state) {
    case INIT:               // Initialize the game, only run one time 
      initscr();
      start_color();
      nodelay(stdscr,TRUE);  // Do not wait for characters using getch.  
      noecho();              // Do not echo input characters 
      getmaxyx(stdscr,y,x);  // Get the screen dimensions 
      w = init_well(((x/2)-(WELL_WIDTH/2)),1,WELL_WIDTH,WELL_HEIGHT);
      draw_well(w);
      srand(time(NULL));     // Seed the random number generator with the time. Used in create tet. 
      state = ADD_PIECE;
      break;
    case ADD_PIECE:          // Add a new piece to the game
      init_move = MOVE_OK;
      if (next) {
	      undisplay_tetromino(next);
          current = next;
	      init_move = move_tet(current, (w->upper_left_x+(w->width/2)), w->upper_left_y);
	      next = create_tetromino (w->upper_left_x + w->width + 5, w->upper_left_y + (w->height/2));
      }
      else {
	      current = create_tetromino ((w->upper_left_x+(w->width/2)), w->upper_left_y);
      	next = create_tetromino (w->upper_left_x + w->width + 5, w->upper_left_y + (w->height/2));

        
      }
      display_tetromino(current);
      display_tetromino(next);
      random_fall = rand() % 5;
      move_timeout = fall_options[random_fall];
      state = MOVE_PIECE;
      break;
    case MOVE_PIECE:         // Move the current piece 
      if ((arrow = read_escape(&c)) != NOCHAR) {
	switch (arrow) {
        case UP:
              undisplay_tetromino(current);
              rotate_cw(current);
              display_tetromino(current);
              mvprintw(10,10,"UP            ");
          break;
        case DOWN:
              undisplay_tetromino(current);
              rotate_ccw(current);
              display_tetromino(current);
              mvprintw(10,10,"DOWN          ");
          break;
        case LEFT:
              undisplay_tetromino(current);
              move_tet(current, current->upper_left_x - 1, current->upper_left_y);
              display_tetromino(current);	
              mvprintw(10,10,"LEFT         ");
          break;
        case RIGHT:
              undisplay_tetromino(current);
              move_tet(current, current->upper_left_x + 1, current->upper_left_y);
              display_tetromino(current);
             mvprintw(10,10,"RIGHT         ");
          break;
        case REGCHAR: 
          mvprintw(10,10,"REGCHAR 0x%02x",c);
	  if (c == 'q') {
	    state = EXIT;
 	  }
          else if (c == 'p'){
            time_passed += difftime(time(NULL), time_start);
            state = PAUSE;
          }
	  else if (c == ' '){
	    move_timeout = DROP_RATE;
	    mvprintw(10,10,"SPACE 0x%02x",c);
	  }
	}
      } 
      if (move_counter++ >= move_timeout) {
	move_counter = 0;
	move_timeout = fall_options[random_fall];
        undisplay_tetromino(current);
	int move_down = move_tet(current, current->upper_left_x , current->upper_left_y + 1);
        display_tetromino(current);
      }
      break;
    case EXIT:
      endwin();
      return(0);
      break;
    }
    refresh();
    nanosleep(&tim,&tim_ret);
  }
}

/* game.cpp ends here */
