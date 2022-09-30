#include <fstream>
#include <functional>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using namespace std;

string performOperation(int x, int y, string op) {
  double result = 0;
  if (!op.compare("*")) {
    result = x * y;
  } else if (!op.compare("-")) {
    result = x - y;
  } else if (!op.compare("+")) {
    result = x + y;
  } else if (!op.compare("/")) {
    result = x / y;
  } else if (!op.compare("%")) {
    result = x % y;
  } else if (!op.compare("%")) {
  }
  // TODO: if the result is a minus number, it will be a bug
  return to_string(result);
}

vector<string> seperate_strings(string line) {
  int coma_counter(0);
  vector<string> str_group;
  string a, b, op;
  for (char cc : line) {
    if ((cc != ',') && (coma_counter == 0)) {
      a.push_back(cc);
    } else {
      coma_counter++;
    }

    if ((cc != ',') && (coma_counter == 1)) {
      b.push_back(cc);
    } else {
      coma_counter++;
    }

    if ((cc != ',') && (coma_counter == 2)) {
      op.push_back(cc);
    } else {
      coma_counter++;
    }

    if (coma_counter == 3) {
      str_group.push_back(a);
      str_group.push_back(b);
      str_group.push_back(op);
    }
  }
  return str_group;
}

int main() {
  ifstream infile("text.txt");
  ofstream outfile("output.txt");
  string line;
  signed int x, y;
  string oprt;
  while (getline(infile, line)) {
    x = (int)line[0] - 48;
    y = (int)line[2] - 48;

    // Clear the operator sting
    oprt.clear();
    // determine whther this a two digit operat or not
    if (line[5] != '\0') {
      oprt.push_back(line[4]);
      oprt.push_back(line[5]);
    } else {
      oprt.push_back(line[4]);
    }
    string result = performOperation(x, y, oprt);
    outfile << line << ',' << result << endl;
  }

  return 0;
}
