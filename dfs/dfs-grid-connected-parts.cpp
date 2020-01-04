#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

#define ROW 5
#define COL 5

int isSafe(int M[][COL], int row, int col, bool visited[][COL]) {
  return (row >= 0) && (col >= 0) &&
         (row < ROW) && (col < COL) &&
         (M[row][col] && !visited[row][col]);
}

void dfs(int M[][COL], int row, int col, bool visited[][COL]) {
  if(visited[row][col]) return;
  visited[row][col] = true;

  int rowNumber[] = {0, 0, 1, -1, 1, -1, 1, -1};
  int colNumber[] = {-1, 1, 0, 0, -1, 1, 1, -1};
  //
  // int rowNumber[] = {-1,-1,-1, 0,0, 1,1,1};
  // int colNumber[] = {-1,0,1, -1,1, -1,0,1};
  
  for (int i = 0; i < 8; i++) {
    if(isSafe(M, row+rowNumber[i], col+colNumber[i], visited)){
      dfs(M, row+rowNumber[i], col+colNumber[i], visited);
    }
  }
}

int countIslands(int M[][COL]){
  bool visited[ROW][COL];
  memset(visited, 0, sizeof(visited));

  int count = 0;
  for (int i = 0; i < ROW; i++) {
    for (int j = 0; j < COL; j++) {
      if(M[i][j] && !visited[i][j]){
        dfs(M, i, j, visited);
        ++count;
      }
    }
  }
  return count;
}

int main() {
  int M[][COL] = {
    { 1, 1, 0, 0, 0 },
    { 0, 1, 0, 0, 1 },
    { 1, 0, 0, 1, 1 },
    { 0, 0, 0, 0, 0 },
    { 1, 0, 1, 0, 1 }
  };

  std::cout << "Connected Components: " << countIslands(M) << '\n';
}
