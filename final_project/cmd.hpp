
#ifndef CMD_H
#define CMD_H

#include "grid.hpp"
#include "state_def.hpp"
#include <menu.h>

/* 
 * @brief render printout for available state
 * */
void render_commands_list(enum VIEW_STATE state,  grid_t* grid);
void take_in_user_cmd(grid_t* grid);
void render_data_region(enum VIEW_STATE state, grid_t* grid);
enum VIEW_STATE control_menu_selection_view();
void control_menu_my_board_view();
enum VIEW_STATE go_back_to_selection_view_with_button_q();

Project * find_project_by_id(int project_id);
Task* find_task_by_id(Project *project,int task_id);

int add_project(Project new_project);
int modify_project_name(Project* project, string name);
int modify_project_description(Project* project,string description);
int modify_project_duedate(Project* project,string dueDate);
int modify_projectcompletiondate(Project* project, string completionDate);
int modify_project_manager(Project* project,string new_manager);
int modify_project_owner(Project* project, string new_owner);
int delete_project(Project* project);

int add_task(Project *project, Task new_task);
int modify_task_priority(Task *task, int priority);
int modify_task_status(Task *task, string status);
int modify_task_assignee(Task *task, string assignee);
int modify_task_completiondate(Task *task,string completionDate);
int modidy_task_issues(Task *task, string issues);
int delete_task(Task *task, Project *projects);
#endif
