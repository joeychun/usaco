#include <iostream>
#include <utility>

#define INF 2147483647
#define min(a,b) (((a)<(b))?(a):(b))

using namespace std;

int n;
pair<long long int, long long int> arr[1000];
long long int dp[1000][1000];

/*
int two_multiply(pair<int,int> a, pair<int,int> b) {
  if (a.first == b.first) return a.first * a.second * b.second;
  if (a.first == b.second) return a.first * a.second * b.first;
  if (a.second == b.first) return a.first * a.second * b.second;
  if (a.second == b.second) return a.first * a.second * b.first;
}*/

/*
long long int recur(int i, int j) {
  if (i == j) return dp[i][j] = 0;
  if (dp[i][j] != INF) return dp[i][j];

  for (int k=i; k<j; ++k) { // Dividing point
    //dp[i][j] = min(dp[i][k] + dp[k+1][j] + (arr[i].first) * (arr[k].second) * (arr[j].second), dp[i][j]);
    dp[i][j] = min(recur(i,k) + recur(k+1,j) + (arr[i].first) * (arr[k].second) * (arr[j].second), dp[i][j]);
  }
  return dp[i][j];
}*/

int main() {
  scanf("%d", &n);
  for (int i=0; i<n; ++i) {
    scanf("%lld %lld", &arr[i].first, &arr[i].second);
  }

  for (int i=0; i<n; ++i) {
    for (int j=0; j<n; ++j) {
      if (i == j) dp[i][j] = 0;
      else dp[i][j] = INF;
    }
  }

  for (int i=0; i<n; ++i) { // Starting point
    for (int j=i+1; j<n; ++j) { // Ending point
      for (int k=i; k<j; ++k) { // Dividing point
        dp[i][j] = min(dp[i][k] + dp[k+1][j] + (arr[i].first) * (arr[k].second) * (arr[j].second), dp[i][j]);
      }
    }
  }

  //long long int ans = recur(0,n-1);
  long long int ans = dp[0][n-1];
  printf("%lld", ans);

  return 0;
}
