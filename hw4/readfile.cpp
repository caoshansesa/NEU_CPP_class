/*readfile.cpp*/

#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

#include "header.hpp"

using namespace std;

Student_info_container load_data_from_csv_into_file(const string &file_name)
{
    Student_info_container _student_info;
    fstream fin;
    string temp, line, word;
    string username;
    string name_Angel_list;
    string name_Devil_list;

    fin.open(file_name, ios::in);

    getline(fin, line); // remove the first row
    struct student_info _student_info_local;

    while (getline(fin, line))
    {
        // break file into words
        stringstream s(line);
        // remove \r from the end
        getline(s, word, ','); // username
        username = word;

        getline(s, word, ','); // c_level
        _student_info_local.c_level = stoi(word);

        getline(s, word, ','); // gdb_level
        _student_info_local.gdb_level = stoi(word);

        getline(s, word, ','); // Alg_level
        _student_info_local.algo_level = stoi(word);

        getline(s, word, ','); // save all the name in one line string
        name_Angel_list = word;

        getline(s, word, ','); // save all the name in one line string
        name_Devil_list = word;

        _student_info_local.angel.clear();
        _student_info_local.devil.clear();

        name_Devil_list.erase(name_Devil_list.size() - 1);

        if (!name_Devil_list.empty())
        {

            stringstream nam_D(name_Devil_list);
            while (getline(nam_D, word, ' '))
            {
                _student_info_local.devil.push_back(word);
            }
        }

        if (!name_Angel_list.empty())
        {
            name_Angel_list.erase(name_Angel_list.size() - 1);
            stringstream nam_A(name_Angel_list);
            while (getline(nam_A, word, ' '))
            {
                _student_info_local.angel.push_back(word);
            }
        }

        _student_info.insert(pair<string, student_info>(username, _student_info_local));
    }
    return _student_info;
}
