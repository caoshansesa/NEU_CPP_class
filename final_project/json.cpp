#include <iostream>
#include <string>
#include <fstream>
#include <ostream>
#include <map>
#include "json.hpp"
#include "state_def.hpp"

using namespace std;

//main API

vector<Project> deserialize(string filename){
	vector<Project> project_vec= json_to_projects(filename);

	return project_vec;

}

int serialize(string filename){

	ofstream ofs;
	ofs.open(filename,ofstream::out | ofstream::trunc);
	ofs.close();
  
  if (global_projects_vector.size() == 0) return 0;
	projects_to_json( global_projects_vector, filename);

	return 0;
}


map<string, string> read_people(string filename){
	map<string,string> temp_map;
	Json::CharReaderBuilder rbuilder;
	rbuilder["collectComments"] = false;
	Json::Value root_group;
	JSONCPP_STRING errs;

	fstream file;
	file.open(filename, ios::in);
	if(!file.is_open()){
		cout << "Open json file error!" <<endl;
	}

	Json::parseFromStream(rbuilder, file, &root_group, &errs);
	
	for(int i = 0; i < root_group.size(); i++){
		string name, role;
		
		name = root_group[i]["name"].asString();
		role = root_group[i]["role"].asString();
	//	cout << name << ": " <<role <<endl;	
		//people_map.insert(make_pair(name, role));
		temp_map[name] = role;

	}

	auto it = temp_map.begin();
	while(it!= temp_map.end()){
		string name = it->first;
		string role = it->second;
		cout << name <<": " <<role <<endl;
		it++;

	}
	file.close();

	return temp_map;
}




//helper functions 
/*TASKS TO JSON FILE*/
vector <Task> tasks_from_project_json(Json::Value tasks_json) {
    vector <Task> tasks;

    for (int i = 0; i < tasks_json.size(); i++) {
        Task temp_task;
        temp_task.assignees = tasks_json[i]["assignees"].asString();
        temp_task.issues = tasks_json[i]["issues"].asString();
        temp_task.id = tasks_json[i]["id"].asInt();
        temp_task.type = tasks_json[i]["type"].asString();
        temp_task.priority = tasks_json[i]["priority"].asInt();
        temp_task.assignDate = tasks_json[i]["assignDate"].asString();
        temp_task.dueDate = tasks_json[i]["dueDate"].asString();
        temp_task.completionDate = tasks_json[i]["completionDate"].asString();
        temp_task.title = tasks_json[i]["title"].asString();
        temp_task.status = tasks_json[i]["status"].asString();

        tasks.push_back(temp_task);
    }

    return tasks;
}

/*1. PROJECT TO JSON*/
int project_to_json(Project project,string filename) {

    Json::CharReaderBuilder rbuilder;
    rbuilder["collectComments"] = false;
    Json::Value root_group;
    JSONCPP_STRING errs;

    fstream file;
    file.open(filename);
    if (!file.is_open()) {
        cout << "Open json file error!" << endl;
    }

    Json::parseFromStream(rbuilder, file, &root_group, &errs);

    file.close();

    root_group.append(project.toJson());

    file.open(filename, ios::out);
    file << root_group.toStyledString();
    file.close();

    return 0;
}

/*2. PROJECT VECTOR TO JSON*/
int projects_to_json(vector <Project> projects, string filename) {
    Json::CharReaderBuilder rbuilder;
    rbuilder["collectComments"] = false;
    Json::Value root_group;
    JSONCPP_STRING errs;

    fstream file;
    file.open(filename);
    if (!file.is_open()) {
        cout << "Open json file error!" << endl;
    }

    Json::parseFromStream(rbuilder, file, &root_group, &errs);

    file.close();
    for (int i = 0; i<projects.size(); i++) root_group.append(projects[i].toJson());

    file.open(filename, ios::out);
    file << root_group.toStyledString();
    file.close();

    return 0;
}


/*3.JSON TO PROJECT*/
Project json_to_project(int i,string filename) {
    Json::CharReaderBuilder rbuilder;
    rbuilder["collectComments"] = false;
    Json::Value root_group;
    JSONCPP_STRING errs;

    fstream f;
    f.open(filename, ios::in);
    if (!f.is_open()) {
        cout << "Open json file error!" << endl;
    }

    Json::parseFromStream(rbuilder, f, &root_group, &errs);

    Project new_proj;

    new_proj.id = root_group[i]["id"].asInt();
    new_proj.name = root_group[i]["name"].asString();
    new_proj.description = root_group[i]["description"].asString();
    new_proj.assignDate = root_group[i]["assignDate"].asString();
    new_proj.dueDate = root_group[i]["dueDate"].asString();
    new_proj.completionDate = root_group[i]["completionDate"].asString();
    new_proj.projectOwnerUserName = root_group[i]["projectOwnerUserName"].asString();
    new_proj.projectManagerUserName = root_group[i]["projectManagerUserName"].asString();
    new_proj.tasks = tasks_from_project_json(root_group[i]["tasks"]);

    f.close();

    return new_proj;
}

/*4.JSON TO PROJECT VECTOR*/
vector <Project> json_to_projects(string filename) {
    vector <Project> idx;
    Json::CharReaderBuilder rbuilder;
    rbuilder["collectComments"] = false;
    Json::Value root_group;
    JSONCPP_STRING errs;

    fstream f;
    f.open(filename, ios::in);
    if (!f.is_open()) {
        cout << "Open json file error!" << endl;
    }

    Json::parseFromStream(rbuilder, f, &root_group, &errs);

    for (int i = 0; i < root_group.size(); i++) {
        Project new_proj;

        new_proj.id = root_group[i]["id"].asInt();
        new_proj.name = root_group[i]["name"].asString();
        new_proj.description = root_group[i]["description"].asString();
        new_proj.assignDate = root_group[i]["assignDate"].asString();
        new_proj.dueDate = root_group[i]["dueDate"].asString();
        new_proj.completionDate = root_group[i]["completionDate"].asString();
        new_proj.projectOwnerUserName = root_group[i]["projectOwnerUserName"].asString();
        new_proj.projectManagerUserName = root_group[i]["projectManagerUserName"].asString();
        new_proj.tasks = tasks_from_project_json(root_group[i]["tasks"]);

        idx.push_back(new_proj);
    }

    f.close();

    return idx;

}

/*1 USER TO JSON*/
int user_to_json(User user, string filename) {
    Json::CharReaderBuilder rbuilder;
    rbuilder["collectComments"] = false;
    Json::Value root_group;
    JSONCPP_STRING errs;

    fstream file;
    file.open(filename);
    if (!file.is_open()) {
        cout << "Open json file error!" << endl;
    }

    Json::parseFromStream(rbuilder, file, &root_group, &errs);

    file.close();
    root_group.append(user.toJson());

    file.open("user.json", ios::out);
    file << root_group.toStyledString();
    file.close();

    return 0;

}
/*2. USER VECTOR TO JSON*/
int users_to_json(vector<User> users,string filename) {
    Json::CharReaderBuilder rbuilder;
    rbuilder["collectComments"] = false;
    Json::Value root_group;
    JSONCPP_STRING errs;

    fstream file;
    file.open(filename);
    if (!file.is_open()) {
        cout << "Open json file error!" << endl;
    }

    Json::parseFromStream(rbuilder, file, &root_group, &errs);

    file.close();

    for (int i = 0; i < users.size(); i++)
        root_group.append(users[i].toJson());

    file.open(filename, ios::out);
    file << root_group.toStyledString();
    file.close();

    return 0;
}


/*3 JSON TO USER*/
User json_to_user(int i, string filename) {

    Json::CharReaderBuilder rbuilder;
    rbuilder["collectComments"] = false;
    Json::Value root_group;
    JSONCPP_STRING errs;

    fstream f;
    f.open(filename, ios::in);
    if (!f.is_open()) {
        cout << "Open json file error!" << endl;
    }

    Json::parseFromStream(rbuilder, f, &root_group, &errs);

    User new_user;

    new_user.name = root_group[i]["name"].asString();
    new_user.userName = root_group[i]["userName"].asString();
    new_user.jobTitle = root_group[i]["jobTitle"].asString();
    new_user.canDeleteTask = root_group[i]["canDeleteTask"].asBool();
    new_user.canEditTask = root_group[i]["canEditTask"].asBool();
    new_user.canAddTask = root_group[i]["canAddTask"].asBool();
    new_user.canDeletePrj = root_group[i]["canDeletePrj"].asBool();
    new_user.canEditPrj = root_group[i]["canEditPrj"].asBool();
    new_user.canAddPrj = root_group[i]["canAddPrj"].asBool();

    f.close();

    return new_user;

}

/*4 JSON TO USER VECTOR*/
vector <User> json_to_users(string filename) {
    vector <User> idx;
    Json::CharReaderBuilder rbuilder;
    rbuilder["collectComments"] = false;
    Json::Value root_group;
    JSONCPP_STRING errs;

    fstream f;
    f.open(filename, ios::in);
    if (!f.is_open()) {
        cout << "Open json file error!" << endl;
    }

    Json::parseFromStream(rbuilder, f, &root_group, &errs);

    for (int i = 0; i < root_group.size(); i++) {
        User new_user;

        new_user.name = root_group[i]["name"].asString();
        new_user.userName = root_group[i]["userName"].asString();
        new_user.jobTitle = root_group[i]["jobTitle"].asString();
        new_user.canDeleteTask = root_group[i]["canDeleteTask"].asBool();
        new_user.canEditTask = root_group[i]["canEditTask"].asBool();
        new_user.canAddTask = root_group[i]["canAddTask"].asBool();
        new_user.canDeletePrj = root_group[i]["canDeletePrj"].asBool();
        new_user.canEditPrj = root_group[i]["canEditPrj"].asBool();
        new_user.canAddPrj = root_group[i]["canAddPrj"].asBool();

        idx.push_back(new_user);
    }
    f.close();

    return idx;

}






