#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

int n,maxt;
int arr[100005];

int timetake(int k) {
  priority_queue<int, vector<int>, greater<int> > pq;
  for (int i=0; i<k; ++i) {
    pq.push(arr[i]);
  }

  int t;
  for (int i=k; i<n; ++i) {
    t = pq.top();
    pq.pop();
    pq.push(t+arr[i]);
  }

  while (!pq.empty()) {
    t = pq.top();
    pq.pop();
  }

  return t;
}

int main() {
  ifstream fin ("cowdance.in");
  ofstream fout ("cowdance.out");
  ios::sync_with_stdio(false);

  fin >> n >> maxt;
  for (int i=0; i<n; ++i) {
    fin >> arr[i];
  }

  int start = 1, end = n+5;
  int ans;
  while (start <= end) {
    int mid = (start+end)/2;
    if (timetake(mid) <= maxt) {
      // Possible; try smaller answers as well
      ans = mid;
      end = mid-1;
    } else {
      // Doesn't work; try bigger answers
      start = mid+1;
    }
  }

  fout << ans;

  return 0;
}
