/*
 * =====================================================================================
 *
 *       Filename:  4_rdm_para_gnrtor.cpp
 *
 *    Description: Randome paragraph generator
 *
 *        Version:  1.0
 *        Created:  09/26/2022 19:09:53
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Shan Cao
 *
 * =====================================================================================
 */
#include <stdlib.h>

#include <cstdlib>
#include <iostream>
#include <iterator>
#include <vector>
#include <string>

using namespace std;

int main() {
  string paragraph;
  char cc;
  int cnt_numbers(0), cnt_letters(0), cnt_spaces(0);
  int para_array[2000] = {0};

  srand(time(nullptr));
  for (int i = 0; i < 2000; i++) {
    cc = rand() % 126 + 32;  // generate number between 32 ~126
    paragraph = paragraph + cc;
    // Range of A~Z and a~z
    if ((64 < cc && cc < 91) || (96 < cc && cc < 123)) {
      cnt_letters++;
      para_array[i] = 1;  // mark the index of letter as 1
    }
    // Range of number
    if (47 < cc && cc < 58) {
      cnt_numbers++;
      para_array[i] = 2;  // mark the index of numbers as 2
    }
    // cnt_spaces
    if (cc == ' ') {
      cnt_spaces++;
      para_array[i] = 3;  // mark the index of spaces as 3
    }

    // cnt_brackets
    if (cc == 40 || cc == 41 || cc == 91 || cc == 93 || cc == 123 || cc == 125) {
      para_array[i] = 4;  // mark the index of spaces as 3
    }
  }

  cout << endl;
  cout << endl;
  cout << endl;
  cout << "Here is the paragraph: \n\n\n\n" << endl;
  cout << paragraph << endl;

  cout << endl;
  cout << endl;
  cout << endl;

  // --------------------------------------------------------------
  // Here is the statistcs

  cout << "There are " << cnt_spaces << " spaces" << endl;
  cout << "There are " << cnt_letters << " letters" << endl;
  cout << "There are " << cnt_numbers << " number" << endl;

  cout << endl;
  cout << endl;
  cout << endl;

  // --------------------------------------------------------------
  // Replace all the non-alphanumeric with cnt_spaces
  for (int i = 0; i < 2000; i++) {
    if ((para_array[i] == 0)&& 
        (paragraph[i] != 46 && paragraph[i] != 44 &&
         paragraph[i] != 34 && paragraph[i] != 39)) 
    {
      paragraph[i] = ' ';
    }
  }

  cout << "Here is the updated paragraph with all non-alphanumeric Replaced with space: \n\n\n\n\n" << endl;
  cout << paragraph << endl;

  cout << endl;
  cout << endl;
  cout << endl;

    string new_paragraph;
  //Replace any numeric digits
    for (int i = 0; i < 2000; i++) {
        if (para_array[i] != 2){
            new_paragraph.push_back(paragraph[i]);
        }
    }

  cout << "Here is the updated paragraph after the numeric number got replaced \n\n\n\n\n" << endl;
  cout << new_paragraph << endl;

  cout << endl;
  cout << endl;
  cout << endl;
    int j = 0;
    for (int i = 0; i< 2000; i++) {
        if(para_array[i] == 3)
        {
            j++;
            if(j % 20 == 0)
            {
                new_paragraph[i] = 10;
            }
        }
    }

  cout << "Here is the updated paragraph every 20th spaces got replaced with LF \n\n\n\n\n" << endl;
  cout << new_paragraph << endl;

  cout << endl;
  cout << endl;
  cout << endl;



    string final_paragraph;
  //Replace any numeric digits
    for (int i = 0; i < 2000; i++) {
        if (para_array[i] == 3){
            final_paragraph.push_back(' '); // Add space before the brackets
        }

        final_paragraph.push_back(new_paragraph[i]);

        if (para_array[i] == 3){
            final_paragraph.push_back(' '); // Ad space after the brackets
        }
    }
    cout << "here is the final paragragh" << endl;

    cout << final_paragraph << endl;

  return 0;
}
