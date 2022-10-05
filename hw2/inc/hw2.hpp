#include <cstdlib>
#include <iostream>
#include <string.h>
#include <fstream>
#include <iostream>
#include "vector"
#include <iostream>

using namespace std;

int seat_taken[72] = {0};
string name_of_passager[72];
int seat_num[72] = {0};

void ShowMainMenu();

void option_for_main_menu();

void print_2_passager_manifest();

void print_2_seat_map();

void Display_2_Print_passager_manifest();

void option_for_2_print_passager_manifest();

void load_3_passager_manifest();

void save_4_passager_manifest();

void print_menu_5();

void option_for_menu_5();

void choose_seats_5();

void Option_Cancel_seat_assignment_6();
void Option_Print_boardingPass_7();

void print_boarding_pass_7(int seatNumber, string name);

