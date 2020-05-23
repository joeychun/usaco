#include <iostream>
#include <stack>

using namespace std;

int main(){
  int N, cnt = 0;
  cin >> N;
  stack<char>st;
  stack<char>stored_st;
  char temp;
  for(int i=0; i<N; i++){
      cin >> temp;
      st.push(temp);
  }

  int points = 0;

  int adj = 1; // checking adjacent letters
  while(st.size()){
    // counting adjacents
    if(stored_st.size() && st.top() == stored_st.top()){
      adj++;  // same alphabet
    } else {
      adj = 1;
    }

    // checking three-in-rows
    if (adj == 3) {
      points++;
      // Breaking the three-adjacent blocks
      stored_st.pop();
      stored_st.pop();
      st.pop();

      // Refilling st with the remainings of stored_st
      while (st.size() && stored_st.size() && st.top() == stored_st.top()) {
        char tmp;
        // Check for two sames in stored_st
        tmp = stored_st.top();
        stored_st.pop();
        if (stored_st.empty()) {
          stored_st.push(tmp);
          break;
        }
        if (stored_st.top() == tmp) {
          points++;
          stored_st.pop();
          st.pop();
          continue;
        } else {
          stored_st.push(tmp);
        }

        // Check for two sames in st
        tmp = st.top();
        st.pop();
        if (st.empty()) {
          st.push(tmp);
          break;
        }
        if (st.top() == tmp) {
          points++;
          st.pop();
          stored_st.pop();
          continue;
        } else {
          st.push(tmp);
        }

      }

      adj = 1;
    }

    // pop and push
    if (st.size()) {
      stored_st.push(st.top());
      st.pop();

    }
  }

  cout << points;
}
