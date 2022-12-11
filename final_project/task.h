#include <string>
#include "json/json.h"

using namespace std;

class Task {
public:
    int id;
    string type;
    int priority;
    string assignDate;
    string dueDate;
    string completionDate;
    string title;
    string assignees;
    string status;
    string issues;

    Json::Value toJson() {
        Json::Value task_json;
        task_json["id"] = id;
        task_json["type"] = type;
        task_json["priority"] = priority;
        task_json["assignDate"] = assignDate;
        task_json["dueDate"] = dueDate;
        task_json["completionDate"] = completionDate;
        task_json["title"] = title;
        task_json["status"] = status;
        task_json["assignees"] = assignees;
        task_json["issues"] = issues;

        return task_json;

    }
};

