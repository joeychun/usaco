#include <iostream>

#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))

using namespace std;

int n;
int arr[100005];

int dp[100005];
int new_dp[100005];

int dp2[100005];
int new_dp2[100005];

int main() {
  scanf("%d", &n);
  for (int i=0; i<n; ++i) {
    for (int j=0; j<3; ++j) {
      scanf("%d", &arr[j]);
      if (j == 0) {
        new_dp[j] = max(dp[j], dp[j+1]) + arr[j];
        new_dp2[j] = min(dp2[j], dp2[j+1]) + arr[j];
      } else if (j == 2) {
        new_dp[j] = max(dp[j], dp[j-1]) + arr[j];
        new_dp2[j] = min(dp2[j], dp2[j-1]) + arr[j];
      } else {
        new_dp[j] = max(max(dp[j-1], dp[j]), dp[j+1]) + arr[j];
        new_dp2[j] = min(min(dp2[j-1], dp2[j]), dp2[j+1]) + arr[j];
      }
    }

    for (int j=0; j<3; ++j) {
      dp[j] = new_dp[j];
      dp2[j] = new_dp2[j];
    }
  }

  int ans = -1;
  int ans2 = 1e9;
  for (int i=0; i<3; ++i) {
    ans = max(ans, dp[i]);
    ans2 = min(ans2, dp2[i]);
  }

  printf("%d %d", ans, ans2);

  return 0;
}
