#include <iostream>

using namespace std;

long long int dp[1000005];
int n;


int main() {
  scanf("%d", &n);

  dp[0] = 1;

  int num = 1;
  while (num <= n) {
    for (int i=num; i<=n; ++i) {
      dp[i] += dp[i-num];
      dp[i] = dp[i] % 1000000000;
    }
    num *= 2;
  }

  printf("%lld", dp[n]);

  return 0;
}
