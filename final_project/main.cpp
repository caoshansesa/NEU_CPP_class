#include <iostream>

using namespace std;

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

int main()
{
    enum VIEW_STATE next_view = INIT;
    while (1) {
        switch (next_view) {

        case INIT: break;
        case LOGIN_VIEW: break;
        case MAKE_SELECT_VIEW: break;
        case CURRENT_STATUS_VIEW: break;
        case MY_BOARD_VIEW: break;
        case MY_PROJECT_VIEW: break;
        case MY_TASKVIEW: break;
        }
    }
    return 0;
}
