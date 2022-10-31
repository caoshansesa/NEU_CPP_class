#include <cstdlib>
#include <stdio.h>
#include <map>
#include <vector>

using namespace std;

int main()
{
    map< string, vector<int> > studnent_grade;
    vector<int> student_score;
    for (int i = 0; i<5; i++) {
        student_score.push_back(rand()%50 + 10);
    }
    return 0;
}
