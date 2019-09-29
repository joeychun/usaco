/*
ALGORITHM :
Area that can be seen = (total area of billboards) - (covered area)
                      = (area of billboard1) + (area of billboard2) - (covered area from billboard1) - (covered area from billboard2)

Billboard Area(x1,y1, x2,y2) = (x2-x1) * (y2-y1)  << Basic length * width area formula

Covered Area:
when Billboard is made out of (x1,y1), (x2,y2),
 CoveringTruck is made out of (X1,Y1), (X2.Y2).

ex)   ___________________________
      |                          |
      |Truck                     |
______|_____________             |
|     |____________|_____________|
|                  |
|Billboard         |
|__________________|
x1   X1            x2            X2

Length of Covered Area (when rectangles are overlapped)
= x2-X1
In other words, min(x2,X2) - max(x1,X1).
This works both when the lengths of the rectangles are partly overlapping and completely overlapping.

Length of Covered Area (when rectangles are overlapped)
= 0

Therefore, Length of Covered Area = max(min(x2,X2) - max(x1,X1), 0)
Width can be done in the same way with y.

Then, covered Area can be calculated with length * width as well.

*/

#include <iostream>
#include <fstream>

#define max(x,y) (x>y?x:y)
#define min(x,y) (x<y?x:y)

using namespace std;

struct rect {
  int x1, x2, y1, y2;
};

int main(){
  rect Rect[3]; // [0]: billboard1, [1]: billboard2, [2]: truck
  int i;

  ifstream ifs;
  ifs.open("billboard.in");

  for (i=0; i<3; ++i) {
    ifs >> Rect[i].x1 >> Rect[i].y1 >> Rect[i].x2 >> Rect[i].y2;
  }

  // TOTAL AREA
  int total_area = (Rect[0].x2-Rect[0].x1)*(Rect[0].y2-Rect[0].y1) + (Rect[1].x2-Rect[1].x1)*(Rect[1].y2-Rect[1].y1);

  // COVERED AREA
  int xlen, ylen;
  for (i=0; i<=1; ++i) {
    // Covered area in billboardi
    int min = max(Rect[i].x1,Rect[2].x1);
    int max = min(Rect[i].x2,Rect[2].x2);
    xlen = max(0,(max-min));

    min = max(Rect[i].y1,Rect[2].y1);
    max = min(Rect[i].y2,Rect[2].y2);
    ylen = max(0,(max-min));

    // DEDUCTING COVERED AREA
    total_area -= xlen*ylen;
  }

  ofstream ofs;
  ofs.open("billboard.out");
  ofs << total_area;
  return 0;
}
