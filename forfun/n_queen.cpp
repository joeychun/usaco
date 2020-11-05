#include <iostream>
#include <stack>

using namespace std;

int n;

int taken[15][15];

void print(int row) {
  for (int i=0; i<row; ++i) printf("\t");
  printf(" ");
  for (int i=0; i<n; ++i) {
    printf(" %d", i);
  }
  printf("\n");
  for (int i=0; i<n; ++i) {
    for (int i=0; i<row; ++i) printf("\t");
    printf("%d ", i);
    for (int j=0; j<n; ++j) {
      if (taken[i][j] == 1) printf("\033[1mO\033[0m ");
      else printf("O ");
    }
    printf("\n");
  }
}

int recur(int row) {
  for (int i=0; i<row; ++i) printf("\t");
  printf("recur(%d): print()\n", row);
  print(row);
  if (row == n) {
    for (int i=0; i<row; ++i) printf("\t");
    printf("Return 1 case!\n");
  }
  printf("\n");
  if (row == n) return 1;
  int sum = 0;
  for (int i=0; i<n; ++i) {
    int available = 1;
    // Check upwards
    for (int j=0; j<=row; ++j) {
      if (!available) break;
      if (taken[j][i]) available = 0;
    }
    // Check upwards left diagonal -- i is the center
    for (int j=0; j<i; ++j) {
      if (!available) break;
      if (row-i+j>=0 && taken[row-i+j][j]) available = 0;
    }
    // Check upwards right diagonal -- i is the center
    for (int j=i+1; j<n; ++j) {
      if (!available) break;
      if (row+i-j>=0 && taken[row+i-j][j]) available = 0;
    }
    if (available) {
      taken[row][i] = 1;
      sum += recur(row+1);
      taken[row][i] = 0;
    }
  }
  return sum;
}

int main() {
  scanf("%d", &n);
  int ans = recur(0);
  printf("%d", ans);

  return 0;
}
