#include <iostream>

using namespace std;

int n;
int arr[1005];
int dp[1005];

int main() {
  scanf("%d", &n);
  for (int i=0; i<n; ++i) {
    scanf("%d", &arr[i]);
  }

  for (int i=0; i<n; ++i) {
    if (dp[i] == 0) dp[i] = arr[i];
    for (int j=0; j<i; ++j) {
      if (arr[j] < arr[i]) {
        dp[i] = max(dp[j] + arr[i], dp[i]);
      }
    }
  }

  int ans = -1;
  for (int i=0; i<n; ++i) {
    ans = max(dp[i], ans);
  }

  printf("%d", ans);
  return 0;
}
