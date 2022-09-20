/*************************************
 * Shan Cao
 * Practices 2
 * 09/19/2022 22:20:56
 *************************************/

#include <algorithm>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>

using namespace std;

int sum_of_ascII(string ss) {
  int sum = 0;
  for (int i = 0; i < ss.size(); i++) {
    sum = sum + ss[i];
  }
  return sum;
}

int main() {
  cout << "Guest Book\n\n";

  string first_name;
  cout << "First name:\t";
  cin >> first_name;  // get first string only

  string middle_initial;
  cout << "Middle initial:\t";
  cin.ignore(100, '\n');       // ignore leftover chars and newline
  middle_initial = cin.get();  // get first char only

  string last_name;
  cout << "Last name:\t";
  cin >> last_name;

  string address;
  cout << "Address:\t";
  cin.ignore();
  getline(cin, address);

  string city;
  cout << "City:    \t";
  cin >> city;

  string state_name;
  cout << "state:   \t";
  cin.ignore(); /* Flush the cin */
  getline(cin, state_name, '\n');
  /* get only the first two digits for the State name string */
  state_name = state_name.substr(0, 2);

  string zip_code;
  cout << "zip_code  \t";
  cin >> zip_code;

  string country;
  cout << "Country:  \t";
  cin >> country;



  cout << "--------------------------------------------------------\n\n";
  cout << "Display what has been typed in \n";

  cout << "\nENTRY\n"  // display the entry
       << "First Name:  \t" << first_name + "\n"
       << "Middle Name: \t" << ' ' + middle_initial + ".\n"
       << "Last Name:   \t" << last_name + "\n"
       << "Address:     \t" << address + "\n"
       << "City:        \t" << city + "\n"
       << "State:       \t" << state_name + " \n"
       << "Country      \t" << country + "\n";





  cout << "--------------------------------------------------------\n\n";
  cout << "Display what it looks like if we put all the variables into the "
          "same variables\n";
  string longstr = first_name + " " + middle_initial + " " + last_name + '\n' +
                   address + " \n" + city + " " + state_name + " " + zip_code +
                   " \n" + country + "\n";

  longstr = longstr + '\n';
  cout << "\nENTRY\n";  // display the entry
  cout << longstr;

  replace(longstr.begin(), longstr.end(), '\n', '.');

  cout << "--------------------------------------------------------\n\n";
  cout << "Display what it looks like if we replace all the slash n with the "
          "dot \n";
  cout << longstr;




  cout << "--------------------------------------------------------\n\n";
  cout << "The Sum of the ASC value of all the digits \n";
  int total = sum_of_ascII(longstr);
  cout << "the number is: \t";
  cout << total;
}
