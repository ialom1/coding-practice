#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector <int> adj[10];
int visited[10];
int dist[10];
int path[10];

void initialize(int count) {
  for (int i = 0; i < count; i++) {
    visited[i] = 0;
  }
}

void bfs(int s, int n, int t){
  initialize(10);
  queue<int> Q;
  Q.push(s);

  visited[s] = 1;
  dist[s] = 0;
  path[s] = s;

  while (!Q.empty()) {
    int u = Q.front();
    Q.pop();
    for (int i = 0; i < adj[u].size(); i++) {
      int v = adj[u][i];
      if(!visited[v]){
        visited[v] = 1;
        Q.push(v);

        dist[v] = dist[u] + 1;
        path[v] = u;
      }
    }
  }

  if(visited[t] == 0) {
    std::cout << "No Path" << '\n';
  }
  else {
    std::vector<int> P;
    P.push_back(t);
    int now = t;
    while (now != s) {
      std::cout << now << '\n';
      now = path[now];
      P.push_back(now);
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
  bfs(1, V, 5);
}
