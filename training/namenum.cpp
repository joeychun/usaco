/*
ID: joey.s.1
LANG: C++
TASK: namenum
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

char id_convert[26] = {'2','2','2','3','3','3','4','4','4','5','5','5','6','6','6','7','N','7','7','8','8','8','9','9','9','N'};

string name_to_id(string name) {
  string id = "";
  for (int i=0; i<name.length(); ++i) {
    if (id_convert[name[i]-'A'] == 'N') return "";
    else id += id_convert[name[i]-'A'];
  }
  return id;
}

int main() {
  ifstream fin ("namenum.in");
  ofstream fout ("namenum.out");
  ifstream dict ("dict.txt");

  string input_id;
  fin >> input_id;

  bool no_name = true;
  string name;
  while (dict >> name) {
    if (name_to_id(name) == input_id) {
      fout << name << endl;
      no_name = false;
    }
  }
  if (no_name) fout << "NONE\n";

  return 0;
}
