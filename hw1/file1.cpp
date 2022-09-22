/* Print the sum of "products of odd" from 1 to 10 (i.e., 1*3*5*7*9) and "products of even" numbers from 1 to 10 (i.e., 2*4*6*8*10)
 *  Add every second characters from 'A' to 'Z' in the reverse order starting with 'Z' (i.e., skip one in between) in a Vector
 *  Print that vector using for each loop
 *  Output of the program should look like:
 *  The value of limit is 10
 *   The Sum = 4785
 *   Z X V T R P N L J H F D B
 */

// Check for possible compiler errors, logical errors and rectify them
// Re-factor the code by adding few comments (make it readable) and
// provide list of most important fixes (in comments)

#include <iostream>

int main()
{
    int limit = -10, even_product = 0, odd_product = 0, sum;
    char c = "z";
    cout << "The value of limit is " << limit << endl;

    while (i > limit)
    {
        if (i / 2 = 1)
        {
            even_product = i;
        }
        if (i / 3 = 1)
        {
            odd_product = i;
        }
        sum = even_product + odd_product;
    }

    cout<<"The Sum = \n"<< "%d", sum);
    vector<char> v;
    while (d < 'a')
    {

        v.push(d);
        d--;
    }

    for (int c : v)
    {
        cout << "c ";
    }
    return;
}