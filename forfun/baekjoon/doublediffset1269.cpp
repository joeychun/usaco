#include <iostream>
#include <map>

using namespace std;

int a_ind,b_ind;
map<int,int> a,b;

int sum;

int main() {
  scanf("%d %d",&a_ind,&b_ind);
  for (int i=0; i<a_ind; ++i) {
    int t;
    scanf("%d", &t);
    a[t] = 1;
  }

  for (int i=0; i<b_ind; ++i) {
    int t;
    scanf("%d", &t);
    b[t] = 1;
  }

  for (map<int,int>::iterator it=a.begin(); it!=a.end(); ++it) {
    if (b.find(it->first) != b.end()) sum++;
  }

  int ans = a_ind + b_ind - sum - sum;
  printf("%d", ans);


  return 0;
}
