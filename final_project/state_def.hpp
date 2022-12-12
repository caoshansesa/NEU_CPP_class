#ifndef MAIN_H
#define MAIN_H

#include <string>
#include <vector>
#include <map>
#include "json/json.h"

using namespace std;

static int terminal_x, terminal_y = 0;
static string username;

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
class User
{
  public:
    string name;
    string userName;
    string jobTitle;
    bool canDeleteTask = true;
    bool canEditTask = true; // only certain attributes
    bool canAddTask = true;
    bool canDeletePrj = true;
    bool canEditPrj = true;
    bool canAddPrj = true;
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

class ProjectOwner : User
{
    ProjectOwner(){};
};

class Developer : User
{
    Developer()
    {
        canDeletePrj = false;
        canDeleteTask = false;
        canEditPrj = false;
        canAddPrj = false;
        canEditTask = true;
        canAddTask = true;
    };
};

class QAEngineers : User
{
    QAEngineers()
    {
        canDeletePrj = false;
        canDeleteTask = false;
        canEditPrj = false;
        canAddPrj = false;
        canEditTask = false;
        canAddTask = false;
    };
};

class ProjectManager : User
{
    ProjectManager()
    {
        canDeletePrj = false;
        canDeleteTask = true;
        canEditPrj = true;
        canAddPrj = false;
        canEditTask = true;
        canAddTask = true;
    };
};


class Project
{
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

extern map<string, string> people_map;
extern vector<Project> global_projects_vector;




// Define user command line state,
enum CMD_STATE
{
    CMD_INIT = 0,
    RUNNING, // RUNNING state, keep taking user input, update json
    EXIT     // EXIT state, exit user command line input, goto next view
};

enum VIEW_STATE
{
    INIT = 0,
    LOGIN_VIEW,
    MAKE_SELECT_VIEW,
    CURRENT_STATUS_VIEW,
    MY_BOARD_VIEW,
    MY_PROJECT_VIEW,
    MY_TASKVIEW
};

static enum VIEW_STATE next_view = INIT;

#endif
