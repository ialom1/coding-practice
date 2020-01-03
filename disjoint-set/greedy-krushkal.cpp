#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
  int u, v, w;
};

bool mycomp(Edge A, Edge B) {
  return A.w < B.w;
}

std::vector<Edge> E(5);
int p[100];

int find(int x){
  if(p[x] == x) return x;
  return p[x] = find(p[x]);
}

int krushkal() {
  sort(E.begin(), E.end(), mycomp);
  std::cout << "Sorted Edge List" << '\n';
  for(auto i: E) {
    printf("%d %d %d \n", i.u, i.v, i.w);
  }

  std::cout << "Krushkal: " << '\n';
  int ans = 0;
  for(auto i : E){
    if(find(i.u) != find(i.v)){
      printf("%d %d %d \n", i.u, i.v, i.w);
      p[find(i.v)] = find(i.u);
      ans += i.w;
    }
  }
  return ans;
}

int main() {
  E[0].u = 0;
  E[0].v = 1;
  E[0].w = 10;

  // add edge 0-2
  E[1].u = 0;
  E[1].v = 2;
  E[1].w = 6;

  // add edge 0-3
  E[2].u = 0;
  E[2].v = 3;
  E[2].w = 5;

  // add edge 1-3
  E[3].u = 1;
  E[3].v = 3;
  E[3].w = 15;

  // add edge 2-3
  E[4].u = 2;
  E[4].v = 3;
  E[4].w = 4;

  for (size_t i = 0; i < 5; i++) {
    p[i] = i;
  }
  std::cout << "Initial Edge List: " << '\n';
  for(auto i: E) {
    printf("%d %d %d \n", i.u, i.v, i.w);
  }

  std::cout << krushkal() << '\n';
  return 0;
}
