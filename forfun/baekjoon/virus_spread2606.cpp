/* BAEKJOON 2606 */

#include <iostream>
#include <utility>
#include <queue>

using namespace std;

int cnt;

int n,e;
int edge[105][105];

int visited[105];

void bfs() {
  /* Uses BFS to go through every computer which has connection with 1 */

  queue<int> q;
  q.push(1);
  visited[1] = 1;

  while (!q.empty()) {
    int front = q.front();

    q.pop();

    for (int i=1; i<=n; ++i) {
      if (edge[front][i]) {
        if (!visited[i]) {
          cnt++;
          q.push(i);
          visited[i] = 1;
        }
      }
    }
  }
}

int main() {
  // Input
  scanf("%d", &n);
  scanf("%d", &e);
  for (int i=0; i<e; ++i) {
    int a,b;
    scanf("%d %d", &a, &b);
    edge[a][b] = 1;
    edge[b][a] = 1;
  }

  bfs();

  printf("%d", cnt);
  return 0;
}
