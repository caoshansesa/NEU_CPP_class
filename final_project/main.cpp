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
    int x, y = 0;
    initscr();
    nodelay(stdscr, TRUE);  // Do not wait for characters using getch.
    noecho();               // Do not echo input characters
    getmaxyx(stdscr, y, x); // Get the screen dimensions
    grid_local = init_grid(x / 2, 0, WELL_WIDTH, WELL_HEIGHT);
    enum VIEW_STATE next_view = INIT;
    draw_grid(grid_local);
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
            mvprintw(grid_local->upper_left_y, 0, " Enter LOGIN_VIEW state");
            config_state_login();
            render_commands(LOGIN_VIEW, grid_local);
            constrcut_login_view();
            take_in_user_cmd(grid_local);
            update_login_view();
            next_view = MAKE_SELECT_VIEW;
            break;
        case MAKE_SELECT_VIEW:
            cout << "Enter MAKE_SELECT_VIEW state" << endl;
            break;
        case CURRENT_STATUS_VIEW:
            cout << "Enter CURRENT_STATUS_VIEW state" << endl;
            break;
        case MY_BOARD_VIEW:
            cout << "Enter MY_BOARD_VIEW state" << endl;
            break;
        case MY_PROJECT_VIEW:
            cout << "Enter MY_TASKVIEW state" << endl;
            break;
        case MY_TASKVIEW:
            cout << "Enter MY_TASKVIEW state" << endl;
            break;
        }
        refresh();
    }
    return 0;
}
