#include <iostream>
#include "main.hpp"


int main(void) {
    cout << "Start!" << endl;
    Person p_obj;
    Book b_obj;
    Course c_obj;

    waitList<Person>  _waitList0(p_obj) ;
    _waitList0.get_prt()->print();

    waitList<Book>  _waitList1(b_obj) ;
    _waitList1.get_prt()->print();

    waitList<Course>  _waitList2(c_obj) ;
    _waitList2.get_prt()->print();


}

