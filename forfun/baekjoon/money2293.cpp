#include <iostream>
#include <algorithm>

#define INF 1e9
#define min(a,b) (((a)<(b))?(a):(b))

using namespace std;

int n,k;
int coins[1005];

int memoi[1000005];

/*
int dp(int x) {
  printf("dp(x=%d, ind=%d\n\t", x, ind);
  if (x == 0) {printf("returning 1\n\n"); return 1;}
  if (x < 0) {printf("returning 0\n\n"); return 0;}
  if (memoi[x] != -1) {printf("returning memoi\n\n");return memoi[x];}

  int return_val = 0;
  for (int i=n-1; i>=0; ++i) {
    return_val += dp(x - coins[i], i);
  }
  memoi[x] = return_val;
  return return_val;
}*/

int main() {
  scanf("%d %d", &n, &k);
  for (int i=0; i<n; ++i) {
    scanf("%d", &coins[i]);
  }

  memoi[0] = 1;
  sort(coins, coins+n);

  for (int i=0; i<n; ++i) {
    for (int j=coins[i]; j<=k; ++j) {
      memoi[j] += memoi[j-coins[i]];
    }
  }

  //int ans = dp(k,0);

  printf("%d", memoi[k]);
  return 0;
}
