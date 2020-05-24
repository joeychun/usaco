/*
ID: joey.s.1
LANG: C++
TASK: dualpal
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
  ifstream fin ("dualpal.in");
  ofstream fout ("dualpal.out");

  int k,n;
  fin >> k >> n;

  int pal_counter = 0;
  for (int i=n+1;; ++i) {
    if (k == 0) break;
    pal_counter = 0;
    for (int b=2; b<=10; ++b) {
      if (is_palindromic(base_convert(i,b))) pal_counter++;
    }
    if (pal_counter >= 2) {
      fout << i << endl;
      k--;
    }
  }

  return 0;
}
