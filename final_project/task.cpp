#include <iostream>
#include <vector>
#include "cmd.hpp"
#include "state_def.hpp"

//map<string, string> people_map;
//vector<Project> global_projects_vector;

Task* find_task_by_id(Project *project, int task_id){
  if (!project) return nullptr;
  cout <<global_projects_vector.size() <<endl;

    for (int i = 0; i < project->tasks.size(); i++) {
        if (project->tasks[i].id == task_id) {
            return &project->tasks[i];
        }
    }
    return nullptr;
}

int add_task(Project *project,Task new_task){
  if (!project) return -1;
  project->tasks.push_back(new_task);
  return 0;
}

int modify_task_priority(Task *task,int priority){
  if (!task) return -1;
  task->priority = priority;
  return 0;
}

int modify_task_status(Task *task, string status){
  if (!task) return -1;
  task->status = status;
  return 0;
}

int modify_task_assignee(Task *task, string assignee){
  if (!task) return -1;
  task->assignees = assignee;
  return 0;
}
int modify_task_completiondate(Task *task,string completionDate){
  if (!task) return -1;
  task->completionDate = completionDate;
  return 0;
}
int modify_task_issues(Task *task, string issues){
  if (!task) return -1;
  task->issues = issues;
  return 0;
}
int delete_task(Task *task, Project *project){
  if (!task || !project) return -1;
  auto it = project->tasks.begin();
  while(it!=project->tasks.end()){
  if (it->id == task->id) {
    project->tasks.erase(it); return 0;
    }
    it++;
  }
      return 0;
  }
