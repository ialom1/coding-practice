#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

void bfs(int s, std::vector<int> adj[], int v){
  int dist[v] = {0}, visited[v] = {0};
  queue<int> Q;

  Q.push(s);
  visited[s] = 1;
  dist[s] = 0;

  while (!Q.empty()) {
    int u = Q.front();
    Q.pop();
    for (int i = 0; i < adj[u].size(); i++) {
      int v = adj[u][i];
      if(!visited[v]) {
        visited[v] = 1;
        dist[v] = dist[u] + 6;
        Q.push(v);
      }
    }
  }
  for (int i = 1; i < v; i++) {
    if(i == s) continue;
    else if(dist[i] == 0) std::cout << -1;
    else std::cout << dist[i];
    std::cout << " ";
  }
  std::cout << '\n';
}

int main() {
  int cases;
  std::cin >> cases;

  while (cases--) {
    int v, e, s;;
    std::cin >> v >> e;
    std::vector<int> adj[v + 1];
    for (int i = 0; i < e; i++) {
      int x, y;
      cin >> x >> y;
      adj[x].push_back(y);
      adj[y].push_back(x);
    }
    std::cin >> s;
    bfs(s, adj, (v + 1));
  }
  return 0;
}
