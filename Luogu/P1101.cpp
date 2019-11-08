#include <bits/stdc++.h>
using namespace std;
const int maxn = 100 + 10;
char maze[maxn][maxn];
int v[maxn][maxn];
int n;
const char *str = "yizhong";
int ans_x[7],ans_y[7];
int dx[8] = {1,1,0,-1,-1,-1,0,1};
int dy[8] = {0,1,1,-1,0,-1,-1,-1};
void dfs(int x,int y,int cur,int turn){
  ans_x[cur] = x; ans_y[cur] = y;
  if (cur == 6){
    for (int i=0;i<7;i++) v[ans_x[i]][ans_y[i]] = 1;
    return;
  }
  int xx = x + dx[turn],yy = y + dy[turn];
  if (xx>=0 && xx<n && yy>=0 && yy<n
   && maze[xx][yy]==str[cur+1]){
     dfs(xx,yy,cur+1,turn);
  }
}

int main(){
  cin >> n;
  for (int i=0;i<n;i++) scanf("%s",maze[i]);
  for (int i=0;i<n;i++)
    for (int j=0;j<n;j++){
      if (maze[i][j]=='y')
        for (int k=0;k<8;k++)
          dfs(i,j,0,k);
    }
  for (int i=0;i<n;i++){
    for (int j=0;j<n;j++){
      if (v[i][j]) putchar(maze[i][j]);
      else putchar('*');
    }
    putchar('\n');
  }
  return 0;
}