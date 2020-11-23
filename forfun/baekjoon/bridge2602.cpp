#include <iostream>
#include <cstring>

using namespace std;

char key[25];
int key_len;
char arr1[25];
char arr2[25];
int arr_len;
int dp[2][25][15];

int recur(int x, int y, int key_ind) {
  if (key_ind >= key_len) return 1;
  if (y >= arr_len) return 0;

  if (dp[x][y][key_ind] != -1) return dp[x][y][key_ind];

  int tmp_arr;
  if (x == 0) tmp_arr = arr1[y];
  else tmp_arr = arr2[y];
  if (tmp_arr == key[key_ind]) { // Current spot is a spot that works
    // Case of using it
    int tmp = recur(1-x,y+1,key_ind+1);

    // Case of not using
    tmp += recur(x,y+1,key_ind);

    return dp[x][y][key_ind] = tmp;
  } else {
    return dp[x][y][key_ind] = recur(x,y+1,key_ind);
  }
}

int main() {
  memset(dp, -1, sizeof(dp));

  scanf("%s", key);
  key_len = strlen(key);
  scanf("%s", arr1);
  arr_len = strlen(arr1);
  scanf("%s", arr2);

  int ans = recur(0,0,0) + recur(1,0,0);
  printf("%d", ans);
  return 0;
}
