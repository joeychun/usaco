#include <iostream>
#include <cstring>

#define max(a,b) (((a)>(b))?(a):(b))

using namespace std;

int n;
int arr[505][505];
int dp[505][505];

int recur(int i, int j) {
  if (i == n-1) return arr[i][j];
  if (dp[i][j] != -1) return dp[i][j];

  dp[i][j] = max(recur(i+1,j), recur(i+1,j+1)) + arr[i][j];
  return dp[i][j];

}

int main() {
  for (int i=0; i<505; ++i) {
    for (int j=0; j<505; ++j) {
      dp[i][j] = -1;
    }
  }

  scanf("%d", &n);
  for (int i=0; i<n; ++i) {
    for (int j=0; j<=i; ++j) {
      //printf("i=%d j=%d\n",i,j);
      scanf("%d", &arr[i][j]);
    }
  }

  int ans = recur(0,0);
  printf("%d", ans);

  return 0;
}
