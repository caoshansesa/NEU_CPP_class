#include "cmd.hpp"
#include <iostream>
#include "state_def.hpp"
#include <iterator>


using namespace std;

void take_in_user_cmd()
{
    enum CMD_STATE next_state = CMD_INIT;
    int            break_loop = 1;
    int            user_input = 1;
    while (break_loop) {
        switch (next_state) {
        case CMD_INIT: break;
        case RUNNING:
            if (user_input == 1) {   // if user input is q, exit. or it will keep reading user input
                                     // cmd and update file
                next_state = EXIT;
            }
            break;
        case EXIT: break_loop = 0; break;

        default: break;
        }
    }
}



/**
 *
 * Renders the command list
 **/
void render_commands(enum VIEW_STATE state)
{
    switch (state) {
    case INIT: cout << "a: Add new task\n"; break;
    case LOGIN_VIEW: break;
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
