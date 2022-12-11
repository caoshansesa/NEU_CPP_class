
#ifndef CMD_H
#define CMD_H

#include "grid.hpp"
#include "state_def.hpp"
i
/* 
 * @brief render printout for available state
 * */
void render_commands(enum VIEW_STATE state,  grid_t* grid);
void take_in_user_cmd(grid_t* grid);

int modify_project_name( project name, string value){

 vector<project> glabal

	 global->prject1->name = value;
}
/*
 *working vector of projects.
 *access the project that is passed and needed to be modified
 *edit that section in the json file
 *modify object in vector
 *
 *
 *
 *
 *
 *
 *
 *
 */

//modifyproject
//addproject
//addtask 
//deletetask
//deleteproject
#endif
