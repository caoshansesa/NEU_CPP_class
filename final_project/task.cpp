#include <iostream>
#include <vector>
#include "cmd.hpp"
#include "state_def.hpp"


int add_task(Project project,Task new_task){
  project.tasks.push_back(new_task);
  return 0;
}

int modify_task_priority(Task task,int priority){
  task.priority = priority;
  return 0;
}

int modify_task_status(Task task, string status){
  task.status = status;
  return 0;
}

int modify_task_assignee(Task task, string assignee){
  task.assignees = assignee;
  return 0;
}
int modify_task_completiondate(Task task,string completionDate){
  task.completionDate = completionDate;
  return 0;
}
int modidy_task_issues(Task task, string issues){
  task.issues = issues;
  return 0;
}
int delete_task(Task task){
  delete &task;
  return 0;
}