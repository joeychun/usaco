/*
ID: joey.s.1
LANG: C++
TASK: friday
*/

#include <iostream>
#include <fstream>

using namespace std;

int main() {
  ifstream fin ("friday.in");
  ofstream fout ("friday.out");

  int n;
  int month_size[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int week_days[7] = {0};
  int current_day = 2; // 0: Sat, 1: Sun, 2: Mon...

  fin >> n;

  for (int year=1900; year<1900+n; ++year) {
    if ((year%4 == 0 && year%100 != 0) || year%400==0) month_size[1] = 29;
    else month_size[1] = 28;
    for (int cur_month=0; cur_month<12; ++cur_month) {
      for (int cur_date=1; cur_date<=month_size[cur_month]; ++cur_date) {
        if (cur_date == 13) week_days[current_day]++;

        current_day = (current_day+1)%7;
      }

    }

  }

  for (int i=0; i<=5; ++i) {
    fout << week_days[i] << " ";
  }
  fout << week_days[6] << endl;

  return 0;
}
