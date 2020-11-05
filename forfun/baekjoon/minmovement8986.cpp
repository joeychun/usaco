#include <iostream>
#include <cmath>
#include <algorithm>

#define min(a,b) (((a)<(b))?(a):(b))

using namespace std;

long long int n;
long long int arr[100005];

long long int min_dist(int dist) {
  long long int sum = 0;
  for (long long int i=0; i<n; ++i) {
    sum += abs(dist*i - arr[i]);
  }
  return sum;
}

int main() {
  scanf("%lld", &n);
  for (long long int i=0; i<n; ++i) {
    scanf("%lld", &arr[i]);
  }
  sort(arr,arr+n);

  long long int start = 0;
  long long int end = 1000000005;
  while (start+100 < end) {
    long long int mid1 = (2*start+end)/3;
    long long int mid2 = (start+2*end)/3;
    if (min_dist(mid1) < min_dist(mid2)) {
      end = mid2;
    } else {
      start = mid1;
    }
  }

  long long int ans = 1e18;
  for (long long int i=start; i<=end; ++i) {
    ans = min(ans,min_dist(i));
  }

  printf("%lld", ans);
}
