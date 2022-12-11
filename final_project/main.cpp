#include "cmd.hpp"
#include "grid.hpp"
#include "login_view.hpp"
#include "state_def.hpp"
#include <iostream>
#include <iterator>
#include <ncurses.h>

#define WELL_WIDTH 20
#define WELL_HEIGHT 20

using namespace std;
void init_game(void)
{
    int x, y;
}

int main()
{
    grid_t *grid_local;
    initscr();
    nodelay(stdscr, TRUE);                    // Do not wait for characters using getch.
    noecho();                                 // Do not echo input characters
    getmaxyx(stdscr, terminal_y, terminal_x); // Get the screen dimensions
    grid_local = init_grid(terminal_y / 2, terminal_x / 2, WELL_WIDTH, WELL_HEIGHT);
    grid_local = init_grid(((terminal_x / 2) - (WELL_WIDTH / 2)), 1, WELL_WIDTH, WELL_HEIGHT);
    while (1)
    {
        switch (next_view)
        {
        case INIT:
            clear();
            next_view = LOGIN_VIEW;
            break;
        case LOGIN_VIEW:
            clear();
            render_commands(LOGIN_VIEW, grid_local);
            // read in json
            take_in_user_cmd(grid_local);
            // dump to json
            update_login_view();
            next_view = MAKE_SELECT_VIEW;
            break;
        case MAKE_SELECT_VIEW:
            clear();
            mvprintw(grid_local->upper_left_y, 0, " Enter LOGIN_VIEW state");
            render_commands(MAKE_SELECT_VIEW, grid_local);
            take_in_user_cmd(grid_local);
            next_view = CURRENT_STATUS_VIEW;
            break;
        case MY_BOARD_VIEW:
            clear();
            mvprintw(grid_local->upper_left_y, 0, " Enter MY_BOARD_VIEW state");
            render_commands(MY_BOARD_VIEW, grid_local);
            take_in_user_cmd(grid_local);
            next_view = MY_PROJECT_VIEW;
            break;
        case CURRENT_STATUS_VIEW:
            clear();
            mvprintw(grid_local->upper_left_y, 0, " Enter CURRENT_STATUS_VIEW state");
            render_commands(CURRENT_STATUS_VIEW, grid_local);
            take_in_user_cmd(grid_local);
            draw_grid(grid_local);
            next_view = MY_BOARD_VIEW;
            break;
        case MY_PROJECT_VIEW:
            clear();
            mvprintw(grid_local->upper_left_y, 0, " Enter MY_PROJECT_VIEW  state");
            render_commands(MY_PROJECT_VIEW, grid_local);
            take_in_user_cmd(grid_local);
            next_view = MY_TASKVIEW;
            break;
        case MY_TASKVIEW:
            clear();
            mvprintw(grid_local->upper_left_y, 0, " Enter MY_TASKVIEW state");
            render_commands(MY_TASKVIEW, grid_local);
            take_in_user_cmd(grid_local);
            next_view = LOGIN_VIEW;
            break;
        }
        refresh();
    }
    return 0;
}
