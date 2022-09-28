#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

char performOperation(int x, int y, char op) {
  int result;
  switch (op) {
    case '+' :
      result = x + y;
      break;
    case '*' :
      result = x* y;
      break;
    case '-' :
      result = x - y;
      break;
    case '/' :
      result = x / y;
      break;
    default:
      result = 'F'; // for failed
  }
  return (char) result;
}


int main() {
  ifstream infile("test.txt");
  ofstream outfile("output.txt");
  string line;
  int x, y;
  char op;
 while (getline(infile, line)) {
    x = (int) line[0] - 48;
    y = (int) line[2] - 48;
    op = line[4];
    char result = performOperation(x, y, op);
    cout << result;
    outfile << line << ',' << result <<endl;
  }
 
  return 0;
}
