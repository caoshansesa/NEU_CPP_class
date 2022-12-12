#include <vector>
#include "json/json.h"
#include "user.h"
#include "project.h"

vector<Task> tasks_from_project_json(Json::Value tasks_json);
int project_to_json(Project project);
int projects_to_json(vector <Project> projects, string filename);
Project json_to_project(int i);
vector<Project> json_to_projects();

int user_to_json(User user);
int users_to_json(vector<User> users);
User json_to_user(int i);
vector<User> json_to_users();
