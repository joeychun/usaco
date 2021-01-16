#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int n,k;
vector<int> hays;

int possible(int r) {
  vector<int>::iterator it = hays.begin();
  for (int i=0; i<k; ++i) {
    if (it == hays.end()) break;
    int val = (*it) + 2*r + 1;
    it = lower_bound(hays.begin(), hays.end(), val);
  }

  return it == hays.end();
}

int main() {
  ifstream fin ("angry.in");
  ofstream fout ("angry.out");
  ios::sync_with_stdio(false);

  fin >> n >> k;
  int tmp;
  for (int i=0; i<n; ++i) {
    fin >> tmp;
    hays.push_back(tmp);
  }
  sort(hays.begin(), hays.end());

  int start = 1, end = (1e9) + 5;
  int ans;
  while (start <= end) {
    int mid = (start+end)/2;
    if (possible(mid)) {
      // Possible, now try smaller radius as well
      ans = mid;
      end = mid - 1;
    } else {
      // Doesn't work, so try bigger radius
      start = mid + 1;
    }
  }

  fout << ans;
  return 0;
}
