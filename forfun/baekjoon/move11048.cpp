#include <iostream>

#define max(a,b,c) (( (((a)>(b))?(a):(b)) > (c))? (((a)>(b))?(a):(b)): (c))

using namespace std;

int n,m;
int candy[1005][1005];
int dp[1005][1005];

int recur(int x, int y) {
  if (x >= n || y >= m) return 0;
  if (dp[x][y] != -1) return dp[x][y];

  return dp[x][y] = max(recur(x+1,y), recur(x,y+1), recur(x+1,y+1)) + candy[x][y];
}

int main() {

  for (int i=0; i<1005; ++i) {
    for (int j=0; j<1005; ++j) {
      dp[i][j] = -1;
    }
  }

  scanf("%d %d", &n, &m);

  for (int i=0; i<n; ++i) {
    for (int j=0; j<m; ++j) {
      scanf("%d", &candy[i][j]);
    }
  }

  int ans = recur(0,0);

  printf("%d", ans);

  return 0;
}
