#include "cmd.hpp"
#include "json.hpp"
#include "state_def.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
//#include "common.hpp"

using namespace std;
static map<string, string> people_map;
// find project by id

Project *find_project_by_id(int project_id) {
  cout << "size of global vector from find_project_by_id:"
       << global_projects_vector.size() << endl;
  for (int i = 0; i < global_projects_vector.size(); i++) {
    if (global_projects_vector[i].id == project_id) {
      return &global_projects_vector[i];
    }
  }
  return nullptr;
}

Task *find_task_by_id(Project &project, int task_id) {
  vector<Task> tasks = project.tasks;
  for (int i = 0; i < tasks.size(); i++) {
    if (tasks[i].id == task_id) {
      return &tasks[i];
    }
  }
  return nullptr;
}
/*************************************************/
int main(void) {
  // test people.json is being read to map
  people_map = read_people("people.json");
  cout << "parse the map" << endl;
  auto it = people_map.begin();
  string name, role;
  while (it != people_map.end()) {
    name = it->first;
    role = it->second;

    cout << name << ": " << role << endl;
    it++;
  }
  cout << "************************" << endl;
  // test that global vector is being passed
  cout << global_projects_vector.size() << endl;
  // write to projects vector
  global_projects_vector = deserialize("project.json");
  cout << global_projects_vector.size() << endl;

  // test project manipulation
  Project *myproject = find_project_by_id(2);
  #if 0
  modify_project_name(*myproject, "this is another test 2");
  modify_project_description(*myproject, "nice description 2");
  modify_project_duedate(*myproject, "Mar-2-21 2");
  modify_project_manager(*myproject, "the new manager is a good test");
  modify_project_owner(*myproject, "the new owner 2");
  modify_projectcompletiondate(*myproject, "Apr-12-22 2");
  add_project(*myproject, global_projects_vector);
  // delete_project(*myproject, global_projects_vector);
  // serialize(global_projects_vector,"project.json");
#endif
  cout << "************************" << endl;
  // test Tasks manipulation
  Task *mytask = find_task_by_id(*myproject, 2);
  //add_task(*myproject, *mytask);
  modify_task_priority(*mytask, 103);
  //modify_task_status(*mytask, "DONE LAST WEEK");
  //modify_task_assignee(*mytask, "JenAmin");
  //modify_task_completiondate(*mytask, "EndofTime");
  //modidy_task_issues(*mytask, "too little time");
  //delete_task(*mytask, *myproject);
  serialize(global_projects_vector,"project.json");
  return 0;
}
