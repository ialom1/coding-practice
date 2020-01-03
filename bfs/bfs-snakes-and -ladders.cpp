#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void print(std::vector<int> adj[]){
  for(int j = 0; j <= 100; j++){
    std::cout << j << " -> ";
    for(auto i: adj[j])
      std::cout << i << ' ';
    std::cout << '\n';
  }
}

void replaceEdge(std::vector<int> adj[], int oldV, int newV) {
  for (int i = oldV-1; i>=oldV-6 && i>0; i--) {
    replace(adj[i].begin(), adj[i].end(), oldV, newV);
  }
}

void bfs(int start, std::vector<int> adj[], int dist[], int path[]){
  queue<int> Q;
  Q.push(start);
  dist[start] = 0; path[start] = start;
  while(!Q.empty()){
    int u = Q.front(); // std::cout << u << " -> " << '\n';
    Q.pop();
    for(auto v: adj[u]){ // std::cout << v << ' ' << dist[v] << '\n';
      if(dist[v] == -1){
        dist[v] = dist[u] + 1; // std::cout << v << ' ' << dist[v] << '\n';
        path[v] = u;
        Q.push(v);
      }
    }
  }
}

int main() {
  int cases;
  std::cin >> cases;
  while (cases--) {
    int V = 100;
    std::vector<int> adj[V+1];
    for (int i = 1; i <= V; i++) {
      for (int j = i+1; j-i<=6 && j<=V; j++) {
        adj[i].push_back(j);
      }
    }

    int n, m, oldV, newV;
    std::cin >> m; // ladders
    for (int i = 0; i < m; i++) {
      std::cin >> oldV >> newV;
      replaceEdge(adj, oldV, newV);
      adj[oldV].clear();
    }
    std::cin >> n; // snakes
    for (int i = 0; i < n; i++) {
      std::cin >> oldV >> newV;
      replaceEdge(adj, oldV, newV);
      adj[oldV].clear();
    }

    // print(adj);

    int dist[V+1], path[V+1];
    for (int i = 0; i <= V; i++) {
      dist[i] = path[i] = -1;
    }
    bfs(1, adj, dist, path);
    std::cout << dist[100] << '\n';
  }
  return 0;
}
