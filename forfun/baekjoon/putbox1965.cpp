#include <iostream>

#define max(a,b) (((a)>(b))?(a):(b))

using namespace std;

int n;
int arr[1005];
int dp[1005];

int main() {
  scanf("%d", &n);
  for (int i=0; i<n; ++i) {
    scanf("%d", &arr[i]);
  }

  // Do LIS
  for (int i=0; i<n; ++i) {
    if (dp[i] == 0) dp[i] = 1;

    for (int j=0; j<i; ++j) {
      if (arr[j] < arr[i]) {
        dp[i] = max(dp[j]+1, dp[i]);
      }
    }
  }

  int ans = 0;
  for (int i=0; i<n; ++i) {
    ans = max(dp[i], ans);
  }

  printf("%d", ans);
  return 0;
}
