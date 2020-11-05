#include <iostream>

#define MIN(a,b) (((a)<(b))?(a):(b))

using namespace std;

int n,m;
int arr[10005];

int memoi[10005];

int dp(int money) {
  if (money < 0) return 1e9;
  if (money == 0) return 0;

  if (memoi[money] != -1) return memoi[money];

  int return_val = 1e9;
  for (int i=0; i<m; ++i) {
    return_val = MIN(return_val,dp(money-arr[i]));
  }
  return_val++;
  memoi[money] = return_val;
  return return_val;
}

int main() {
  scanf("%d", &n);
  scanf("%d", &m);

  for (int i=0; i<m; ++i) {
    scanf("%d", &arr[i]);
  }

  for (int i=0; i<10004; ++i) memoi[i] = -1;

  int ans = dp(n);
  if (ans >= 1e9 - 3) printf("-1");
  else printf("%d", ans);
  return 0;
}
