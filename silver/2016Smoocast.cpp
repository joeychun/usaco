#include <iostream>
#include <fstream>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>

#define max(a,b) (((a)>(b))?(a):(b))

using namespace std;

typedef struct {
  int x;
  int y;
  int p;
}cow;

int n;
cow cows[205];

vector<int> adj[205]; // Ex: adj[i] = {j1, j2}   =>   i->j1, i->j2 both possible
bool visited[205];

int distsq(cow a, cow b) {
  int x = abs(a.x - b.x);
  int y = abs(a.y - b.y);
  return x*x + y*y;
}

int dfs(int i) {
  int returnval = 1;
  for (vector<int>::iterator it=adj[i].begin(); it!=adj[i].end(); ++it) {
    int cur = (*it);
    if (!visited[cur]) {
      visited[cur] = 1;
      returnval += dfs(cur);
    }
  }

  return returnval;
}

int main() {
  ifstream fin ("moocast.in");
  ofstream fout ("moocast.out");
  ios::sync_with_stdio(false);

  fin >> n;
  for (int i=1; i<=n; ++i) {
    fin >> cows[i].x >> cows[i].y >> cows[i].p;
  }

  for (int i=1; i<=n; ++i) {
    // Check if i->j is possible
    for (int j=1; j<=n; ++j) {
      int psq = (cows[i].p) * (cows[i].p);
      if (distsq(cows[i], cows[j]) <= psq) {
        // Approachable
        adj[i].push_back(j);
      }
    }
  }
  
  int ans = 0;
  for (int i=1; i<=n; ++i) {
    for (int i=1; i<=n; ++i) visited[i] = 0;
    visited[i] = 1;

    int tmp = dfs(i);
    ans = max(tmp, ans);
  }

  fout << ans;
  return 0;
}
