// IOI 2000

#include <iostream>
#include <string>
#include <cstring>

#define min(a,b) (((a)<(b))?(a):(b))

using namespace std;

int n;
string s;
int dp[5005][5005];

int recur(int first, int last) {
  // Base Case
  if (first >= n || last < 0 || first >= last) return 0;
  if (dp[first][last] != -1) return dp[first][last];

  if (s[first] == s[last]) {
    return dp[first][last] = recur(first+1, last-1);
  } else {
    return dp[first][last] = min(recur(first+1, last), recur(first, last-1)) + 1;
  }
}

int main() {
  memset(dp, -1, sizeof(dp));

  cin >> n;
  cin >> s;

  int ans = recur(0,n-1);
  cout << ans;

  return 0;
}
