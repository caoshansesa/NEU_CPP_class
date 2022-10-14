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
#include <ostream>
#include <stdlib.h>

#include <iostream>
#include <iterator>
using namespace std;

struct alien {
  unsigned int alien_id_number = 1111;
  char* last_name ="caoshan";
  struct {
    char origin[10] = "China";
    int age = 33;
  } personal, *personal_ptr = &personal;
} alien_record, *alien_ptr = &alien_record, all_records[5];

int main() {
    cout << alien_record.alien_id_number << endl;
    cout<< alien_ptr->alien_id_number <<endl;
    cout << alien_record.last_name << endl;
    cout<< alien_ptr->last_name<<endl;
    cout<< alien_record.personal.age <<endl;
    cout<< alien_ptr->personal_ptr->age <<endl;
    cout<< (&alien_record)->personal.origin<<endl;
    cout << alien_ptr->personal_ptr->origin <<endl;
}
