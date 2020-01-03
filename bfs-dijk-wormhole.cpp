#include <iostream>

using namespace std;

struct Node {
  int x, dist;
  Node(){}
  Node(int _x, int _dist){
    x = _x;
    dist = _dist;
  }
};

int x[] = {0,0,1,-1};
int y[] = {1,-1,0,0};
int cost[120][120], dist[600];
int head = 0, tail = 0;

Node qu[1000000];

void _sort() {
  for(int i=head; i<tail; i++){
    for(int j=i+1; j<tail; j++){
      Node a = qu[i];
      Node b = qu[j];
      if(a.dist >= b.dist){
        qu[i] = b;
        qu[j] = a;
      }
    }
  }
}

void _push(Node a){
  qu[tail++] = a;
  _sort();
  // cout << a.x << " " << a.dist << "\n";
}
Node _top(){
  return qu[head++]; // return top and pop
}
int _min(int a, int b){
  return (a < b) ? a : b;
}
int dijk(int s, int d, int total){
  for(int i=1; i<=total; i++)
    dist[i] = 1000000;

  dist[s] = 0;
  _push(Node(s, 0));

  while (head < tail) {
    Node ds = _top();
    int v = ds.x;
    int dis = ds.dist;
    if(v == d){
      return dis;
    }
    for(int i=1; i<=total; i++){
      int cos = dis + cost[v][i];
      if(cos < dist[i]){
        dist[i] = cos;
        _push(Node(i, dist[i]));
      }
    }
  }
  return dist[d];
}

int jar[120][120], trackx[120], tracky[120], cnt;
int make(int a, int b){
  if(jar[a][b] != 0) return jar[a][b];
  jar[a][b] = ++cnt;
  trackx[cnt] = a;
  tracky[cnt] = b;
  return cnt;
}

int main() {
  int sx, sy, dx, dy, holes, a, b, c, d, cst;

  // cnt = 0;
  for(int i=0; i<sizeof(cost)/sizeof(cost[0]); i++)
    for(int j=0; j<sizeof(cost)/sizeof(cost[0]); j++)
      cost[i][j] = -1;

  std::cin >> sx >> sy >> dx >> dy;
  make(sx, sy);
  make(dx, dy);

  std::cin >> holes;
  for(int i=1; i<=holes; i++){
    std::cin >> a >> b >> c >> d >> cst;
    int l = make(a, b);
    int k = make(c, d);
    cost[l][k] = cst;
    cost[k][l] = cst;
  }

  for(int i=1; i<=cnt; i++){
    for(int j=1; j<=cnt; j++){
      int dis = abs(trackx[i]-trackx[j]) + abs(tracky[i]-tracky[j]);
      if(cost[i][j] == -1) cost[i][j] = dis;
      else cost[i][j] = _min(cost[i][j], dis);
    }
  }

  int ans = dijk(jar[sx][sy], jar[dx][dy], cnt);
  std::cout << ans << '\n';
  return 0;
}
