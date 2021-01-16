#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

typedef pair<int,int> pii;

int n,m;
int arr[105][105];

int lights[105][105];
int conn_lights[105][105];
int visited[105][105];

vector<pii > toggles[105][105];

int dfsvisited[105][105];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

bool turn_on() {
  bool turned_on = false;
  for (int i=1; i<=n; ++i) {
    for (int j=1; j<=n; ++j) {
      if (conn_lights[i][j] && !visited[i][j]) {
        visited[i][j] = 1;
        for (vector<pii>::iterator it=toggles[i][j].begin(); it!=toggles[i][j].end(); ++it) {
          turned_on = true;
          lights[it->first][it->second] = 1;
        }
      }
    }
  }

  return turned_on;
}

bool within_range(int i, int j) {
  return (1 <= i && i <= n && 1 <= j && j <= n);
}

void dfs(int i, int j) {
  for (int k=0; k<4; ++k) {
    int new_x = i+dx[k], new_y = j+dy[k];
    if (within_range(new_x, new_y) && !dfsvisited[new_x][new_y] && lights[new_x][new_y]) {
      conn_lights[new_x][new_y] = 1;
      dfsvisited[new_x][new_y] = 1;
      dfs(new_x, new_y);
    }
  }
}

int main() {
  ifstream fin ("lightson.in");
  ofstream fout ("lightson.out");
  ios::sync_with_stdio(false);

  fin >> n >> m;
  int a,b,c,d;
  for (int i=0; i<m; ++i) {
    fin >> a >> b >> c >> d;
    toggles[a][b].push_back(make_pair(c,d));
  }

  lights[1][1] = 1;
  conn_lights[1][1] = 1;

  int happening = 1;
  while (happening) {
    happening = turn_on();

    memset(dfsvisited, 0, sizeof(dfsvisited));
    dfsvisited[1][1] = 1;
    dfs(1,1);
  }

  int ans = 0;
  for (int i=1; i<=n; ++i) {
    for (int j=1; j<=n; ++j) {
      ans += lights[i][j];
    }
  }
  fout << ans;
  return 0;
}
