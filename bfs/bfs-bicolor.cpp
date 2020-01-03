#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector <int> adj[100];
int color[100];

// 0 : White
// 1 : Red
// 2 : Blue

void initialize(int count) {
  for (int i = 0; i < count; i++) {
    color[i] = 0;
  }
}

int bfs(int s, int n){
  initialize(n);

  queue<int> Q;
  Q.push(s);
  color[s] = 1;

  while (!Q.empty()) {
    int u = Q.front();
    Q.pop();

    for (int i = 0; i < adj[u].size(); i++) {
      int v = adj[u][i];
      if(!color[v]){
        if(color[u] == 1)
          color[v] = 2;
        else
          color[v] = 1;
        Q.push(v);
      }
      if(color[u] == color[v])
        return 0;
    }
  }
  return 1;
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

  std::cout << "Bicolorable : " << bfs(1, V) << '\n';
}
