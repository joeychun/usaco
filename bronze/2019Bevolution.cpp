#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  ifstream fin;
  fin.open("evolution.in");
  ofstream fout;
  fout.open("evolution.out");

  // Getting inputs
  int n;
  fin >> n;

  // Holding vector of cows for each superpower
  map< string, vector<int> > powered_cows;

  int k;
  string s;
  for (int i=0; i<n; ++i) {
    fin >> k;
    for (int j=0; j<k; ++j) {
      fin >> s;
      map< string, vector<int> >::iterator it = powered_cows.find(s);
      if(it == powered_cows.end()) { // Key-value pair not present in map
        vector<int> empty_vect; // Make new empty vector for this superpower
        powered_cows.insert(pair< string, vector<int> >(s,empty_vect));
      }
      powered_cows[s].push_back(i);
    }
  }

  // Iterate through map, Compare different superpower cow-vectors
  for (map< string, vector<int> >::iterator pow1 = powered_cows.begin(); pow1 != powered_cows.end(); ++pow1) {
    for (map< string, vector<int> >::iterator pow2 = pow1; pow2 != powered_cows.end(); ++pow2) {
      if (pow1 == pow2) continue;

      // If there are OVERLAPS and NON-OVERLAPS, this evolution tree cannot form
      vector<int> cows1 = pow1->second;
      vector<int> cows2 = pow2->second;

      // Check OVERLAPS
      vector<int> overlaps;
      for (vector<int>::iterator i1 = cows1.begin(); i1 != cows1.end(); ++i1) {
        for (vector<int>::iterator i2 = cows2.begin(); i2 != cows2.end(); ++i2) {
          if (*i1 == *i2) overlaps.push_back(*i1);
        }
      }

      if (overlaps.size() == 0) continue;

      // Checks NON-OVERLAPS
      if (!((overlaps.size() == cows1.size()) || (overlaps.size() == cows2.size()))) {
        // Cannot form evolution tree
        fout << "no";
        return 0;
      }
      // Continue this checking process; if there are no "no"s found, give out "yes"
    }
  }
  fout << "yes";
  return 0;
}
