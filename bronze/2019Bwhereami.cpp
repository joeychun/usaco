#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

#define INFINITY 1000

using namespace std;

int main(){
  ifstream ifs;
  ifs.open("whereami.in");
  ofstream ofs;
  ofs.open("whereami.out");

  int n;
  int k = INFINITY;
  string s,s1,s2;

  int scope;

  ifs >> n;
  ifs >> s;

  int i,j;
  int break_check;
  for (scope=1; scope<=n; ++scope) {
    for (i=0; i<n+1-scope; ++i) {
      for (j=0; j<n+1-scope; ++j) {
        break_check = 0;
        if (i==j) continue;
        s1 = s.substr(i,scope);
        s2 = s.substr(j,scope);
        if (s1.compare(s2) == 0) {
          break_check = 1;
          break;
        }
      }
      if (break_check) break;
    }
    if (!(break_check)) {
      ofs << scope;
      return 0;
    }
  }
}
