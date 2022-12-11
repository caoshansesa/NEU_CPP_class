
#ifndef CMD_H
#define CMD_H

#include "grid.hpp"
#include "state_def.hpp"

/* 
 * @brief render printout for available state
 * */
void render_commands_list(enum VIEW_STATE state,  grid_t* grid);
void take_in_user_cmd(grid_t* grid);
#endif
