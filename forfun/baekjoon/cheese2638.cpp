/* BAEKJOON 2638 */

#include <iostream>
#include <utility>
#include <queue>

using namespace std;

queue<pair<int, int> > q;

int n,m;
int arr[110][110];

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

void print_queue(queue<pair<int, int> > tmpQ) {
  queue<pair<int, int> > l = tmpQ;
  while (!l.empty()) {
    int x = l.front().first;
    int y = l.front().second;
    printf("%d %d\n", x, y);
    l.pop();
  }
}

void bfs() {
  /* BFS to differentiate outer air as -1 and give cheeses value of how many air blocks it's touching */

  queue<pair<int, int> > q;
  q.push(make_pair(0,0));
  arr[0][0] = -1;

  while (!q.empty()) {
    pair<int, int> front = q.front();
    int x = front.first;
    int y = front.second;

    q.pop();

    for (int i=0; i<4; ++i) {
      int new_x = x+dx[i];
      int new_y = y+dy[i];
      if (0 <= new_x && new_x < n && 0 <= new_y && new_y < m) {
        if (arr[new_x][new_y] == 0) { // If unvisited outer air
          arr[new_x][new_y] = -1;
          q.push(make_pair(new_x,new_y));
        } else if (arr[new_x][new_y] > 0) { // If cheese block
          arr[new_x][new_y]++;
        }
        // Already visited outer air (-1) does not need to be considered
      }
    }
  }

}

void melt() {
  for (int i=0; i<n; ++i) {
    for (int j=0; j<m; ++j) {
      if (arr[i][j] >= 3) {
        // Melt the cheese with 2+ air blocks nearby
        arr[i][j] = 0;
      } else if (arr[i][j] == 2) { // or 1
        // Make it into initial cheese block for next bfs
        arr[i][j] = 1;
      } else if (arr[i][j] == -1) {
        // Turn it into initial air: 0
        arr[i][j] = 0;
      }
    }
  }
}

int all_air() {
  for (int i=0; i<n; ++i) {
    for (int j=0; j<m; ++j) {
      if (arr[i][j]) return 0;
    }
  }
  return 1;
}

int main() {
  // Scan
  scanf("%d %d", &n, &m);
  for (int i=0; i<n; ++i) {
    for (int j=0; j<m; ++j) {
      scanf("%d", &arr[i][j]);
    }
  }

  int hours = 0;

  while (!all_air()) {
    bfs();
    hours++;
    melt();
  }

  printf("%d\n", hours);
  return 0;
}
