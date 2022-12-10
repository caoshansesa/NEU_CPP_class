#include "cmd.hpp"
#include "login_view.hpp"
#include <iostream>
#include <iterator>

using namespace std;


int main()
{
    enum VIEW_STATE next_view = LOGIN_VIEW;
    while (1) {
        switch (next_view) {

        case INIT: cout << "Enter INIT state" << endl; break;
        case LOGIN_VIEW:
            cout << " Enter LOGIN_VIEW state" << endl;
            config_state_login();
            render_commands(LOGIN_VIEW);
            constrcut_login_view();
            take_in_user_cmd();
            update_login_view();
            break;
        case MAKE_SELECT_VIEW: cout << "Enter MAKE_SELECT_VIEW state" << endl; break;
        case CURRENT_STATUS_VIEW: cout << "Enter CURRENT_STATUS_VIEW state" << endl; break;
        case MY_BOARD_VIEW: cout << "Enter MY_BOARD_VIEW state" << endl; break;
        case MY_PROJECT_VIEW: cout << "Enter MY_TASKVIEW state" << endl; break;
        case MY_TASKVIEW: cout << "Enter MY_TASKVIEW state" << endl; break;
        }
    }
    return 0;
}
