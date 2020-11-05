// Make two arrays. arr1[i][j] will be the pizza slice amount when sliced clockwise from piece i to j
// Same for arr2[i][j] for second pizza
// Go through iteration for arr 1. Inside that loop, nest another loop that iterates through arr2
// If arr1[i][j] + arr2[x][y] == (wanted number), add to sum
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int size,m,n;
int t;
int pizz1[1005];
int pizz2[1005];
int pizz1_tot,pizz2_tot;

// int pizz1_calc[1005][1005];
// int pizz2_calc[1005][1005];
vector<int> pizz1_calc;
vector<int> pizz2_calc;

int sum;
int ans;

int main() {
  scanf("%d", &size);
  scanf("%d %d", &m, &n);
  for (int i=0; i<m; ++i) {
    scanf("%d", &t);
    pizz1[i] = t;
    pizz1_tot += t;
  }
  for (int i=0; i<n; ++i) {
    scanf("%d", &t);
    pizz2[i] = t;
    pizz2_tot += t;
  }

  int a,b;
  for (int i=0; i<m; ++i) {
    sum = 0;
    for (int j=i; j<m+i; ++j) {
      a = i%m;
      b = j%m;
      sum += pizz1[b];
      if (sum == pizz1_tot && i != 0) continue;
      // pizz1_calc[a][b] = sum;
      pizz1_calc.push_back(sum);
    }
  }

  for (int i=0; i<n; ++i) {
    sum = 0;
    for (int j=i; j<n+i; ++j) {
      a = i%n;
      b = j%n;
      sum += pizz2[b];
      if (sum == pizz2_tot && i != 0) continue;
      // pizz2_calc[a][b] = sum;
      pizz2_calc.push_back(sum);
    }
  }
  pizz1_calc.push_back(0);
  pizz2_calc.push_back(0);

  sort(pizz1_calc.begin(),pizz1_calc.end());
  sort(pizz2_calc.begin(),pizz2_calc.end());


  for (vector<int>::iterator it=pizz1_calc.begin(); it!=pizz1_calc.end(); ++it) {
    printf("%d ", *it);
  }
  printf("\n\n");
  for (vector<int>::iterator it=pizz2_calc.begin(); it!=pizz2_calc.end(); ++it) {
    printf("%d ", *it);
  }
  printf("\n\n");

  // Instead of this, make values of pizz1_calc and pizz2_calc inside a vector.
  // Sort them, then use upper_bound - lower_bound to find the amount of numbers that would sum up to "size"
  int pizz1_tot_cov = 0, pizz2_tot_cov = 0;
  for (vector<int>::iterator it=pizz1_calc.begin(); it!=pizz1_calc.end(); ++it) {
    int desired = size - (*it);
    // if (pizz1_tot == *it || pizz2_tot = desired) continue;
    /*
    if (pizz1_tot == *it) {
      if (pizz1_tot_cov == 0) pizz1_tot_cov = 1;
      else continue;
    }
    if (pizz2_tot == desired) {
      if (pizz2_tot_cov == 0) pizz2_tot_cov = 1;
      else continue;
    }*/
    vector<int>::iterator lower_val = lower_bound(pizz2_calc.begin(),pizz2_calc.end(),desired);
    vector<int>::iterator upper_val = upper_bound(pizz2_calc.begin(),pizz2_calc.end(),desired);
    ans += (upper_val-lower_val);
  }

  printf("%d", ans);
  return 0;
}
