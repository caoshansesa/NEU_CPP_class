#include "cmd.hpp"
#include "grid.hpp"
#include "state_def.hpp"
#include <cstdio>
#include <iostream>
#include <iterator>
#include <ncurses.h>

using namespace std;

/* *
 *@brief Draw a window inside the current view based on the size
 * */
WINDOW *create_newwin(int height, int width, int starty, int startx)
{

    WINDOW *win = newwin(height, width, starty, startx);
    refresh();
    box(win, '-', '-');
    wborder(win, '*', '*', '*', '*', '*', '*', '*', '*');
    wrefresh(win);
    return win;
}

void destroy_win(WINDOW *local_win)
{
    /* box(local_win, ' ', ' '); : This won't produce the desired
     * result of erasing the window. It will leave it's four corners
     * and so an ugly remnant of window.  */

    wborder(local_win, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');

    /* The parameters taken are
     * 1. win: the window on which to operate
     * 2. ls: character to be used for the left side of the window
     * 3. rs: character to be used for the right side of the window
     * 4. ts: character to be used for the top side of the window
     * 5. bs: character to be used for the bottom side of the window
     * 6. tl: character to be used for the top left corner of the window
     * 7. tr: character to be used for the top right corner of the window
     * 8. bl: character to be used for the bottom left corner of the window
     * 9. br: character to be used for the bottom right corner of the window */

    wrefresh(local_win);
    delwin(local_win);
}

int read_escape(int *read_char)
{
    int c;
    c = getch();
    *read_char = c;
    return 0;
}

/* *
 * @brief read in a string and return the string
 * */
string getstring()
{
    string input;
    echo();
    // this reads from buffer after <ENTER>, not "raw"
    // so any backspacing etc. has already been taken care of
    int ch = getch();
    while (ch != '\n')
    {
        input.push_back(ch);
        ch = getch();
    }
    return input;
}

/* *
 * @brief, Add the login readline, read in a string which used as username
 * */
void get_name_from_login()
{
    // start get user name: new window
    char mesg[] = "Please input your username ";
    int x, y;
    initscr();
    getmaxyx(stdscr, y, x);
    mvprintw(y / 2, (x - strlen(mesg)) / 2, "%s", mesg);
    refresh();
    username = getstring();
    nodelay(stdscr, true);
    noecho();
    endwin();
    refresh();
}

/*
 * @brief Show my task view
 * */
void show_my_task_view()
{
    attron(A_REVERSE | A_BOLD);
    mvprintw(5, 5, "My Task View");
    attroff(A_REVERSE | A_BOLD);
    WINDOW *summary_window = create_newwin(40, 80, 6, 25);
    mvwprintw(summary_window, 2, 2, "this is a box");
    wrefresh(summary_window);
}

/*
 * @brief Show my proejct summary view
 * */
void show_my_project_summary_view()
{
    mvprintw(5, 5, "My Proejct Summary");
    WINDOW *summary_window = create_newwin(40, 80, 6, 25);
    mvwprintw(summary_window, 2, 2, "this is a box");
    wrefresh(summary_window);
}

/*
 * @brief Show the current status View
 * */
void show_my_current_status_view()
{
    mvprintw(0, 5, "Current Status");
    grid_t *my_current_status_grid = init_grid(26, 5, 80, 40);
    // draw_grid(my_current_status_grid);
    WINDOW *local_win = create_newwin(40, 80, 5, 26);
    mvwprintw(local_win, 1, 1, "this is a box");
    wrefresh(local_win);
}

/*
 * @brief construct static my board view
 * */
void show_static_my_board_summary_view()
{
    mvprintw(30, 0, "a: Add new task\n");
    mvprintw(31, 0, "m: Move task to doing\n");
    mvprintw(32, 0, "r: Remove task\n");

    WINDOW *todo_window = create_newwin(40, 49, 6, 25);
    WINDOW *ongoing_window = create_newwin(40, 49, 6, 75);
    WINDOW *done_window = create_newwin(40, 49, 6, 125);

    mvwprintw(todo_window, 2, 2, "this is a box");
    mvwprintw(ongoing_window, 2, 2, "this is a box");
    mvwprintw(done_window, 2, 2, "this is a box");
    wrefresh(todo_window);
    wrefresh(ongoing_window);
    wrefresh(done_window);

    mvprintw(5, 50, "TODO:");
    mvprintw(5, 100, "DOING:");
    mvprintw(5, 150, "DONE:");
}

/*
 * @brief construct static view of LOGIN_VIEW
 * */
void show_static_view_of_login()
{
    mvprintw(0, 0, " Enter LOGIN_VIEW state");
    get_name_from_login();
    // handle the username global variables here to verify the name and
}

/* @brief construct static view of MAKE_SELECT_VIEW
 * */
void show_static_view_of_selection()
{
    attron(A_REVERSE | A_BOLD);
    mvprintw(20, 70, "1. View/Manage My Board");
    mvprintw(22, 70, "2. View My Projects");
    mvprintw(24, 70, "3. View/Edit Current Status");
    attroff(A_REVERSE | A_BOLD);
    attron(A_BOLD | A_BLINK);
    mvprintw(30, 65, "Please choose your view here");
    attroff(A_BOLD | A_BLINK);
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
/*
 * rendering LOGIN_VIEW data region
 * */
void render_Login_view_data_region()
{
    // Empty, no data hand in login view
}

/*
 * rendering selction view data region
 * */
void render_Make_selection_view_data_region()
{
    // Empty, no data hand in login view
}

/*
 * rendering current status view data region
 * */
void render_curent_status_view_data_region()
{
}

/*
 * rendering my board view data region
 * */
void render_my_board_view_data_region()
{
}

/*
 * rendering my project view data region
 * */
void render_my_project_view_data_region()
{
}

/*
 * rendering my task view data region
 * */
void render_my_task_view_data_region()
{
}

/*
 *@ brief Render data region based on the Project and people objs
 * */
void render_data_region(enum VIEW_STATE state, grid_t *grid)
{
    switch (state)
    {
    case INIT:
        break;
    case LOGIN_VIEW:
        break;
    case MAKE_SELECT_VIEW:
        break;
    case CURRENT_STATUS_VIEW:
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

