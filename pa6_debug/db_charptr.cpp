//This program should read any string (including spaces) from the user and print it using a character pointer
//The program is setup to use pointer offset notation to get each character of the string

//Number of bugs/errors : 8

#include <iostream> // bug1: use iostream for c++
#include <cstring> //bug2: use cstring 

using namespace std;

int main(void){ // return type
    char s[20];
    char *cPtr; // bug3: use the ptr;
    cin.getline(s, 20);  // bug4: use getline for the input of string.
    cPtr = s;
	cout << "what you have typed /n/n" <<endl;
    while(*(cPtr) != '\0'){  //bug 5: no decrement
							// bug 6: use dereference to get the value to compare.
 							
        cout << *(cPtr++);     //bug7: need output value
    }
  cout<<"\n";
  return 0;    
}
