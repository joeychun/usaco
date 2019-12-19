#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int Data[11][11] = {0, }; // Square data stored as 2d-array
int flip_counter = 0;

// Method that flips a certain area of Data[][]
void flip(int a, int b) {
  // Flipping (0,0) to (a,b)
  flip_counter++;

  int i,j;
  for (i=0; i<=a; ++i) {
    for (j=0; j<=b; ++j) {
      Data[i][j] = 1 - Data[i][j];
    }
  }
}

// Method that checks if Data[][] only holds 0s
bool allzero(int n){
  int i,j;
  for (i=0; i<n; ++i) {
    for (j=0; j<n; ++j) {
      if (Data[i][j]) return false;
    }
  }
  return true;
}

int main() {
  ifstream ifs;
  ifs.open("cowtip.in");
  ofstream ofs;
  ofs.open("cowtip.out");

  int sum;
  int x,y;

  int n;

  // Getting Scanned
  ifs >> n;

  int i,j;
  string seq;
  for (i=0; i<n; ++i) {
    ifs >> seq;
    for (j=0; j<n; ++j) {
      Data[i][j] = seq[j] - 48;
    }
  }

  // Iterating through the farthest "1"s
  for (sum=n-1+n-1; sum>=0; --sum) {
    for (x=0; x<=n-1; ++x) { // x coordinate
      y = sum - x;
      if ((y<0) || (y>n-1))
        continue; // check out of range
      if (Data[x][y] == 1){ // flip if it's 1
        flip(x,y);
      }
    }
    if (allzero(n)) {
      ofs << flip_counter;
      break;
    }
  }

  return 0;
}
