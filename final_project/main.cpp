#include "login_view.hpp"
#include "cmd.hpp"
#include <iostream>

using namespace std;


int main()
{
    enum VIEW_STATE next_view = INIT;
    while (1) {
        switch (next_view) {

        case INIT:
            config_state_login();
            constrcut_login_view();
            take_in_user_cmd();
            update_login_view();

            break;
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
