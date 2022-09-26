/* Save the multiplication of the two numbers in a file without using
   multiplication operator. This approach uses add & shift operations to
   calculate the product of two numbers (as discussed in class). The program
   will ask you to enter 2 numbers, then it will save  the product of the two
   number in result.txt. Output of result.txt - The multiplation of 20 and 30 is
   600
*/

// Check for possible compiler errors, logical errors and rectify them
// Re-factor the code by adding few comments (make it readable) and
// provide list of most important fixes (in comments)

#include <fstream>
#include <iostream>

using namespace std;  // Bug: Add namespace

int main() {
  int number1, number2;
  cout << "Enter 1st number:\n";

  cin >> number1;  // Bug: fix cin input error
  cout << "Enter 2nd number:\n";
  cin >> number2;  // Bug: fix cin input error

  int res = 0, count = 0;

  for (int i = number2; i > 0; i = i / 2) {
    if (i % 2 == 1) {           // Bug: change to mode
      res += number1 << count;  // Bug: Add the res
    }
    count++;
  }
  ofstream output("result.txt");  // Bug: Open a file to write

  cout << "The multiplication of " << number1 << " and " << number2 << " is "
       << res << endl;  // Bug: Change the direction of arrow to write to file
  output << "The multiplication of " << number1 << " and " << number2 << " is "
         << res << endl;  // Bug: Change the direction of arrow to write to file
  output.close();
  return 0;
}
