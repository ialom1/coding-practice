#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

void dfs (long s, vector<long> adj[], long visited[], long &r) {
  if(visited[s]) return;
  visited[s] = 1;
  for(auto u: adj[s]){
    if(!visited[u]){
      ++r;
      dfs(u, adj, visited, r);
    }
  }
}

int main() {
  long cases, n, m, cr, cl;
  std::cin >> cases;
  while (cases--) {
    std::cin >> n >> m >> cl >> cr;
    std::vector<long> adj[n+1];
    for (long i = 0; i < m; i++) {
      long x, y;
      std::cin >> x >> y;
      adj[x].push_back(y);
      adj[y].push_back(x);
    }
    if(cl < cr){
      std::cout << cl*n << '\n';
    }
    else{
      long visited[n+1] = {0}, r = 0, l = 0;
      for (long i = 1; i <= n; i++) {
        if(!visited[i]){
          ++l;
          dfs(i, adj, visited, r);
          // printf("%d %d %d %d %d \n", i, l, r, cl, cr);
        }
      }
      std::cout << cl*l + cr*(r) << '\n';
    }
  }
  return 0;
}
