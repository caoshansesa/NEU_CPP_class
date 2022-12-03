/*main.cpp*/

#include <iostream>

#include "header.hpp"

using namespace std;

int main()
{
    Student_info_container students;

    students = load_data_from_csv_into_file("Assignment4_Pref1.csv");

    group_students(students);
    return 0;
}

