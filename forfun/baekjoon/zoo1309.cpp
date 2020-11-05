#include <iostream>

using namespace std;

int n;
int dp[100005][3];

int recur(int x, int y) {
  if (x == n-1) return 1;
  if (x >= 0 && dp[x][y] != 0) return dp[x][y];

  if (y == 0) {
    dp[x][y] = recur(x+1, 0) + recur(x+1, 1) + recur(x+1, 2);
    dp[x][y] = dp[x][y]%9901;
    return dp[x][y];
  } else {
    dp[x][y] = recur(x+1, 0) + recur(x+1, 3-y);
    dp[x][y] = dp[x][y]%9901;
    return dp[x][y];
  }
}

int main() {
  scanf("%d", &n);
  int ans = (recur(0,0) + recur(0,1) + recur(0,2))%9901;

  printf("%d", ans);

  return 0;
}
