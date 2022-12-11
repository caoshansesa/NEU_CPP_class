#include "cmd.hpp"
#include "grid.hpp"
#include "login_view.hpp"
#include "state_def.hpp"
#include <iostream>
#include <iterator>
//#include <ncurses.h>
#include "json.hpp"

#define WELL_WIDTH 20
#define WELL_HEIGHT 20

using namespace std;
void init_game(void)
{
    int x, y;
}

int main(void) {
    vector <Project> test_projects = json_to_projects();//project.json
    projects_to_json(test_projects, "projects_test.json");

    return 0;
}