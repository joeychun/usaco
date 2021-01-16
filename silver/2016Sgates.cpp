#include <iostream>
#include <fstream>
#include <string>
#include <utility>

#define INF 1e9
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))

using namespace std;

int n;
string s;

int min_x = INF, min_y = INF, max_x = 0, max_y = 0;

int gates[2200][2200][4]; // N:0, S:1, E:2, W:3

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
bool visited[2200][2200];

int curId = 1;

bool within_range(int i, int j) {
  return (min_x <= i && i <= max_x && min_y <= j && j <= max_y);
}

void dfs(int i, int j) {
  for (int k=0; k<4; ++k) {
    int new_x = i+dx[k], new_y = j+dy[k];
    if (within_range(new_x, new_y) && !visited[new_x][new_y] && !gates[i][j][k]) {
      visited[new_x][new_y] = 1;
      dfs(new_x, new_y);
    }
  }
}

int main() {
  ifstream fin ("gates.in");
  ofstream fout ("gates.out");
  ios::sync_with_stdio(false);

  fin >> n >> s;

  pair<int,int> cur;
  cur.first = 1100; cur.second = 1100;

  for (int i=0; i<n; ++i) {
    if (s[i] == 'N') {
      cur.second++;
      gates[cur.first][cur.second-1][3] = 1;
      gates[cur.first-1][cur.second-1][2] = 1;

      min_x = min(cur.first-1, min_x);
      max_x = max(cur.first, max_x);
      min_y = min(cur.second-1, min_y);
      max_y = max(cur.second-1, max_y);
    } else if (s[i] == 'S') {
      cur.second--;
      gates[cur.first][cur.second][3] = 1;
      gates[cur.first-1][cur.second][2] = 1;

      min_x = min(cur.first-1, min_x);
      max_x = max(cur.first, max_x);
      min_y = min(cur.second, min_y);
      max_y = max(cur.second, max_y);
    } else if (s[i] == 'E') {
      cur.first++;
      gates[cur.first-1][cur.second][1] = 1;
      gates[cur.first-1][cur.second-1][0] = 1;

      min_x = min(cur.first-1, min_x);
      max_x = max(cur.first-1, max_x);
      min_y = min(cur.second-1, min_y);
      max_y = max(cur.second, max_y);
    } else if (s[i] == 'W') {
      cur.first--;
      gates[cur.first][cur.second][1] = 1;
      gates[cur.first][cur.second-1][0] = 1;

      min_x = min(cur.first, min_x);
      max_x = max(cur.first, max_x);
      min_y = min(cur.second-1, min_y);
      max_y = max(cur.second, max_y);
    }
  }


  min_x -= 10; min_y -= 10;
  max_x += 10; max_y += 10;

  for (int i=min_x; i<=max_x; ++i) {
    for (int j=min_y; j<=max_y; ++j) {
      if (!visited[i][j]) {
        visited[i][j] = 1;
        dfs(i,j);
        curId++;
      }
    }
  }

  fout << curId-2;

  return 0;
}
