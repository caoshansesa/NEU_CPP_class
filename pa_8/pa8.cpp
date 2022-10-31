#include <stdio.h>

#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>

using namespace std;
int index_vector = 0;

void print_list_info(pair<string, vector<int> > _student_score) {
  cout << _student_score.first << ": ";
  for (int i = 0; i < 7; i += 1) {
    cout << " " << _student_score.second.back() << "  ";
    _student_score.second.pop_back();
  }
  cout << endl;
}

double average[7] = {0};
double sum[7] = {0};
void print_average(pair<string, vector<int> > _student_score) {
  index_vector++;
  for (int i = 0; i < 7; i += 1) {
    sum[i] += _student_score.second.at(i);
  }
  if (index_vector == 5) {
    for (int i = 0; i < 7; i += 1) {
      average[i] = sum[i] / 5;
      cout << "Assignment " << i + 1 << " average is :" << average[i] << endl;
    }
  }
}

int main() {
  map<string, vector<int> > studnent_grade;
  vector<int> student_score[7];
  string name_student[5] = {"Shan", "Amel", "Ted ", "Moh ", "Jeff"};

  for (int j = 0; j < 5; j++) {
    for (int i = 0; i < 7; i++) {
      student_score[j].push_back(rand() % 50 + 10);
    }
    studnent_grade.insert(
        pair<string, vector<int> >(name_student[j], student_score[j]));
  }

  cout << "Name  HW1  HW2  HW3  HW4  HW5  HW6  HW7  " << endl;

  for_each(studnent_grade.begin(), studnent_grade.end(), print_list_info);

  cout << "The average " << endl;
  for_each(studnent_grade.begin(), studnent_grade.end(), print_average);

  return 0;
}
