#include <iostream>
#include <cstring>
#include <cmath>
#include <utility>

#define INF 9000000000000000

using namespace std;

typedef long long ll;

int n;
int arr[2005];
pair<ll,ll> dp[2005][2005]; // [Number that A select][Number that B select]

pair<ll,ll> pair_min(pair<ll,ll> pa, pair<ll,ll> pb) {
  if (pa.first + pa.second < pb.first + pb.second) {
    return pa;
  }
  return pb;
}

pair<ll,ll> recur(int ind, int x, int y) {
  //if (ind >= n) return make_pair(arr[x], arr[y]);
  if (x >= n || y >= n) return make_pair(0,0);

  pair<ll,ll> minustmp = make_pair(-1,-1);
  if (dp[x][y] != minustmp) return dp[x][y];

  // CASE 1: recur(ind+1, ind, y)
  pair<ll,ll> tmp = recur(ind+1, ind, y);
  if (x != 0) tmp.first += abs(arr[x] - arr[ind]);

  // CASE 2: recur(ind+1, x, ind)
  pair<ll,ll> tmp2 = recur(ind+1, x, ind);
  if (y != 0) tmp2.second += abs(arr[y] - arr[ind]);

  return dp[x][y] = pair_min(tmp,tmp2);
}

int main() {
  for (int i=0; i<2005; ++i) {
    for (int j=0; j<2005; ++j) {
      dp[i][j] = make_pair(-1,-1);
    }
  }

  scanf("%d", &n);
  arr[0] = 0;
  for (int i=1; i<=n; ++i) {
    scanf("%d", &arr[i]);
  }


  pair<ll,ll> t = recur(1,0,0);
  ll ans = t.first + t.second;

  printf("%lld", ans);
  return 0;
}
