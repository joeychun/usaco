#include <iostream>

using namespace std;

int n;
bool arr[7000][7000];

void recur(int x, int y, int size) {
  /* Assignes 1 to arr when those spots are worthy of being printed a star */

  if (size == 3) {
    /* Base Case */
    arr[x][y] = 1;
    arr[x][y+1] = 1;
    arr[x][y+2] = 1;
    arr[x+1][y] = 1;
    // arr[x+1][y+1] is the hole!
    arr[x+1][y+2] = 1;
    arr[x+2][y] = 1;
    arr[x+2][y+1] = 1;
    arr[x+2][y+2] = 1;
    return;
  }

  int delta = size/3;

  for (int i=0; i<3; ++i) {
    for (int j=0; j<3; ++j) {
      if (i==1 && j==1) continue;
      recur(x+i*delta, y+j*delta, delta);
    }
  }
}

int main() {
  scanf("%d", &n);

  if (n==1) {
    printf("*\n");
    return 0;
  }
  
  recur(0,0,n);

  for (int x=0; x<n; ++x) {
    for (int y=0; y<n; ++y) {
      if (arr[x][y]) printf("*");
      else printf(" ");
    }
    printf("\n");
  }

  return 0;
}
