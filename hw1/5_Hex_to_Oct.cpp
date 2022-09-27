/*
 * =====================================================================================
 *
 *       Filename:  5_Hex_to_Oct.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  09/26/2022 22:09:37
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Shan Cao ,
 *   Organization:
 *
 * =====================================================================================
 */
#include <stdlib.h>

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

string hex2binary(char c) {
    switch (c) {
        case '0':
            return "0000";
            break;
        case '1':
            return "0001";
            break;
        case '2':
            return "0010";
            break;
        case '3':
            return "0011";
            break;
        case '4':
            return "0100";
            break;
        case '5':
            return "0101";
            break;
        case '6':
            return "0110";
            break;
        case '7':
            return "0111";
            break;
        case '8':
            return "1000";
            break;
        case '9':
            return "1001";
            break;
        case 'A':
            return "1010";
            break;
        case 'B':
            return "1011";
            break;
        case 'C':
            return "1100";
            break;
        case 'D':
            return "1101";
            break;
        case 'E':
            return "1110";
            break;
        case 'F':
            return "1111";
            break;

        case 'a':
            return "1010";
            break;
        case 'b':
            return "1011";
            break;
        case 'c':
            return "1100";
            break;
        case 'd':
            return "1101";
            break;
        case 'e':
            return "1110";
            break;
        case 'f':
            return "1111";
            break;
    }
    return 0;
}

int main() {
    int hex_num(0), binary_num(0), octal_num(0);
    string input_hex_string;
    cout << "Please type a input of sit digits hex, for example 0xABABAB. \n"
         << endl;
    cin >> input_hex_string;
    string hex_v;  // string in hex format
    string bin_v;  // string in binary format

    // remove the 0x from the beginning
    for (int i = 2; i < 8; i++) {
        hex_v.push_back(input_hex_string[i]);  // save the string format of the hex
        bin_v.append(hex2binary(
                input_hex_string[i]));  // save the string format of the binary
    }

    cout << "the hex string is  " << hex_v << endl;
    cout << "the binary string is " << bin_v << endl;

    // change binary string to dec integer value
    int number_of_bits_in_binary = sizeof(bin_v);

    cout << "the number of bit of the binary is " << number_of_bits_in_binary
         << endl;
    long long int dec_value(0);
    for (int i = number_of_bits_in_binary; i > 0; i--) {
        if (bin_v[i] == '0') {
            dec_value += 0;
        } else {
            dec_value += exp2(i - 1);
        }
    }
    cout << hex << dec_value;
    
    string octal_v;
    int i = 0;
    while (dec_value != 0)
    {
        int oct_digit = (dec_value % 8);
        dec_value /= 8;
        char oct_digit_char = oct_digit + 48;
        octal_v.push_back(oct_digit_char);
    }

    cout << "Your number" << input_hex_string <<  "(in hex) is equivalent to" << bin_v << "(in binary) and "<< octal_v<< " (in octal)" << endl;
     return 0;
    ;
}

