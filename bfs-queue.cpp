#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector <int> adj[10];
int visited[10];

void initialize(int count) {
  for (int i = 0; i < count; i++) {
    visited[i] = 0;
  }
}

void bfs(int at, int n){
  initialize(10);

  queue<int> Q;
  Q.push(at);
  visited[at] = 1;

  while (!Q.empty()) {
    int u = Q.front();
    Q.pop();

    for (int i = 0; i < adj[u].size(); i++) {
      int v = adj[u][i];
      if(!visited[v]){
        visited[v] = 1;
        Q.push(v);
      }
    }
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
      bfs(i, V);
      ++conComp;
    }
  }

  std::cout << "Connected Components: " << conComp << '\n';
}
