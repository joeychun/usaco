#include <iostream>
#include <cstring>
#include <map>

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

using namespace std;

int n;
map<int, pair<int,int> > childs;

int parent[10005];

// int visited[105];

int min_depth[10005];
int max_depth[10005];
int total_depth;

int cnt;
int t;
int order[10005];

void dfs(int i, int depth) {
  if (t < 10000000) {
    /* Inorder */
    // printf("dfs(%d)\n", i);
    t++;
    if (i == -1) return;
    total_depth = MAX(total_depth,depth);

    dfs(childs[i].first, depth+1);

    cnt++;
    order[i] = cnt;

    min_depth[depth] = MIN(min_depth[depth], order[i]);
    max_depth[depth] = MAX(max_depth[depth], order[i]);

    dfs(childs[i].second, depth+1);
  }
}

int main() {
  scanf("%d", &n);
  for (int i=0; i<n+5; ++i) min_depth[i] = 1000000;

  int p,c1,c2;
  int a;
  for (int i=0; i<n; ++i) {
    scanf("%d %d %d", &p, &c1, &c2);
    if (i==0) a = p;
    childs[p] = make_pair(c1,c2);
    parent[c1] = p;
    parent[c2] = p;
  }

  int cur = a;
  while (parent[cur] != 0) {
    cur = parent[cur];
  }

  dfs(cur,1);

  int ans_depth = -1;
  int ans_length = -1;
  for (int i=1; i<=total_depth; ++i) {
    if (max_depth[i] - min_depth[i] > ans_length) {
      ans_depth = i;
      // printf("\nmaxlen:%d minlen:%d\n", max_depth[i], min_depth[i]);
      ans_length = max_depth[i] - min_depth[i];
    }
  }
  ans_length++;

  printf("%d %d", ans_depth, ans_length);
  return 0;
}
