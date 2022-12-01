#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Book
{
private:
    string name;

public:
    Book(){};
    Book(string _name) { name = _name; }
    string get_name() { return name; }
    void   set_name(string _name);

    vector<string> people_waiting;
};

class Person
{
private:
    string name;

public:
    Person(){};
    Person(string _name) { name = _name; }
    string get_name() { return name; }
    void   set_name(string _name);


    vector<string> order_waiting;
};

template<class T>
class WaitList
{
public:
    /*
     compiler generates:
        - default constructor => X one;
        - copy constructor => X two(one);
        - copy assignment operator => X two = one;
        - destructor
     in C++ 11, we added 2 more
        - move constructor
        - move assignment operator
      */

    WaitList()                                 = default;
    WaitList(WaitList const& other)            = default;
    WaitList& operator=(WaitList const& other) = default;
    WaitList(WaitList&& other)                 = default;
    WaitList& operator=(WaitList&& other)      = default;
    ~WaitList()                                = default;
    map<string, T> _waitList;

    void add(string list_name, T newList);
    void remove(string list_name);
    void add_multiple(string* names_array, T* list_array, int size);
    int  list_size();
    int  rank_determine(string index_name);
    void remove_multiple(string* names_array, T* list_array, int size);
};

template<class T>
void WaitList<T>::add(string list_name, T newList)
{
    typename map<string, T>::iterator it;   // use typename to tell compiler this is a type
    it = _waitList.find(list_name);
    if (it != _waitList.end()) {
        _waitList.erase(it);
    }
    _waitList.insert(pair<string, T>(list_name, newList));
}

template<class T>
void WaitList<T>::add_multiple(string* names_array, T* list_array, int size)
{
    for (int i = 0; i < size; i++) {
        this->add(names_array[i], list_array[i]);
    }
}

template<class T>
int WaitList<T>::list_size()
{
    return this->_waitList.size();
}

template<class T>
int WaitList<T>::rank_determine(string index_name)
{
    int                               return_index = 0;
    typename map<string, T>::iterator it;
    for (it = _waitList.begin(); it != _waitList.end(); ++it) {
        return_index++;
        if (it->first == index_name) {
            return return_index;
        }
    }
    if (it == _waitList.end()) {
        return -1;   // if this elemnt does not exist
    }
}

template<class T>
void WaitList<T>::remove(string list_name)
{

    typename map<string, T>::iterator it;   // use typename to tell compiler this is a type
    it = _waitList.find(list_name);
    if (it != _waitList.end()) {
        _waitList.erase(it);
    }
}

template<class T>
void WaitList<T>::remove_multiple(string* names_array, T* list_array, int size)
{
    for (int i = 0; i < size; i++) {
        this->remove(names_array[i], list_array[i]);
    }
}


int main()
{
    Person p_obj("Shan");
    Person p_obj1("Joe");
    Person p_obj2("Moh");

    WaitList<Person> wait_person_obj;
    wait_person_obj.add(p_obj.get_name(), p_obj);   // Add single obj to the list

    p_obj.order_waiting.push_back("Order:000001");   // make change to the order of the single obj

    string name_arr[3] = {"Shan", "Joe", "Moh"};   // it will hit the same element of "Shan", and
                                                   // replace the P-obj with the updated one
    Person p_obj_arr[3] = {p_obj, p_obj1, p_obj2};

    wait_person_obj.add_multiple(name_arr, p_obj_arr, 3);
    wait_person_obj.list_size();   // return the size of the current list
                                   //
    cout << wait_person_obj.rank_determine(
        "Shan 1");   // if an element did not belong to the WaitList, return -1, or return the index
                     // of that element in the list




    Book book_obj("Butterfly");
}
