#include <bits/stdc++.h>
using namespace std;
const int maxn = 100 + 10;
int maze[maxn][maxn];
int r,c;
int dp[maxn][maxn];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int dfs(int x,int y){
  if (dp[x][y]!=1) return dp[x][y];
  int b = 0;
  for (int i=0;i<4;i++){
    int xx = x + dx[i], yy = y + dy[i];
    if (xx>-1&&xx<r&&yy>-1&&yy<c&&maze[xx][yy]>maze[x][y]){
      b = max(b,dfs(xx,yy) + 1);
    }
  }
  dp[x][y] = max(b,dp[x][y]);
  return dp[x][y];
}
int main(){
  cin >> r >> c;
  for (int i=0;i<r;i++)
    for (int j=0;j<c;j++){
      scanf("%d",&maze[i][j]);
      dp[i][j] = 1;
    }
  for (int i=0;i<r;i++)
    for (int j=0;j<c;j++){
      if (dp[i][j]==1) dfs(i,j);
    }
  int res = 0;
  for (int i=0;i<r;i++)
    for (int j=0;j<r;j++)
      if (dp[i][j] > res) res = dp[i][j];
  cout << res;
  
  return 0;
}