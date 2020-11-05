#include <iostream>
#include <utility>

using namespace std;

int n;
int arr[250][250];

pair<int,int> dfs(int start_x, int end_x, int start_y, int end_y) {
  /* Returns int pair. First: # of gray tiles, Second: # of white tiles */

  int all_gray = 1;
  int all_white = 1;
  for (int i=start_x; i<=end_x; ++i) {
    for (int j=start_y; j<=end_y; ++j) {
      if (arr[i][j]) {
        all_white = 0;
      } else {
        all_gray = 0;
      }
    }
  }

  if (all_gray) {
    return make_pair(1,0);
  }
  if (all_white) {
    return make_pair(0,1);
  }

  int mid_x = (start_x + end_x)/2;
  int mid_y = (start_y + end_y)/2;

  pair<int,int> p1 = dfs(start_x, mid_x, start_y, mid_y);
  pair<int,int> p2 = dfs(start_x, mid_x, mid_y+1, end_y);
  pair<int,int> p3 = dfs(mid_x+1, end_x, start_y, mid_y);
  pair<int,int> p4 = dfs(mid_x+1, end_x, mid_y+1, end_y);

  return make_pair(p1.first + p2.first + p3.first + p4.first, p1.second + p2.second + p3.second + p4.second);
}

int main() {
  scanf("%d", &n);
  for (int i=1; i<=n; ++i) {
    for (int j=1; j<=n; ++j) {
      scanf("%d", &arr[i][j]);
    }
  }

  pair<int,int> ans = dfs(1,n,1,n);

  printf("%d\n", ans.second);
  printf("%d", ans.first);

  return 0;
}
