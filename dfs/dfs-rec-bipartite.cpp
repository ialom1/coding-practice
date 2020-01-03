#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct Edge {int x, y;};

int dfs(int v, vector<int> adj[], vector<int> visited, vector<int> color){
  for(int u: adj[v]){
    if(!visited[u]){
      visited[u] = 1;
      color[u] = !color[v];
      if(!dfs(u, adj, visited, color))
        return 0;
    }
    else if(color[u] == color[v])
      return 0;
  }
  return 1;
}

int main() {
  int V = 10;
  vector<Edge> E = {
    {1, 2}, {2, 3}, {2, 8}, {3, 4},
    {4, 6}, {5, 7}, {5, 9}, {8, 9},
    // {2, 4}
    // removing {2, 4} makes it bipartite
  };

  vector<int> adj[V+1];
  vector<int> visited(V+1);
  vector<int> color(V+1);

  for (auto e: E) {
    adj[e.x].push_back(e.y);
    adj[e.y].push_back(e.x);
  }
  visited[1] = 1, color[1] = 0;
  int res = dfs(1, adj, visited, color);
  std::cout << "Bicolorable: " << res << '\n';
}
