#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int n,m;
int need[100005];

int calc(int k) {
  int m_calc = 1;
  int bal = k;
  for (int i=0; i<n; ++i) {
    if (need[i] > k) return m+5;

    if (bal >= need[i]) {
      bal -= need[i];
    } else {
      m_calc++;
      bal = k-need[i];
    }
  }
  return m_calc;
}

int main() {
  scanf("%d %d", &n, &m);

  int start = 0;
  int end = 0;

  for (int i=0; i<n; ++i) {
    scanf("%d", &need[i]);
    end += need[i];
  }



  int ans = 987654321;
  while (start <= end) {
    int mid = (start+end)/2;
    // printf("Calcing calc(%d)...\n", mid);

    if (calc(mid) <= m) {
      ans = (mid<ans)?(mid):(ans);
      end = mid-1;
    } else {
      start = mid+1;
    }
  }

  printf("%d", ans);

  return 0;
}
