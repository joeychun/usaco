#include <iostream>

using namespace std;

char dc(long long int a, long long int b, long long int n) {
  if (2*a+b < n) {
    return dc(2*a+b, b+1, n);
  } else {
    if (n <= a) {
      return dc((a-b+1)/2, b-1, n);
    } else if (n <= a+b) {
      if (n-a == 1) return 'm';
      return 'o';
    } else {
      return dc((a-b+1)/2, b-1, n-a-b);
    }
  }
}

int main() {
  long long int x;
  scanf("%lld", &x);

  char ans = dc(0,3,x);
  printf("%c", ans);
  return 0;
}
