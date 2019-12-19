#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
  ifstream ifs;
  ifs.open("gymnastics.in");
  ofstream ofs;
  ofs.open("gymnastics.out");

  int k,n;
  ifs >> k >> n;

  int data[15][25];

  int i,j,h;
  int tmp_input;
  for (i=0; i<k; ++i) {
    for (j=1; j<=n; ++j) {
      ifs >> tmp_input;
      data[i][tmp_input] = j;
    }
  }

  int consisBool;
  int consisCounter = 0;
  for (i=1; i<=n; ++i){
    for (j=1; j<=n; ++j){
      if (i==j) continue;
      consisBool = 1;
      // Check if cow I is better than cow J
      for (h=0; h<k; ++h){
        if (!(data[h][i] < data[h][j])){
          consisBool = 0;
        }
      }
      consisCounter += consisBool;
    }
  }
  ofs << consisCounter;
}
