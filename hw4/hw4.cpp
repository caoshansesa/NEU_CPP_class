#include <sstream>
#include <string>
#include "hw4.hpp"

Student_info_container load_data_from_csv_into_file(string file_name) {
    Student_info_container _student_info;
    fstream fin;
    string temp, line, word;
    string username;
    string name_Angel_list;
    string name_Devil_list;

    fin.open(file_name, ios::in);

    getline(fin, line);  // remove the first row
        struct student_info _student_info_local;

        while (getline(fin, line)) {
            // break file into words
            stringstream s(line);
            //remove \r from the end
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

            _student_info_local.name_Angel.clear();
            _student_info_local.name_Devil.clear();

            name_Devil_list.erase(name_Devil_list.size() -1);

            if(name_Devil_list != "") {

                stringstream nam_D(name_Devil_list);
                while (getline(nam_D, word, ' ')) {
                    _student_info_local.name_Devil.push_back(word);
                }
            }

            if(name_Angel_list != "") {
                name_Angel_list.erase(name_Angel_list.size() -1);
                stringstream nam_A(name_Angel_list);
                while (getline(nam_A, word, ' ')) {
                    _student_info_local.name_Angel.push_back(word);
                }
            }

            _student_info.insert(
                    pair<string, student_info>(username, _student_info_local));

        }
    return _student_info;
}

int main() {
    Student_info_container student_info_obj;
    student_info_obj = load_data_from_csv_into_file("Assignment4_Pref3.csv");
    for(auto const& x : student_info_obj)
    {
        cout << x.first << ":" << x.second.c_level << " " << x.second.gdb_level << " " << x.second.Alg_level << endl;
        for (auto name : x.second.name_Angel) {
            cout << name << " ";
        }
        cout << endl;
        for (auto name : x.second.name_Devil ) {
            cout << name << " ";
        }
        cout << endl;
        cout << "----------" <<endl;
    }
    return 0;
}
