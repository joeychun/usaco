#include <iostream>
#include <fstream>

#define max(x,y) (x>y?x:y)

using namespace std;

int main() {
  int n,m; // Input

  // array[x] = y, as x is the mile given and y is the speed when in that mile.
  int limit[101]; // Speed limit
  int journey[101]; // Actual speed

  int mile, speed; // Temporary variables cotaining (mile, speed) input
  int cumulative_mile = 1; // Holds how many miles were recorded in the array

  ifstream ifs;
  ifs.open("speeding.in");
  ifs >> n >> m;

  int i,j;
  for (i=0; i<n; ++i) {
    ifs >> mile >> speed;
    for (j=cumulative_mile; j<=cumulative_mile+mile; ++j) {
      limit[j] = speed;
    }
    cumulative_mile += mile;
  }


  cumulative_mile = 1;
  for (i=0; i<m; ++i) {
    ifs >> mile >> speed;
    for (j=cumulative_mile; j<=cumulative_mile+mile; ++j) {
      journey[j] = speed;
    }
    cumulative_mile += mile;
  }

  int max_speeding = 0;
  // Go over every 100 miles
  for (i=1; i<=100; ++i) {
    int speed_diff = journey[i]-limit[i];
    max_speeding = max(max_speeding, speed_diff); // Change max if the speed difference is bigger than max
  }

  ofstream ofs;
  ofs.open("speeding.out");
  ofs << max_speeding;

  return 0;
}
