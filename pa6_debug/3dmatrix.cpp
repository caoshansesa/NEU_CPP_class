// Program to read 3-dimensional matrix and display the elements as 1x3N matrix
// TODO
// initize matrix using update_3d method (see comments below)
// display method must not be able to modify array elements (update the code as
// needed) display method must use a single loop/iterator to print the entire
// array with addresses display cannot use nested loops
//

#include <iostream>
#define SIZE 3

using namespace std;  // Bugs1: namespace missing

void update_3d(double Matrix_3d[SIZE][SIZE][SIZE], int size);
void display_3d(double Matrix_3d[SIZE][SIZE][SIZE], int size);

int main(void) {
  // prompt the use to enter appropriate dimensions and initializ the matrix
  // accordingly
  double Matrix_3d[SIZE][SIZE][SIZE] = {};
  // initialize the array to non-zero values (use scanf or random numbers
  // generator)
  update_3d(Matrix_3d, SIZE);
  // display the values
  display_3d(Matrix_3d, SIZE);
  return 0;
}

void update_3d(double matrix[SIZE][SIZE][SIZE], int size) {
  cout << "Entering 3N elements of the matrix:" << endl;
  int i = 0;
  for (; i < size; i++) {
    int j = 0;
    for (; j < size; j++) {
      int k = 0;
      for (; k < size; k++) {
        matrix[i][j][k] = rand() % 500 + 100;
      }
    }
  }
}

// update as needed. 1 'for' loop only with 1 iterator to print all values with
// addresses must not be able to update the array. Share any observations.

void display_3d(double Matrix_3d[SIZE][SIZE][SIZE], int size) {
  int i;
  for (i = 0; i < (size * size * size); i++) {
    if ((i % (size)) == 0) {
      cout << endl;
    }
    if ((i % (size * size)) == 0) {
      cout << "Next panel" << endl;
    }

    cout << (double*)Matrix_3d + i << ", "
         << Matrix_3d[i / (size * size)][(i / size) % size][i % size] << endl;
  }
}
