/*  This program should print all the prime numbers between 1 and the input
   number. The program should ask user for a number 'number' The output of the
   program should look like Enter Number: 10 2 3 5 7
*/

// Check for possible compiler errors, logical errors and rectify them
// Re-factor the code by adding few comments (make it readable) and
// provide list of most important fixes (in comments)

#include <iostream>   // bug: Wrong name
using namespace std;  // bug: add namespace

int main(void)  // change the main error
{
    int number = 1, num = 0;  // bug: add definition of num
    bool factor_found = false;    // change the variables name
    cout << "Enter Number:\n";
    cin >> num;
    int i= 0, j = 0;  // bug: add define here

    for (i = number + 1; i < num; ++i) {  // change to for loop
        factor_found = false;
        for (j = 2; j <= i / 2; ++j) {  // Bug: for loop ,->;, add definition
            if (i % j == 0) {
                factor_found = true;  // Change True to bool true, fix typo
                break;
            }
        }

        if (factor_found == false) {  // Bug: using Assignment instead of
            cout << i << " " << endl;
        }
    }
    return 0;
}

