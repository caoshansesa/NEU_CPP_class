#include <iostream>
#include <string>
#include <vector>
#include "json.hpp"



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
	return 0;
}
