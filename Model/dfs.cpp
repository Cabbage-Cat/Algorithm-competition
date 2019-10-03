#include <bits/stdc++.h>
using namespace std;
const int maxn = 30 + 5;
int maze[maxn][maxn];
int vis[maxn][maxn];
int n;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
void dfs(int x,int y){
  vis[x][y] = 1;
  for (int i=0;i<4;i++){
    int xx = x+dx[i],yy = y+dy[i];
    if (xx>-1 && xx<n && yy>-1 && yy<n 
      &&maze[xx][yy]==0 &&!vis[xx][yy])
      dfs(xx,yy);
  }
}
int main(){
  cin >> n;
  for (int i=0;i<n;i++)
    for (int j=0;j<n;j++) scanf("%d",&maze[i][j]);
  for (int i=0;i<n;i++) if (maze[0][i]==0) dfs(0,i);
  for (int i=0;i<n;i++) if (maze[n-1][i]==0) dfs(n-1,i);
  for (int i=0;i<n;i++) if (maze[i][0]==0) dfs(i,0);
  for (int i=0;i<n;i++) if (maze[i][n-1]==0) dfs(i,n-1);
  for (int i=0;i<n;i++){
    for (int j=0;j<n;j++){
      if (vis[i][j]) printf("%d ",maze[i][j]);
      else if (maze[i][j]==0) printf("2 ");
      else printf("1 ");
    }
    putchar('\n');
  }
  return 0;
}