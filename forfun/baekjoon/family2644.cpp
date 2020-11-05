#include <iostream>
#include <cstring>
#include <queue>
#include <utility>

using namespace std;

int n,a,b;
int arr[200][200];
int relation[200];


void bfs() {
  queue<pair<int,int> > q;
  q.push(make_pair(a,0));
  relation[a] = 0;

  while (!q.empty()) {
    pair<int,int> front = q.front();
    int num = front.first;
    int depth = front.second;

    q.pop();

    for (int i=0; i<200; ++i) {
      if (arr[num][i]) {
        if (relation[i] == -1 || depth+1 < relation[i]) {
          relation[i] = depth+1;
          q.push(make_pair(i,depth+1));
        }
      }
    }
  }
}

int main() {
  memset(relation, -1, sizeof(relation));
  scanf("%d", &n);
  scanf("%d %d", &a, &b);

  int k;
  scanf("%d", &k);

  int x,y;
  for (int i=0; i<k; ++i) {
    // Create a graph that shows relationship of two nodes
    scanf("%d %d", &x, &y);
    arr[x][y] = 1;
    arr[y][x] = 1;
  }

  bfs();

  int ans = relation[b];

  printf("%d", ans);

  return 0;
}
