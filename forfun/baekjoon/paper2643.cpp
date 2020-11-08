#include <iostream>
#include <algorithm>
#include <utility>

#define max(a,b) (((a)>(b))?(a):(b))

using namespace std;

int n;
pair<int,int> arr[105];
int dp[105];

int main() {
  scanf("%d", &n);
  for (int i=0; i<n; ++i) {
    scanf("%d %d", &arr[i].first, &arr[i].second);
    if (arr[i].second > arr[i].first) {
      int tmp = arr[i].second;
      arr[i].second = arr[i].first;
      arr[i].first = tmp;
    }
  }

  sort(arr, arr+n, greater<pair<int,int> >() );

  for (int i=0; i<n; ++i) {
    if (dp[i] == 0) dp[i] = 1;
    for (int j=0; j<i; ++j) {
      if (arr[j].first >= arr[i].first && arr[j].second >= arr[i].second) {
        // Worth considering using dp[j] case along with rectangle i
        dp[i] = max(dp[j] + 1, dp[i]);
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
