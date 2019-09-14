#include <bits/stdc++.h>
using namespace std;

int G[5][5];
void fill_edge(int x,int y){
  G[x][y] = 1; G[y][x] = 1;
}
int vis[5][5];
void euler(int u){
  for (int v=0;v<5;v++){
    if (G[u][v] && !vis[u][v]){
      vis[u][v] = vis[v][u] = 1;
      euler(v);
      printf("%d %d\n",u,v);
    }
  }
}
int main(){
  fill_edge(0,1);
  fill_edge(1,2);
  fill_edge(2,3);
  fill_edge(3,4);
  fill_edge(4,0);
  fill_edge(3,0);
  fill_edge(1,3);
  int xx;
  cin >> xx;
  euler(xx);
  return 0;
}