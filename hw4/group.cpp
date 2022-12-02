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

int total_students = 0;
int group_n = 0;

int c = 10, gdb = 5, algo = 5;

map<string, int> student_non_dev; // every student with out a devil list and
                                  // their weighted score
map<string, int> student_dev;     // student with  a devil list and their wighted score
map<string, int> student_groups;  // every student and their team assigned

map<string, int>::iterator finder;

int w_sum(const student_info &s)
{
    return c * s.c_level + gdb * s.gdb_level + algo * s.algo_level;
};

void print_team_info(map<string, int> students_str)
{
    for (int i = 0; i < group_n; i++)
    {
        int team_sum = 0;
        auto it = students_str.begin();
        cout << "This is group " << i << "\n";
        while (it != students_str.end())
        {
            if (it->second == i)
            {
                cout << it->first << " ";
                if (student_non_dev.find(it->first) != student_non_dev.end())
                {
                    team_sum += student_non_dev.find(it->first)->second;
                }
                else
                {
                    team_sum += student_dev.find(it->first)->second;
                }
            }
            it++;
        }
        cout << "group_score is " << team_sum << endl;
        cout << endl;
    }
}

bool compare_v(const pair<string, int> &a, const pair<string, int> &b)
{
    return a.second < b.second;
}

int sort_m(map<string, int> &student_map)
{
    vector<pair<string, int> > vec;

    for (const auto &p : student_map)
    {
        vec.emplace_back(p);
    }

    sort(vec.begin(), vec.end(), compare_v);

    return 0;
}

int group_students(Student_info_container students)
{
    // create a copy of students with devil list and without devil list
    cout << " Please input your per_group student number: 3 or 4 \n";
    int max_per_group = 0;
    cin >> max_per_group;
    for (auto p : students)
    {
        auto key = p.first;
        auto value = students[key];
        if (value.devil.empty())
        {
            student_non_dev[key] = w_sum(value); // add to non_dev map
        }
        else
        {
            student_dev[key] = w_sum(value);
        }                 // add to dev map
        total_students++; // total number of students in container
    }
    group_n = total_students / max_per_group;
    // sort maps
    sort_m(student_non_dev);
    sort_m(student_dev);

    // assign every student__dev first
    auto it = student_dev.begin();
    int n = 0;
    while (n < group_n && it != student_dev.end())
    {
        student_groups[it->first] = n;
        n++;
        it++;
    }

    int r = 0;
    while (r < max_per_group)
    {
        // assign the rest of students in student_dev
        n = 0;
        while (n < group_n && it != student_dev.end())
        {
            int curr_g = 0, prev_g = 0;
            bool found_dev = false;
            while (!found_dev)
            {
                curr_g = rand() % group_n;
                if (curr_g == prev_g)
                {
                    found_dev = true;
                }
                for (auto p : students)
                {
                    if (it->second == curr_g)
                    {
                        auto itr2 = p.second.devil.begin();
                        int j = 0;
                        while (itr2 != p.second.devil.end())
                        {
                            if (it->first == p.second.devil.at(j))
                            {
                                found_dev = false;
                            }
                            itr2++;
                            j++;
                        }
                    }
                }
            }

            student_groups[it->first] = n;
            prev_g = curr_g;
            it++;
            n++;
        }
        r++;
    }

    // assign those who don't have a dev list based on their pref before
    // randomizing a number

    r = 0;

    it = student_non_dev.begin();
    while (r < max_per_group)
    {
        // assign the rest of students in student_dev
        n = 0;
        while (n < group_n && it != student_non_dev.end())
        {
            int curr_g = 0, prev_g = 0;
            bool found_dev = false;
            while (!found_dev)
            {
                if (curr_g == prev_g)
                {
                    found_dev = true;
                }
                for (auto p : students)
                {
                    if (it->second == curr_g)
                    {
                        auto itr2 = p.second.devil.begin();
                        int j = 0;
                        while (itr2 != p.second.devil.end())
                        {
                            if (it->first == p.second.devil.at(j))
                            {
                                found_dev = false;
                            }
                            itr2++;
                            j++;
                        }
                    }
                }
            }
            student_groups[it->first] = n;
            prev_g = curr_g;
            it++;
            n++;
        }
        r++;
    }

    print_team_info(student_groups);

    return 0;
}
