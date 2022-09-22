/* Save the multiplication of the two numbers in a file without using multiplication operator. This approach
   uses add & shift operations to calculate the product of two numbers (as discussed in class).
   The program will ask you to enter 2 numbers, then it will save  the product of the two number in result.txt.
   Output of result.txt -
   The multiplation of 20 and 30 is 600
*/

// Check for possible compiler errors, logical errors and rectify them
// Re-factor the code by adding few comments (make it readable) and
// provide list of most important fixes (in comments)

#include <iostream>
#include <fstream>
int main()
{
    int number1, number2;
    cout << "Enter 1st number:\n";
    cin << number1;
    cout << "Enter 2nd number:\n";
    cin << number2;

    int res = 0, count = 0;

    for (int i = number2; i > 0; i / 2)
    {
        count++;
        if (i / 2 = 1)
            res = number1 << count;
    }

    ifstream output("result.txt");

    output >> "The multiplication of " >> number1 >> " and " >> number2 >> " is " << res << endl;
    output.close();
    return 0;
}