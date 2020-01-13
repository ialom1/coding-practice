#include <iostream>

using namespace std;

#define MAX 10000

struct Node {
  int x, y, d;
  Node(){}
  Node(int _x, int _y, int _d){
    x = _x;
    y = _y;
    d = _d;
  }
};
Node qu[100];
int dist[100][100];
int vist[100][100];
int head=0, tail=0, cV = 0, V=3;

void _sort(){
  for(int i=head; i<tail; i++){
    for(int j=i+1; j<tail; j++){
      Node n1 = qu[i];
      Node n2 = qu[j];
      if(n1.d > n2.d){
        qu[i] = n2;
        qu[j] = n1;
      }
    }
  }
}

void _push(Node n){
  qu[tail++] = n;
  vist[n.x][n.y] = 1;
  _sort();
}
Node _pop(){
  return qu[head++];
}
int _cost(int ix, int jx){
  return (ix == jx) ? 0 : 1;
}
int isSafe(int i, int j) {
  return i>=0 && i<V && j>=0 && j<V && !vist[i][j];
}

int dijkstra(int grid[][3], int sx, int sy, int dx, int dy){
  for(int i=0; i<V; i++)
    for(int j=0; j<V; j++)
      dist[i][j] = MAX;

  Node st = Node(sx, sy, 0);
  dist[sx][sy] = 0;
  _push(st);

  while(head < tail){
    Node u = _pop();
    int dis = u.d;
    if(u.x == dx & u.y == dy) return dis;

    int rows[] = {0, 0, 1, -1};
    int cols[] = {1, -1, 0, 0};

    for(int i=0; i<4; i++){
      int mx = u.x + rows[i];
      int my = u.y + cols[i];
      if(isSafe(mx, my) && grid[mx][my] != 0){
        int cos = dis + _cost(u.x, mx);
        if(cos < dist[mx][my]){
          dist[mx][my] = cos;
          _push(Node(mx, my, cos));
        }
        std::cout << mx << " " << my << " " << cos << '\n';
      }
    }
    std::cout << '\n';
  }

  return dist[dx][dy];
}

int main() {
  int grid[][3] = {
    1, 1, 1,
    0, 0, 1,
    1, 1, 1
  };

  int sx = 0, sy = 0;
  int dx = 2, dy = 2;
  std::cout << dijkstra(grid, sx, sy, dx, dy) << '\n';
  return 0;
}
