#include <iostream>
#include <vector>
#include "cmd.hpp"
#include "state_def.hpp"

using namespace std;

//work on this

Project* find_project_by_id(int project_id, vector<Project> projects) {

    for (int i = 0; i < projects.size(); i++) {
        if (projects[i].id == project_id) {
            return &projects[i];
        }
    }
    return nullptr;
}

int modify_project_name(Project project, string name) {
    project.name = name;
    return 0;
}

int modify_project_description(Project project, string description){
  project.description = description;
  return 0;
}

int modify_project_duedate(Project project, string dueDate) {
    project.dueDate = dueDate;
    return 0;
}

int modify_projectcompletiondate(Project project, string completionDate) {
    project.completionDate = completionDate;
    return 0;
}

int modify_project_manager(Project project, string new_manager) {
    project.projectManagerUserName = new_manager;
    return 0;
}

int modify_project_owner(Project project, string new_owner) {
    project.projectOwnerUserName = new_owner;
    return 0;
}

int delete_project(Project project) {
    delete &project;
    return 0;
}



