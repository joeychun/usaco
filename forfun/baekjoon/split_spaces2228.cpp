#include <iostream>
#include <cstring>

#define max(a,b) (((a)>(b))?(a):(b))
#define MININF -9000000000000000000

using namespace std;

int n,m;
long long int arr[105];
long long int dp[105][105][2];

long long int recur(int ind, int splits, int used) {
  if (splits == 0) return 0;
  if (ind >= n) return MININF;
  if (dp[ind][splits][used] != -1) return dp[ind][splits][used];

  if (used == 0) {
    return dp[ind][splits][used] = max(recur(ind+1, splits, 0), recur(ind+1, splits, 1) + arr[ind+1]);
  } else {
    return dp[ind][splits][used] = max(recur(ind+1, splits-1, 0), recur(ind+1, splits, 1) + arr[ind+1]);
  }
}

int main() {
  memset(dp, -1, sizeof(dp));

  scanf("%d %d", &n, &m);
  for (int i=0; i<n; ++i) {
    scanf("%lld", &arr[i]);
  }

  long long int ans = max(recur(0,m,0), recur(0,m,1)+arr[0]);
  printf("%lld", ans);

  return 0;
}
