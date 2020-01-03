#include <iostream>
#include <vector>

using namespace std;

vector <int> adj[10];
int visited[10];

void initialize(int count) {
  for (int i = 0; i < count; i++) {
    visited[i] = 0;
  }
}

void dfs(int at){
  if(visited[at]) return;
  visited[at] = 1;
  for (int i = 0; i < adj[at].size(); i++) {
    dfs(adj[at][i]);
  }
}

int main() {
  int V, E, x, y, conComp = 0;

  std::cin >> V;
  std::cin >> E;

  for (int i = 0; i < E; i++) {
    std::cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }

  initialize(10);

  for (int i = 0; i < V; i++) {
    if(!visited[i]){
      dfs(i);
      ++conComp;
    }
  }

  std::cout << "Connected Components: " << conComp << '\n';
}
