#include <vector>
#include "cmd.hpp"


using namespace std;

Project find_project_by_id(int project_id){
	auto it = global_projects_vector.begin();
	while(it != global_vectors.begin.end()){
		if(it->id == project_id) return *it;
	
	it++;
	}
	return nullptr;
}


int modify_project_name(int project_id, string name){
	Project obj = find_project_by_id(project_id);
	if(obj == nullptr) return -1;
	else{
		obj.name = name;
		return 0;
	}	
}


int modify_project_description(int project_id,string description){
	Project obj = find_project_by_id(project_id);
	if(obj == nullptr) return -1;
	else{
		obj.description = description;
		return 0;
	}

}

int modify_project_duedate(int project_id, string dueDate){
        Project obj = find_project_by_id(project_id);
	if(obj == nullptr) return -1;
        else{
                obj.dueDate = dueDate;
                return 0;
        }

}

int modify_projectcompletiondate(int project_id, string completionDate){
        Project obj = find_project_by_id(project_id);
	if(obj==nullptr) return -1;
        else{
                obj.completionDate = completionDate;
                return 0;
        }

}

int modify_project_manager(int project_id, string new_manager){
        Project obj = find_project_by_id(project_id);
	if(obj ==nullptr) return -1;
        else{
                obj.projectManagerUserName = new_manager;
                return 0;
        }

}

int modify_project_owner(int project_id, string new_owner){
        Project obj = find_project_by_id(project_id);
	if(obj == nullptr) return -1;
        else{
                obj.projectOwnerUserName = new_owner;
                return 0;
        }

        return -1;

}

int delete_project(int project_id){
        auto obj = find_project_by_id(project_id);
	if(obj == nullptr) return -1;
        delete obj;
	return 0;

}



