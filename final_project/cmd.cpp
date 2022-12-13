#include "cmd.hpp"
#include "grid.hpp"
#include "state_def.hpp"
#include <cstdio>
#include <cwchar>
#include <iostream>
#include <iterator>
#include <ncurses.h>
#include <string.h>
#include <string>

using namespace std;

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))
#define CTRLD 4

void goto_my_board_view(char *name)
{
    move(50, 40);
    clrtoeol();
    mvprintw(50, 40, "Item selected is : %s", name);

    if (name[0] == '1')
    {
        next_view = MY_BOARD_VIEW;
        mvprintw(30, 30, "MY_BOARD_VIEW selected");
    }

    if (name[0] == '2')
    {
        next_view = MY_BOARD_VIEW;
    }

    if (name[0] == '3')
    {
        next_view = MY_BOARD_VIEW;
    }
}

void goto_my_project_view()
{
    next_view = MY_PROJECT_VIEW;
}
void goto_my_task_view()
{
    next_view = MY_TASKVIEW;
}

void goto_my_current_status_view()
{
    next_view = CURRENT_STATUS_VIEW;
}

void goto_my_slection_view()
{
    next_view = MAKE_SELECT_VIEW;
}

void goto_Login_view()
{
    next_view = LOGIN_VIEW;
}

void control_menu()
{
    char *choices[] = {"1. View/Manage My Board", "2. View My Projects", "3. View/Edit Current Status"};
    char *return_index[] = {"1", "2", "3"};
    ITEM **my_items;
    int c;
    MENU *my_menu;
    int n_choices, i;
    ITEM *cur_item;

    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);

    n_choices = ARRAY_SIZE(choices);
    my_items = (ITEM **)calloc(n_choices + 1, sizeof(ITEM *));
    for (i = 0; i < n_choices; ++i)
    {
        my_items[i] = new_item(choices[i], return_index[i]);
        set_item_userptr(my_items[i], reinterpret_cast<void *>(goto_my_board_view));
    }
    my_items[n_choices] = (ITEM *)NULL;
    my_menu = new_menu((ITEM **)my_items);
    post_menu(my_menu);
    refresh();

    while ((c = getch()) != KEY_F(1))
    {
        switch (c)
        {
        case KEY_DOWN:
            menu_driver(my_menu, REQ_DOWN_ITEM);
            break;
        case KEY_UP:
            menu_driver(my_menu, REQ_UP_ITEM);
            break;
        case 10: /* Enter */
        {
            ITEM *cur;
            void (*p)(char *);
            cur = current_item(my_menu);
            p = (void (*)(char *))item_userptr(cur);
            p((char *)item_name(cur));
            pos_menu_cursor(my_menu);
            break;
        }
        break;
        }
    }

    unpost_menu(my_menu);
    for (i = 0; i < n_choices; ++i)
    {
        free_item(my_items[i]);
    }
    free_menu(my_menu);
    endwin();
}

map<string, string> people_map;
vector<Project> global_projects_vector;

WINDOW *todo_window;
WINDOW *ongoing_window;
WINDOW *done_window;
WINDOW *cmd_sumary_window;
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
    clrtoeol(); // delete current line
    return input;
}

/* *
 * @brief, Add the login readline, read in a string which used as username
 * */
void get_name_from_login()
{
    // start get user name: new window
    string mesg = "Please input your username ";
    int x, y;
    initscr();
    getmaxyx(stdscr, y, x);
    mvprintw(y / 2, (x - mesg.size()) / 2, "%s", mesg.c_str());
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
    my_task_window = create_newwin(40, 80, 6, 50);
    mvwprintw(my_task_window, 2, 2, "this is a box");
    wrefresh(my_task_window);
}

/*
 * @brief Show my proejct summary view
 * */
void show_my_project_summary_view()
{
    mvprintw(5, 5, "My Proejct Summary");
    prj_summary_window = create_newwin(40, 80, 6, 50);
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
    mvprintw(6, 0, "a: Add new task\n");
    mvprintw(7, 0, "m: Move task to doing\n");
    mvprintw(8, 0, "r: Remove task\n");

    todo_window = create_newwin(40, 49, 6, 35);
    ongoing_window = create_newwin(40, 49, 6, 85);
    done_window = create_newwin(40, 49, 6, 135);

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
    echo();
    getch();
    control_menu();
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

    current_status_win = create_newwin(40, 80, 5, 50);
    int i = 0;
    for (auto &prj_idx : global_projects_vector) // access by reference to avoid copying
    {
        mvwprintw(current_status_win, i + 2, 2, prj_idx.name.c_str());
        mvwprintw(current_status_win, i + 3, 2, prj_idx.projectManagerUserName.c_str());
        mvwprintw(current_status_win, i + 4, 2, prj_idx.assignDate.c_str());
        mvwprintw(current_status_win, i + 5, 2, prj_idx.dueDate.c_str());
        mvwprintw(current_status_win, i + 6, 2, prj_idx.description.c_str());
        i = i + 10;
    }

    wrefresh(current_status_win);
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
/* this command window will be constrauct for input cmd */
void cmd_window()
{
    cmd_sumary_window = create_newwin(40, 25, 10, 1);
    echo();
    wmove(cmd_sumary_window, 1, 1);
    wrefresh(cmd_sumary_window);
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
    int keyboard_input;
    mvprintw(6, 2, "Enter non cmd mode");
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

