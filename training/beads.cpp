/*
ID: joey.s.1
LANG: C++
TASK: beads
*/

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int n;
string necklace;

int num_changer(int k) {
    while (k < 0) {
      k += n;
    }
    return (k%n);
}

int main() {
  ifstream fin("beads.in");
  ofstream fout("beads.out");

  fin >> n;
  fin >> necklace;

  int max_val = 0;

  for (int i=0; i<n; ++i) {
    // Check for counterclockwise direction
    int counterclock_count;
    int position = i-1;
    char first_bead = 'w'; //color decider
    for (counterclock_count = 0; counterclock_count < n; ++counterclock_count) {
      if (first_bead=='w' && necklace[num_changer(position)]!='w')
        first_bead = necklace[num_changer(position)];
      if (first_bead!='w' && necklace[num_changer(position)]!='w' && first_bead!=necklace[num_changer(position)])
        break;
      // else:
      position--;
    }

    // Check for clockwise direction
    int clock_count;
    position = i;
    first_bead = 'w'; //color decider
    for (clock_count = 0; clock_count < n; ++clock_count) {
      if (first_bead=='w' && necklace[num_changer(position)]!='w')
        first_bead = necklace[num_changer(position)];
      if (first_bead!='w' && necklace[num_changer(position)]!='w' && first_bead!=necklace[num_changer(position)])
        break;
      // else:
      position++;
    }

    max_val = max(max_val, counterclock_count+clock_count);
  }

  max_val = min(max_val, n); // Get rid of overlap cases

  fout << max_val << endl;

  return 0;
}
