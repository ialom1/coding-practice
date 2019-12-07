#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

struct Edge {
  int u, v, w;
};

bool mycomp(Edge A, Edge B) {
  return A.w < B.w;
}

int find(int x, int p[]){
  if(p[x] == x) return x;
  return p[x] = find(p[x], p);
}

void unite(int a, int b, int p[]) {
  int x = find(a, p);
  int y = find(b, p);
  p[x] = y;
}

int krushkal(std::vector<Edge> E, int p[]){
  sort(E.begin(), E.end(), mycomp);
  int ans = 0;
  for(int i = 0; i < E.size(); i++){
    int x = find(E[i].u, p);
    int y = find(E[i].v, p);
    if(x != y){
      // printf("%d %d %d \n", E[i].u, E[i].v, E[i].w);
      unite(E[i].u, E[i].v, p);
      ans += E[i].w;
    }
  }
  return ans;
}

int main() {
  int v, e;
  std::cin >> v >> e;

  std::vector<Edge> E(e);
  int p[v+1];
  for (int i = 0; i < e; i++) {
    std::cin >> E[i].u >> E[i].v >> E[i].w;
  }
  for (int i = 1; i <= v; i++) {
    p[i] = i;
  }

  std::cout << krushkal(E, p) << '\n';
  return 0;
}
