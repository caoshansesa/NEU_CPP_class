
/*-----------------------------------------------------------------------------
 * hw1.cpp
 *
 * Author: Shan Cao
 *
 * Date: Sep 13th, 2022
 *-----------------------------------------------------------------------------*/
#include <iostream>
#include <ostream>
using namespace std;

int main() {
  int num_of_rows = 0;
  int null_dev = 0;
  int symble_choice;
  char cross = '+';
  char star = '*';
  char dollar = '$';
  char symble_in_use;

  cout << "This is a program could print "
            "an up-wise Right triangle,\n" 
            "a down-wise triangle, \n"
            "a rectangle.\n\n\n"
            "Please provide:\n"
            "number of rows you expected,\n" 
            "the shape you want, \n"
            "and the symble you prefer \n"
          "----------------------------------------------------------\n";
  do {
    cout << '\n' << "Press a key to continue...";
  } while (cin.get() != '\n');



  cout << "Please input the number of rows you expect \n";
  cin >> num_of_rows;
  cout << "Please privide what shape you prefer, input 1 for +, input 2 for * "
          "input 3 for $";

  cin >> symble_choice;
  if (symble_choice == 1) {
    symble_in_use = cross;
  } else if (symble_choice == 2) {
    symble_in_use = star;
  } else if (symble_choice == 3) {
    symble_in_use = dollar;
  } else {
    cout << "Wrong input, try again \n";
    return -1;
  }

  cout << "------------------------------------" << endl;

  /* Use + to print a up-wise triangle */
  for (int i = 0; i < num_of_rows; i += 1) {
    for (int j = 0; j < num_of_rows - i; j += 1) {
      cout << symble_in_use;
    }
    cout << endl;
  }

  cout << "------------------------------------" << endl;
  /* print a down-wise triangle */

  for (int i = 0; i < num_of_rows; ++i) {
    for (int j = 0; j < i; ++j) {
      cout << symble_in_use;
    }
    cout << endl;
  }

  cout << "------------------------------------" << endl;
  /* print a rectangle */
  for (int i = 0; i < num_of_rows; ++i) {
    for (int j = 0; j < num_of_rows; ++j) {
      cout << symble_in_use;
    }
    cout << endl;
  }
}
