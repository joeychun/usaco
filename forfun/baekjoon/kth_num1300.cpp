#include <iostream>
#include <algorithm>

/* NEED TO BE FIXED; THERE IS INCORRECT ANSWER CASES */

#define min(a,b) (((a)<(b))?(a):(b))

using namespace std;

int k,n;
int sum;
int ans;

int main() {
  scanf("%d %d", &n,&k);

  int start = 1;
  int end = k;

  int check;
  while (start < end) {
    int mid = (start+end)/2;

    // printf("\nCurrently: ");
    // printf("\n\tStart: %d, End: %d, Testing Num: %d \n", start,end,mid);

    check = 0;
    for (int i=1; i<=n; ++i) {
      check += min(mid/i, n);
    }

    if (check >= k) { // The number "mid" is too big! (or same)
      end = mid;
      // ans = mid;
    } else { // The number "mid" is too big!
      start = mid+1;
    }
    // printf("\tCheck: %d, Craving Pos: %d \n\n", check,k);
  }

  printf("%d", end);

  return 0;
}
