// Debug T-2
// Function template finds biggest of two or three objects. The function works on any data type
// which has greater than operator defined.

#include <iostream>
#include <string>
using namespace std;

template<class T> void findBiggest(T a, T b, T c)
{
    T large = a;
    if (b > large) large = b;
    if (c > large) large = c;
    cout << "The largest of " << a << " " << b << " " << c << " is " << a << endl;
}

template<class T> void findBiggest(T a, T b)
{
    T large = a;
    if (b > large) {
        large = b;
    }
    cout << "The larger of " << a << " " << b << " is " << large << endl;
}

class BankAccount
{
public:
    BankAccount(const string& name, const int amount);
    BankAccount(const int);
    bool operator>(const BankAccount&);

    string name;
    int    amount;

    friend ostream& operator<<(ostream&, const BankAccount&);
};

BankAccount::BankAccount(const string& name, const int amount)
{
    this->name   = name;
    this->amount = amount;
}

ostream& operator<<(ostream& out, const BankAccount& bh)
{
    out << "Name " << bh.name << " Amount: " << bh.amount << endl;
    return out;
}

bool BankAccount::operator>(const BankAccount& bh)
{
    bool flag = false;
    if (amount > bh.amount) flag = true;
    return flag;
}

int main()
{
    BankAccount bAA("A", 800);
    BankAccount bAB("B", 120);
    BankAccount bAC("C", 500);
    findBiggest(bAA, bAB);
    findBiggest(bAB, bAC);
    findBiggest(bAC, bAA);
    findBiggest(bAA, bAB, bAC);
    return 0;
}
