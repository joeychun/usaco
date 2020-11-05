#include <iostream>
#include <algorithm>

using namespace std;

int k,n;
int arr[10005];
int sum;

int cust(int a, int b){return a > b;}

int check(int val) {
  int sum = 0;
  for (int i=0; i<k; ++i) {
    sum += arr[i]/val;
  }
  if (sum >= n) return 1;
  return 0;
}

int binsearch(int start, int end) {
  int mid = (start+end)/2;

  if (start == end) {
    return start;
  }

  int does_work = check(mid);
  if (does_work) {
    return binsearch(mid,end);
  } else {
    return binsearch(start,mid-1);
  }
}

int main() {
  scanf("%d %d", &k,&n);
  for (int i=0; i<k; ++i) {
    scanf("%d", &arr[i]);
    sum += arr[i];
  }
  int try_min = 0;
  int try_max = sum/n + 1;
  sort(arr,arr+k,cust);

  int ans = binsearch(try_min,try_max);

  printf("%d", ans);

  return 0;
}
