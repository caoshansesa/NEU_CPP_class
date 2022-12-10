#include "cmd.hpp"
#include "state_def.hpp"
#include <cstdio>
#include <iostream>
#include <iterator>


using namespace std;


/**
 *
 * Renders the command list
 **/
void render_commands(enum VIEW_STATE state)
{
    switch (state) {
    case INIT: cout << "a: Add new task\n" << endl; break;
    case LOGIN_VIEW: cout << "a: Add new task\n" << endl; break;
    case MAKE_SELECT_VIEW: break;
    case CURRENT_STATUS_VIEW: break;
    case MY_BOARD_VIEW: break;
    case MY_PROJECT_VIEW: break;
    case MY_TASKVIEW: break;
    }
    printf("l: Change current list\n");
    printf("s: Save\n");
    printf("q: Quit (and save)\n");
}

/** @brief
 *  in RUNNING state, take in user input, update current_user_obj, current_project_obj
 *  and dump changes to json
 *
 *  in EXIT state, exit and goto next view
 *  @return void
 */
void take_in_user_cmd()
{
    enum CMD_STATE next_state = CMD_INIT;
    int            break_loop = 1;
    char           c;
    int            user_input = 1;
    string         chosen_command;
    int            items_read = 0;
    string         user_cmd;
    while (break_loop) {
        switch (next_state) {
        case CMD_INIT:
        case RUNNING:
            printf("\nInsert q to quit \n ");
            getline(cin, user_cmd);
            // equal q, exit. other keep read user input and update file
            if (user_cmd.front() == 'q') {
                next_state = EXIT;
            }
            break;
        case EXIT: break_loop = 0; break;

        default: break;
        }
    }
}

