
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
enum VIEW_STATE control_menu();
enum VIEW_STATE go_back_to_selection_view_with_button_q();

#endif
