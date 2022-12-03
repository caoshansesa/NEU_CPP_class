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

    WaitList()
    {
        vector<T> temp1;
        temp = temp1;
    };
    WaitList(WaitList const &other)
    {
        this->temp.empty(); // copy constructor
        for (const T &item : other)
        {
            this->temp.push_back(item);
        };
    };
    WaitList &operator=(WaitList const &other)
    {
        for (const T &item : other)
        {
            this->temp.push_back(item);
        };
        return *this;
    };
    WaitList(WaitList &&other)
    {
        this->temp = move(other); // move constructor
    };
    WaitList &operator=(WaitList &&other)
    {
        this->temp = move(other);
        return *this;
    };
    ~WaitList(){

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

int main()
{
    Person p_obj("Shan");
    Person p_obj1("Joe");
    Person p_obj2("Moh");

    WaitList<Person> wait_person_obj;
    wait_person_obj.add(p_obj.get_name(), p_obj); // Add single obj to the list

    p_obj.order_waiting.push_back("Order:000001"); // make change to the order of the single obj

    string name_arr[3] = {"Shan", "Joe", "Moh"}; // it will hit the same element of "Shan", and
                                                 // replace the P-obj with the updated one
    Person p_obj_arr[3] = {p_obj, p_obj1, p_obj2};

    wait_person_obj.add_multiple(name_arr, p_obj_arr, 3);
    wait_person_obj.list_size(); // return the size of the current list
                                 //
    cout << "The Rank is" << wait_person_obj.rank_determine("Shan 1")
         << endl; // if an element did not belong to the WaitList, return -1, or return the index
                  // of that element in the list

    Book book_obj("Butterfly");
    Book book_obj1("Butterfly1");
    Book book_obj2("Butterfly2");
    Book book_obj3("Butterfly3");

    WaitList<Book> wait_book_obj;
    wait_book_obj.add(book_obj.get_name(), book_obj);

    book_obj.people_waiting.push_back("Order: 00002");

    string b_name_arr[3] = {"Like butter", "butter Like", "I do not like"};
    Book b_obj_arr[3] = {book_obj, book_obj1, book_obj2};

    wait_book_obj.add_multiple(b_name_arr, b_obj_arr, 3);
    wait_book_obj.list_size();

    cout << "The Rank is" << wait_book_obj.rank_determine("Butterfly")
         << endl; // if an element did not belong to the WaitList, return -1, or return the index
                  // of that element in the list

    Moive moive_obj("Moive1");
    Moive moive_obj1("Moive2");
    Moive moive_obj2("Moive3");

    WaitList<Moive> wait_moive_obj;
    wait_moive_obj.add(book_obj.get_name(), moive_obj);

    book_obj.people_waiting.push_back("Order: 00002");

    string m_name_arr[3] = {"Like butter", "butter Like", "I do not like"};
    Moive m_obj_arr[3] = {moive_obj, moive_obj1, moive_obj2};

    wait_moive_obj.add_multiple(m_name_arr, m_obj_arr, 3);
    wait_book_obj.list_size();

    cout << "The Rank is" << wait_moive_obj.rank_determine("Butterfly")
         << endl; // if an element did not belong to the WaitList, return -1, or return the index
                  // of that element in the list
}
