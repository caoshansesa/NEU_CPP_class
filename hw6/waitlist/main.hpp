#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Moive
{
  private:
    string name;

  public:
    Moive(){};
    Moive(string _name)
    {
        name = _name;
    }
    string get_name()
    {
        return name;
    }
    void set_name(string _name);

    vector<string> people_waiting;
};

class Book
{
  private:
    string name;

  public:
    Book(){};
    Book(string _name)
    {
        name = _name;
    }
    string get_name()
    {
        return name;
    }
    void set_name(string _name);

    vector<string> people_waiting;
};

class Person
{
  private:
    string name;

  public:
    Person(){};
    Person(string _name)
    {
        name = _name;
    }
    string get_name()
    {
        return name;
    }
    void set_name(string _name);

    vector<string> order_waiting;
};

template <class T> class WaitList
{
  private:
    vector<T> temp;

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

    WaitList()//- default constructor => X one;
    {
        vector<T> temp1;
        temp = temp1;
    };
    WaitList(WaitList const &other)//- copy constructor => X two(one);
    {
        this->temp.empty(); // copy constructor
        for (const T &item : other)
        {
            this->temp.push_back(item);
        };
    };
    WaitList &operator=(WaitList const &other)//- copy assignment operator => X two = one;
    {
        for (const T &item : other)
        {
            this->temp.push_back(item);
        };
        return *this;
    };
    WaitList(WaitList &&other)//- move constructor
    {
        this->temp = move(other); 
    };
    WaitList &operator=(WaitList &&other)//- move assignment operator
    {
        this->temp = move(other);
        return *this;
    };
    ~WaitList() //- destructor
    {

    };

    map<string, T> _waitList;

    void add(string list_name, T newList);
    void remove(string list_name);
    void add_multiple(string *names_array, T *list_array, int size);
    int list_size();
    int rank_determine(string index_name);
    void remove_multiple(string *names_array, T *list_array, int size);
};

template <class T> void WaitList<T>::add(string list_name, T newList)
{
    typename map<string, T>::iterator it; // use typename to tell compiler this is a type
    it = _waitList.find(list_name);
    if (it != _waitList.end())
    {
        _waitList.erase(it);
    }
    _waitList.insert(pair<string, T>(list_name, newList));
}

template <class T> void WaitList<T>::add_multiple(string *names_array, T *list_array, int size)
{
    for (int i = 0; i < size; i++)
    {
        this->add(names_array[i], list_array[i]);
    }
}

template <class T> int WaitList<T>::list_size()
{
    return this->_waitList.size();
}

template <class T> int WaitList<T>::rank_determine(string index_name)
{
    int return_index = 0;
    typename map<string, T>::iterator it;
    for (it = _waitList.begin(); it != _waitList.end(); ++it)
    {
        return_index++;
        if (it->first == index_name)
        {
            return return_index;
        }
    }
    if (it == _waitList.end())
    {
        return -1; // if this elemnt does not exist
    }
}

template <class T> void WaitList<T>::remove(string list_name)
{

    typename map<string, T>::iterator it; // use typename to tell compiler this is a type
    it = _waitList.find(list_name);
    if (it != _waitList.end())
    {
        _waitList.erase(it);
    }
}

template <class T> void WaitList<T>::remove_multiple(string *names_array, T *list_array, int size)
{
    for (int i = 0; i < size; i++)
    {
        this->remove(names_array[i], list_array[i]);
    }
}