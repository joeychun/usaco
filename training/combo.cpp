/*
ID: joey.s.1
LANG: C++
TASK: combo
*/

#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int n;
int farmer[3], master[3];

int combination[3];

/* Compares "combination" and "comparing_list",
   checking if the numbers on the dials are
   each within at most 2 positions of a valid combination */
bool check(int* comparing_list) {
  int diff1, diff2;
  for (int i=0; i<3; ++i) {
    diff1 = abs(combination[i] - comparing_list[i]); // Normal difference
    diff2 = abs(diff1 - n); // Difference regarding 1 and n are adjacent
    if (diff1 > 2 && diff2 > 2) {
      return false;
    }
  }
  return true;
}

int main() {
  ifstream fin ("combo.in");
  ofstream fout ("combo.out");

  // Take input of "n" and the other 6 numbers
  fin >> n;
  fin >> farmer[0] >> farmer[1] >> farmer[2];
  fin >> master[0] >> master[1] >> master[2];

  int counter = 0;

  // Iterate for every lock combination possible within 1 ~ n
  for (combination[0]=1; combination[0]<=n; ++combination[0]) {
    for (combination[1]=1; combination[1]<=n; ++combination[1]) {
      for (combination[2]=1; combination[2]<=n; ++combination[2]) {
        counter += (check(farmer) || check(master));
      }
    }
  }


  fout << counter << endl;

  return 0;
}
