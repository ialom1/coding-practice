#include <iostream>

using namespace std;
#define Max 1000
#define row_size 3
#define col_size 4

// input matrix containing the pipes
int mt[row_size][col_size] = { { 0, 0, 4, 0 },
                               { 1, 3, 6, 0 },
                               { 5, 0, 0, 0 } };
// visited matrix checks for cells already visited
int vi[row_size][col_size];
// calculates the depth of connection for each cell
int depth[row_size][col_size];

struct Node{
  int x, y,d;
  Node(){}
  Node(int _x, int _y, int _dist){
    x = _x;
    y = _y;
    d = _dist;
  }
};
int head = 0, tail = 0;
Node qu[Max];
void _push(Node a){
  qu[tail++] = a;
  vi[a.x][a.y] = 1;
}
Node _pop(){
  return qu[head++];
}

bool _left(int p){
  return p == 1 || p == 3 || p == 6 || p == 7;
}
bool _up(int p){
  return p == 1 || p == 2 || p == 4 || p == 7;
}
bool _right(int p){
  return p == 1 || p == 3 || p == 4 || p == 5;
}
bool _down(int p){
  return p == 1 || p == 2 || p == 5 || p == 6;
}
bool isSafe(int i, int j){
  return (
    i >= 0 && i < row_size &&
    j >= 0 && j < col_size &&
    vi[i][j] == 0
  );
}
void bfs(int x, int y, int d){
  _push(Node(x, y, d));
  while (head < tail) {
    Node temp = _pop();
    int i = temp.x;
    int j = temp.y;
    int c = temp.d;
    depth[i][j] = c;
    std::cout << i << " " << j << ' ';

    if(_right(mt[i][j])){
      if(_left(mt[i][j+1]) && isSafe[i][j+1]){
        _push(Node(i, j+1, c+1));
        std::cout << "right ";
      }
    }
    if(_down(mt[i][j])){
      if(_up(mt[i+1][j]) && isSafe(i+1, j)){
        _push(Node(i+1, j, c+1));
        std::cout << "down ";
      }
    }
    if(_left(mt[i][j])){
      if(_right(mt[i][j-1]) && isSafe(i, j-1)){
        _push(Node(i, j-1, c+1));
        std::cout << "left ";
      }
    }
    if(_up(mt[i][j])){
      if(_down(mt[i-1][j]) && isSafe(i-1, j)){
        _push(Node(i-1, j, c+1));
        std::cout << "up ";
      }
    }
    std::cout << '\n';
  }
}


int main() {
  int x = 1, y = 0; // starting index(x, y),
  int l = 4; // length of probe tool
  for(int i=0; i<row_size; i++)
    for(int j=0; j<col_size; j++){
      vi[i][j] = 0;
      depth[i][j] = Max;
    }

  if(mt[x][y] != 0){
    bfs(x, y, 1);
  }

  int nc = 0;
  for(int i=0; i<row_size; i++)
    for(int j=0; j<col_size; j++){
      if(depth[i][j] <= l){
        cout << "(" << i << ", " << j << ")";
        ++nc;
      }
    }
  std::cout << "\n" << nc << '\n';

  return 0;
}
