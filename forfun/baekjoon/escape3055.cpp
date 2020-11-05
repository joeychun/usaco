/* BAEKJOON 3055 */

#include <iostream>
#include <utility>
#include <queue>
#include <vector>

using namespace std;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int r,c;
char arr[55][55];
pair<int, int> d,s; // Coord pair of where D and S is
vector<pair<int,int> > w,x; // List of coord pairs of where water and stone are

int water[55][55];
int hedge[55][55];

void water_calc() {
  /* Uses BFS to calculate how the water will spread in the array
     The minute of the water spreading to (x,y) will be stored in water[x][y] */

  // First, initializes water arr to all -1 to differentiate it from 0
  for (int i=0; i<r; ++i) {
    for (int j=0; j<c; ++j) {
      water[i][j] = -1;
    }
  }

  // Begin the BFS process
  queue<pair<int, int> > q;

  for (vector<pair<int,int> >::iterator it = w.begin(); it != w.end(); ++it) {
    pair<int,int> coord = *it;
    q.push(coord);
    water[coord.first][coord.second] = 0;
  }

  while (!q.empty()) {
    // No Break Condition given; do it until the queue is empty

    pair<int, int> front = q.front();
    int x = front.first;
    int y = front.second;

    q.pop();

    for (int i=0; i<4; ++i) {
      int new_x = x+dx[i];
      int new_y = y+dy[i];
      if (new_x < 0 || new_x >= r || new_y < 0 || new_y >= c) continue;

      if (water[new_x][new_y] == -1) {
        if (arr[new_x][new_y] != 'D' && arr[new_x][new_y] != 'X') {
          q.push(make_pair(new_x, new_y));
          water[new_x][new_y] = water[x][y] + 1;
        }
      }
    }
  }
}

void moving_calc() {
  /* Uses BFS to calculate the way of how the hedgehog will move through the map */

  // First, initializes water arr to all -1 to differentiate it from 0
  for (int i=0; i<r; ++i) {
    for (int j=0; j<c; ++j) {
      hedge[i][j] = -1;
    }
  }

  // Begin the BFS process
  queue<pair<int, int> > q;

  q.push(s);
  hedge[s.first][s.second] = 0;

  while (!q.empty()) {
    pair<int, int> front = q.front();
    int x = front.first;
    int y = front.second;

    q.pop();

    for (int i=0; i<4; ++i) {
      int new_x = x+dx[i];
      int new_y = y+dy[i];
      if (new_x < 0 || new_x >= r || new_y < 0 || new_y >= c) continue;

      if (hedge[new_x][new_y] == -1) {
        if (arr[new_x][new_y] != 'X') {
          // Compare hedgehog minute and water minute
          if (water[x][y] == -1 || hedge[x][y] + 1 < water[new_x][new_y])
          q.push(make_pair(new_x, new_y));
          hedge[new_x][new_y] = hedge[x][y] + 1;
        }
      }
    }

  }
}

int main() {
  // Input
  char inp[55];
  scanf("%d %d", &r, &c);
  for (int i=0; i<r; ++i) {
    scanf("%s", inp);
    for (int j=0; j<c; ++j) {
      arr[i][j] = inp[j];
      if (arr[i][j] == 'D') {
        d.first = i;
        d.second = j;
      } else if (arr[i][j] == 'S') {
        s.first = i;
        s.second = j;
      } else if (arr[i][j] == '*') {
        w.push_back(make_pair(i,j));
      } else if (arr[i][j] == 'X') {
        x.push_back(make_pair(i,j));
      }
    }
  }

  water_calc();
  moving_calc();

  if (hedge[d.first][d.second] == -1) {
    printf("KAKTUS");
  } else {
    printf("%d", hedge[d.first][d.second]);
  }
  return 0;
}
