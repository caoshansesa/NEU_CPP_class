#include <iostream>
#include <vector>
#include "cmd.hpp"
#include "state_def.hpp"

/* Work on this
Task* find_task_by_id(Project &project, int task_id){
    vector<Task> tasks = project.tasks;
    for (int i = 0; i < tasks.size(); i++) {
        if (tasks[i].id == task_id) {
            return &tasks[i];
        }
    }
    return nullptr;
}
  */
int add_task(Project &project,Task new_task){
  project.tasks.push_back(new_task);
  return 0;
}

int modify_task_priority(Task &task,int priority){
  task.priority = priority;
  cout <<task.title << " "<< task.priority <<endl;
  return 0;
}

int modify_task_status(Task &task, string status){
  task.status = status;
  return 0;
}

int modify_task_assignee(Task &task, string assignee){
  task.assignees = assignee;
  return 0;
}
int modify_task_completiondate(Task &task,string completionDate){
  task.completionDate = completionDate;
  return 0;
}
int modidy_task_issues(Task &task, string issues){
  task.issues = issues;
  return 0;
}
int delete_task(Task &task, Project &project){
  auto it = project.tasks.begin();
  
  while(it!=project.tasks.end()){
  if (it != project.tasks.end()) {
    project.tasks.erase(it);
    it++;
    }
  }
      return 0;
  }