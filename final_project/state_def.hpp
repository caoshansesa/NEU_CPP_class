#ifndef MAIN_H
#define MAIN_H

// Define user command line state, 
enum CMD_STATE
{
    CMD_INIT = 0,
    RUNNING,  // RUNNING state, keep taking user input, update json
    EXIT // EXIT state, exit user command line input, goto next view
};

enum VIEW_STATE
{
    INIT = 0,
    LOGIN_VIEW,
    MAKE_SELECT_VIEW,
    CURRENT_STATUS_VIEW,
    MY_BOARD_VIEW,
    MY_PROJECT_VIEW,
    MY_TASKVIEW
};

#endif
