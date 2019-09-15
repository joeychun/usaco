#include <iostream>
#include <fstream>
using namespace std;

int main() {
  int x[4], y[4];
  int i;
  ifstream ifs;
  ifs.open("square.in");

  for (i=0; i<4; ++i){
    ifs >> x[i] >> y[i];
  }

  int xmin = x[0], xmax = x[0];
  int ymin = y[0], ymax = y[0];
  for (i=1; i<4; ++i){
    if (xmin > x[i]){
      xmin = x[i];
    }
    if (ymin > y[i]){
      ymin = y[i];
    }
    if (xmax < x[i]){
      xmax = x[i];
    }
    if (ymax < y[i]){
      ymax = y[i];
    }
  }

  ofstream ofs;
  ofs.open("square.out");
  int deltax = xmax - xmin;
  int deltay = ymax - ymin;
  if (deltax > deltay){
    ofs << (deltax * deltax);
  } else {
    ofs << (deltay * deltay);
  }

  ifs.close();
  ofs.close();

  return 0;
}
