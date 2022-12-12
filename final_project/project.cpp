#include <iostream>
#include <vector>
#include "cmd.hpp"
#include "state_def.hpp"
//#include "common.hpp"


using namespace std;


/*Work on this 
Project* find_project_by_id(int project_id) {
cout <<"size of global vector from find_project_by_id:" << global_projects_vector.size() <<endl;
    for (int i = 0; i < global_projects_vector.size(); i++) {
        if (global_projects_vector[i].id == project_id) {
            return &global_projects_vector[i];
        }
    }
    return nullptr;
}
*/
int add_project(Project new_project, vector<Project> &projects){
  //cout << global_projects_vector.size()<<endl;
  projects.push_back(new_project);
  return 0;
}

int modify_project_name(Project &project, string name) {
    project.name = name;
    return 0;
}

int modify_project_description(Project &project, string description){
  project.description = description;
  return 0;
}

int modify_project_duedate(Project &project, string dueDate) {
    project.dueDate = dueDate;
    return 0;
}

int modify_projectcompletiondate(Project &project, string completionDate) {
    project.completionDate = completionDate;
    return 0;
}

int modify_project_manager(Project &project, string new_manager) {
    project.projectManagerUserName = new_manager;
    return 0;
}

int modify_project_owner(Project &project, string new_owner) {
    project.projectOwnerUserName = new_owner;
    return 0;
}

//need to work on this 
int delete_project(Project &project, vector<Project> &projects) {
  //free(project);
  //projects.remove(project);
  auto it = projects.begin();
  
  while(it!=projects.end()){
  if (it != projects.end()) {
    projects.erase(it);
    it++;
    }
  }
      return 0;
  }



