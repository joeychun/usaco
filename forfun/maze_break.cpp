#include <utility>
#include <queue>
#include <vector>
#include <algorithm>

#define min(a,b) (((a)<(b))?(a):(b))

using namespace std;

int n;
int ans = 100000000;

int arr[70][70]; // A;0, B:1, C:2

queue<pair<pair<int,int>, int> > q;
int visited[70][70];

void initialize() {
  for (int i=0; i<n; ++i) {
    for (int j=0; j<n; ++j) {
      visited[i][j] = -1;
    }
  }
}

void bfs() {
  q.push(make_pair(make_pair(0,0),0));
  while (!q.empty()) {
    pair<pair<int,int>,int> front = q.front();
    int x = front.first.first;
    int y = front.first.second;
    int b = front.second;
    
    q.pop();

    if (x < 0 || x >= n) continue;
    if (y < 0 || y >= n) continue;
    if (visited[x][y] != -1 && visited[x][y] <= b) continue;
    visited[x][y] = b;

    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,1,-1};
    for (int i=0; i<4; ++i) {
      int black = (0 <= x+dx[i]) && (x+dx[i] < n) && (0 <= y+dy[i]) && (y+dy[i] < n) && !arr[x+dx[i]][y+dy[i]];
      q.push(make_pair(make_pair(x+dx[i],y+dy[i]), b+black));
    }
  }
}

int main() {
  scanf("%d", &n);
  char inp[150];
  for (int i=0; i<n; ++i) {
    scanf("%s", inp);
    for (int j=0; j<n; ++j) {
      arr[i][j] = inp[j] - '0';
    }
  }
  initialize();
  bfs();
  printf("%d", visited[n-1][n-1]);
}
