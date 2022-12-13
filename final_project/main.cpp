#include "cmd.hpp"
#include "grid.hpp"
#include "json.hpp"
#include "login_view.hpp"
#include "state_def.hpp"
#include <iostream>
#include <iterator>
#include <ncurses.h>
#include <string>
#include <vector>

#define WELL_WIDTH 20
#define WELL_HEIGHT 20

static Project *global_addr;
unsigned int microsecond = 1000000;

using namespace std;
void init_game(void)
{
    int x, y;
}

int main()
{
    grid_t *grid_local;
    initscr();
    nodelay(stdscr, TRUE); // Do not wait for characters using getch.
    cbreak();
    getmaxyx(stdscr, terminal_y, terminal_x); // Get the screen dimensions
    grid_local = init_grid(terminal_y / 2, terminal_x / 2, WELL_WIDTH, WELL_HEIGHT);
    grid_local = init_grid(((terminal_x / 2) - (WELL_WIDTH / 2)), 1, WELL_WIDTH, WELL_HEIGHT);
    deserialize("project.json");

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
            render_commands_list(LOGIN_VIEW, grid_local);
            take_in_user_cmd(grid_local);
            update_login_view();
            next_view = MAKE_SELECT_VIEW;
            break;
        case MAKE_SELECT_VIEW:
            noecho(); // disable the curse from the screen
            clear();
            mvprintw(grid_local->upper_left_y, 0, " Enter LOGIN_VIEW state");
            render_commands_list(MAKE_SELECT_VIEW, grid_local);
            render_data_region(MAKE_SELECT_VIEW, grid_local);
            next_view = control_menu();
            break;
        case MY_BOARD_VIEW:
            noecho(); // enable the curse from the screen
            clear();
            mvprintw(grid_local->upper_left_y, 0, " Enter MY_BOARD_VIEW state");
            render_commands_list(MY_BOARD_VIEW, grid_local);
            render_data_region(MY_BOARD_VIEW, grid_local);
            take_in_user_cmd(grid_local);
            next_view = MY_PROJECT_VIEW;
            break;
        case CURRENT_STATUS_VIEW:
            echo();
            clear();
            mvprintw(grid_local->upper_left_y, 0, " Enter CURRENT_STATUS_VIEW state");
            render_commands_list(CURRENT_STATUS_VIEW, grid_local);
            render_data_region(CURRENT_STATUS_VIEW, grid_local);
            take_in_user_cmd(grid_local);
            next_view = MY_BOARD_VIEW;
            break;
        case MY_PROJECT_VIEW:
            clear();
            mvprintw(grid_local->upper_left_y, 0, " Enter MY_PROJECT_VIEW state");
            render_commands_list(MY_PROJECT_VIEW, grid_local);
            render_data_region(MY_PROJECT_VIEW, grid_local);
            take_in_user_cmd(grid_local);
            next_view = MY_TASKVIEW;
            break;
        case MY_TASKVIEW:
            clear();
            mvprintw(grid_local->upper_left_y, 0, " Enter MY_TASKVIEW state");
            render_commands_list(MY_TASKVIEW, grid_local);
            render_data_region(MY_TASKVIEW, grid_local);
            take_in_user_cmd(grid_local);
            next_view = MAKE_SELECT_VIEW;
            break;
        }
        refresh();
        mssleep(100);
    }
    return 0;
}
