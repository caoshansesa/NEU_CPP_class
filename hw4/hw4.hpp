#include <string>
#include <map>
#include <vector>
#include <stdio.h>
#include <fstream>

using namespace std;
struct student_info
{
		int c_level;
		int gdb_level;
		int Alg_level;
		vector<string> name_Devil;
		vector<string> name_Angel;
		int Grounp_num_been_asign;
};

map<string, struct student_info> _student_info;

typedef  map<string, struct student_info> Student_info_container;
