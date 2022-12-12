#include "state_def.hpp"
#include "json/json.h"
#include <map>
#include <vector>

vector<Task> tasks_from_project_json(Json::Value tasks_json);
int project_to_json(Project project, string filename);
int projects_to_json(vector<Project> projects, string filename);
Project json_to_project(int i, string filename);
vector<Project> json_to_projects(string filename);

int user_to_json(User user, string filename);
int users_to_json(vector<User> users, string filename);
User json_to_user(int i, string filename);
vector<User> json_to_users(string filename);

int deserialize(string filename); // to vector of Project objects
int serialize(string filename);   // objects to Json file
map<string, string> read_people(string filename);

