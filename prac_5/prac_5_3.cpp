/*
 * =====================================================================================
 *
 *       Filename:  prac_5.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  10/13/2022 18:52:29
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Shan Cao
 *   Organization:
 *
 * =====================================================================================
 */
#include <stdlib.h>

#include <iostream>
#include <iterator>
using namespace std;

struct alien {
  unsigned int alien_id_number;
  char* last_name;
  struct {
    char origin[10];
    int age;
  } personal, *personal_ptr = &personal;
} alien_record, *alien_ptr = &alien_record, all_records[5];

int main() {
  all_records[0].last_name = "Cao";
  all_records[1].last_name = "Cao";
  all_records[2].last_name = "Han";
  all_records[3].last_name = "Unni";
  all_records[4].last_name = "Wang";

  all_records[0].alien_id_number = 12345;
  all_records[1].alien_id_number = 12346;
  all_records[2].alien_id_number = 12347;
  all_records[3].alien_id_number = 12348;
  all_records[4].alien_id_number = 12349;

  strcpy(all_records[0].personal.origin, "China");
  strcpy(all_records[1].personal.origin, "China");
  strcpy(all_records[2].personal.origin, "China");
  strcpy(all_records[3].personal.origin, "China");
  strcpy(all_records[4].personal.origin, "China");

  all_records[0].personal.age = 33;
  all_records[1].personal.age = 33;
  all_records[2].personal.age = 33;
  all_records[3].personal.age = 33;
  all_records[4].personal.age = 33;

  for (int i = 0; i < 5; i++) {
    cout << "LastName: " << all_records[i].last_name << endl;
    cout << "Alien Numer: " << all_records[i].alien_id_number << endl;
    cout << "Age: " << all_records[i].personal.age << endl;
    cout << "Origin: " << all_records[i].personal.origin << endl << endl;
  }

  cout << "------------------------------------------------" << endl;

  alien* new_records = new alien[5]();

  new_records[0].last_name = "Cao";
  new_records[1].last_name = "Cao";
  new_records[2].last_name = "Han";
  new_records[3].last_name = "Unni";
  new_records[4].last_name = "Wang";

  new_records[0].alien_id_number = 12345;
  new_records[1].alien_id_number = 12346;
  new_records[2].alien_id_number = 12347;
  new_records[3].alien_id_number = 12348;
  new_records[4].alien_id_number = 12349;

  strcpy(new_records[0].personal.origin, "China");
  strcpy(new_records[1].personal.origin, "China");
  strcpy(new_records[2].personal.origin, "China");
  strcpy(new_records[3].personal.origin, "China");
  strcpy(new_records[4].personal.origin, "China");

  new_records[0].personal.age = 33;
  new_records[1].personal.age = 33;
  new_records[2].personal.age = 33;
  new_records[3].personal.age = 33;
  new_records[4].personal.age = 33;

  for (int i = 0; i < 5; i++) {
    cout << "LastName: " << new_records[i].last_name << endl;
    cout << "Alien Numer: " << new_records[i].alien_id_number << endl;
    cout << "Age: " << new_records[i].personal.age << endl;
    cout << "Origin: " << new_records[i].personal.origin << endl << endl;
  }
}
