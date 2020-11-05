#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <stack>
#include <cstring>

using namespace std;


/* A CASE THAT DOES NOT WORK: (CLOSED ISSUE)

9
4 2
6 1
6 5
2 7
7 8
5 9


My answer: 3 4 6 1 2 5 7 8 9
Correct  : 3 4 6 1 2 5 7 9 8

I suspect the topological is okay, but the lexicographical part has bug

THIS ISSUE IS FIXED
*/

int n;
int adj[105][105]; // If adj[a][b] is 1, a->b exists
int deg[105];

vector<int> ans;
int ans_used[105];

queue<pair<int,int> > q;
priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;


int in_stack[105];

/*
int dfs_cycle(int x) {
  // Return 1 if a cycle exists with node x as root //
  // Return 0 if not //
  stack<int> s;

  in_stack[x] = 1;
  s.push(x);
  int loop_cnt = 0;
  while (!s.empty()) {
    printf("loop cnt: %d\n", ++loop_cnt);
    int top = s.top();

    s.pop();
    in_stack[top] = 0;

    for (int i=1; i<=n; ++i) {
      if (adj[top][i]) {
        if (in_stack[i]) return 1;
        in_stack[i] = 1;
        s.push(i);
      }
    }
  }

  return 0;
}
*/

int dfs_cycle(int x) {
  int is_cyc = 0;

  in_stack[x] = 1;
  for (int i=1; i<=n; ++i) {
    if (adj[x][i]) {
      if (in_stack[i]) return 1;
      is_cyc = is_cyc || dfs_cycle(i);
    }
  }

  in_stack[x] = 0;
  return is_cyc;
}

int check_cycle() {
  for (int i=1; i<=n; ++i) {
    if (dfs_cycle(i)) {
      return 1;
    }
  }
  return 0;
}

void bfs() {
  int f = 0; // Phase number

  int new_first = 1;
  for (int i=1; i<=n; ++i) {
    if (deg[i] == 0) {
      q.push(make_pair(new_first,i));
      new_first++;
    }
  }

  int q_cnt = q.size();
  while (!q.empty()) {
    pair<int,int> front = q.front();

    q.pop();
    //ans_used[front.second] = 1;
    pq.push(make_pair(f,front.second));

    for (int i=1; i<=n; ++i) {
      if (adj[front.second][i]) {
        deg[i]--;
        if (deg[i] == 0) {
          q.push(make_pair(new_first,i));
          new_first++;
        }
      }
    }

    if (front.first == q_cnt) {
      f++;
      q_cnt += q.size();
    } /*else if (front.first == q_cnt + 1) {
      q_cnt += q.size();
    }*/

  }
}

int main() {
  cin >> n;

  char a,b;
  int x,y;

  // Fill in adj 2d array, as well as initiating degrees
  while (cin >> x >> y) {
    // scanf(" %c %c", &a, &b);
    // x = a-'0';
    // y = b-'0';
    if (x == -1 && y == -1) break;
    adj[x][y] = 1;
    deg[y]++;
  }

  if (check_cycle()) {
    printf("impossible");
    return 0;
  }

  bfs();

  /*
  for (int i=1; i<=n; ++i) {
    if (!ans_used[i]) {
      printf("impossible");
      return 0;
    }
  }*/



  /*
  for (vector<int>::iterator it=ans.begin(); it!=ans.end(); ++it) {
    printf("%d ", (*it));
  }*/

  vector<int> temp[100];
  int temp_ind = 0;

  while (!pq.empty()) {
    int top = pq.top().second;
    int phase = pq.top().first;
    printf("%d ",top);
    temp[phase].push_back(top);
    temp_ind = phase;

    pq.pop();
  }

  /*
  printf("\n\n");
  for (int i=0; i<=temp_ind; ++i) {
    printf("PHASE %d => ", i);
    for (vector<int>::iterator j=temp[i].begin(); j!=temp[i].end(); ++j) {
      printf("%d ", (*j));
    }
    printf("\n");
  }
  */

  return 0;
}
