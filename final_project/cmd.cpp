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
 * @brief Show my task view
 * */
void show_my_task_view()
{
    mvprintw(5, 5, "My Task View");
    grid_t *my_current_status_grid = init_grid(26, 5, 80, 40);
    draw_grid(my_current_status_grid);
}

/*
 * @brief Show my proejct summary view
 * */
void show_my_project_summary_view()
{
    mvprintw(5, 5, "My Proejct Summary");
    grid_t *my_current_status_grid = init_grid(26, 5, 80, 40);
    draw_grid(my_current_status_grid);
}

/*
 * @brief Show the current status View
 * */
void show_my_current_status_view()
{
    mvprintw(5, 5, "Current Status");
    grid_t *my_current_status_grid = init_grid(26, 5, 80, 40);
    draw_grid(my_current_status_grid);
}

/*
 * @brief construct static my board view
 * */
void show_static_my_board_summary_view()
{
    grid_t *todo_grid = init_grid(25, 6, 49, 40);
    grid_t *ongoing_grid = init_grid(75, 6, 49, 40);
    grid_t *done_grid = init_grid(125, 6, 49, 40);

    draw_grid(todo_grid);
    draw_grid(ongoing_grid);
    draw_grid(done_grid);
    mvprintw(5, 50, "TODO:");
    mvprintw(5, 100, "DOING:");
    mvprintw(5, 150, "DONE:");
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
 * Renders the command list and staic frame of each view
 **/
void render_commands_list(enum VIEW_STATE state, grid_t *grid)
{
    switch (state)
    {
    case INIT:
        break;
    case LOGIN_VIEW:
        show_static_view_of_login();
        break;
    case MAKE_SELECT_VIEW:
        show_static_view_of_selection();
        break;
    case CURRENT_STATUS_VIEW:
        show_my_current_status_view();
        break;
    case MY_BOARD_VIEW:
        show_static_my_board_summary_view();
        break;
    case MY_PROJECT_VIEW:
        show_my_project_summary_view();
        break;
    case MY_TASKVIEW:
        show_my_task_view();
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

