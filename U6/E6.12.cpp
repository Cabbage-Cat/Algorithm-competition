#include <cstring>
#include <cstdio>

const int maxn = 100+2;
char maze[maxn][maxn];
int vis[maxn][maxn];
int m,n;
void dfs(int x,int y){
  vis[x][y] = 1;
  for (int dx=-1;dx<=1;dx++)
    for (int dy=-1;dy<=1;dy++){
      if (x+dx>=0 && x+dx<m && y+dy>=0 && y+dy<n && maze[x+dx][y+dy] == '@' && !vis[x+dx][y+dy])
        dfs(x+dx,y+dy);
    }
}
int main(){
  while (scanf("%d%d",&m,&n)==2 &&m &&n){
    for (int i=0;i<m;i++)
      scanf("%s",maze[i]);
    memset(vis,0,sizeof(vis));
    int cnt = 0;
    for (int i=0;i<m;i++)
      for (int j=0;j<n;j++){
        if (maze[i][j] == '@' && !vis[i][j]){
          dfs(i,j); 
          cnt++;
        }
      }
    printf("%d\n",cnt);
  }
  return 0;
}