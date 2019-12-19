/*
BRIEF ALGORITHM EXPLANATION:
When there is a 2D array that holds when which grid was visited,
revisiting can be tracked and the time distance can be calculated.


1. grid[][] is initiated as all 0s.

2. Find grid data according to the direction input given
ex)
grid[3][3] = 2 // (3,3) was visited when t=2
grid[5][5] = 4 // (5,5) was visited when t=4

3. When there are revisits, time difference is calculated
ex)
When grid[5][5] is revisited at t=9, there is a time difference of 5.
This means the maximum grass regrowth time is 5 in this case

This maximum grass regrowth value is stored as variable min_time_diff

When grid[3][3] is revisited at t=15, there is a time difference of 13.
This means the maximum grass regrowth time is 13 in this case.

min_time_diff = 5, and 13 is compared. The min value 5 remains as min_time_diff.
(Since the first of these two constraints is tighter)
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

#define min(x,y) (((x)<(y))?(x):(y))

#define INFINITY 100000

using namespace std;

int grid[2005][2005] = { 0 }; // ex) grid(-1000, 1000) => grid[0][2000] (adds 1000 to make nonnegative)
                              // Initiate everything to 0
int x_pos = 1000, y_pos = 1000; // Current position. Will move according to instructions of NESW

void move(char direction) { // changes farmer's x_pos and y_pos when getting direction as input
  if (direction == 'N') {
    y_pos = y_pos + 1;
  } else if (direction == 'S') {
    y_pos = y_pos - 1;
  } else if (direction == 'E') {
    x_pos = x_pos + 1;
  } else if (direction == 'W') {
    x_pos = x_pos - 1;
  }
}

int main() {
  ifstream ifs;
  ifs.open("mowing.in");
  ofstream ofs;
  ofs.open("mowing.out");

  int min_time_diff = INFINITY;

  // 2D Grid
  int time = 1; // Current time. Lets say the initial t=0 square actually starts in t=1
                // This is in order to differentiate the initial sqaure's value t=0 to
                // non-visited grids having the value of 0
  grid[1000][1000] = 1; // Initial square

  int n;
  char d;
  int s;
  ifs >> n;

  int i,j;
  for (i=0; i<n; ++i) {
    ifs >> d >> s;
    for (j=0; j<s; ++j) {
      move(d);
      time++;
      if (grid[x_pos][y_pos] == 0){ // If it's a non-visited grid
        grid[x_pos][y_pos] = time; // Save when visited
      } else { // If it's a visited grid
        // The newly visited time minus the oldly visited time
        // is a candidate of maximum grass regrowth time
        min_time_diff = min((time - grid[x_pos][y_pos]), min_time_diff);
        grid[x_pos][y_pos] = time; // Update when visited
      }
    }
  }

  if (min_time_diff == INFINITY) {
    ofs << -1;
  } else {
    ofs << min_time_diff;
  }


}
