#include <iostream>
#include <algorithm>

#define INF 1e9
#define min(a,b) (((a)<(b))?(a):(b))

using namespace std;

int n,k;
int coins[1005];

int memoi[1000005];

int dp(int x, int ind) {
  if (x == 0) return 0;
  if (x < 0) return INF;
  if (memoi[x] != -1) return memoi[x];

  int return_val = INF;
  for (int i=ind; i<n; ++i) {
    return_val = min(return_val, dp(x - coins[i], i));
  }
  memoi[x] = return_val + 1;
  return return_val + 1;
}

int main() {
  scanf("%d %d", &n, &k);
  for (int i=0; i<n; ++i) {
    scanf("%d", &coins[i]);
  }

  for (int i=0; i<1000005; ++i) {
    memoi[i] = -1;
  }

  sort(coins, coins+n, greater<int>());

  int ans = dp(k,0);

  if (ans >= INF - 2) {
    printf("-1");
  } else {
    printf("%d", ans);
  }
  return 0;
}
