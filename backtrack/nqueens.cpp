#include <iostream>

using namespace std;

int board[10][10];
int N;

void print() {
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      std::cout << board[i][j] << ' ';
    }
    std::cout << '\n';
  }
  std::cout << '\n';
}

bool isSafe(int row, int col) {
  for(int i=0; i<col; i++){ // row to the left
    if(board[row][i]) return false;
  }
  for(int i=row, j=col; i>=0 && j>=0; i--, j--) {// upper left diagonal
    if(board[i][j]) return false;
  }
  for(int i=row, j=col; i<N && j>=0; i++, j--) {// lower left diagonal
    if(board[i][j]) return false;
  }
  return true;
}

int solve(int col){
  if(col == N){
    print();
    return true;
  }
  int res = false;
  for(int i=0; i<N; i++){
    if(isSafe(i, col)){ // std::cout << i << '\n';
      board[i][col] = 1;
      res = solve(col+1) || res;
      board[i][col] = 0;
    }
  }
  return res;
}

int main() {
  N = 4;
  for(int i=0; i<N; i++)
    for(int j=0; j<N; j++)
      board[i][j] = 0;
  if(!solve(0)){
    std::cout << "No Solution" << '\n';
  }
  return 0;
}
