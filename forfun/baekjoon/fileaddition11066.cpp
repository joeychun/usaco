#include <iostream>
#include <cstring>
#include <utility>

#define min(a,b) (((a)<(b))?(a):(b))
#define INF 9000372036854775807

using namespace std;

typedef long long ll;

int t;
int n;
ll arr[505];
ll sum[505];
ll dp[505][505]; // Price, Resulting file


// DONT USE THE SECOND PAIR TO GET RESULTING FILE
// INSTED, GET VALUES OF ARR[I] ~ ARR[J]

ll recur(int i, int j) { // First and Last inclusive
  if (i == j) return 0;
  if (i + 1 == j) return arr[i]+arr[j];

  //pair<ll,ll> minustmp = make_pair(-1,-1);
  if (dp[i][j] != -1) return dp[i][j];

  dp[i][j] = INF;
  for (int k=i; k<j; ++k) {
    ll tmp = recur(i, k);
    ll tmp2 = recur(k+1, j);
    dp[i][j] = min(tmp + (sum[j] - sum[i-1]) + tmp2, dp[i][j]);
    // if (k == i) dp[i][j].second = tmp.second + tmp2.second;
  }

  return dp[i][j];
}

int main() {
  /*
  for (int i=0; i<505; ++i) {
    for (int j=0; j<505; ++j) {
      dp[i][j].first = -1;
      dp[i][j].second = -1;
    }
  }*/

  scanf("%d", &t);
  for (int i=0; i<t; ++i) {
    scanf("%d", &n);
    ll sum_tmp = 0;
    for (int j=0; j<n; ++j) {
      scanf("%lld", &arr[j]);
      sum_tmp += arr[j];
      sum[j] = sum_tmp;
    }

    for (int i=0; i<505; ++i) {
      for (int j=0; j<505; ++j) {
        dp[i][j] = -1;
      }
    }

    ll ans = recur(0,n-1);
    printf("%lld\n", ans);

  }

  return 0;
}
