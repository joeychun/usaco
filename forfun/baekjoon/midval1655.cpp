#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define min(a,b) (((a)<(b))?(a):(b))

using namespace std;

int n,t,m;

int main() {
  scanf("%d", &n);

  priority_queue<int> mins; // small -> big
  priority_queue<int,vector<int>,greater<int> > maxs; // big -> small

  int cnt = 0;
  for (int j=0; j<n; ++j) {
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

    if (j%2) {
      int top1 = maxs.top();
      int top2 = mins.top();
      printf("%d\n", min(top1,top2));
    }
    if (j%2 == 0) {
      int top = maxs.top();
      printf("%d\n", top);
    }
  }

  return 0;
}
