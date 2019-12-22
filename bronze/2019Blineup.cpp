#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> cow_list;
vector<string> constraints_a;
vector<string> constraints_b;


int search(string s) {
  for (int i=0; i<8; ++i) {
    if (cow_list[i] == s) return i; // Return where cow s is at
  }
  return -1;
}

bool satisfy(int n) {
  for (int i=0; i<n; ++i){
    // Checking if it's next to or not
    if (abs(search(constraints_a[i]) - search(constraints_b[i])) != 1) return false;
  }
  return true;
}

int main() {
  ifstream ifs;
  ifs.open("lineup.in");
  ofstream ofs;
  ofs.open("lineup.out");

  // Initialize cow_list
  cow_list.push_back("Beatrice");
  cow_list.push_back("Belinda");
  cow_list.push_back("Bella");
  cow_list.push_back("Bessie");
  cow_list.push_back("Betsy");
  cow_list.push_back("Blue");
  cow_list.push_back("Buttercup");
  cow_list.push_back("Sue");

  // Scanning
  int n;
  ifs >> n;

  string a,b;
  string t;
  for (int i=0; i<n; ++i) {
    ifs >> a >> t >> t >> t >> t >> b;
    constraints_a.push_back(a);
    constraints_b.push_back(b);
  }

  // Checking if it satisfies all constraints
  do {
    if (satisfy(n)) {
      for (int i=0; i<8; i++) ofs << cow_list[i] << "\n";
      break;
    }
  } while (next_permutation(cow_list.begin(), cow_list.end()));
}
