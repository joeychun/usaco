#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

int main() {
  ifstream fin ("spiral.in");
  ofstream fout ("spiral.out");

  int n;
  fin >> n; // Take in Input

  // 2-D array to store the spiral-walk values
  int arr[n+5][n+5];

  /* In a 2-D array arr[x][y], x and y would mean the following:
  [
      Y --->
  X  [1, 2, 3],
  |  [8, 9, 4],
  V  [7, 6, 5]

  ]
  */

  // Initializing variables
  int x = 0, y = 0;
  int x_min = 0, x_max = n-1, y_min = 0, y_max = n-1;
  arr[0][0] = 1;

  int status = 0;
  for (int num=2; num<=n*n; ++num) {
    if (status == 0) {
      if (y<y_max) {
        y++;
      } else {
        status = 1;
        x_min++;
      }
    }
    if (status == 1) {
      if (x<x_max) {
        x++;
      }
      else {
        status = 2;
        y_max--;
      }
    }
    if (status == 2) {
      if (y>y_min) {
        y--;
      }
      else {
        status = 3;
        x_max--;
      }
    }
    if (status == 3) {
      if (x>x_min) {
        x--;
      }
      else {
        status = 0;
        num--;
        y_min++;
        continue;
      }
    }
    //fout << "num: " << num << "  current x: " << x << "   current y: " << y << "   status: " << status << endl;
    arr[x][y] = num;
  }

  for (int i=0; i<n; ++i) {
    for (int j=0; j<n; ++j) {
      fout << arr[i][j] << " ";
    }
    fout << "\n";
  }


  return 0;
}
