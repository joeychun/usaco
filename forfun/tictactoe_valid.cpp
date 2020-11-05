#include <iostream>
#include <cmath>

using namespace std;

char arr[15]; // input tictactoe array
int check[20000];

int board[5][5]; // board used for recursion; X: 2 / O: 1 / .: 0

int tenary_change_char(char a[]) {
  int val = 0;
  for (int ind=0; ind<9; ++ind) {
    if (a[ind] == 'X') {
      val += pow(3,ind)*2;
    } else if (a[ind] == 'O') {
      val += pow(3,ind)*1;
    }
  }
  return val;
}

int tenary_change_board() {
  int val = 0;
  for (int i=2; i>=0; --i) {
    for (int j=2; j>=0; --j) {
      val += pow(3,3*i+j) * board[i][j];
    }
  }
  return val;
}

void record() {
  int val = tenary_change_board();
  check[val] = 1;
}

void recur(int turn, int sym) { // turn: 1~9
  if (turn == 9) {
    record();
    return;
  }

  // Check if the board shows a winner
  int player;
  int players[2] = {2,1};
  for (int s=0; s<2; ++s) {
    player = players[s];
    if (board[0][0] == player && board[0][1] == player && board[0][2] == player) {
      record();
      return;
    } else if (board[1][0] == player && board[1][1] == player && board[1][2] == player) {
      record();
      return;
    } else if (board[2][0] == player && board[2][1] == player && board[2][2] == player) {
      record();
      return;
    } else if (board[0][0] == player && board[1][0] == player && board[2][0] == player) {
      record();
      return;
    } else if (board[0][1] == player && board[1][1] == player && board[2][1] == player) {
      record();
      return;
    } else if (board[0][2] == player && board[1][2] == player && board[2][2] == player) {
      record();
      return;
    } else if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
      record();
      return;
    } else if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
      record();
      return;
    }
  }

  for (int i=0; i<3; ++i) {
    for (int j=0; j<3; ++j) {
      if (board[i][j] != 2 && board[i][j] != 1) {
        board[i][j] = sym;
        recur(turn+1, 3-sym);
        board[i][j] = 0;
      }
    }
  }


}

int main() {
  char ans[2][15] = {"invalid", "valid"};

  recur(0, 2);

  int val;
  while (1) {
    scanf("%s", arr);
    if (arr[0] == 'e') break;

    // Change arr tictactoe board into a number using tenary
    // X: 2 / O: 1 / .: 0
    printf("%s\n", ans[check[tenary_change_char(arr)]]);
  }
  return 0;
}
