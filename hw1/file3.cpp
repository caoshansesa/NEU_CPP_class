/*  This program should print all the prime numbers between 1 and the input number.
    The program should ask user for a number 'number'
    The output of the program should look like
    Enter Number:
    10
    2 3 5 7
*/

// Check for possible compiler errors, logical errors and rectify them
// Re-factor the code by adding few comments (make it readable) and
// provide list of most important fixes (in comments)

#include <iosteam>

int main(int a)
{
    int number;
    Boolean factor_found;
    cout << "Enter Number:\n";
    cin >> num;
    i = 2;
    do(i > num)
     {
            factor_found = False;
            for (j = 2, j < i / 2, j++):
        if (i/j = 0)
         {
             factor_Found = True;
              break;
          }
        if (factor_found = False)
         {
           cout << i << " ";
         }
        }while;
}