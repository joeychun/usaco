#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#define min(x,y) (((x)<(y))?(x):(y))
#define max(x,y) (((x)<(y))?(y):(x))

using namespace std;

int main() {
  ifstream fin ("angry.in");
  ofstream fout ("angry.out");

  int n,k; // n: amount of haybales. k: amount of cows slingshoted
  fin >> n >> k;
  long min_val = 1000000005, max_val = -1;

  // Get input
  long tmp;
  vector<long> hay_location; // Holds all of the locations of haybales
  long max_radius = -1; // The answer
  for (int i=0; i<n; ++i) {
    fin >> tmp;
    // This is done to differentiate value 0 from array initial value 0
    hay_location.push_back(tmp+1); // No difference if added-by-one value is put in

    // Update minimum, maximum value
    min_val = min(min_val, tmp+1);
    max_val = max(max_val, tmp+1);
  }

  // Go through all of the locations, divide them into k groups
  long min_hay[15] = { 0 }; // Holds the min hay location among its group (k groups in total)
  long max_hay[15] = { 0 }; // Holds the max hay location among its group (k groups in total)
  for (vector<long>::iterator it = hay_location.begin(); it != hay_location.end(); ++it) {
    for (int n=0; n<k; ++n) { // Internal dividing points
      // Dividing points: (min_val)x(a) + (max_val)x(k-a)
      //                  -------------------------------
      //                                k
      double div1 = (min_val*n + max_val*(k-n))/(double)k;
      double div2 = (min_val*(n+1) + max_val*(k-n-1))/(double)k;
      if (n==0) div1 += 1; // To include maximum hay location in a group as well
      if ((div2 <= (*it)) && ((*it) < div1)) {
        /* cout << n << ": " << div1 << ", " << div2 << "\n" << "value => " << (*it) << "\n\n"; */
        // Check if (*it) can be part of min_hay[n] or max_hay[n]
        // Before that, check if min_hay[n] and max_hay[n] exists
        if (min_hay[n] == 0) {
          min_hay[n] = (*it);
        } else {
          min_hay[n] = min(min_hay[n], (*it));
        }

        if (max_hay[n] == 0) {
          max_hay[n] = (*it);
        } else {
          max_hay[n] = max(max_hay[n], (*it));
        }
      }
    }
  }

  // Radius Calculation
  for (int i=0; i<k; ++i) {
    long diff = max_hay[i] - min_hay[i];
    long radius = (diff+1)/2;
    max_radius = max(max_radius, radius);
  }

  fout << max_radius;

  return 0;
}
