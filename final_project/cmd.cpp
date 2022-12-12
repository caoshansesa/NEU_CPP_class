#include "cmd.hpp"
#include "grid.hpp"
#include "state_def.hpp"
#include <vector>
#include <cstring>
#include <string>
#include <cstdio>
#include <iostream>
#include <iterator>
#include <ncurses.h>

using namespace std;

map<string, string> people_map;
vector<Project> global_projects_vector;

WINDOW *todo_window;
WINDOW *ongoing_window;
WINDOW *done_window;
WINDOW *current_status_win;
WINDOW *my_task_window;
WINDOW *prj_summary_window;

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
    my_task_window = create_newwin(40, 80, 6, 25);
    mvwprintw(my_task_window, 2, 2, "this is a box");
    wrefresh(my_task_window);
}

/*
 * @brief Show my proejct summary view
 * */
void show_my_project_summary_view()
{
    mvprintw(5, 5, "My Proejct Summary");
    prj_summary_window = create_newwin(40, 80, 6, 25);
    mvwprintw(prj_summary_window, 2, 2, "this is a box");
    wrefresh(prj_summary_window);
}

/*
 * @brief Show the current status View
 * */
void show_my_current_status_view()
{
}

/*
 * @brief construct static my board view
 * */
void show_static_my_board_summary_view()
{
    mvprintw(30, 0, "a: Add new task\n");
    mvprintw(31, 0, "m: Move task to doing\n");
    mvprintw(32, 0, "r: Remove task\n");

    todo_window = create_newwin(40, 49, 6, 25);
    ongoing_window = create_newwin(40, 49, 6, 75);
    done_window = create_newwin(40, 49, 6, 125);

    mvwprintw(todo_window, 2, 2, "this is a box");
    mvwprintw(ongoing_window, 2, 2, "this is a box");
    mvwprintw(done_window, 2, 2, "this is a box");
    wrefresh(todo_window);
    wrefresh(ongoing_window);
    wrefresh(done_window);

    mvprintw(5, 50, "TODO:");
    mvprintw(5, 100, "DOING:");
    mvprintw(5, 150, "DONE:");
    render_my_board
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
    clear();
    mvprintw(0, 0, " Enter Slection View State");
    attron(A_REVERSE | A_BOLD);
    mvprintw(20, 70, "1. View/Manage My Board");
    mvprintw(22, 70, "2. View My Projects");
    mvprintw(24, 70, "3. View/Edit Current Status");
    attroff(A_REVERSE | A_BOLD);
    attron(A_BOLD | A_BLINK);
    mvprintw(30, 65, "Please choose your view here");
    noecho();
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

//AMEL START EDIT
void render_curent_status_view_data_region()
{

    current_status_win = create_newwin(40, 80, 5, 26);
    int i = 0;
    for (auto &prj_idx : global_projects_vector) // access by reference to avoid copying
    {
        mvwprintw(current_status_win, i+ 2, 2, prj_idx.name.c_str());
        mvwprintw(current_status_win, i + 3, 2, prj_idx.projectManagerUserName.c_str());
        mvwprintw(current_status_win, i + 4, 2, prj_idx.assignDate.c_str());
        mvwprintw(current_status_win, i + 5, 2, prj_idx.dueDate.c_str());
        mvwprintw(current_status_win, i + 6, 2, prj_idx.description.c_str());
        i= i+10;
    }

    wrefresh(current_status_win);
}

/*
 * rendering my board view data region
 * */
//AMEL EDIT HERE 1.
void render_my_board_view_data_region()
{
    todo_window;
    ongoing_window;
    done_window;
    int x,y,z = 2;
    vector<Task> tasks= global_projects_vector[0].tasks;
    for (auto &task_idx : tasks) // access by reference to avoid copying
    {
        if(task_idx.status == "TODO"){
        mvwprintw(todo_window, x, 2, task_idx.title.c_str());
        x+2;
        }
        if(task_idx.status == "ONGOING"){
            mvwprintw(ongoing_window, y + 2, 2, task_idx.title.c_str());
            y+2;
        }
        if(task_idx.status == "DOING"){
            mvwprintw(done_window, z, 2, task_idx.title.c_str());
            z+2;
        }
    }

    wrefresh(todo_window);
    wrefresh(ongoing_window);
    wrefresh(done_window);
    // for window_myboard
    // doing, to do, done windows
    // loop for 1 project
    // make it look for task which belongs to each "status" : to do, doing, done
    // print each of the tasks into 3 different windows with task name only
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
        render_curent_status_view_data_region();
        break;
    case MY_BOARD_VIEW:
        render_my_board_view_data_region();
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

