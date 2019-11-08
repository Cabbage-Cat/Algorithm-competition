#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000 + 10;
int n,m;
char maze[maxn][maxn];
int vis[maxn][maxn];
int col[maxn][maxn];
int col_sum[maxn*maxn];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
typedef pair<int,int> P;
int col_cnt = 1;
void dfs(int x,int y,int color){
  col[x][y] = color; col_sum[color]++;
  int xx,yy;
  for (int i=0;i<4;i++){
    xx = x+dx[i]; yy = y+dy[i];
    if (xx>-1&&xx<n&&yy>-1&&yy<n&&maze[xx][yy]!=maze[x][y]&&!col[xx][yy]){
      dfs(xx,yy,color);
    }
  }
}
int main(){
  scanf("%d%d",&n,&m); 
  for (int i=0;i<n;i++){
    scanf("%s",maze[i]);
  }
  for (int i=0;i<n;i++)
    for (int j=0;j<n;j++){
      if (!col[i][j]) dfs(i,j,col_cnt);
      col_cnt++;
    }
  int x,y;
  for (int i=0;i<m;i++){
    scanf("%d%d",&x,&y); x--;y--;
    printf("%d\n",col_sum[col[x][y]]);
  }
  return 0;
}