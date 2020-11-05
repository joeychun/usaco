#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int m,n;
vector<int> v;

int main() {
  scanf("%d", &m);
  int t;
  for (int i=0; i<m; ++i) {
    scanf("%d", &t);
    v.push_back(t);
  }

  sort(v.begin(), v.end());

  scanf("%d", &n);
  int fnum;
  for (int i=0; i<n; ++i) {
    scanf("%d", &fnum);
    int ans = lower_bound(v.begin(), v.end(), fnum) != upper_bound(v.begin(), v.end(), fnum);
    printf("%d ", ans);
  }
  return 0;
}
