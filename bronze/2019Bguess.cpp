#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

#define max(x,y) (((x)>(y))?(x):(y))

using namespace std;

struct Animal { // holds the information for one animal
  string name;
  int k;
  string characteristics[105];
};

int main() {
  ifstream fin;
  fin.open("guess.in");
  ofstream fout;
  fout.open("guess.out");

  // Variables
  vector<Animal> info; // vector holding all of the information of the animals
  int same_char; // amount of same characteristics of two animals
  int max_same_char = -1; // the max of same_char among all nC2 pairs

  int n;
  fin >> n;

  // Getting Inputs
  Animal tmp;
  for (int i=0; i<n; ++i) {
    fin >> tmp.name;
    fin >> tmp.k;
    for (int j=0; j<tmp.k; ++j) {
      fin >> tmp.characteristics[j];
    }
    info.push_back(tmp);
  }

  // Iterating through animals, comparing two animals
  for (vector<Animal>::iterator i = info.begin(); i != info.end(); ++i) {
    for (vector<Animal>::iterator j = i+1; j != info.end(); ++j) {
      if (i==j) continue;
      same_char = 0;
      // Compare characteristics of animals *i and *j
      Animal anim1 = *i; Animal anim2 = *j;
      for (int x=0; x<anim1.k; ++x) {
        for (int y=0; y<anim2.k; ++y) {
          if (anim1.characteristics[x].compare(anim2.characteristics[y]) == 0) {
            same_char += 1;
          }
        }
      }
      // Check if the amount of "yes"s for animals anim1 and anim2 is the max or not
      max_same_char = max(max_same_char, same_char);
    }
  }
  fout << (max_same_char + 1); // The maximum number of "yes" answers Elsie could
                               // possibly receive before she knows the right animal
                               // = the maximum amount of same characteristics
                               // that can be found among pairs of animals + 1
}
