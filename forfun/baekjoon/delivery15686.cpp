#include <iostream>
#include <utility>

#define MIN(a,b) (((a)<(b))?(a):(b))

using namespace std;

int n,m;
int arr[55][55];

int checking;

pair<int,int> house[105];
int house_ind;
pair<int,int> chicken[20];
int chicken_ind;
int visited[20]; // Check if chicken place node was visited

int mins[105];
int preserved[105];

int dist[105][20]; // house and chicken place distance

int ans = 987654321;


void move(int a[], int b[]) {
  for (int i=0; i<house_ind; ++i) {
    b[i] = a[i];
  }
}

int absolute(int x) {
  if (x >= 0) return x;
  return x * (-1);
}

void mins_init() {
  for (int i=0; i<house_ind; ++i) {
    mins[i] = 100000;
  }
}

void dist_init(int x, int y) {
  for (int i=0; i<house_ind; ++i) {
    for (int j=0; j<chicken_ind; ++j) {
      int x1 = house[i].first;
      int y1 = house[i].second;
      int x2 = chicken[j].first;
      int y2 = chicken[j].second;
      dist[i][j] = absolute(x1-x2) + absolute(y1-y2);
    }
  }/*
  int x1 = house[i].first;
  int y1 = house[i].second;
  int x2 = chicken[j].first;
  int y2 = chicken[j].second;
  int dist = absolute(x1-x2) + absolute(y1-y2);
  return dist;*/
}

void dfs(int amount, int start) {
  // if (i > m) return;
  /*printf("dfs(i=%d, start=%d)", i, start);
  for (int x=0; x<chicken_ind; ++x) {
    printf("%d ",visited[x]);
  }
  printf("\n");*/
  if (amount == m) {
    checking++;
    // All Chicken Places determined
    int sum=0;
    for (int i=0; i<house_ind; ++i) {
      int min_dist = 987654321;
      for (int j=0; j<chicken_ind; ++j) {
        if (visited[j]) min_dist = MIN(min_dist,dist[i][j]);
      }
      sum += min_dist;
    }

    ans = MIN(ans,sum);
    return;
  } else if (amount > m || start == chicken_ind) {
    return;
  }
  /*
  for (int i=start; i<chicken_ind; ++i) {
    if (!visited[i]) {
      visited[i] = 1;
      dfs(amount+1,start+i-start+1);
      visited[i] = 0;

      //dfs(amount,start+1);
    }
  }*/
  visited[start] = 1;
  dfs(amount+1, start+1);
  visited[start] = 0;

  dfs(amount,start+1);
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i=0; i<n; ++i) {
    for (int j=0; j<n; ++j) {
      scanf("%d", &arr[i][j]);
      if (arr[i][j] == 1) {
        house[house_ind] = make_pair(i,j);
        house_ind++;
      } else if (arr[i][j] == 2) {
        chicken[chicken_ind] = make_pair(i,j);
        chicken_ind++;
      }
    }
  }

  // mins_init();
  dist_init(0,0);

  dfs(0,0);
  printf("%d", ans);
  // printf("\ni==m called %d times\n", checking);
  return 0;
}
