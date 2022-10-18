// This program includes a struct called car that is used to store information
// about a given car The program should ask the user for information about their
// car and initialize a car structure with the given information The program
// should also print the information using a pointer to the initialized struct
// The information printed using the struct and the pointer should be the same

// Bugs to fix : 9

#include <iostream>
#include <string>

// Bug 1. missing std namespace
using namespace std;
struct car {
  char *name;
  int modelYear;
  float speed;
};

int main(void) {
  char n[20]; 
  int a;
  float w;

  struct car c;
  car *cPtr = &c;

  cout << "What is your favorite car's name: ";
  cin >> n;
  c.name = n; //bug 3. name is part of struct car

  cout << "When was it launched : ";
  cin >> a;// bug 4.this should be a cin for input
  c.modelYear = a; 

  cout << "How much speed does it give : ";
  cin >> w; //bug 5. the operator error
  c.speed = w; //bug 6. the assignment should be input w


  cout << "Car's name is " << c.name << ", and should be the same as " << cPtr->name// bugs 7. should use cPtr ->name
       << ".\n";

  cout << "Car's model year is " << c.modelYear << ", and should be the same as "// use instance not the type
       << cPtr->modelYear << ".\n";//9 shoudl use cPtr->modelYear
  cout << "Car's speed is " << c.speed << ", and should be the same as "
       << cPtr->speed  << ".\n"; // 10. it should use cPtr -> speed
}
