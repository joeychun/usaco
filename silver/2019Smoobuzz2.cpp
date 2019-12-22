/*
Pattern:
1 2 Moo 4 Moo Moo 7 8 Moo Moo 11 Moo 13 14 Moo => there are 8 numbers spoken in 1~15
*/
#include <iostream>
#include <fstream> // will use fin, fout
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  ifstream fin;
  fin.open("moobuzz.in");
  ofstream fout;
  fout.open("moobuzz.out");

  long n;
  fin >> n;

  int spok_numbers[8] = {14,1,2,4,7,8,11,13};

  // Amount of {1,2,4,7,8,11,13,14}s
  int eight_bundles = ((n-1)/8);

  // The number found in the pattern {1,2,4,7,8,11,13,14}
  int patt_number = spok_numbers[n%8];

  int ans = eight_bundles*15 + patt_number;
  fout << ans;
}
