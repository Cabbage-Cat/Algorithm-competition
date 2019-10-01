#include <bits/stdc++.h>
using namespace std;
const int maxn = 6;
int maze[maxn][maxn];
int vis[maxn][maxn];
int bg_x,bg_y,ed_x,ed_y;
int n,m,t;
int total = 0;
int ddx[4] = {1,-1,0,0};
int ddy[4] = {0,0,-1,1};
void dfs(int x,int y){
  if (x==ed_x && y==ed_y) { total+=1; return; }
  for (int i=0;i<4;i++){
    int dx = ddx[i],dy=ddy[i];
    if (x+dx<0 || x+dx>=n || y+dy<0 || y+dy>=m || vis[x+dx][y+dy] || maze[x+dx][y+dy]) continue;
    vis[x+dx][y+dy] = 1;
    dfs(x+dx,y+dy);
    vis[x+dx][y+dy] = 0;
  }
}
int main() {
  cin >> n >> m >> t;
  cin >> bg_x >> bg_y >> ed_x >> ed_y;
  bg_x--;bg_y--;ed_x--;ed_y--;
  int x,y;
  for (int i=0;i<t;i++){
    cin >> x >> y;
    x--;y--;
    maze[x][y] = 1;
  }
  vis[bg_x][bg_y] = 1;
  dfs(bg_x,bg_y);
  cout << total;
  return 0;
}