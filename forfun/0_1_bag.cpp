#include <iostream>

#define max(a,b) (((a)>(b))?(a):(b))

using namespace std;

int n,k;
int weight[105];
int price[105];

int dp[10005];

int main() {
  scanf("%d %d", &n, &k);
  for (int i=0; i<n; ++i) {
    scanf("%d %d", &weight[i], &price[i]);
  }

  for (int i=0; i<n; ++i) {
    for (int j=k; j>=weight[i]; --j) {
      dp[j] = max(dp[j], dp[j-weight[i]] + price[i]);
    }
  }

  printf("%d", dp[k]);

  return 0;
}
