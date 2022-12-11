#include <bits/stdc++.h>
#include "json/json.h"

using namespace std;

class User {
public:
    string name;
    string userName;
    string jobTitle;
    bool canDeleteTask;
    bool canEditTask;
    bool canAddTask;
    bool canDeletePrj;
    bool canEditPrj;
    bool canAddPrj;

    Json::Value toJson() {
        Json::Value user_json;
        user_json["name"] = name;
        user_json["userName"] = userName;
        user_json["jobTitle"] = jobTitle;
        user_json["canDeleteTask"] = canDeleteTask;
        user_json["canEditTask"] = canEditTask;
        user_json["canAddTask"] = canAddTask;
        user_json["canDeletePrj"] = canDeletePrj;
        user_json["canEditPrj"] = canEditPrj;
        user_json["canAddPrj"] = canAddPrj;

        return user_json;
    }
};

class ProjectOwner : User {
    ProjectOwner() {};
};

class Developer : User {
    Developer() {
        canDeletePrj = false;
        canDeleteTask = false;
        canEditPrj = false;
        canAddPrj = false;
        canEditTask = true;
        canAddTask = true;

    };
};

class QAEngineers : User {
    QAEngineers() {
        canDeletePrj = false;
        canDeleteTask = false;
        canEditPrj = false;
        canAddPrj = false;
        canEditTask = false;
        canAddTask = false;

    };
};

class ProjectManager : User {
    ProjectManager() {
        canDeletePrj = false;
        canDeleteTask = true;
        canEditPrj = true;
        canAddPrj = false;
        canEditTask = true;
        canAddTask = true;
    };
};































































