#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int counter(int x, int y, int r, int c, char grid[][15]) {
  if(x == r-1 && y == c-1) {
    // Destination
    return 1;
  }

  // Otherwise try all valid next moves and sum them up
  int ret = 0;
  for(int i = x+1; i < r; i++) {
    for(int j = y+1; j < c; j++) {
      if (grid[i][j] != grid[x][y]) { // Check if different color
        ret += counter(i, j, r, c, grid);
      }
    }
  }
  return ret;
}

int main() {
  ifstream fin;
  fin.open("hopscotch.in");
  ofstream fout;
  fout.open("hopscotch.out");

  int r,c;
  fin >> r >> c;

  char grid[15][15];
  string s;
  for (int i=0; i<r; ++i) {
    fin >> s;
    for (int j=0; j<c; ++j) {
      grid[i][j] = s[j];
    }
  }

  fout << counter(0, 0, r, c, grid);
}
