#include <iostream>
#include <cstring>

#define max(a,b) (((a)>(b))?(a):(b))

using namespace std;

int n;
int arr[505][505];
int memoi[505][505];

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int dfs(int x, int y) {
  if (memoi[x][y] != -1) return memoi[x][y];

  int sum = 1;
  for (int i=0; i<4; ++i) {
    int new_x = x+dx[i];
    int new_y = y+dy[i];
    if (0 <= new_x && new_x < n && 0 <= new_y && new_y < n) {
      if (arr[x][y] < arr[new_x][new_y]) {
        sum = max(sum, dfs(new_x, new_y) + 1);
      }
    }
  }

  return memoi[x][y] = sum;
}

int main() {
  memset(memoi, -1, sizeof(memoi));

  scanf("%d", &n);
  for (int i=0; i<n; ++i) {
    for (int j=0; j<n; ++j) {
      scanf("%d", &arr[i][j]);
    }
  }

  int ans = -1;
  for (int i=0; i<n; ++i) {
    for (int j=0; j<n; ++j) {
      ans = max(dfs(i,j), ans);
    }
  }

  printf("%d", ans);
  return 0;
}
