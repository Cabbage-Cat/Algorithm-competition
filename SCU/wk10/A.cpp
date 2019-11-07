#include <bits/stdc++.h>
using namespace std;
const int maxn = 20 + 2;
char maze[maxn][maxn];
int vis[maxn][maxn];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,1,-1};
int r,c,res;
void get_bgn(int& x,int &y){
  for (int i=0;i<r;i++)
    for (int j=0;j<c;j++)
      if (maze[i][j] == '@'){ x = i; y = j; return;}
}
void dfs(int x,int y){
  vis[x][y] = 1; res++;
  int xx,yy;
  for (int i=0;i<4;i++){
    xx = x+dx[i];
    yy = y+dy[i];
    if (xx>-1&&xx<r&&yy>-1&&yy<c&&maze[xx][yy]=='.'&&!vis[xx][yy]) dfs(xx,yy);
  }
  return;
}
int main(){
  int bgn_x,bgn_y;
  while (scanf("%d%d",&c,&r)==2 && c){
    res = 0;
    memset(vis,0,sizeof(vis));
    for (int i=0;i<r;i++)
      scanf("%s",maze[i]);
    get_bgn(bgn_x,bgn_y);
    dfs(bgn_x,bgn_y);
    cout << res << endl;
  }
  return 0;
}