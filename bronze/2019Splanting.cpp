#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void range(vector<int>& v, int n) {
  for (int i=0; i<n; ++i) {
    v.push_back(i);
  }
}

int main() {
  ifstream fin;
  fin.open("planting.in");
  ofstream fout;
  fout.open("planting.out");

  int n;
  fin >> n;

  vector<int> adjList[n+1];
  int assignedColor[n+1];
  assignedColor[1] = 0;
  int color_amount = 1;

  int field1, field2;
  for (int i=0; i<n-1; ++i) {
    fin >> field1 >> field2;
    adjList[field1].push_back(field2);
    adjList[field2].push_back(field1);
  }

  vector<int> vect;
  for (int i=2; i<=n; ++i) {
    vect = adjList[i];
    vector<int> nexts;
    vector<int> colors;
    range(colors, color_amount);
    for (vector<int>::iterator j=vect.begin(); j!=vect.end(); ++j) {
      // Adjacents
      if (*j < i) {
        vector<int>::iterator pos = find(nexts.begin(), nexts.end(), *j);
        if (pos == nexts.end()) { // == nexts.end() means the element was not found
          nexts.push_back(*j);
        }
      }
      for (vector<int>::iterator k=adjList[*j].begin(); k!=adjList[*j].end(); ++k) {
        // Next-adjacents
        if (*k < i) {
          vector<int>::iterator pos = find(nexts.begin(), nexts.end(), *k);
          if (pos == nexts.end()) { // == nexts.end() means the element was not found
            nexts.push_back(*k);
          }
        }
      }
    }
    for (vector<int>::iterator l=nexts.begin(); l!=nexts.end(); ++l) {
      // Cannot be assignedColor[*l]s
      vector<int>::iterator pos = find(colors.begin(), colors.end(), assignedColor[*l]);
      if (pos != colors.end()) { // == colors.end() means the element was not found
        colors.erase(pos);
      }
    }
    if (colors.size() == 0) {
      assignedColor[i] = color_amount;
      color_amount++;
    } else {
      assignedColor[i] = colors[0];
    }
  }
  fout << color_amount;
}
