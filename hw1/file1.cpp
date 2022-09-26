/* Print the sum of "products of odd" from 1 to 10 (i.e., 1*3*5*7*9) and
 * "products of even" numbers from 1 to 10 (i.e., 2*4*6*8*10) Add every second
 * characters from 'A' to 'Z' in the reverse order starting with 'Z' (i.e., skip
 * one in between) in a Vector Print that vector using for each loop Output of
 * the program should look like: The value of limit is 10 The Sum = 4785 Z X V T
 * R P N L J H F D B
 */

// Check for possible compiler errors, logical errors and rectify them
// Re-factor the code by adding few comments (make it readable) and
// provide list of most important fixes (in comments)

#include <strings.h>

#include <iostream>
#include <ostream>
#include <vector>

using namespace std;  // Bug: Add std namespace for cout.

int main() {
  int i = 0, limit = 10, even_product = 0, odd_product = 0,
      sum = 0;   // Bug Define sum
  char c = 'z';  // Bug: change the quote for char.
  cout << "The value of limit is " << limit << endl;

  vector<int> odd_number, even_number;
  while (i < limit)  // Bug: the limit should be a < sign, and the variable
                     // should be type defined.
  {
    if (i % 2 == 0)  // Bug: for a condition should be == sign
    {
      even_number.push_back(i);
      even_product = even_product + i;
    } else  // Bug: Wrong if statement for odd number
    {
      odd_number.push_back(i);
      odd_product = odd_product + i;
    }
    i++;
  }
  sum = odd_product + even_product;

  cout << "Here is all the ood Number \n";
  for (int index : odd_number) {
    cout << index << " ";
  }
  cout << endl;

  cout << "Here is all the even Number \n";

  for (int index : even_number) {
    cout << index << " ";
  }
  cout << endl;

  vector<char> v;  // Bug: missing the header file

  char d = 'Z';

  while ('@' < d)  // Bug: d is not deined, define the range of A ~ Z
  {
    v.push_back(d);  // Bug: Vector pushback api
    d = d - 2;
  }

  for (char c : v)  // Bug: change variable
  {
    cout << c;  // Bug, the variable is in a quote
    sum = sum +c;
  }

  cout << "The Sum =" << dec << sum << endl;    // Bug: mix defined c/c++ printf and cout
  cout << "\n" << endl;
  return 0;
}
