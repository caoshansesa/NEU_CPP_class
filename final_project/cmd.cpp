#include "cmd.hpp"
#include "grid.hpp"
#include "state_def.hpp"
#include <vector>
#include <cstring>
#include <string>
#include <cstdio>
#include <cwchar>
#include <iostream>
#include <iterator>
#include <memory>
#include <menu.h>
#include <ncurses.h>
#include <string.h>
#include <string>

using namespace std;

/* *
 * @brief read in a string and return the string
 * */
string getstring()
{
    string input;
    timeout(-1);
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

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))
#define CTRLD 4

map<string, string> people_map;
vector<Project> global_projects_vector;

/*******POPUP FUNCTIONS START HERE**************/
//modify task status
void modify_task_status_pop_up(int prj_id){
    int task_id;
    move(20,0);

    clrtoeol();
    mvprintw(20, 0, "Please Enter the task id:");
    refresh();

    task_id = int(getch()) -48;
    Project * project = find_project_by_id(prj_id);
    Task * task = find_task_by_id(project,task_id);

    clrtoeol(); //clear current line
    mvprintw(20, 0, "Please print one of the options:TODO,DOING,DONE - case-sensitive");
    refresh();

    string x = getstring();
    modify_task_status(task,x);

    clrtoeol(); //clear current line
    mvprintw(20, 0, "Task has been updated");
    refresh();
}
//modify task priority
void modify_task_priority_pop_up(int prj_id){
    int task_id;
    int x;
    move(20,0);

    clrtoeol();
    mvprintw(20, 0, "Please Enter the task id:");
    refresh();

    task_id = int(getch()) -48;
    Project * project = find_project_by_id(prj_id);
    Task * task = find_task_by_id(project,task_id);

    clrtoeol(); //clear current line
    mvprintw(20, 0, "Please print new task priority");
    refresh();

    x = int(getch())- 48;
    modify_task_priority(task,x);

    clrtoeol(); //clear current line
    mvprintw(20, 0, "Task has been updated");
    refresh();
}
//modify task assignee
void modify_task_assignee_pop_up(int prj_id){
    int task_id;
    move(20,0);

    clrtoeol();
    mvprintw(20, 0, "Please Enter the task id:");
    refresh();

    task_id = int(getch()) -48;
    Project * project = find_project_by_id(prj_id);
    Task * task = find_task_by_id(project,task_id);

    clrtoeol(); //clear current line
    mvprintw(20, 0, "Please print new task assignee");
    refresh();

    string x = getstring();
    modify_task_assignee(task,x);

    clrtoeol(); //clear current line
    mvprintw(20, 0, "Task has been updated");
    refresh();
}
//modify task status
void modify_task_completion_date_pop_up(int prj_id){
    int task_id;
    move(20,0);

    clrtoeol();
    mvprintw(20, 0, "Please Enter the task id:");
    refresh();

    task_id = int(getch()) -48;
    Project * project = find_project_by_id(prj_id);
    Task * task = find_task_by_id(project,task_id);

    clrtoeol(); //clear current line
    mvprintw(20, 0, "Please print new task completion date as Month-day-Year");
    refresh();

    string x = getstring();
    modify_task_completiondate(task,x);

    clrtoeol(); //clear current line
    mvprintw(20, 0, "Task has been updated");
    refresh();
}
//modify task status
void modify_task_issues_pop_up(int prj_id){
    int task_id;
    move(20,0);

    clrtoeol();
    mvprintw(20, 0, "Please Enter the task id:");
    refresh();

    task_id = int(getch()) -48;
    Project * project = find_project_by_id(prj_id);
    Task * task = find_task_by_id(project,task_id);

    clrtoeol(); //clear current line
    mvprintw(20, 0, "Please enter issues");
    refresh();

    string x = getstring();
    modify_task_issues(task,x);

    clrtoeol(); //clear current line
    mvprintw(20, 0, "Task has been updated");
    refresh();
}
//modify task status
void delete_task_pop_up(int prj_id){
    int task_id;
    const char * x[20];
    move(20,0);

    clrtoeol();
    mvprintw(20, 0, "Please Enter the task id:");
    refresh();

    task_id = int(getch()) -48;
    Project * project = find_project_by_id(prj_id);
    Task * task = find_task_by_id(project,task_id);
    delete_task(task, project);

    clrtoeol(); //clear current line
    mvprintw(20, 0, "Task has been deleted");
    refresh();
}
//add task
void add_task_pop_up(int prj_id){
    int priority;

    Project * project = find_project_by_id(prj_id);
    Task new_task = Task();

    move(20,0);
    clrtoeol(); //clear current line
    mvprintw(20, 0, "Please print new task type");
    string type = getstring();
    new_task.type = type;

    clrtoeol();
    mvprintw(20, 0, "Please print new task title:");
    refresh();
    string title = getstring();
    new_task.dueDate = title;

    clrtoeol(); //clear current line
    mvprintw(20, 0, "Please print new task priority");
    refresh();
    priority = int(getch()) - 48;
    new_task.priority = priority;

    clrtoeol();
    mvprintw(20, 0, "Please print new task assignDate:");
    refresh();
    string assigndate = getstring();
    new_task.assignDate = assigndate;

    clrtoeol();
    mvprintw(20, 0, "Please print new task dueDate:");
    refresh();
    string duedate = getstring();
    new_task.dueDate = duedate;

    clrtoeol();
    mvprintw(20, 0, "Please print new task assignee:");
    refresh();
    string assignee = getstring();
    new_task.dueDate = assignee;

    //id is constructed uniquely and status is TO-DO by default.

    add_task(project, new_task);

    clrtoeol(); //clear current line
    mvprintw(20, 0, "Task has been updated");
    refresh();
}

/**************************************************************************/
#if 0
//modify project status
void modify_project_name_pop_up(int prj_id){
    int project_id;
    const char * new_status[20];
    //already done
    // initscr();
    move(20,0);
    clrtoeol(); //clear current line
    //mvprintw(20, 0, "Item selected is : %s", name); //print
    mvprintw(20, 0, "Please Enter the project id:");
    refresh();
    //get project id
    //scanw("%d",&project_id);
    project_id = int(getch()) -48;
    Project * project = find_project_by_id(prj_id);
    //int indx = _tstoi(project_id); //convert cstring to int

    project * project = find_project_by_id(project,idx);
    clrtoeol(); //clear current line
    mvprintw(20, 0, "Please print one of the options: TODO,DOING,DONE -case-sensistive");
    getstr(new_status);
    refresh();
    string status = new_status;//convert cstring to string
    project->status = new_status;
    clrtoeol(); //clear current line
    mvprintw(20, 0, "Task has been moved to : %s", new_status);
    refresh();
}
//modify project status
void modify_project_description_pop_up(int prj_id){
    int project_id;
    const char * new_status[20];
    //already done
    // initscr();
    move(20,0);
    clrtoeol(); //clear current line
    //mvprintw(20, 0, "Item selected is : %s", name); //print
    mvprintw(20, 0, "Please Enter the project id:");
    refresh();
    //get project id
    //scanw("%d",&project_id);
    project_id = int(getch()) -48;
    Project * project = find_project_by_id(prj_id);
    //int indx = _tstoi(project_id); //convert cstring to int

    project * project = find_project_by_id(project,idx);
    clrtoeol(); //clear current line
    mvprintw(20, 0, "Please print one of the options: "TODO","DOING","DONE" (case-sensistive)");
    getstr(new_status);
    refresh();
    string status = new_status;//convert cstring to string
    project->status = new_status;
    clrtoeol(); //clear current line
    mvprintw(20, 0, "project has been moved to : %s", new_status);
    refresh();
    //already done
    //endwin();
}
//modify project status
void modify_project_duedate_pop_up(int prj_id){
    int project_id;
    const char * new_status[20];
    //already done
    // initscr();
    move(20,0);
    clrtoeol(); //clear current line
    //mvprintw(20, 0, "Item selected is : %s", name); //print
    mvprintw(20, 0, "Please Enter the project id:");
    refresh();
    //get project id
    //scanw("%d",&project_id);
    project_id = int(getch()) -48;
    Project * project = find_project_by_id(prj_id);
    //int indx = _tstoi(project_id); //convert cstring to int

    project * project = find_project_by_id(project,idx);
    clrtoeol(); //clear current line
    mvprintw(20, 0, "Please print one of the options: "TODO","DOING","DONE" (case-sensistive)");
    getstr(new_status);
    refresh();
    string status = new_status;//convert cstring to string
    project->status = new_status;
    clrtoeol(); //clear current line
    mvprintw(20, 0, "project has been moved to : %s", new_status);
    refresh();
    //already done
    //endwin();
}
//modify project priority
void modify_project__pop_up(int prj_id){
    int project_id;
    const char * new_status[20];
    //already done
    // initscr();
    move(20,0);
    clrtoeol(); //clear current line
    //mvprintw(20, 0, "Item selected is : %s", name); //print
    mvprintw(20, 0, "Please Enter the project id:");
    refresh();
    //get project id
    //scanw("%d",&project_id);
    project_id = int(getch()) -48;
    Project * project = find_project_by_id(prj_id);
    //int indx = _tstoi(project_id); //convert cstring to int

    project * project = find_project_by_id(project,idx);
    clrtoeol(); //clear current line
    mvprintw(20, 0, "Please print one of the options: "TODO","DOING","DONE" (case-sensistive)");
    getstr(new_status);
    refresh();
    string status = new_status;//convert cstring to string
    project->status = new_status;
    clrtoeol(); //clear current line
    mvprintw(20, 0, "project has been moved to : %s", new_status);
    refresh();
    //already done
    //endwin();
}
//modify project status
void modify_project_status_pop_up(int prj_id){
    int project_id;
    const char * new_status[20];
    //already done
    // initscr();
    move(20,0);
    clrtoeol(); //clear current line
    //mvprintw(20, 0, "Item selected is : %s", name); //print
    mvprintw(20, 0, "Please Enter the project id:");
    refresh();
    //get project id
    //scanw("%d",&project_id);
    project_id = int(getch()) -48;
    Project * project = find_project_by_id(prj_id);
    //int indx = _tstoi(project_id); //convert cstring to int

    project * project = find_project_by_id(project,idx);
    clrtoeol(); //clear current line
    mvprintw(20, 0, "Please print one of the options: "TODO","DOING","DONE" (case-sensistive)");
    getstr(new_status);
    refresh();
    string status = new_status;//convert cstring to string
    project->status = new_status;
    clrtoeol(); //clear current line
    mvprintw(20, 0, "project has been moved to : %s", new_status);
    refresh();
    //already done
    //endwin();
}
//modify project status
void modify_project_status_pop_up(int prj_id){
    int project_id;
    const char * new_status[20];
    //already done
    // initscr();
    move(20,0);
    clrtoeol(); //clear current line
    //mvprintw(20, 0, "Item selected is : %s", name); //print
    mvprintw(20, 0, "Please Enter the project id:");
    refresh();
    //get project id
    //scanw("%d",&project_id);
    project_id = int(getch()) -48;
    Project * project = find_project_by_id(prj_id);
    //int indx = _tstoi(project_id); //convert cstring to int

    project * project = find_project_by_id(project,idx);
    clrtoeol(); //clear current line
    mvprintw(20, 0, "Please print one of the options: "TODO","DOING","DONE" (case-sensistive)");
    getstr(new_status);
    refresh();
    string status = new_status;//convert cstring to string
    project->status = new_status;
    clrtoeol(); //clear current line
    mvprintw(20, 0, "project has been moved to : %s", new_status);
    refresh();
    //already done
    //endwin();
}
//modify project priority
void modify_project_status_pop_up(int prj_id){
    int project_id;
    const char * new_status[20];
    //already done
    // initscr();
    move(20,0);
    clrtoeol(); //clear current line
    //mvprintw(20, 0, "Item selected is : %s", name); //print
    mvprintw(20, 0, "Please Enter the project id:");
    refresh();
    //get project id
    //scanw("%d",&project_id);
    project_id = int(getch()) -48;
    Project * project = find_project_by_id(prj_id);
    //int indx = _tstoi(project_id); //convert cstring to int

    project * project = find_project_by_id(project,idx);
    clrtoeol(); //clear current line
    mvprintw(20, 0, "Please print one of the options: "TODO","DOING","DONE" (case-sensistive)");
    getstr(new_status);
    refresh();
    string status = new_status;//convert cstring to string
    project->status = new_status;
    clrtoeol(); //clear current line
    mvprintw(20, 0, "project has been moved to : %s", new_status);
    refresh();
    //already done
    //endwin();
}
//modify project status
void modify_project_status_pop_up(int prj_id){
    int project_id;
    const char * new_status[20];
    //already done
    // initscr();
    move(20,0);
    clrtoeol(); //clear current line
    //mvprintw(20, 0, "Item selected is : %s", name); //print
    mvprintw(20, 0, "Please Enter the project id:");
    refresh();
    //get project id
    //scanw("%d",&project_id);
    project_id = int(getch()) -48;
    Project * project = find_project_by_id(prj_id);
    //int indx = _tstoi(project_id); //convert cstring to int

    project * project = find_project_by_id(project,idx);
    clrtoeol(); //clear current line
    mvprintw(20, 0, "Please print one of the options: "TODO","DOING","DONE" (case-sensistive)");
    getstr(new_status);
    refresh();
    string status = new_status;//convert cstring to string
    project->status = new_status;
    clrtoeol(); //clear current line
    mvprintw(20, 0, "project has been moved to : %s", new_status);
    refresh();
    //already done
    //endwin();
}
#endif
/*******POPUP FUNCTIONS END HERE**************/
void goto_my_board_view(char *name)
{
    /*do something here*/
}
enum VIEW_STATE control_menu_selection_view()
{
    enum VIEW_STATE return_state;
    char const *choices[] = {"1. View/Manage My Board", "2. View My Projects", "3. View/Edit Current Task Status",
                             "4. LOG_OUT "};
    char const *return_index[] = {"1", "2", "3", "4"};
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
        my_items[i] = new_item(choices[i], "");
        set_item_userptr(my_items[i], reinterpret_cast<void *>(goto_my_board_view));
    }
    my_items[n_choices] = (ITEM *)NULL;
    my_menu = new_menu((ITEM **)my_items);
    post_menu(my_menu);
    refresh();
    c = getch();
    while (c != KEY_F(1))
    {
        mvprintw(0, 50, "MAKE a selection with Enter, then press F1 to continue");
        c = getch();
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

            if ((item_name(cur)[0] == '1'))
            {
                return_state = MY_BOARD_VIEW;
            }

            if ((item_name(cur)[0] == '2'))
            {
                return_state = MY_PROJECT_VIEW;
            }

            if ((item_name(cur)[0] == '3'))
            {
                return_state = MY_TASKVIEW;
            }
            if ((item_name(cur)[0] == '4'))
            {
                c = KEY_F(1);
                return_state = LOGIN_VIEW;
            }
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
    return return_state;
}

//1. BOARD VIEW
void control_menu_my_board_view()
{
    char const *choices[] = {"1. Add new task", "2. Move task", "3. Remove task", "Exit"}; //CHANGE FOR ANOTHER MENU
    char const *return_index[] = {"1", "2", "3", "4"};
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

    c = getch();
    while (c != KEY_F(1))
    {
        mvprintw(0, 50, "MAKE a selection with Enter, then press F1 to continue");
        c = getch();
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
//"1. Add new task", "2. Move task", "3. Remove task", "Exit"
            if ((item_name(cur)[0] == '1'))
            {
                //check user access
                //if user property=true
                //Add new task
            }
            if ((item_name(cur)[0] == '2'))
            {
               // modify_task_status_pop_up(0);
            }
            if ((item_name(cur)[0] == '3'))
            {
                //Delete task
            }
            if ((item_name(cur)[0] == '3'))
            {
                c =KEY_F(1);
            }
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
}

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
 * @brief, Add the login readline, read in a string which used as username
 * */
bool get_name_from_login() {
    // start get user name: new window
    char mesg[] = "Please input your username ";
    char errmsg[] ="You are not a registered user.";
    char smsg[] = "You are logged in.";
    int x, y;
    initscr();
    getmaxyx(stdscr, y, x);
    mvprintw(y / 2, (x - strlen(mesg)) / 2, "%s", mesg);
    refresh();
    username = getstring();
    noecho();
    endwin();
    refresh();

    //find username in people_map
    if(people_map.find(username) == people_map.end()){
        mvprintw(y / 2 +2, (x - strlen(errmsg)) / 2, "%s", errmsg);
	timeout(-1);
	getch();
	refresh();
	return false;
	}
    else{
        //get user role
        string role = people_map[username]; //string
        //construct user with that role
        if(role == "Developer") Developer* currentuser = new Developer();
	if(role == "QAEngineer") QAEngineer* currentuser = new QAEngineer();
	if(role == "Owner") ProjectOwner* currentuser = new ProjectOwner();
	if(role == "Manager") ProjectManager* currentuser = new ProjectManager();
        mvprintw(y/2 +2,(x-strlen(smsg))/2,"%s",smsg);
	timeout(-1);
	getch();
	refresh();
	return true;
    }
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

    todo_window = create_newwin(40, 49, 6, 35);
    ongoing_window = create_newwin(40, 49, 6, 85);
    done_window = create_newwin(40, 49, 6, 135);

    //mvwprintw(todo_window, 2, 2, "this is a box");
    //mvwprintw(ongoing_window, 2, 2, "this is a box");
    //mvwprintw(done_window, 2, 2, "this is a box");

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
//AMEL EDIT HERE 1.
void render_my_board_view_data_region() {
    todo_window = create_newwin(40, 49, 6, 25);
    ongoing_window = create_newwin(40, 49, 6, 75);
    done_window = create_newwin(40, 49, 6, 125);

    int x = 2;
    int y = 2;
    int z = 2;

    vector <Task> tasks = global_projects_vector[0].tasks;
    for (auto &task_idx: tasks) // access by reference to avoid copying
    {
        if (task_idx.status == "TODO") {
            mvwprintw(todo_window, x, 2, task_idx.title.c_str());
            x += 2;
        }
        if (task_idx.status == "ONGOING") {
            mvwprintw(ongoing_window, y, 2, task_idx.title.c_str());
            y += 2;
        }
        if (task_idx.status == "DONE") {
            mvwprintw(done_window, z, 2, task_idx.title.c_str());
            z += 2;

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
}
/*
 * rendering my project view data region
 * */
//AMEL EDIT HERE 2.
void render_my_project_view_data_region() {
    int i = 0;
    for (auto &prj_idx: global_projects_vector) // access by reference to avoid copying
    {
        mvwprintw(prj_summary_window, i + 2, 2, prj_idx.name.c_str());
        i += 3;
    }

    wrefresh(prj_summary_window);
}

/*
 * rendering my task view data region
 * */
//AMEL EDIT HERE 3.
void render_my_task_view_data_region() {
    vector<Task> tasks = global_projects_vector[0].tasks;
    int i = 0;
//   for (auto &task_idx: tasks) // access by reference to avoid copying
//    {
    	Task task_idx = tasks[0];
	string id = to_string(task_idx.id);
	string priority = to_string(task_idx.priority);
        mvwprintw(my_task_window, i + 2, 2, "Task id: ");
        mvwprintw(my_task_window, i + 2, 20, id.c_str());
        mvwprintw(my_task_window, i + 3, 2, "Type: ");
        mvwprintw(my_task_window, i + 3, 20, task_idx.type.c_str());
        mvwprintw(my_task_window, i + 4, 2, "Assignee: ");
        mvwprintw(my_task_window, i + 4, 20, task_idx.assignees.c_str());
        mvwprintw(my_task_window, i + 5, 2, "Priority: ");
        mvwprintw(my_task_window, i + 5, 20, priority.c_str());
        mvwprintw(my_task_window, i + 6, 2, "Date Assigned: ");
        mvwprintw(my_task_window, i + 6, 20, task_idx.assignDate.c_str());
        mvwprintw(my_task_window, i + 7, 2, "Due Date: ");
        mvwprintw(my_task_window, i + 7, 20, task_idx.dueDate.c_str());
        i = i + 5;
//    }

    wrefresh(my_task_window);
}


/*
 *@ brief Render data region based on the Project and people objs
 * */
void render_data_region(enum VIEW_STATE state, grid_t *grid) {
    switch (state) {
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
            render_my_project_view_data_region();
            break;
        case MY_TASKVIEW:
            render_my_task_view_data_region();
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
void take_in_user_cmd(grid_t *grid) {
    enum CMD_STATE next_state = CMD_INIT;
    int break_loop = 1;
    int keyboard_input = 0;
    while (break_loop) {
        switch (next_state) {
            case CMD_INIT:
            case RUNNING:
                refresh();
                read_escape(&keyboard_input);
                if (keyboard_input == 'q') {
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

enum VIEW_STATE go_back_to_selection_view_with_button_q()
{
    enum CMD_STATE next_state = CMD_INIT;
    enum VIEW_STATE return_view = MAKE_SELECT_VIEW;
    int break_loop = 1;
    int keyboard_input;
    while (break_loop)
    {
        switch (next_state)
        {
        case CMD_INIT:
        case RUNNING:
            read_escape(&keyboard_input);
            if (keyboard_input == 'q')
            {
                next_state = EXIT;
            }
            break;
        case EXIT:
            break_loop = 0;

        default:
            break;
        }
    }
    return return_view;
}

