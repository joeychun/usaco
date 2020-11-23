#include <iostream>
#include <cstring>

// 일단 포기 함, 내일 해야지 :D

#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))

using namespace std;

int n;
int arr[3005];

int dp[3005][3005][2][2];

int recur(int start, int end, int type, int player, int d) { // Acquire "type" (mod 2) game

  /*
  for (int i=0; i<d; ++i) printf("  ");

  if (type == 0) printf("recur(start=%d, end=%d, type=짝, player=%d)", start, end, player);
  if (type == 1) printf("recur(start=%d, end=%d, type=홀, player=%d)", start, end, player);
  */

  if (start == end) {
    if (player == 0)
      return (arr[start]%2 == type);
      // printf("\treturning %d...\n\n", (arr[start]%2 == type));

    else return (type == 0);
  }
  if (start + 1 == end) {
    int x = arr[start];
    int y = arr[end];
    if (player == 0) {
      if (type == 0)
        return 1;
        // printf("\treturning 1...\n\n");

      //else return (((x%2 == 0) && (y%2 == 0))?0:1);
      else {
        if (x % 2 == 0 && y % 2 == 0)
          return 0;
          // printf("\treturning 0...\n\n");

        // printf("\treturning 1...\n\n");
        return 1;
      }
    } else { /* BUG */
      if (type == 1)
        return 0;
        //printf("\treturning 0...\n\n");

      //else return (((x%2 == 0) && (y%2 == 0))?1:0);
      else {
        if (x % 2 == 0 && y % 2 == 0)
          return 1;
          // printf("\treturning 1...\n\n");

        // printf("\treturning 0...\n\n");
        return 0;
      }
    }
  }
  // printf("\n\n");

  if (dp[start][end][type][player] != -1) return dp[start][end][type][player];

  if (player == 0) {
    int case1 = recur(start+1, end, (type+arr[start])%2, 1, d+1);
    int case2 = recur(start+2, end, (type+arr[start]+arr[start+1])%2, 1, d+1);
    int case3 = recur(start, end-1, (type+arr[end])%2, 1, d+1);
    int case4 = recur(start, end-2, (type+arr[end]+arr[end-1])%2, 1, d+1);

    return dp[start][end][type][player] = max(max(case1,case2), max(case3,case4));
  } else {
    int case1 = recur(start+1, end, type, 0, d+1);
    int case2 = recur(start+2, end, type, 0, d+1);
    int case3 = recur(start, end-1, type, 0, d+1);
    int case4 = recur(start, end-2, type, 0, d+1);

    return dp[start][end][type][player] = min(min(case1,case2), min(case3,case4));
  }
}

int main() {
  memset(dp, -1, sizeof(dp));

  scanf("%d", &n);

  int tmp;
  for (int i=0; i<n; ++i) {
    scanf("%d", &tmp);
    arr[i] = tmp % 2;
  }

  char boolarr[2][15] = {"No","Yes"};
  int ans = recur(0,n-1,0,0,0);
  printf("%s", boolarr[ans]);

  return 0;
}
