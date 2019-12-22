/*
Check if it works on the equation x-\frac{x}{3}-\frac{x}{5}+\frac{x}{15}=n

Other easier way to solve this:

Pattern: 
1 2 Moo 4 Moo Moo 7 8 Moo Moo 11 Moo 13 14 Moo => there are 8 numbers spoken in 1~15
*/
#include <iostream>
#include <fstream> // will use fin, fout
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long n;

int works(int x) { // checks if it satisfies the equation
  if ((x - x/3 - x/5 + x/15) == n) return 0; // Works!
  if ((x - x/3 - x/5 + x/15) > n) return 1; // Too big
  if ((x - x/3 - x/5 + x/15) < n) return -1; // Too small
}

int main() {
  ifstream fin;
  fin.open("moobuzz.in");
  ofstream fout;
  fout.open("moobuzz.out");

  fin >> n;

  long middle = (n*15)/8;
  long error = 0;
  long ans;
  long current_num = n;

  if (works(middle) == 0) {
    // Check smaller numbers -- this not might be the min value
    // If the 1st smaller number doesn't work, this is the answer
    ans = middle;
    while (1) {
      if (works(ans-1) == 0) {
        ans--;
      } else {
        break;
      }
    }
  } else if (works(middle) == 1) {
    // Check smaller numbers -- this is too big
    ans = middle;
    while (1) {
      if (works(ans) == 1) {
        ans--;
      } else {
        break;
      }
    } // Found a number that works.

    while (1) {
      if (works(ans-1) == 0) {
        ans--;
      } else {
        break;
      }
    }

  } else { // = -1
    // Check bigger numbers, until a number that works appears
    ans = middle;
    while (1) {
      if (works(ans) == -1) {
        ans++;
      } else {
        break;
      }
    }
  }

  while ((ans % 3 == 0) || (ans % 5 == 0)) {
    ans++;
  }
  fout << ans;
}
