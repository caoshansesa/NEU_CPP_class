#include "main.hpp"
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
