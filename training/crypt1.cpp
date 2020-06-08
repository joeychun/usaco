/*
ID: joey.s.1
LANG: C++
TASK: crypt1
*/

#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int n;
int legal_dig[15]; // Digits that can be used

bool is_dig_legal(int dig) {
  for (int i=0; i<n; ++i) { // iterating through legal_dig
    if (legal_dig[i] == dig) { // to check if "num" is in it
      return true;
    }
  }
  return false;
}

bool is_num_legal(int num) {
  while (num != 0) {
    if (!(is_dig_legal(num%10))) { // Checking whetheer the unit digit is legal
      return false;
    }
    num /= 10; // Iterate
  }
  return true;
}

bool is_crypt_legal(int d1, int d2, int d3, int d4, int d5) { // digit 1 through 5
  int first_num = 100*d1+10*d2+d3;
  int second_num = 10*d4+d5;

  if (!(is_num_legal(first_num*d4))) { // a b c  x  d  part
    return false;
  } else if (first_num*d4 < 100 || first_num*d4 > 999) {
    return false;
  } else if (!(is_num_legal(first_num*d5))) { // a b c  x  e  part
    return false;
  } else if (first_num*d5 < 100 || first_num*d5 > 999) {
    return false;
  } else if (!(is_num_legal(first_num*second_num))) { // a b c  x  d e  part
    return false;
  } else if (first_num*second_num < 1000 || first_num*second_num > 9999) {
    return false;
  }

  return true;
}

int main() {
  ifstream fin ("crypt1.in");
  ofstream fout ("crypt1.out");

  // Take input of "n" and the n digits that can be used in the crypt
  fin >> n;
  for (int i=0; i<n; ++i) {
    fin >> legal_dig[i];
  }

  // Brute force; Substituting legal digits into a,b,c,d,e one by one
  //   a b c
  // x   d e
  // _______

  int counter = 0;
  int a,b,c,d,e;
  for (a=0; a<n; ++a) {
    if (legal_dig[a] == 0) {
      continue; // the digit on "a" cannot be 0 (leading 0 not allowed)
    }

    for (b=0; b<n; ++b) {

      for (c=0; c<n; ++c) {

        for (d=0; d<n; ++d) {
          if (legal_dig[d] == 0) {
            continue; // the digit on "d" cannot be a 0 (same reason)
          }

          for (e=0; e<n; ++e) {
            counter += is_crypt_legal(legal_dig[a],legal_dig[b],legal_dig[c],legal_dig[d],legal_dig[e]);
          }
        }
      }
    }
  }

  fout << counter << endl;

  return 0;
}
