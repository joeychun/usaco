/*
ID: joey.s.1
LANG: C++
TASK: milk2
*/

#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

int main() {
  ifstream fin ("milk2.in");
  ofstream fout ("milk2.out");

  int n;
  fin >> n;

  bool milking[1000005] = {0, };
  int max_time = -1;
  int min_time = 1000005;

  int start;
  int end;
  for (int i=0; i<n; ++i) {
    fin >> start >> end;
    for (int t=start; t<end; ++t) {
      milking[t] = 1;
    }
    // Update max_time
    if (end > max_time) max_time = end;
    if (start < min_time) min_time = start;
  }

  int milk_days = 0;
  int rest_days = 0;
  int max_milk = -1;
  int max_rest = -1;

  for (int time = min_time; time < max_time; ++time) {
    if (time == min_time) {
      if (milking[time]) milk_days++;
      else rest_days++;
    } else {
      if (milking[time]) { // Milked Currently
        if (milking[time-1]) { // Milked Previously
          milk_days++;
        } else { // Not Milked Previously
          if (rest_days > max_rest) max_rest = rest_days;
          rest_days = 0;
          milk_days = 1;
        }
      } else { // Not Milked Currently
        if (milking[time-1]) { // Milked Previously
          if (milk_days > max_milk) max_milk = milk_days;
          milk_days = 0;
          rest_days = 1;
        } else {  // Not Milked Previously
          rest_days++;
        }
      }

      if (time == max_time-1) { // Update before the for loop ends
        if (rest_days > max_rest) max_rest = rest_days;
        if (milk_days > max_milk) max_milk = milk_days;
      }
    }
  }

  fout << max_milk << " " << max_rest << endl;

  return 0;
}
