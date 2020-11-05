#include <iostream>

using namespace std;

int dp[1005];
int choices[2];

int n;

/*
int main() {
  scanf("%d", &n);

  dp[0] = 1;
  dp[1] = 1;

  for (int i=2; i<=n; ++i) {
    dp[i] = (dp[i-1] + dp[i-2]) % 10007;
  }

  printf("%d", dp[n]);

  return 0;
}*/

int main() {
  scanf("%d", &n);

  dp[0] = 1;
  dp[1] = 1;

  for (int i=2; i<=n; ++i) {
    dp[i] = (dp[i-1] + dp[i-2] * 2) % 10007;
  }

  printf("%d", dp[n]);

  return 0;
}
