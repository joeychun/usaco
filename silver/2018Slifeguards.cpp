#include <iostream>
#include <fstream>
#include <set>
#include <vector>
#include <algorithm>
#include <utility>

#define min(a,b) (((a)<(b))?(a):(b))

using namespace std;

typedef struct {
  int t;
  int element;
  int isInsert;
}sched;

struct cmp {
  bool operator() (sched a, sched b) {
    if (a.t == b.t) {
      return a.isInsert > b.isInsert;
    }
    return a.t < b.t;
  }
};

int n;
vector<sched> times;
set<int> s;

int exclusives[100005];

int main() {
  ifstream fin ("lifeguards.in");
  ofstream fout ("lifeguards.out");
  ios::sync_with_stdio(false);

  fin >> n;
  int a,b;
  sched tmp;
  for (int i=0; i<n; ++i) {
    fin >> a >> b;
    tmp.t = a; tmp.element = i+1; tmp.isInsert = 1;
    times.push_back(tmp);
    tmp.t = b; tmp.element = i+1; tmp.isInsert = 0;
    times.push_back(tmp);
  }
  sort(times.begin(), times.end(), cmp());

  int nocow = -1, nocow_s = 0;
  int ele = -1;
  for (vector<sched>::iterator it=times.begin(); it!=times.end(); ++it) {
    tmp = (*it);
    if (tmp.isInsert) {
      s.insert(tmp.element);
    } else {
      s.erase(tmp.element);
    }

    // Check if alone sched from previous has ended
    if (ele != -1) {
      exclusives[ele] = tmp.t - exclusives[ele];
    }

    // Check alone sched for now
    if (s.size() == 1) {
      // If there is alone sched
      ele = *(s.begin());
      exclusives[ele] = tmp.t;
    } else {
      ele = -1;
    }


    // Check if no sched from previous has ended
    if (nocow != -1) {
      nocow = tmp.t - nocow;
      nocow_s += nocow;
      nocow = -1;
    }

    // Check no cow sched
    if (s.size() == 0) {
      nocow = tmp.t;
    } else {
      nocow = -1;
    }
  }



  int total_t = (times.back().t - times.front().t) - nocow_s;

  int minval = exclusives[1];
  for (int i=1; i<=n; ++i) {
    minval = min(exclusives[i], minval);
  }

  int ans = total_t - minval;
  fout << ans;
  return 0;
}
