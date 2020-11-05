#include <iostream>

#define min(a,b) (((a)<(b))?(a):(b))

using namespace std;

int n;
int dp[1000005];

int main() {
  scanf("%d", &n);
  dp[1] = 0;

  int tmp = 1e9;
  for (int i=2; i<=n; ++i) {
    tmp = 1e9;
    if (i % 3 == 0) {
      tmp = min(tmp, dp[i/3]);
    }
    if (i % 2 == 0) {
      tmp = min(tmp, dp[i/2]);
    }
    tmp = min(tmp, dp[i-1]);

    dp[i] = tmp + 1;
  }

  printf("%d", dp[n]);
  return 0;
}
