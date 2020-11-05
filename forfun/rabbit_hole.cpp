#include <iostream>
#include <algorithm>

using namespace std;

int n;
int holed[50][50];

int recur(int i, int j) {
  if (holed[i][j] == 0) return 0;

  holed[i][j] = 0;
  int sum = 1;
  if (i-1 >= 0) sum += recur(i-1,j);
  if (i+1 < n) sum += recur(i+1,j);
  if (j-1 >= 0) sum += recur(i,j-1);
  if (j+1 < n) sum += recur(i,j+1);
  return sum;
}

int main() {
  // INPUT
  scanf("%d", &n);
  for (int i=0; i<n; ++i) {
    for (int j=0; j<n; ++j) {
      scanf("%d", &holed[i][j]);
    }
  }
  // CALL RECUR FUNC
  int arr[100000];
  int arr_ind = 0;
  for (int i=0; i<n; ++i) {
    for (int j=0; j<n; ++j) {
      if (holed[i][j]) {
        arr[arr_ind] = recur(i,j);
        arr_ind++;
      }
    }
  }

  sort(arr, arr+arr_ind);

  printf("%d\n", arr_ind);
  for (int i=arr_ind-1; i>=0; --i) {
    printf("%d\n", arr[i]);
  }

  return 0;
}
