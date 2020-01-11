#include <iostream>

using namespace std;

int g[6][5] = {
  0, 1, 0, 2, 0,
  0, 2, 2, 2, 1,
  0, 2, 1, 1, 1,
  1, 0, 1, 0, 0,
  0, 0, 1, 2, 2,
  1, 1, 0, 0, 1,
};
int vis[6][5] = {0};

int x, y, r, c, bomb;
void print(int x) {
  for(int i=0; i<5; i++){
    std::cout << g[x][i] << ' ';
  }
  std::cout << '\n';
}
void blast(int x) {
  for(int i=x-1; i>=x-2 && i>=0; i--){
    for(int j=0; j<c; j++){
      if(g[i][j] == 2) g[i][j] = 0;
    }
  }
}
int isSafe(int x, int y) {
  return x >= 0 && x < r && y >= 0 && y < c
  && g[x][y] != 2 && vis[x][y] == 0;
}
int isBlocked(int x, int y){
  return g[x-1][y-1] == 2 && g[x-1][y] == 2 && g[x-1][y+1] == 2;
}

int track(int x, int y, int coins){
  std::cout << x << y << " -> ";
  int ret = 0;
  if(bomb) blast(x);
  if(x == 0) return coins;

  else {
    int r[] = {-1, -1, -1};
    int c[] = {-1, 0, 1};
    for(int i=0; i<3; i++){
      int mx = x + r[i];
      int my = y + c[i];
      if(isSafe(mx, my)){
        vis[mx][my] = 1;
        int res = track(mx, my, coins+g[mx][my]);
        vis[mx][my] = 0;
        if(res > ret) ret = res;
        std::cout << res << " : ";
        print(mx);
      }
    }
  }

  return ret;
}

int main() {
  x=6, y=2, r=6, c=5, bomb=1;

  // for(int i=r-1; i>=0; i--){
  //   for(int j=c-1; j>=0; j--){
  //     std::cin >> g[i][j];
  //   }
  // }

  int coins = track(x, y, 0);

  std::cout << "Max coins: " << coins << '\n';

  return 0;
}
