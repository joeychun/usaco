#include <iostream>

using namespace std;

int n;
bool arr[4000][7000];

void recur(int x, int y, int size) {
  /* Assignes 1 to arr when those spots are worthy of being printed a star */

  if (size == 3) {
    /* Base Case */
    arr[x][y] = 1;
    arr[x+1][y-1] = 1;
    arr[x+1][y+1] = 1;
    arr[x+2][y-2] = 1;
    arr[x+2][y-1] = 1;
    arr[x+2][y] = 1;
    arr[x+2][y+1] = 1;
    arr[x+2][y+2] = 1;
    return;
  }

  recur(x,y,size/2);
  recur(x+size/2,y-size/2,size/2);
  recur(x+size/2,y+size/2,size/2);
}


int main() {
  scanf("%d", &n);

  recur(0,n-1,n);

  for (int x=0; x<n; ++x) {
    for (int y=0; y<2*n-1; ++y) {
      if (arr[x][y]) printf("*");
      else printf(" ");
    }
    printf("\n");
  }

  return 0;
}
