#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <queue>

using namespace std;

struct Node{
  int x,y;
};

int dist(Node node1, Node node2){
  return abs(node1.x - node2.x) + abs(node1.y - node2.y);
}

int main() {
  int cases;
  cin >> cases;

  Node node[cases];
  int visited[500][500];
  for (int i = 0; i < cases; i++) {
    std::cin >> node[i].x >> node[i].y;
    visited[node[i].x][node[i].y] = 0;
  }

  queue<Node> Q;
  Q.push(node[0]);
  visited[node[0].x][node[0].y] = 1;
  int len = 0;

  for (int i = 1; i < cases; i++) {
    Node u = Q.back();
    Node v;
    int min = 999999;
    for (int j = 0; j < cases; j++) {
      Node t = node[j];
      if(!visited[t.x][t.y]) {
        int w = dist(u, t);
        if(w < min) {
          v = t;
          min = w;
        }
      }
    }
    Q.push(v);
    visited[v.x][v.y] = 1;
    len += min;
  }
  len += dist(node[0], Q.back());
  for (int i = 0; i < cases; i++) {
    std::cout << Q.front().x << " " << Q.front().y << '\n';
    Q.pop();
  }
  std::cout << len << '\n';

  return 0;
}
