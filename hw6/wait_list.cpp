#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

class Person
{
  private:
    string name;

  public:
    Person(string _name)
    {
        name = _name;
    }
};

template <class T> class WaitList
{
  public:
    WaitList(T arr)
    {
    }
    map<string, T> _waitList;

    void add(string listname, T newList);
};

template <class T> void WaitList<T>::add(string listname, T newList)
{
    typename map<string, T>::iterator it; // use typename to tell compiler this is a type
    it = _waitList.find(listname);
    if (it != _waitList.end())
    {
        _waitList.erase(it);
    }
    _waitList.insert(pair<string, T>(listname, newList));
}

int main()
{
    Person p_obj("Shan");
    WaitList<Person> _wait_person(p_obj);
}
