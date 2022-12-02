/*main.cpp*/

#include <iostream>

#include "header.hpp"

using namespace std;

int main() {
    Student_info_container students;
    students = load_data_from_csv_into_file("Assignment4_Pref1.csv");
    
    group_students(students);
#if 0
    for (const auto &p: student_groups) {
        cout << p.first << endl;
        cout << p.second << endl;
	if(student_non_dev[p.first]){
	 cout << student_non_dev[p.first];}
	else{cout << student_dev[p.first];}
     for(auto d: students[p.first].devil){
	cout <<d;}
        cout << "\n\n" << endl;
    }
#endif
    return 0;
}



