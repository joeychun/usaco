#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
  ifstream fin ("cowsignal.in");
  ofstream fout ("cowsignal.out");

  int a,b,z; // a x b drawing, zoom by z
  fin >> a >> b >> z;

  for (int i=0; i<a; ++i) {
    string s;
    fin >> s;
    for (int j=0; j<z; ++j) {
      for (int k=0; k<b; ++k) {
        for (int l=0; l<z; ++l) {
          fout << s[k];
        }
      }
      fout << "\n";
    }
  }
}
