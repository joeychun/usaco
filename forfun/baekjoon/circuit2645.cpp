#include <iostream>
#include <utility>
#include <cstring>
#include <queue>

#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))

using namespace std;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};


int n;
pair<int,int> a;
pair<int,int> b;

int k;

int x;

int arr[55][55];
int price[55][55]; // The most optimized price for going to grid i,j

void bfs() {
  queue<pair<int,int> > q;
  q.push(a);
  price[a.first][a.second] = 1;

  while (!q.empty()) {
    pair<int, int> front = q.front();
    int x = front.first;
    int y = front.second;

    q.pop();

    for (int i=0; i<4; ++i) {
      int new_x = x+dx[i];
      int new_y = y+dy[i];
      if (1 <= new_x && new_x <= n && 1 <= new_y && new_y <= n) {
        int new_price = price[x][y];
        if (arr[new_x][new_y] != 0) new_price += arr[new_x][new_y];
        else new_price += 1;
        if (price[new_x][new_y] == -1 || new_price < price[new_x][new_y]) {
          // if (arr[new_x][new_y] != 0) price[new_x][new_y] = price[x][y]+arr[new_x][new_y];
          // else price[new_x][new_y] = price[x][y]+1;
          price[new_x][new_y] = new_price;
          q.push(make_pair(new_x,new_y));
        }
      }
    }
  }

}

int main() {
  memset(price,-1,sizeof(price));
  scanf("%d", &n);
  scanf("%d %d %d %d", &a.first,&a.second,&b.first,&b.second);
  scanf("%d", &k);

  scanf("%d", &x);
  for (int i=0; i<x; ++i) {
    int t;
    scanf("%d", &t);
    pair<int,int> prev;
    pair<int,int> cur;

    int a,b;
    for (int j=0; j<t; ++j) {
      scanf("%d %d", &a, &b);
      if (j==0) {
        cur.first = a;
        cur.second = b;
      } else{
        prev.first = cur.first;
        prev.second = cur.second;
        cur.first = a;
        cur.second = b;

        // All grids between prev and cur need an increase!
        if (prev.first == cur.first) {
          if (prev.second < cur.second) {
            for (int l=prev.second; l<cur.second; ++l) {
              arr[prev.first][l] += k;
            }
            if (j==t-1) {
              arr[prev.first][cur.second] += k;
            }
          } else {
            for (int l=prev.second; l>cur.second; --l) {
              arr[prev.first][l] += k;
            }
            if (j==t-1) {
              arr[prev.first][cur.second] += k;
            }
          }

        } else if (prev.second == cur.second) {
          if (prev.first < cur.first) {
            for (int l=prev.first; l<cur.first; ++l) {
              arr[l][prev.second] += k;
            }
            if (j==t-1) {
              arr[cur.first][prev.second] += k;
            }
          } else {
            for (int l=prev.first; l>cur.first; --l) {
              arr[l][prev.second] += k;
            }
            if (j==t-1) {
              arr[cur.first][prev.second] += k;
            }
          }
        }
      }

    }
  }

  bfs();
  int ans = price[b.first][b.second];
  printf("%d", ans);

  return 0;
}
