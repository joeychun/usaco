#include <iostream>

using namespace std;

int n;
int k;

long long int dp[2500][1500];

int main() {
  for (int i=0; i<2500; ++i) {
    dp[i][0] = 1;
    dp[i][1] = i;
  }

  scanf("%d", &n);
  scanf("%d", &k);

  for (int i=1; i<=n; ++i) {
    for (int j=1; j<=k; ++j) {
      dp[i][j] = (dp[i-1][j] + dp[i-2][j-1]) % 1000000003;
    }
  }

  long long int ans = dp[n-1][k] + dp[n-3][k-1];

  printf("%lld", ans);
  return 0;
}
