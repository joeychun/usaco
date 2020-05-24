/*
ID: joey.s.1
LANG: C++
TASK: palsquare
*/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

string base_convert(int num, int base) {
  string converted = "";
  int curr_number;
  string curr_str_number;
  stringstream ss;
  while (num != 0) {
    curr_number = num%base;
    if (curr_number < 10) curr_str_number = to_string(curr_number);
    else {
      curr_str_number = (char)('A'-10+curr_number);
    }
    converted = curr_str_number + converted;
    num /= base;
  }
  return converted;
}

bool is_palindromic(string s) {
  for (int i=0; i<s.length(); ++i) {
    if (s.at(i) != s.at(s.length()-i-1)) return false;
  }
  return true;
}

int main() {
  ifstream fin ("palsquare.in");
  ofstream fout ("palsquare.out");

  int b;
  fin >> b;

  string converted_val, converted_square;
  for (int n=1; n<=300; ++n) {
    converted_val = base_convert(n,b);
    converted_square = base_convert(n*n,b);
    if (is_palindromic(converted_square)) {
      fout << converted_val << " " << converted_square << endl;
    }
  }

  return 0;
}
