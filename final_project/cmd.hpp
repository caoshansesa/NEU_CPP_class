
#ifndef CMD_H
#define CMD_H

#include "grid.hpp"
#include "state_def.hpp"
/* 
 * @brief render printout for available state
 * */
void render_commands(enum VIEW_STATE state,  grid_t* grid);
void take_in_user_cmd(grid_t* grid);
Project find_project_by_id(int project_id);
Task find_task_by_id(int task_id);

int add_project(Project new_project);
int modify_project_name(int project_id, string name);
int modify_project_description(int project_id,string description);
int modify_project_duedate(int project_id, string dueDate);//?
int modify_projectcompletiondate(int project_id, string completionDate);
int modify_project_manager(int project_id, string new_manager);
int modify_project_owner(int project_id, string new_owner);
int delete_project(int project_id);

int add_task(int project_id,Task new_task);
int modify_task_priority(int task_id, int priority);
int modify_task_status(int task_id, string status);
int modify_task_assignee(int task_id, string assignee);
int modify_task_completiondate(int task_id, string completionDate);
int modidy_task_issues(int task_id, string issues);
int delete_task(int project_id, int task_id);
#endif
