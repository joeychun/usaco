#include <iostream>
#include <fstream>
#include <string>

#define max(x,y) ((x)>(y)?(x):(y))

using namespace std;

int main(){
  int n;
  ifstream ifs;
  ifs.open("blocks.in");

  ifs >> n;

  int it;
  string word1, word2;
  int alpha[26] = {0, };
  for (int i=0; i<n; ++i){
    int alpha1[26] = {0, };
    int alpha2[26] = {0, };
    ifs >> word1 >> word2;
    for (it=0; it<word1.length(); ++it){
      alpha1[int(word1[it])-97] += 1;
    }
    for (it=0; it<word2.length(); ++it){
      alpha2[int(word2[it])-97] += 1;
    }
    for (int i=0; i<26; ++i){
      alpha[i] += max(alpha1[i],alpha2[i]);
    }
  }

  ofstream ofs;
  ofs.open("blocks.out");
  for (int i=0; i<26; ++i){
    ofs << alpha[i];
    ofs << "\n";
  }

  return 0;
}
