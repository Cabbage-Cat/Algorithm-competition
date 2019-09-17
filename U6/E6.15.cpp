#include <bits/stdc++.h>
using namespace std;

const int maxn = 100 + 10;
int graph[maxn][maxn];
stack<int> topo;
int c[maxn];
int m,n;

bool dfs(int u){
  c[u] = -1;
  for (int v = 1;v<=n;v++){
    if (graph[u][v]){
      if (c[v]<0) return false;
      else if (!c[v]) dfs(v);
    }
  }
  c[u] = 1; topo.push(u);
  return true;
}

int main(){
  while (scanf("%d%d",&n,&m)==2 && m && n){
    memset(graph,0,sizeof(graph));
    memset(c,0,sizeof(c));
    int x,y;
    for (int i=0;i<m;i++){
      scanf("%d%d",&x,&y); 
      graph[x][y] = 1;
    }
    for (int u=1;u<=n;u++) if (!c[u])
      dfs(u);
    while (!topo.empty()){
      printf("%d ",topo.top()); topo.pop();
    }
    printf("\n");
  }

  return 0;
}

