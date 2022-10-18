// Program to read integers into a 3X3 matrix and display them
// Todo: Fix bugs and makesure program works as intended.
// for each bug fix, add a comments specifying what you fixed.

// Number of errors/bugs = 10

#include <iostream>

#define SIZE 3  // 1. No define for SIZE
using namespace std;
void display(int Matrix[SIZE][SIZE], int size);  // 2.API siginiture wrong

int main(void) {
  int size = 3;
  int input = 0;           // define input
  int Matrix[SIZE][SIZE];  // 3 . the requiremnt say 3x3, this use 4x4.
  cout << "Enter 9 elements of the matrix:"
       << endl;                   // 4. should use cout for te output
  for (int i = 0; i < SIZE; i++)  // 5.  i was not defined.
  {
    int j = 0;  // 6.  j was not defined.
    for (; j < SIZE; j++) {
      cin >> input;
      Matrix[i][j] = input;  // 7 could not assign to Matrix directly typo also
    }
  }
  display(Matrix, SIZE);  // 8, remove &
                          // 9.typo Matrix
  return 0;
}

void display(int Matrix[SIZE][SIZE], int size) {  // 10. signiture does not
                                                  // match
  for (int i = 0; i < size; i++) {  // 11 :  ; insted ,
    for (int j = 0; j < size; j++)  // 12.  j++ inread of i++
    {
      cout << Matrix[i][j] << ", ";
    }
    cout << endl;  // 13. missing a ;
  }
}
