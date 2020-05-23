/*
ID: joey.s.1
LANG: C++
TASK: gift1
*/

#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

int main() {
  ifstream fin ("gift1.in");
  ofstream fout ("gift1.out");

  int n;
  string tmp_name;
  string names_list[15];
  map<string,int> name_ids;
  int money[15] = {0, };

  fin >> n;
  for (int i=0; i<n; ++i) {
    fin >> tmp_name;
    names_list[i] = tmp_name;
    name_ids.insert(pair<string,int>(tmp_name,i));
  }

  int cash,divide,one_person;
  string reciever, giver;
  for (int i=0; i<n; ++i) {
    fin >> giver;
    fin >> cash >> divide;
    money[name_ids.find(giver)->second] -= cash;
    one_person = cash / divide;
    for (int j=0; j<divide; ++j) {
      fin >> reciever;
      money[name_ids.find(reciever)->second] += one_person;
    }
    money[name_ids.find(giver)->second] += cash - one_person*divide;
  }

  for (int i=0; i<n; ++i) {
    fout << names_list[i] << " " << money[name_ids.find(names_list[i])->second] << "\n";
  }

  return 0;
}
