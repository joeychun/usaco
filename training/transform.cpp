/*
ID: joey.s.1
LANG: C++
TASK: transform
*/

#include <iostream>
#include <fstream>

using namespace std;

int main() {
  ifstream fin ("transform.in");
  ofstream fout ("transform.out");

  int n;
  fin >> n;

  char A[15][15], B[15][15];
  for (int i=0; i<n; ++i) {
    for (int j=0; j<n; ++j) {
      fin >> A[i][j];
    }
  }

  for (int i=0; i<n; ++i) {
    for (int j=0; j<n; ++j) {
      fin >> B[i][j];
    }
  }

  int case_one=0,case_two=0,case_three=0,case_four=0,case_five1=0,case_five2=0,case_five3=0,case_six=0;
  for (int i=0; i<n; ++i) {
    for (int j=0; j<n; ++j) {
      if (A[i][j] == B[i][j]) case_six++;
      if (A[i][j] == B[j][n-i-1]) case_one++;
      if (A[i][j] == B[n-i-1][n-j-1]) case_two++;
      if (A[i][j] == B[n-j-1][i]) case_three++;
      if (A[i][j] == B[i][n-j-1]) case_four++;
      if (A[i][j] == B[n-j-1][n-i-1]) case_five1++;
      if (A[i][j] == B[n-i-1][j]) case_five2++;
      if (A[i][j] == B[j][i]) case_five3++;
    }
  }

  int all = n*n;
  if (case_one == all) {
    fout << 1 << endl;
  } else if (case_two == all) {
    fout << 2 << endl;
  } else if (case_three == all) {
    fout << 3 << endl;
  } else if (case_four == all) {
    fout << 4 << endl;
  } else if ((case_five1 == all) || (case_five2 == all) || (case_five3 == all)) {
    fout << 5 << endl;
  } else if (case_six == all) {
    fout << 6 << endl;
  } else {
    fout << 7 << endl;
  }

  return 0;
}
