#include <iostream>

using namespace std;

#define S 4

int grid[8][8] = {
              { 0, 1, 1, 1 },
              { 1, 0, 0, 0 },
              { 0, 0, 0, 0 },
              { 1, 0, 0, 0 }
            };

int isSafe(int r, int c){
  return r>=0 && r<S && c>=0 && c<S;
}
int up(int r, int c) {
  for(int i=r; i>=r-2 && i>=0; i--){
    if(grid[i][c] != 0) return 0;
  }
  return 1;
}
int down(int r, int c) {
  for(int i=r; i<=r+2 && i<S; i++){
    if(grid[i][c] != 0) return 0;
  }
  return 1;
}
int left(int r, int c) {
  for(int i=c; i>=c-2 && i>=0; i--){
    if(grid[r][i] != 0) return 0;
  }
  return 1;
}
int right(int r, int c) {
  for(int i=c; i<=c+2 && i<S; i++){
    if(grid[r][i] != 0) return 0;
  }
  return 1;
}

int findWays(int x, int y){
  int res = 0;
  if(up(x, y)) { std::cout << "up" << ' ';
    if(isSafe(x-2, y+1)) ++res;
    if(isSafe(x-2, y-1)) ++res;
  }
  if(down(x, y)) { std::cout << "down" << ' ';
    if(isSafe(x+2, y+1)) ++res;
    if(isSafe(x+2, y-1)) ++res;
  }
  if(left(x, y)) { std::cout << "left" << ' ';
    if(isSafe(x+1, y-2)) ++res;
    if(isSafe(x-1, y-2)) ++res;
  }
  if(right(x, y)) { std::cout << "right" << ' ';
    if(isSafe(x+1, y+2)) ++res;
    if(isSafe(x-1, y+2)) ++res;
  }
  return res;
}

int main() {
  int countWays = findWays(2, 2);
  std::cout << countWays << '\n';
  return 0;
}
