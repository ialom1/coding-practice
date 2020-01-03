#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

void dfs(int s, std::vector<int> adj[], int visited[], int &count){
  if(visited[s]) return;
  visited[s] = 1;
  ++count;
  for(auto u: adj[s]){
    dfs(u, adj, visited, count);
  }
}

int main() {
  int N;
  std::cin >> N;

  std::vector<int> adj[2*N + 1];
  for (int i = 0; i < N; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }

  int visited[2*N + 1] = {0};
  int min = 2*N+1, max = -1;
  for (int i = 1; i <= N; i++) {
    if(!visited[i] && adj[i].size()){
      int count = 0;
      dfs(i, adj, visited, count);
      if(count > max) max = count;
      if(count < min) min = count;
      // printf("%d %d %d %d\n", i, count, min, max);
    }
  }
  std::cout << min << " " << max << '\n';
  return 0;
}
