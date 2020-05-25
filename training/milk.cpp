/*
ID: joey.s.1
LANG: C++
TASK: milk
*/

#include <iostream>
#include <fstream>

using namespace std;

int main() {
  ifstream fin ("milk.in");
  ofstream fout ("milk.out");

  int n,m;
  fin >> n >> m;

  int P[m+1], A[m+1];
  for (int i=0; i<m; ++i) {
    fin >> P[i] >> A[i];
  }

  int tmp;
  // Sort P[i] and A[i] regarding cheapest to most expensive
  for (int i=0; i<m; ++i) {
    for (int j=0; j<m-i-1; ++j) {
      if (P[j] > P[j+1]) {
        tmp = P[j];
        P[j] = P[j+1];
        P[j+1] = tmp;

        tmp = A[j];
        A[j] = A[j+1];
        A[j+1] = tmp;
      }
    }
  }

  int money = 0;
  for (int i=0; i<m; ++i) {
    if (n > A[i]) {
      money += A[i]*P[i];
      n -= A[i];
    } else {
      money += n*P[i];
      break;
    }
  }

  fout << money << endl;

  return 0;
}
