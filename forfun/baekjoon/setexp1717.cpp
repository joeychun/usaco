#include <iostream>

using namespace std;

int n,m;
int arr[1000005];

int setnum(int i) {
  if (i == arr[i]) return i;
  arr[i] = setnum(arr[i]);
  return arr[i];
}

int main() {
  char msg[2][100] = {"NO","YES"};

  scanf("%d %d", &n, &m);
  for (int i=0; i<=n; ++i) {
    arr[i] = i;
  }

  int t,a,b;
  for (int i=0; i<m; ++i) {
    scanf("%d %d %d", &t, &a, &b);
    if (t == 0) {
      int setnum_a = setnum(a);
      int setnum_b = setnum(b);
      arr[setnum_b] = arr[setnum_a];
    } else {
      int setnum_a = setnum(a);
      int setnum_b = setnum(b);
      printf("%s\n", msg[setnum_a==setnum_b]);
    }
  }
  return 0;
}
