#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <queue>

using namespace std;

string s;

int n,m;
int arr[105][15];

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
bool tmpvisited[105][15];
bool visited[105][15];

bool within_range(int i, int j) {
  return (0 <= i && i < n && 0 <= j && j < 10);
}

int dfsrecur(int i, int j, int color) {
  int returnval = 1;
  for (int k=0; k<4; ++k) {
    int new_x = i+dx[k], new_y = j+dy[k];
    if (within_range(new_x, new_y) && !tmpvisited[new_x][new_y] && arr[new_x][new_y] == color) {
      tmpvisited[new_x][new_y] = 1;
      returnval += dfsrecur(new_x, new_y, color);
    }
  }

  return returnval;
}

bool dfs() {
  memset(visited, 0, sizeof(visited));
  int happened = false;
  int tmp;
  for (int i=0; i<n; ++i) {
    for (int j=0; j<10; ++j) {
      if (!visited[i][j] && arr[i][j] != 0) {
        memset(tmpvisited, 0, sizeof(tmpvisited));
        tmpvisited[i][j] = 1;
        tmp = dfsrecur(i,j, arr[i][j]);

        if (tmp >= m) {
          happened = true;
          for (int x=0; x<n; ++x) {
            for (int y=0; y<10; ++y) {
              if (tmpvisited[x][y]) {
                visited[x][y] = 1;
                arr[x][y] = 0;
              }
            }
          }
        } else {
          for (int x=0; x<n; ++x) {
            for (int y=0; y<10; ++y) {
              if (tmpvisited[x][y]) {
                visited[x][y] = 1;
              }
            }
          }
        }
      }
    }
  }

  return happened;
}

void gravity() {
  for (int j=0; j<10; ++j) {
    queue<int> q;
    for (int i=n-1; i>=0; --i) {
      if (arr[i][j] != 0) {
        q.push(arr[i][j]);
        arr[i][j] = 0;
      }
    }

    int cur_ind = n-1;
    while (!q.empty()) {
      arr[cur_ind][j] = q.front();
      q.pop();

      cur_ind--;
    }
  }
}

int main() {
  ifstream fin ("mooyomooyo.in");
  ofstream fout ("mooyomooyo.out");
  ios::sync_with_stdio(false);

  fin >> n >> m;
  for (int i=0; i<n; ++i) {
    fin >> s;
    for (int j=0; j<10; ++j) {
      arr[i][j] = s[j] - '0';
    }
  }

  bool happened = true;

  gravity();
  while (happened) {
    happened = dfs();
    gravity();
  }

  for (int i=0; i<n; ++i) {
    for (int j=0; j<10; ++j) {
      fout << arr[i][j];
    }
    fout << endl;
  }

  return 0;
}
