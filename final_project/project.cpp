#include <iostream>
#include <vector>
#include "cmd.hpp"
#include "state_def.hpp"
//#include "common.hpp"

//map<string, string> people_map;
//vector<Project> global_projects_vector;

using namespace std;

Project* find_project_by_id(int project_id) {

    for (int i = 0; i < global_projects_vector.size(); i++) {
        if (global_projects_vector[i].id == project_id) {
            return &global_projects_vector[i];
        }
    }
    return nullptr;
}

int add_project(Project new_project){

  global_projects_vector.push_back(new_project);
  
  return 0;
}

int modify_project_name(Project* project, string name) {
  if (!project) return -1;
    project->name = name;
    return 0;
}

int modify_project_description(Project* project, string description){
  if (!project) return -1;
  project->description = description;
  return 0;
}

int modify_project_duedate(Project* project, string dueDate) {
  if (!project) return -1;
    project->dueDate = dueDate;
    return 0;
}

int modify_projectcompletiondate(Project* project, string completionDate) {
  if (!project) return -1;
    project->completionDate = completionDate;
    return 0;
}

int modify_project_manager(Project* project, string new_manager) {
  if (!project) return -1;
    project->projectManagerUserName = new_manager;
    return 0;
}

int modify_project_owner(Project * project, string new_owner) {
  if (!project) return -1;
    project->projectOwnerUserName = new_owner;
    return 0;
}

int delete_project(Project* project) {
  if (!project) return -1;
  
  auto it = global_projects_vector.begin(); 
  
  while(it!=global_projects_vector.end()){
  if (it->id == project->id) {global_projects_vector.erase(it);
    return 0;}
    it++;
  }
      return 0;
}

/**************************************/
