#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <utility>

using namespace std;

typedef pair<int,int> pii;

int n,q,k;
vector<pii> adj[5005];

bool visited[5005];

int dfs(int i) {
  int returnval = 1;
  for (vector<pii>::iterator it=adj[i].begin(); it!=adj[i].end(); ++it) {
    if (it->second >= k && !visited[it->first]) {
      visited[it->first] = 1;
      returnval += dfs(it->first);
    }
  }

  return returnval;
}

int main() {
  ifstream fin ("mootube.in");
  ofstream fout ("mootube.out");
  ios::sync_with_stdio(false);

  fin >> n >> q;
  int a,b,c;
  for (int i=0; i<n-1; ++i) {
    fin >> a >> b >> c;
    adj[a].push_back(make_pair(b,c));
    adj[b].push_back(make_pair(a,c));
  }

  int v;
  for (int i=0; i<q; ++i) {
    fin >> k >> v;
    memset(visited, 0, sizeof(visited));

    visited[v] = 1;
    fout << (dfs(v) - 1) << endl;
  }

  return 0;
}
