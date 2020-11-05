#include <iostream>
#include <algorithm>

using namespace std;

int n,m;
int choices[10];
int arr[10];

bool check[10];

void numSeq(int depth) {
  if (depth == m) {
    // print arr[10]
    for (int i=0; i<depth; ++i) {
      printf("%d ", arr[i]);
    }
    printf("\n");
    return;
  }
  int prev = -1;
  for (int i=0; i<n; ++i) {
    if (check[i] == 0 && prev != choices[i]) {
      arr[depth] = choices[i];
      prev = choices[i];
      check[i] = 1;
      numSeq(depth+1);
      check[i] = 0;
    }
  }

}

int main() {
  scanf("%d %d", &n,&m);
  int val;
  for (int i=0; i<n; ++i) {
    scanf("%d", &val);
    choices[i] = val;
  }
  sort(choices,choices+n);
  numSeq(0);
  return 0;
}
