#include <string>
#include "task.h"
#include <vector>

using namespace std;

class Project {
public:
    int id;
    string name;
    string description;
    string assignDate;
    string dueDate;
    string completionDate;
    vector <Task> tasks;
    string projectOwnerUserName;
    string projectManagerUserName;

    Json::Value toJson() {
        Json::Value proj_json;
        proj_json["id"] = id;
        proj_json["name"] = name;
        proj_json["description"] = description;
        proj_json["assignDate"] = assignDate;
        proj_json["dueDate"] = dueDate;
        proj_json["completionDate"] = completionDate;


        Json::Value tasks_json;
        for (Task t: tasks) tasks_json.append(t.toJson());
        proj_json["tasks"] = tasks_json;

        proj_json["projectOwnerUserName"] = projectOwnerUserName;
        proj_json["projectManagerUserName"] = projectManagerUserName;

        return proj_json;


    }


};


/*
map<string, int> roles = {
        {"owner", 1},
        {"developer", 2},
        {"manager", 3},
        {"QA",4}
};
*/
