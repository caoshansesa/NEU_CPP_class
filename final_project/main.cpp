#include <vector>
#include "json.hpp"

int main(void) {
    vector <Project> test_projects = json_to_projects();//project.json
    projects_to_json(test_projects, "projects_test.json");

    return 0;
}
