#include <bits/stdc++.h>
using namespace std;
const int maxn = 50 + 5;
int n,m;
int bgn_x,bgn_y,end_x,end_y;
int maze[maxn][maxn];
int ans[4][maxn][maxn];
char bgn_face[5];
struct node{
  int face,x,y;
};
int get_face(char *s){
  char turn[5] = {'E','S','W','N'};
  for (int i=0;i<4;i++){
    if (s[0]==turn[i])
      return i;
  }
}
pair<int,int> p[4] = {pair<int,int>(0,1),pair<int,int>(1,0),
                      pair<int,int>(0,-1),pair<int,int>(-1,0)};
node move(node u,int step){
  node v; v.face = u.face; v.x=u.x;v.y=u.y;
  for (int i=0;i<step;i++){
    v.x+=p[v.face].first;
    v.y+=p[v.face].second;
  }
  return v;
}
int turn_time[3] = {1,1,2};
node turn(node u,int t){
  node v; v.face = u.face; v.x=u.x;v.y=u.y;
  if (t==0) v.face = (v.face + 4 - 1)%4;
  else if (t==1) v.face = (v.face + 1)%4;
  else v.face = (v.face+2)%4;
  return v;
}
int main(){
  memset(ans,-1,sizeof(ans));
  cin >> n >> m;
  for (int i=0;i<n;i++)
    for (int j=0;j<m;j++)
      scanf("%d",&maze[i][j]);
  scanf("%d%d%d%d%s",&bgn_x,&bgn_y,&end_x,&end_y,bgn_face); bgn_x--;bgn_y--; end_x--; end_y--;
  node u; u.face = get_face(bgn_face); u.x = bgn_x; u.y = bgn_y; ans[u.face][u.x][u.y] = 0;
  queue<node> q; q.push(u);
  int has_ans = 0;
  while (!q.empty()){
    node v = q.front(); q.pop();
    if (v.x == end_x && v.y == end_y){
      printf("%d",ans[v.face][v.x][v.y]);
      has_ans = 1;
      break;
    }
    for (int i=0;i<3;i++){
      node x = turn(v,i);
      if (ans[x.face][x.x][x.y]==-1)
      { q.push(x); ans[x.face][x.x][x.y] = ans[v.face][v.x][v.y] + turn_time[i]; }
    }
    int x = v.x,y=v.y;
    pair<int,int> cor[4] = { pair<int,int>(x,y),
      pair<int,int>(x,y+1),pair<int,int>(x+1,y),pair<int,int>(x+1,y+1) };
    int dx = p[v.face].first,dy = p[v.face].second;
    for (int step = 1;step<=3;step++){
      int flag = 1;
      // 验证路径是否畅通.
      for (int i=0;i<=step;i++){
        for (int j=0;j<4;j++){
          int xx = cor[j].first + i*dx,yy = cor[j].second + i*dy;
          if (xx<0 || xx>=n || yy<0 || yy>=m || maze[xx][yy]) { flag=0; break; }
        }
        if (!flag) break;
      }
      if (flag){
        node vv; vv.face = v.face; vv.x = x + dx*step; vv.y = y + dy*step;
        if (ans[vv.face][vv.x][vv.y] == -1){
          q.push(vv);
          ans[vv.face][vv.x][vv.y] = ans[v.face][x][y] + 1;
        }
      }
    }
  }
  if (!has_ans) cout << -1;
  return 0;
}