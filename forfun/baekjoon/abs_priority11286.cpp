#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

int n;

/*
bool cmp(int a, int b) {
  if (abs(a) == abs(b)) return a>b;
  return abs(a) > abs(b);
}*/

int main() {
  scanf("%d", &n);
  //priority_queue<int, vector<int>, cmp> q;
  priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > q;
  int t;
  for (int i=0; i<n; ++i) {
    scanf("%d", &t);
    if (t != 0) q.push(make_pair(abs(t),t));
    else {
      if (q.empty()) printf("0\n");
      else {
        int top = q.top().second;
        printf("%d\n", top);
        q.pop();
      }
    }
  }
}
