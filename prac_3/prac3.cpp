/*************************************
 * Shan Cao, Omar Shair
 * Practices 2
 * 09/19/2022 22:20:56
 *************************************/

#include <cmath>
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>

using namespace std;

/*
 * ===  FUNCTION
 * ====================================================================== Name:
 * performOperation Description: This will performOperation based on the input
 * operators and string based variables
 * =====================================================================================
 */
string performOperation(int x, int y, string op) {
  double result = 0;
  if (op == "+") {
    result = x + y;
  } else if (op == "*") {
    result = x * y;
  } else if (op == "-") {
    result = x - y;
  } else if (op == "/") {
    result = x / y;
  } else if (op == "%") {
    result = x % y;
  } else if (op == "<") {
    result = x < y;
  } else if (op == ">") {
    result = x > y;
  } else if (op == "<=") {
    result = x <= y;
  } else if (op == ">=") {
    result = x >= y;
  } else if (op == ">>") {
    result = (x >> y);
  } else if (op == "<<") {
    result = (x << y);
  } else if (op == "&&") {
    result = (x & y);
  } else if (op == "||") {
    result = (x | y);
  } else if (op == "^") {
    result = pow(x, y);
  }
  return to_string(result);
}

/*
 * ===  FUNCTION
 * ====================================================================== Name:
 * seperate_strings Description: This is a FUNCTION will seperate input string
 * into 3 parts base on coma
 * =====================================================================================
 */
void seperate_strings(string line, string* a, string* b, string* op) {
  int coma_counter(0);
  for (char cc : line) {
    if ((cc != ',') && (coma_counter == 0)) {
      a->push_back(cc);
    }

    if ((cc != ',') && (coma_counter == 1)) {
      b->push_back(cc);
    }

    if ((cc != ',') && (coma_counter == 2)) {
      op->push_back(cc);
    }
    if (cc == ',') {
      coma_counter++;
    }
  }
}

int main() {
  ifstream infile("test.txt");
  ofstream outfile("output.txt");
  string line;
  signed int x = 0, y = 0;

  while (getline(infile, line)) {
    string str_x, str_y, oprt;
    seperate_strings(line, &str_x, &str_y, &oprt);
    x = stoi(str_x);
    y = stoi(str_y);
    string result = performOperation(x, y, oprt);
    outfile << line << ',' << result << endl;
  }

  return 0;
}
