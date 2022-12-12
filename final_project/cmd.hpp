
#ifndef CMD_H
#define CMD_H

#include "grid.hpp"
#include "state_def.hpp"
/* 
 * @brief render printout for available state
 * */
void render_commands(enum VIEW_STATE state,  grid_t* grid);
void take_in_user_cmd(grid_t* grid);
Project *find_project_by_id(int project_id);
Task* find_task_by_id(Project &project,int task_id);

int add_project(Project new_project, vector<Project> &projects);
int modify_project_name(Project &project, string name);
int modify_project_description(Project &project,string description);
int modify_project_duedate(Project &project,string dueDate);
int modify_projectcompletiondate(Project &project, string completionDate);
int modify_project_manager(Project &project,string new_manager);
int modify_project_owner(Project &project, string new_owner);
int delete_project(Project &project, vector<Project> & projects);

int add_task(Project &project, Task new_task);
int modify_task_priority(Task &task, int priority);
int modify_task_status(Task &task, string status);
int modify_task_assignee(Task &task, string assignee);
int modify_task_completiondate(Task &task,string completionDate);
int modidy_task_issues(Task &task, string issues);
int delete_task(Task &task, Project projects);
#endif
