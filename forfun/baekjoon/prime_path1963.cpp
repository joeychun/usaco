/* BAEKJOON 1963 */

#include <iostream>
#include <utility>
#include <queue>
#include <vector>

using namespace std;

int n;
int s,e;

int p[10005];

int visited[10005];

void prime_check() {
  /* Makes the array p a prime number checker */
  int is_prime = 1;
  for (int i=1000; i<=9999; ++i) {
    is_prime = 1;
    // Checking if i is prime
    for (int j=2; j<i; ++j) {
      if (i%j == 0) {
        is_prime = 0;
        break;
      }
    }

    if (is_prime) {
      p[i] = 1;
    }
  }
}

vector<int> adj_nums(int num, int dist) {
  /* Returns numbers that are prime and can be made by changing one digit
     Return form is in vector of ints */
  vector<int> adjs;

  int th = num/1000;
  int hu = (num%1000)/100;
  int te = (num%100)/10;
  int on = num%10;

  int new_num;
  // Change thousands digit
  for (int i=1; i<10; ++i) {
    if (i == th) continue;
    new_num = i*1000 + hu*100 + te*10 + on;
    if (p[new_num] && (visited[new_num] == -1 || dist+1 < visited[new_num])) adjs.push_back(new_num);
  }

  // Change hundreds digit
  for (int i=0; i<10; ++i) {
    if (i == hu) continue;
    new_num = th*1000 + i*100 + te*10 + on;
    if (p[new_num] && (visited[new_num] == -1 || dist+1 < visited[new_num])) adjs.push_back(new_num);
  }

  // Change tens digit
  for (int i=0; i<10; ++i) {
    if (i == te) continue;
    new_num = th*1000 + hu*100 + i*10 + on;
    if (p[new_num] && (visited[new_num] == -1 || dist+1 < visited[new_num])) adjs.push_back(new_num);
  }

  // Change ones digit
  for (int i=0; i<10; ++i) {
    if (i == on) continue;
    new_num = th*1000 + hu*100 + te*10 + i;
    if (p[new_num] && (visited[new_num] == -1 || dist+1 < visited[new_num])) adjs.push_back(new_num);
  }

  return adjs;
}

void bfs(int s, int e) {
  // First, initializes visited arr to all -1 to differentiate it from 0
  for (int i=0; i<10005; ++i) {
    visited[i] = -1;
  }

  // Begin the BFS process
  queue<pair<int, int> >q;
  q.push(make_pair(s,0));
  visited[s] = 0;

  while (!q.empty()) {
    pair<int, int> front = q.front();
    int num = front.first;
    int dist = front.second;

    if (num == e) break;

    q.pop();

    vector<int> adjs = adj_nums(num, dist);
    for (vector<int>::iterator it = adjs.begin(); it != adjs.end(); ++it) {
      int new_num = *it;
      visited[new_num] = dist+1;
      q.push(make_pair(new_num,dist+1));
    }
  }
}

int main() {
  prime_check();
  scanf("%d", &n);
  for (int i=0; i<n; ++i) {
    scanf("%d %d", &s, &e);
    bfs(s,e);
    if (visited[e] == -1) {
      printf("Impossible\n");
    } else {
      printf("%d\n", visited[e]);
    }
  }

  return 0;
}
