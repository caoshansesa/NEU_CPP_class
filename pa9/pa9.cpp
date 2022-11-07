#include <stdlib.h>

#include <list>
#include <string>

using namespace std;

class Student {
 private:
  string student_name;
  int unique_ID;
  int course_number;
};

class GROUP {
 private:
  string group_name;
  string course_name;
  list<Student> student_in_group;
};

class Course {
 private:
  int unique_course_number;
  string course_name;
  int course_number;
  list<Student> student_Enroll_in_course;

 public:
  void operator<<(const Student& student_list);

  list<GROUP>& operator/(const int& NumOfGroups);
};

list<GROUP>& Course::operator/(const int& NumOfGroups) {

}

void Course::operator<<(const Student& student_list) {}

int main() {
    
}
