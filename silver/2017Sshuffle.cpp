#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int n;
int arr[100005];

int visited[100005];
int inStack[100005];

int until = 0;
int cnt = 1;

int dfs(int i) {
  // Check if instack or visited
  if (inStack[i] > until) {
    return (cnt - inStack[i]);
  } else if (visited[i]) {
    return 0;
  }

  // If not...
  visited[i] = 1;
  inStack[i] = cnt;
  cnt++;

  return dfs(arr[i]);
}

int main() {
  ifstream fin ("shuffle.in");
  ofstream fout ("shuffle.out");
  ios::sync_with_stdio(false);

  fin >> n;
  for (int i=1; i<=n; ++i) {
    fin >> arr[i];
  }

  int ans = 0;
  for (int i=1; i<=n; ++i) {
    if (!visited[i]) {
      // Check for cycle; dfs
      until = cnt - 1;
      ans += dfs(i);
    }
  }

  fout << ans;
  return 0;
}
