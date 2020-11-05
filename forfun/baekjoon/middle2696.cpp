#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int n,t,m;

int main() {
  scanf("%d", &n);

  for (int i=0; i<n; ++i) {
    scanf("%d", &t);
    printf("%d\n", (t/2 + 1));

    priority_queue<int> mins; // small -> big
    priority_queue<int,vector<int>,greater<int> > maxs; // big -> small

    int cnt = 0;
    for (int j=0; j<t; ++j) {
      scanf("%d", &m);
      if (mins.size() == maxs.size()) {
        maxs.push(m);
      } else {
        mins.push(m);
      }

      if (!mins.empty() && !maxs.empty() && mins.top() > maxs.top()) {
        int temp1 = mins.top();
        int temp2 = maxs.top();
        mins.pop();
        maxs.pop();
        mins.push(temp2);
        maxs.push(temp1);
      }

      if (j%2 == 0) {
        int top = maxs.top();
        printf("%d ", top);
        cnt++;
        if (cnt == 10) {
          cnt = 0;
          printf("\n");
        }
      }
    }
    printf("\n");
  }

  return 0;
}
