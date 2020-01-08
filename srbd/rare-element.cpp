#include <iostream>

using namespace std;

struct Node{
  int x, y;
  Node(){};
  Node(int _x, int _y){
    x = _x;
    y = _y;
  }
};

Node qu[100];
int ara[100][100];
int dist[100][100];
int vis[100][100];
int head = 0, tail = 0, V, m;
int mx[100], my[100];

void _push(Node n){
  qu[tail++] = n;
  vis[n.x][n.y] = 1;
}
Node _pop(){
  return qu[head++];
}
int isSafe(int i, int j){
  return i>=0 && i<V && j>=0 && j<V && !vis[i][j];
}
int bfs(int sx, int sy){
  for(int i=0; i<V; i++)
    for(int j=0; j<V; j++)
      vis[i][j] = 0;

  _push(Node(sx, sy));
  while (head < tail) {
    Node u = _pop();
    dist[sx][sy] = 0;

    int r[] = {0, 0, 1, -1};
    int c[] = {1, -1, 0, 0};
    for(int i=0; i<4; i++){
      int mx = u.x + r[i];
      int my = u.y + c[i];
      if(isSafe(mx, my)){
        dist[mx][my] = dist[u.x][u.y] + 1;
        _push(Node(mx, my));
        // std::cout << mx << " " << my << " " << dist[mx][my] << '\n';
      }
    }
    // std::cout << '\n';
  }

  int max = -1;
  for(int i=0; i<m; i++){
    int d = dist[mx[i]][my[i]];
    if(d > max) max = d;
  }
  return max;
}

int main() {
  int i,j,k,l;
  std::cin >> V;

  // path grid
  for(int i=0;i<V;i++)
    for(int j=0;j<V;j++)
      std::cin >> ara[i][j];

  std::cin >> m;
  for(i=0;i<m;i++)
    std::cin >> mx[i] >> my[i];

  int min = 2147483647;
  for(int i=0;i<V;i++){
    for(int j=0;j<V;j++){
      if(ara[i][j] == 0) continue;
      int d = bfs(i, j);
      if(d < min) min = d;
    }
  }
  cout << min << endl;
  return 0;
}
