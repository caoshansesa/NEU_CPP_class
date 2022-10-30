#include "hw4.hpp"

#include <sstream>
#include <string>

Student_info_container load_data_from_csv_into_file(string file_name) {
  Student_info_container _student_info;
  fstream fin;
  string temp, line, word;
  string username;
  string name_Angel_list;
  string name_Devil_list;

  fin.open(file_name, ios::in);

  getline(fin, line);  // remove the first row
  while (fin >> temp) {
    struct student_info _student_info_local;

    while (getline(fin, line)) {
      // break file into words
      stringstream s(line);

      getline(s, word, ',');  // username
      username = word;

      getline(s, word, ',');  // c_level
      _student_info_local.c_level = stoi(word);

      getline(s, word, ',');  // gdb_level
      _student_info_local.gdb_level = stoi(word);

      getline(s, word, ',');  // Alg_level
      _student_info_local.Alg_level = stoi(word);

      getline(s, word, ',');  // save all the name in one line string
      name_Angel_list = word;

      getline(s, word, ',');  // save all the name in one line string
      name_Devil_list = word;

      stringstream nam_D(name_Devil_list);
      while (getline(nam_D, word, ' ')) {
        _student_info_local.name_Devil.push_back(word);
      }

      stringstream nam_A(name_Angel_list);
      while (getline(nam_A, word, ' ')) {
        _student_info_local.name_Angel.push_back(word);
      }
      _student_info.insert(
          pair<string, student_info>(username, _student_info_local));
    }
  }
  return _student_info;
}

int main() {
  Student_info_container student_info_obj;
  student_info_obj = load_data_from_csv_into_file("Assignment4_Pref1.csv");
  return 0;
}
