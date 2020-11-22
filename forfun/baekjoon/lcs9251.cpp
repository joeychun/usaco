#include <iostream>
#include <string>
#include <cstring>

#define max(a,b) (((a)>(b))?(a):(b))

using namespace std;

string s1, s2;
int len1, len2;
int dp[4005][4005];

int recur(int ind1, int ind2) {
  // Base Case
  if (ind1 == -1 || ind2 == -1) return 0;

  if (dp[ind1][ind2] != -1) return dp[ind1][ind2];

  if (s1[ind1] == s2[ind2]) {
    return dp[ind1][ind2] = recur(ind1-1, ind2-1) + 1;
  } else {
    return dp[ind1][ind2] = max(recur(ind1-1,ind2), recur(ind1,ind2-1));
  }
}

int main() {
  memset(dp,-1,sizeof(dp));

  cin >> s1 >> s2;
  len1 = s1.length();
  len2 = s2.length();

  int ans = recur(len1 - 1, len2 - 1);
  cout << ans;
  return 0;
}
