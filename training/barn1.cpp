/*
ID: joey.s.1
LANG: C++
TASK: barn1
*/

#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int main() {
  ifstream fin ("barn1.in");
  ofstream fout ("barn1.out");

  int m,s,c;
  int cow_pos[205];
  int between_dist[205];

  fin >> m >> s >> c;

  // IF there are more maximum # of boards that can be plcaed than
  // # of stalls that are filled, answer is # of stalls that are filled
  if (m >= c) {
    fout << c << endl;
    return 0;
  }

  // ELSE

  for (int i=0; i<c; ++i) {
    fin >> cow_pos[i];
  }
  sort(cow_pos, cow_pos+c); // sort the list containing stall numbers

  for (int i=0; i<c-1; ++i) {
    between_dist[i] = cow_pos[i+1] - cow_pos[i];
  }
  sort(between_dist, between_dist+c-1, greater<int>()); // sort the distances from biggest to smallest

  int sum = 0;
  for (int i=m-1; i<c-1; ++i) {
    sum += between_dist[i];
  }
  sum += m;

  fout << sum << endl;

  return 0;
}
