#include <iostream>
#include <utility>
#include <queue>
#include <map>

using namespace std;

int dx[6] = {0,1,1,0,-1,-1};
int dy[6] = {2,1,-1,-2,-1,1};

int n;
// map<pair<pair<int,int>,pair<int,int> >, int> visited;
// int visited[1000][1000][6][50];
int visited[1000][1000];

int ans;

/*
void bfs() {
  queue<pair<pair<int,int>,pair<int,int> > > q;
  q.push(make_pair(make_pair(0+500,0+500), make_pair(0,0)));
  visited[0+500][0+500][0][0] = 1;
  // visited[make_pair(make_pair(0+500,0+500),make_pair(0,0))] = 1;

  while (!q.empty()) {
    pair<pair<int,int>,pair<int,int> > front = q.front();
    int x = front.first.first;
    int y = front.first.second;
    int direct = front.second.first;
    int depth = front.second.second;

    q.pop();

    int r = (direct+1)%6;
    int l = (direct+5)%6;

    if (depth >= n) continue;

    // turn Right case
    int new_x = x+dx[r];
    int new_y = y+dy[r];
    if (visited[new_x][new_y]) {
      if (depth+1 == n) ans++;
    } else {
      visited[new_x][new_y][r][depth+1] = 1;
      q.push(make_pair(make_pair(new_x,new_y), make_pair(r,depth+1)));
    }

    // turn Left case
    new_x = x+dx[l];
    new_y = y+dy[l];
    if (visited[new_x][new_y]) {
      if (depth+1 == n) ans++;
    } else {
      visited[new_x][new_y][l][depth+1] = 1;
      q.push(make_pair(make_pair(new_x,new_y), make_pair(l,depth+1)));
    }

  }

}*/

void dfs(int x, int y, int depth, int direct) {
  int r = (direct+1)%6;
  int l = (direct+5)%6;

  /*
  for (int i=0; i<depth; ++i) {
    printf("  ");
  }
  printf("dfs(x=%d, y=%d, depth=%d, direct=%d)\n", x, y, depth, direct);*/

  if (depth >= n) return;

  // turn Right case
  int new_x = x+dx[r];
  int new_y = y+dy[r];
  if (visited[new_x][new_y]) {
    // printf("\n OK \n");
    if (depth+1 == n) ans++;
  } else {
    visited[new_x][new_y] = 1;
    // q.push(make_pair(make_pair(new_x,new_y), make_pair(r,depth+1)));
    dfs(new_x,new_y,depth+1,r);
    visited[new_x][new_y] = 0;
  }

  // turn Left case
  new_x = x+dx[l];
  new_y = y+dy[l];
  if (visited[new_x][new_y]) {
    // printf("\n OK \n");
    if (depth+1 == n) ans++;
  } else {
    visited[new_x][new_y] = 1;
    // q.push(make_pair(make_pair(new_x,new_y), make_pair(l,depth+1)));
    dfs(new_x,new_y,depth+1,l);
    visited[new_x][new_y] = 0;
  }

}


int main() {
  scanf("%d", &n);
  visited[500][498] = 1;
  visited[500][500] = 1;
  dfs(500,500,0,0);
  printf("%d", ans);
  return 0;
}
