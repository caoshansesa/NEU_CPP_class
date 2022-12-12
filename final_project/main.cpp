#include <iostream>
#include <string>
#include <vector>
#include "json.hpp"
#include "cmd.hpp"


using namespace std;

int main(void) {
	deserialize("project.json");
	serialize("projects_test.json");
	
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
	modify_project_name(1,"this is a new name");
	serialize("projects_test.json");
	return 0;
}
