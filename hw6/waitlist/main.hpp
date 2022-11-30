#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <map>

using namespace std;

template <typename T>
bool contains(const vector<T> &vec,  T value){
    cout<<"vector template version"<<endl;
    for(T e : vec){
        if(e == value)
            return true;
    }
    return false;
}

class Book {
private :
    string name;
public:
    map<string,string> _wait_list;
    void print(){ cout << "Book" <<endl;}
};

class Course
{
private :
    string name;
public:
    map<string,string> _wait_list;
    void print(){ cout << "Course" <<endl;}
};

class Person
{
private :
    string name;
public:
    map<string,string> _wait_list;
    void print(){ cout << "Person" <<endl;}
};

template<class T>
class waitList {
private:
    T *ptr;
    int size;
public:
    waitList(T arr) { ptr = &arr; }

    T sort(T list_obj);

    T *get_prt() { return ptr; }

};

template<class T>
T waitList<T>::sort(T list_obj) {
    list_obj._wait_list.size();
};


