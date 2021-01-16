#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>

using namespace std;

typedef struct {
  int t;
  int cow;
  int change;
}timestamp;

struct cmp {
  bool operator() (timestamp a, timestamp b) {
    return a.t < b.t;
  }
};

int n,g;

timestamp info[100005];

map<int,int> gal;
map<int,int, greater<int> > cnt;

int main() {
  ifstream fin ("measurement.in");
  ofstream fout ("measurement.out");
  ios::sync_with_stdio(false);

  fin >> n >> g;
  for (int i=0; i<n; ++i) {
    fin >> info[i].t >> info[i].cow >> info[i].change;
    gal[info[i].cow] = 0;
  }
  sort(info, info+n, cmp());

  cnt[0] = 100005;

  int ans = 0;
  for (int i=0; i<n; ++i) {
    int cow = info[i].cow;
    int change = info[i].change;

    bool was_max = (cnt.begin()->first == gal[cow]);

    bool was_unique = (cnt[gal[cow]] == 1);

    /* Put change */
    cnt[gal[cow]]--;
    if (cnt[gal[cow]] == 0) {
      cnt.erase(gal[cow]);
    }

    gal[cow] += change;

    cnt[gal[cow]]++;

    bool is_max = (cnt.begin()->first == gal[cow]);

    bool is_unique = (cnt[gal[cow]] == 1);


    if (was_max) {
      if (was_unique) {
        if (is_max && is_unique) {
          ans = ans;
        } else {
          ans += 1;
        }
      } else {
        ans += 1;
      }
    } else {
      if (is_max) {
        ans += 1;
      }
    }
  }

  fout << ans;

  return 0;
}
