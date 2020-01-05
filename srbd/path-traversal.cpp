#include <iostream>

using namespace std;
// Problem: Shotest traveral distance
// (Backtrack)
int N;
int X[11], Y[11];
int off[3], hom[3];
int vis[11];

int _minus(int a, int b){
  if(a > b) return a-b;
  return b-a;
}
int track(int u, int k){
  std::cout << k << ' ';
  int ret = 1000000;
  if(k == 0) { // Start
    for(int i=0; i<N; i++){
      vis[i] = 1;
      int dis = _minus(off[0], X[i]) + _minus(off[1], Y[i]);
      int tmp = track(i, k+1) + dis;
      if(tmp < ret) ret = tmp;
      vis[i] = 0;
    }
  }
  else if(k == N) { // Finish
    int dis = _minus(hom[0], X[u]) + _minus(hom[1], Y[u]);
    return dis;
  }
  else {
    for(int i=0; i<N; i++){
      if(!vis[i]) {
        vis[i] = 1;
        int dis = _minus(X[u], X[i]) + _minus(Y[u], Y[i]);
        int tmp = track(i, k+1) + dis;
        if(tmp < ret) ret = tmp;
        vis[i] = 0;
      }
    }
  }
  return ret;
}

int main() {
  int cases;
  std::cin >> cases;
  while (cases--) {
    std::cin >> N;
    std::cin >> off[0] >> off[1] >> hom[0] >> hom[1];
    for(int i=0; i<N; i++){
      std::cin >> X[i] >> Y[i];
      vis[i] = 0;
    }
    std::cout << "Distance: " << track(0, 0) << '\n';
  }
  return 0;
}
