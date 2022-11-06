/*
 * =====================================================================================
 *
 *       Filename:  pa9.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  11/06/2022 08:32:11
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (),
 *   Organization:
 *
 * =====================================================================================
 */
#include <stdlib.h>

#include <list>
#include <string>

using namespace std;
class GROUP {
 private:
  string group_name;
  string course_name;
  list<string> student_in_group;
};

class Student {
 private:
  string student_name;
  int unique_ID;
  int course_number;
};

class Course {
 private:
  int unique_course_number;
  string course_name;
  int course_number;
  list<string> student_Enroll_in_course;
};

int main() {}
