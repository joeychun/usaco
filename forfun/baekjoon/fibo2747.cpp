#include <iostream>
#include <vector>

using namespace std;

long long int n;

/* Method 1: 1, 1 will always repeat
vector<int> v;

long long int cycle;

void cycle_init() {
  long long int prev = 1;
  long long int cur = 2;

  do {
    cycle++;

    v.push_back((v[prev] + v[cur])%1000000);

    prev++; cur++;

  } while(!(v[prev] == 1 && v[cur] == 1));
}

int fib(long long int x) {
  return v[x%cycle];
}

int main() {
  v.push_back(0);
  v.push_back(1);
  v.push_back(1);
  cin >> n;

  cycle_init();

  int ans = fib(n);
  printf("%d", ans);

  return 0;
}
*/

/* Method 2: D & C (log n method using matrix multiplication) */
// fib(n) = [1 1]^n
//          [1 0]

typedef struct Two_by_Two_Matrix {
  long long int vals[2][2];
}matrix;

matrix multiplication(matrix a, matrix b) {
  matrix new_matrix;
  new_matrix.vals[0][0] = (a.vals[0][0]*b.vals[0][0]) + (a.vals[0][1]*b.vals[1][0]);
  new_matrix.vals[0][1] = (a.vals[0][0]*b.vals[0][1]) + (a.vals[0][1]*b.vals[1][1]);
  new_matrix.vals[1][0] = (a.vals[1][0]*b.vals[0][0]) + (a.vals[1][1]*b.vals[1][0]);
  new_matrix.vals[1][1] = (a.vals[1][0]*b.vals[0][1]) + (a.vals[1][1]*b.vals[1][1]);

  for (int i=0; i<2; ++i) {
    for (int j=0; j<2; ++j) {
      new_matrix.vals[i][j] = new_matrix.vals[i][j] % 1000000;
    }
  }

  return new_matrix;
}

matrix matrix_exp(long long int x) {
  if (x == 1) {
    matrix new_matrix;
    new_matrix.vals[0][0] = 1;
    new_matrix.vals[0][1] = 1;
    new_matrix.vals[1][0] = 1;
    new_matrix.vals[1][1] = 0;

    return new_matrix;
  }

  if (x%2 == 0) {
    matrix tmp = matrix_exp(x/2);
    return multiplication(tmp,tmp);
  } else {
    matrix tmp = matrix_exp(x/2);
    return multiplication(matrix_exp(1), multiplication(tmp,tmp));
  }

}

int main() {
  scanf("%lld", &n);

  matrix ans_matrix = matrix_exp(n);
  int ans = ans_matrix.vals[0][1];

  printf("%d", ans);

  return 0;
}
