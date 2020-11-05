#include <iostream>
#include <utility>
#include <string>
#include <stack>

using namespace std;

int k;
string s;

void dfs(int ind1, int ind2) {
  /* DFS where the order 1,2,3,4 turns into 3,4,1,2 */

  if (ind1 + 1 == ind2) {
    cout << s[ind1];
    return;
  }

  int cur_ind = 0;
  int index[4] = {0,0,0,0};

  int count = 0;
  int cur = 0;
  int add_amount = 0;
  for (int i=ind1+1; i<ind2; ++i) {
    if (cur == add_amount) {
      index[cur_ind] = i;
      cur_ind++;

      cur = -1;
      add_amount = 0;
    }

    cur++;
    if (s[i] == 'x') add_amount += 4;
  }

  cout << "x";
  dfs(index[2],index[3]);
  dfs(index[3],ind2);
  dfs(index[0],index[1]);
  dfs(index[1],index[2]);
}


int main() {
  cin >> k;
  for (int i=0; i<k; ++i) {
    cin >> s;
    dfs(0, s.length());
    cout << "\n";
  }
  return 0;
}
