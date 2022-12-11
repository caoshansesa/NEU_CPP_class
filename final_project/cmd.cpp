#include "cmd.hpp"
#include "grid.hpp"
#include "state_def.hpp"
#include <cstdio>
#include <iostream>
#include <iterator>
#include <ncurses.h>

using namespace std;

int read_escape(int *read_char)
{
    int c;
    c = getch();
    *read_char = c;
    return 0;
}

/*
 * @brief construct static current status view
 * */
void show_static_view_of_current_status()
{
    mvprintw(20, 50, "TODO:");
    mvprintw(20, 100, "DOING:");
    mvprintw(20, 150, "DONE:");
}

/*
 * @brief construct static view of LOGIN_VIEW
 * */
void show_static_view_of_login()
{
    mvprintw(20, 100, "Login:");
    mvprintw(40, 0, " Enter LOGIN_VIEW state");
}

/* @brief construct static view of MAKE_SELECT_VIEW
 * */
void show_static_view_of_selection()
{

    mvprintw(20, 100, "1. View/Manage My Board");
    mvprintw(21, 100, "2. View My Projects");
    mvprintw(22, 100, "3. View/Edit Current Status");
}

/**
 *
 * Renders the command list
 **/
void render_commands(enum VIEW_STATE state, grid_t *grid)
{
    switch (state)
    {
    case INIT:
        cout << "a: Add new task\n" << endl;
        break;
    case LOGIN_VIEW:
        show_static_view_of_login();
        break;
    case MAKE_SELECT_VIEW:
        show_static_view_of_selection();
        break;
    case CURRENT_STATUS_VIEW:
        show_static_view_of_current_status();
        break;
    case MY_BOARD_VIEW:
        break;
    case MY_PROJECT_VIEW:
        break;
    case MY_TASKVIEW:
        break;
    }
}

/** @brief
 *  in RUNNING state, take in user input, update current_user_obj, current_project_obj
 *  and dump changes to json
 *
 *  in EXIT state, exit and goto next view
 *  @return void
 */
void take_in_user_cmd(grid_t *grid)
{
    enum CMD_STATE next_state = CMD_INIT;
    int break_loop = 1;
    int keyboard_input = 0;
    while (break_loop)
    {
        switch (next_state)
        {
        case CMD_INIT:
        case RUNNING:
            mvprintw(2, 2, "Insert q to quit");
            refresh();
            read_escape(&keyboard_input);
            if (keyboard_input == 'q')
            {
                next_state = EXIT;
            }
            break;
        case EXIT:
            return;

        default:
            break;
        }
    }
}

