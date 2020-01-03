#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector <int> adj[10];
int visited[10];

void initialize(int count) {
  for (int i = 0; i < count; i++) {
    visited[i] = 0;
  }
}

void dfs(int s){
  stack<int> S;
  S.push(s);

  while(!S.empty()){
    int u = S.top();
    visited[u] = 1; 
    S.pop();

    for(auto v: adj[u]){
      if(!visited[v]) S.push(v);
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
      dfs(i);
      std::cout << i << '\n';
      ++conComp;
    }
  }

  std::cout << "Connected Components: " << conComp << '\n';
}
