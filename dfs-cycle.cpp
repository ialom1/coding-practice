#include <stdio.h>
#include <iostream>

using namespace std;

struct Adj{
  int list[100];
  int k = 0;
};

class Graph{
public:
  int V;
  Adj *adj;
  Graph(int v);
  void addEdge(int u, int v);
  bool isCyclic();
  bool isCyclicUtil(int v, int visited[], int recStack[]);
};

Graph :: Graph(int v){
  V = v;
  adj = new Adj[V];
}
void Graph :: addEdge(int u, int v){
  adj[u].list[adj[u].k++] = v;
}
bool Graph :: isCyclicUtil(int v, int visited[], int recStack[]){
  if(!visited[v]){
    visited[v] = recStack[v] = 1;
    for(int i=0; i<adj[v].k; i++){
      int n = adj[v].list[i];
      if(!visited[n] && isCyclicUtil(n, visited, recStack))
      return true;
      else if(recStack[n])
      return true;
    }
  }
  recStack[v] = 0;
  return false;
}
bool Graph :: isCyclic(){
  int visited[V] = {0};
  int recStack[V] = {0};
  for(int i=0; i< V; i++){
    if(isCyclicUtil(i, visited, recStack))
    return true;
  }
  return false;
}
int main() {
  Graph g(4);
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 2);
  // g.addEdge(2, 0);
  g.addEdge(2, 3);
  // g.addEdge(3, 3);
  // for(int i=0; i<4; i++){
  //   std::cout << g.adj[i].list[0] << '\n';
  // }
  if(g.isCyclic())
    cout << "Graph contains cycle";
  else
    cout << "Graph doesn't contain cycle";
}
