#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <list>
#include <string>

using namespace std;

class Student {
 private:
  string student_name;
  int unique_ID;
  int course_number;

 public:
  string get_student_name();
  int get_uniue_ID();
  int get_course_number();

  void set_student_name(string _student_name);
  void set_uniue_ID(int _unique_ID);
  void set_course_number(int _course_number);
};

string Student::get_student_name() { return student_name; }
int Student::get_uniue_ID() { return unique_ID; }
int Student::get_course_number() { return course_number; }

void Student::set_student_name(string _student_name) {
  student_name = _student_name;
}
void Student::set_uniue_ID(int _unique_ID) { unique_ID = _unique_ID; }
void Student::set_course_number(int _course_number) {
  course_number = _course_number;
}

class GROUP {
 private:
  string group_name;
  string course_name;

 public:
  list<Student> student_in_group;
  string get_group_name();
  void set_group_name(string _group_name);

  string get_course_name();
  void set_course_name(string _course_name);
};

string GROUP::get_group_name() { return group_name; }
void GROUP::set_group_name(string _group_name) { group_name = _group_name; }
string GROUP::get_course_name() { return course_name; }
void GROUP::set_course_name(string _course_name) { course_name = _course_name; }

class Course {
 private:
  int unique_course_number;
  string course_name;
  int course_number;

 public:
  list<Student> student_Enroll_in_course;
  Course(string _course_name, int _course_number, int _unique_course_number) {
    _course_name = course_name;
    _course_number = course_number;
    _unique_course_number = unique_course_number;
  };
  friend std::ostream& operator<<(ostream& os, Student& student_list);

  GROUP& operator/(const int& NumOfGroups);
};

std::ostream& operator<<(ostream& os, Student& _student) {
  os << _student.get_student_name();
  return os;
}

GROUP& Course::operator/(const int& NumOfGroups) {
  int student_total = this->student_Enroll_in_course.size();
  int num_per_group = student_total / NumOfGroups;
  GROUP group_obj;
  for (int i = 0; i < NumOfGroups; i++) {
    string group_name = "group" + to_string(i);
    for (int j = 0; j < num_per_group; j++) {
      cout << this->student_Enroll_in_course.back();
      this->student_Enroll_in_course.pop_back();
    }
  }
  return group_obj;
}

int main() {
  Course cs3520("cs3520", 3520, 111);
  GROUP _group;
  string _name[15] = {
      "Oluwatobiloba Cortes", "Brandy Mata", "Kiera Moran",    "Lyla Sosa",
      "Alysia Abbott",        "Cian Barr",   "Hugh O'Connor",  "Lukasz Curran",
      "Rachelle Bishop",      "Lorcan Drew", "Anwen",          "Baxter Nelson",
      "Weston Anabella",      "Park Isaac",  "Kurtis Paterson"};
  for (int i = 0; i < 15; i++) {
    Student _student;
    _student.set_student_name(_name[i]);
    cs3520.student_Enroll_in_course.push_back(_student);
  }

  int _num_of_group = 3;
  _group = cs3520 / _num_of_group;
}
