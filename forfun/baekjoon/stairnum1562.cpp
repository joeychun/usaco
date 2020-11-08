#include <iostream>

#define MOD 1000000007

using namespace std;

int n;
long long int dp[105][11][1<<11];

int main() {
  cin >> n;

  for (int i=1; i<=9; ++i) {
    dp[1][i][1<<i] = 1;
  }

  long long int tmp;
  int new_z;
  for (int i=2; i<=n; ++i) {
    for (int j=0; j<=9; ++j) {
      for (int z=0; z < 1<<10; ++z) {
        if (j != 0) {
          // tmp = dp[i-1][j-1][z];
          new_z = z | (1<<j);
          dp[i][j][new_z] += (dp[i-1][j-1][z] % MOD);
        }

        if (j != 9) {
          // tmp = dp[i-1][j+1][z];
          new_z = z | (1<<j);
          dp[i][j][new_z] += (dp[i-1][j+1][z] % MOD);
        }
      }
    }
  }

  long long int ans = 0;
  for (int j=0; j<=9; ++j) {
    ans += dp[n][j][(1<<10) - 1];
  }
  ans = ans % MOD;

  printf("%lld", ans);
  return 0;
}
