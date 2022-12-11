#ifndef MAIN_H
#define MAIN_H

#include <string>

static int terminal_x, terminal_y = 0;
using namespace std;

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

class Task
{
  public:
    int id;
    string type;
    int priority;
    int size;
    string assignDate;
    string dueDate;
    string completionDate;
    string title;
    string assignees;
    string status; // to-do, doing, done
    string issues[10];
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
    Task tasks[10];
    string projectOwnerUserName;
    string projectManagerUserName;
};

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
