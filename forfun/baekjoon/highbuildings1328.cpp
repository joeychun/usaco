#include <iostream>
#include <cstring>

#define MOD 1000000007

using namespace std;

int a,b,c;
long long int dp[105][105][105];

long long int recur(int b, int l, int r) {
  // Cases that don't work at all
  if (l > b || r > b) return 0;
  if ((l == b && r > 1) || (r == b && l > 1)) return 0;
  if (b * l * r == 0) return 0;

  // Base Case; return 1
  if ((l == b && r == 1) || (r == b && l == 1)) return 1;

  if (dp[b][l][r] != -1) return dp[b][l][r];

  return dp[b][l][r] = (recur(b-1, l-1, r) + recur(b-1, l, r-1) + (b-2)*recur(b-1, l, r)) % MOD;
}

int main() {
  memset(dp, -1, sizeof(dp));
  cin >> a >> b >> c;

  int ans = recur(a,b,c) % MOD;
  printf("%d", ans);

  return 0;
}
