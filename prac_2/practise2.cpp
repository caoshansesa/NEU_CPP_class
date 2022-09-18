#include <iostream>
#include <string>

using namespace std;

int main()
{
	cout << "Guest Book\n\n";

	string first_name;
	cout << "First name:\t";
	cin >> first_name;             // get first string only

	char middle_initial;
	cout << "Middle initial:\t";
	cin.ignore(100, '\n');         // ignore leftover chars and newline
	middle_initial = cin.get();    // get first char only

	string last_name;
	cout << "Last name:\t";
	cin.ignore(100, '\n');         // ignore leftover chars and newline
	getline(cin, last_name);       // get entire line

	string address;
	cout << "Address:\t";
	cin.ignore(100, '\n');         // ignore leftover chars and newline

	string city;
	cout << "City:\t";
	getline(cin, city);            // get entire line
	
    string state_name;
	cout << "state:\t";
	cin.ignore(100, '\n');         // ignore leftover chars and newline
	getline(cin, state_name);       // get entire line
    
	string zip_code;
	cout << "zip_code\t";
	getline(cin, zip_code);            // get entire line

	string country;
	cout << "Country:\t";
	getline(cin, country);         // get entire line

	cout << "\nENTRY\n"            // display the entry
		<< first_name + ' ' + middle_initial + ". " + last_name + '\n'
        << address + ' ' + city + ' ' + state_name + '\n' 
		<< zip_code + ", " + country + "\n";
}
