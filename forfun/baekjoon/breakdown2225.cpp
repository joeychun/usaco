#include <iostream>

using namespace std;

long long int dp[605][405];

int n,k;

long long int comb(int x, int r) {
  if (r == 0) return 1;
  if (x == r) return 1;
  if (dp[x][r] != -1) return dp[x][r];

  dp[x][r] = comb(x-1,r) + comb(x-1,r-1);
  dp[x][r] = dp[x][r] % 1000000000;
  return dp[x][r];
}

int main() {
  for (int i=0; i<605; ++i) {
    for (int j=0; j<405; ++j) {
      dp[i][j] = -1;
    }
  }

  scanf("%d %d", &n, &k);

  long long int ans = comb(n+k-1,n);
  printf("%lld", ans);

  return 0;
}
