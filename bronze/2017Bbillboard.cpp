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

  int total_area = (Rect[0].x2-Rect[0].x1)*(Rect[0].y2-Rect[0].y1) + (Rect[1].x2-Rect[1].x1)*(Rect[1].y2-Rect[1].y1);

  int xlen, ylen;
  for (i=0; i<=1; ++i) {
    // Covered area in billboardi
    int min = max(Rect[i].x1,Rect[2].x1);
    int max = min(Rect[i].x2,Rect[2].x2);
    xlen = max(0,(max-min));

    min = max(Rect[i].y1,Rect[2].y1);
    max = min(Rect[i].y2,Rect[2].y2);
    ylen = max(0,(max-min));

    total_area -= xlen*ylen;
  }

  ofstream ofs;
  ofs.open("billboard.out");
  ofs << total_area;
  return 0;
}
