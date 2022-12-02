/*header.hpp*/

#include <map>
#include <string>
#include <vector>

using namespace std;

struct student_info
{
    int c_level;
    int gdb_level;
    int algo_level;
    vector<string> devil;
    vector<string> angel;
};


typedef map<string, struct student_info> Student_info_container;

int group_students(Student_info_container students);

Student_info_container load_data_from_csv_into_file(const string &filename);

