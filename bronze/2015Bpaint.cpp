#include <iostream>
#include <fstream>

using namespace std;

int main() {
  int a,b,c,d; // Input
  int length; // the answer: total length of fence that is covered with paint

  ifstream ifs;
  ifs.open("paint.in");
  ifs >> a >> b >> c >> d;

  // Because of W.L.O.G, change so that b is bigger than d (so that line 1 is always in the left side of line 2)
  if (d<b) {
    // Switch the left smaller points
    int temp = a;
    a = c;
    c = temp;

    // Switch the right bigger points
    temp = d;
    d = b;
    b = temp;
  }

  // Divide into three possible cases
  if (b<c) {
    /* CASE 1
       a--b
             c--d */
    length = b-a + d-c;
  } else if (a<c) {
    /* CASE 2
       a-----b
          c----d */
    length = d-a;
  } else {
    /* CASE 3
         a--b
      c-------d */
    length = d-c;
  }

  ofstream ofs;
  ofs.open("paint.out");
  ofs << length;

  return 0;
}
