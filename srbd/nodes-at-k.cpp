#include <iostream>

int node[101][3];
int ans[101], vis[101];
int cnt, dis, k;

void dfs(int u, int d){
  vis[u] = 1;
  if(d == dis){
    ans[cnt++] = u;
    return;
  }
  for(int i=0; i<3; i++){
    int v = node[u][i];
    if(!vis[v] && v != -1){
      dfs(v, d+1);
    }
  }
}

int main() {
  cnt = 0;
  for(int i=0; i<100; i++){
    for(int j=0; j<3; j++){
      node[i][j] = -1;
    }
    vis[i] = 0;
  }
  int n, u, v;
  char ch;
  std::cin >> n;
  for(int i=0; i<n; i++){
    std::cin >> u >> v >> ch;
    if(ch == 'L') node[u][1] = v;
    if(ch == 'R') node[u][2] = v;
    node[v][0] = u;
  }
  std::cin >> k >> dis;
  dfs(k, 0);
  for(int i=0; i<cnt; i++){
    std::cout << ans[i] << ' ';
  }
  std::cout << '\n';
  return 0;
}
