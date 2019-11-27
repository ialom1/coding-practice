#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define ROWS 4
#define COLS 4

class Cell {
public:
  int row, col, dist;
  Cell(int x, int y, int w)
  : row(x), col(y), dist(w) {}
};

int isSafe(char grid[ROWS][COLS], int row, int col, int visited[ROWS][COLS]) {
  return (row >= 0) && (col >= 0)
  && (row < ROWS) && (col < COLS)
  && (grid[row][col] != '0' && !visited[row][col]);
}

int bfs(char grid[ROWS][COLS]){
  Cell source(0,0,0);
  int visited[ROWS][COLS];

  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      char t = grid[i][j];
      if(t == 's'){
        source.row = i;
        source.col = j;
      }
      if(t == '0')
        visited[i][j] = 1;
      else
        visited[i][j] = 0;
    }
  }

  queue<Cell> Q;
  Q.push(source);
  visited[source.row][source.col] = 1;

  while (!Q.empty()) {
    Cell u = Q.front();
    Q.pop();
    std::cout << u.row << " " << u.col << '\n';

    if(grid[u.row][u.col] == 'd')
      return u.dist;

    int rowNumber[] = {-1,-1,-1, 0,0, 1,1,1};
    int colNumber[] = {-1,0,1, -1,1, -1,0,1};

    for (int i = 0; i < 8; i++) {
      int row = u.row+rowNumber[i];
      int col = u.col+colNumber[i];
      if(isSafe(grid, row, col, visited)){
        Cell v(row, col, u.dist+1);
        visited[v.row][v.col] = 1;
        Q.push(v);
      }
    }
  }
  return -1;
}

int main() {
  char grid[ROWS][COLS] = {
    { '0', '*', '0', 's' },
    { '*', '0', '*', '*' },
    { '0', '*', '*', '*' },
    { 'd', '*', '*', '*' }
  };
  std::cout << bfs(grid) << '\n';
}
