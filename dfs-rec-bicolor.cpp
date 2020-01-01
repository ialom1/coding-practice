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
      if(!dfs(v, adj, visited, color)){
        return 0;
      }
    } else if(color[u] == color[v]){
      return 0;
    }
  }
  return 1;
}

int main() {
  int V = 10, E = 9;
  Adj adj[V];

  int u, v;
  for(int i=0; i<E; i++){
    std::cin >> u >> v;
    adj[u].arr[adj[u].k++] = v;
  }

  int visited[V] = {0};
  int color[V] = {0};

  visited[0] = 1, color[0] = 0;
  int res = dfs(1, adj, visited, color);
  std::cout << "Bicolorable: " << res << '\n';
  return 0;
}
