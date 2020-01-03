#include <iostream>

using namespace std;

struct Adj{
  int arr[1000];
  int k = 0;
};

int dfs(int u, Adj adj[], int visited[], int color[]){
  for(int i=0; i<adj[u].k; i++){
    int v = adj[u].arr[i];
    if(!visited[v]){
      visited[v] = 1;
      color[v] = !color[u];
      if(!dfs(v, adj, visited, color))
        return 0;
    }
    else if(color[u] == color[v])
      return 0;
  }
  return 1;
}

int main() {
  int V, E;
  std::cin >> V >> E;

  Adj adj[V+1];
  int u, v;
  for(int i=0; i<E; i++){
    std::cin >> u >> v;
    adj[u].arr[adj[u].k++] = v; // Directed graph
  }

  int visited[V+1] = {0};
  int color[V+1] = {0};

  visited[1] = 1, color[1] = 0;
  int bipartite = 1;

  for(int i=1; i<=V; i++){
    if(visited[i] == 0) {
      int res = dfs(i, adj, visited, color);
      if(res == 0) {
        bipartite = 0; break;
      }
    }
  }
  std::cout << "Bicolorable: " << bipartite << '\n';
  return 0;
}
