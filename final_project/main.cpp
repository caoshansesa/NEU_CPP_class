#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "json.hpp"
#include "cmd.hpp"


using namespace std;

int main(void) {
  
//test people.json is being read to map 
	people_map = read_people("people.json");
	cout << "parse the map" <<endl;
	auto it = people_map.begin();
	string name, role;
	while(it!= people_map.end()){
		name = it->first;
		role = it->second;
		
	cout << name<<": " <<role <<endl;
	it++;
    }
  cout << "************************"<<endl;
  //test that global vector is being passed
  cout << global_projects_vector.size() <<endl;
  global_projects_vector= deserialize("project.json");
  cout << global_projects_vector.size() <<endl;
  for(int i =0; i< global_projects_vector.size();i++){
    cout << "Project name: " <<global_projects_vector.at(i).name <<endl;
    }
    cout << "************************"<<endl;
    /*Project* myproject = find_project_by_id(1,global_projects_vector);*/
  Project myproject = global_projects_vector[0];
  cout << "project_name:" << myproject.name << endl;
  //modify_project_name(*myproject, "new name");
    
  myproject.name = "newname";
  cout << "project_name:" << global_projects_vector[0].name << endl;

  Task mytask = myproject.tasks[0];
  
	serialize(global_projects_vector,"projects_test.json");
	return 0;
}
