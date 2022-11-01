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

map<string, double> map_asseding;
map<string, double> map_desseding;

bool cmp_assending(pair<string, double>& a, pair<string, double>& b) {
  return a.second < b.second;
}


bool cmp_dessending(pair<string, double>& a, pair<string, double>& b) {
  return a.second < b.second;
}

void sort_assending(map<string, double>& M) {
  vector<pair<string, double> > A;
  for (auto& it : M) {
    A.push_back(it);
  }

  sort(A.begin(), A.end(), cmp_assending);
  for (auto& it : A) {
    cout << it.first << endl;
  }
}


void sort_desending(map<string, double>& M) {
  vector<pair<string, double> > A;
  for (auto& it : M) {
    A.push_back(it);
  }

  sort(A.begin(), A.end(), cmp_dessending);
  for (auto& it : A) {
    cout << it.first << endl;
  }
}

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
void print_each_HW_avarage(pair<string, vector<int> > _student_score) {
    string local_buffer;
  index_vector++;
  for (int i = 0; i < 7; i += 1) {
    sum[i] += _student_score.second.at(i);
  }
  if (index_vector == 5) {
    for (int i = 0; i < 7; i += 1) {
      average[i] = sum[i] / 5;
      local_buffer.append(" Assignment ");
      local_buffer.append(to_string(i+1));
      local_buffer.append(" average is ");
      local_buffer.append(to_string(average[i]));
      local_buffer.append("\n");
    }
  }

      cout << local_buffer << endl;
}

void print_each_student_average(pair<string, vector<int> > _student_score) {
  string local_buffer;
  double sum_local = 0;
  for (int i = 0; i < 7; i++) {
    sum_local += _student_score.second.at(i);
  }
  local_buffer.append(_student_score.first);
  local_buffer.append(", Grade:");
  for (int i = 0; i < 7; i++) {
    local_buffer.append(to_string(_student_score.second.at(i)));
    local_buffer.append(" ");
  }
  local_buffer.append("average : ");
  local_buffer.append(to_string(sum_local / 7));
  map_asseding.insert(pair<string, double>(local_buffer, sum_local / 7));
  if (map_asseding.size() == 5) {
    sort_assending(map_asseding);
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
  cout << endl;

  for_each(studnent_grade.begin(), studnent_grade.end(), print_list_info);

  cout << endl;
  cout << "The average " << endl;
  for_each(studnent_grade.begin(), studnent_grade.end(), print_each_HW_avarage);

  cout << endl;
  cout << "Per student Grade" << endl;
  for_each(studnent_grade.begin(), studnent_grade.end(),
           print_each_student_average);

  return 0;
}
