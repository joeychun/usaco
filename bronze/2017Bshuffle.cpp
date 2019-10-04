/*
ALGORITHM:

Consider the shuffle process as a mathmatical funciton.

IF the second line of the input (order) is
1 3 4 5 2, the shuffle function would be made as

SHUFFLE()
 X -> Y
 1 -> 1
 2 -> 3
 3 -> 4
 4 -> 5
 5 -> 2

Cows get shuffled regarding this SHUFFLE() order. In other words, to see what happened before the shuffle, the cows can be moved by the inverse function.
SHUFFLE-1
 X -> Y
 1 -> 1
 3 -> 2
 4 -> 3
 5 -> 4
 2 -> 5

To see what the cows' order was before 3 shuffles, the inverse function can be ran 3 times.
(In the code, order[] is used as a function.
 x is given by a for loop iteration (since it's just 1,2.., n)
 y is given by cin>> in input line 2.
 Then, order[y] = x )
*/

#include <iostream>
#include <fstream>

using namespace std;

int main() {
  int n; // number of cows
  int location;
  int order[105]; // key to the reverse-shuffle
  int id; // used for scanning cowIds
  int arrangedId[105]; // the original arranged cowId order

  ifstream ifs;
  ifs.open("shuffle.in");
  ifs >> n;

  int i;
  for (i=1; i<=n; ++i) {
    ifs >> location; // SHUFFLE FUNCTION: shuffle is done in  (i --> loc)
    order[location] = i; // INVERSE FUNCTION: reverse-shuffle has to be done in (loc --> i) inverse
  }

  for (i=1; i<=n; ++i) {
    ifs >> id;
    arrangedId[order[order[order[i]]]] = id;
  }

  // Printing
  ofstream ofs;
  ofs.open("shuffle.out");
  for (i=1; i<=n; ++i) {
    ofs << arrangedId[i] << '\n';
  }
  return 0;
}
