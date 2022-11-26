// Debug T-1
// Function template subtracts objects from each other. The function works on any object which has
// '-' opertor defined. Check for possible compiler errors, logical errors and rectify them
// Re-factor the code by adding few comments (make it readable) and
// provide list of most important fixes (in comments)

#include <iostream>
#include <string>
using namespace std;

template<class T> T add(T x, T y)   // Type defined not right
{
    T sum;
    sum = x + y;
    return sum;
}
class Person
{
public:
    Person(){};
    ~Person(){};


    string lastName;
    string firstName;
    int    age;

    void            setValues(string, string, int);
    Person          operator+(Person);
    friend ostream& operator<<(ostream&, const Person&);
};


ostream& operator<<(ostream& out, Person& per)
{
    out << per.firstName << " " << per.lastName << " " << per.age << " years old" << endl;
}


void Person::setValues(string last_setValue, string first_setValue, int age_setValue)
{
    lastName  = last_setValue;
    firstName = first_setValue;
    age       = age_setValue;
}

Person Person::operator+(Person p)
{
    Person temp;
    temp.lastName  = "of Age";
    temp.firstName = "Sum";
    temp.age       = p.age + age;
    return temp;
}

int main()
{
    int    a = 7, b = 26, c = 0;
    double d = 39.25, e = 2.01, f;
    Person g, h, i;
    g.setValues("Mitchell", "Donald", 40);
    h.setValues("Clayton", "Rita", 35);

    // This is very good example of using Template, for template API for different type, + and << overloading
    // use template for diffrent type add
    c = add(a, b);
    f = add(d, e);
    i = add(g, h);

    cout << c << endl;
    cout << f << endl;
    cout << i << endl;
    return 0;
}
