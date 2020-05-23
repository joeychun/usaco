/*
ID: joey.s.1
LANG: C++
TASK: ride
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
  ifstream fin ("ride.in");
  ofstream fout ("ride.out");

  string first, second;
  int first_multi=1, second_multi=1;

  fin >> first >> second;
  for (int i=0; i<first.length(); ++i) {
    first_multi *= first.at(i) - 'A' + 1;
  }
  for (int i=0; i<second.length(); ++i) {
    second_multi *= second.at(i) - 'A' + 1;
  }

  if (first_multi%47 == second_multi%47) {
    fout << "GO\n";
  } else {
    fout << "STAY\n";
  }

  return 0;
}
