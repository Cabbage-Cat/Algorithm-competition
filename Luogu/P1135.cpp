#include <bits/stdc++.h>
using namespace std;
const int maxn = 200 + 10;
int maze[maxn][maxn];
int d[maxn];
int n,a,b;
int main(){
  cin >> n >> a >> b;
  int x;
  for (int i=1;i<=n;i++){
    cin >> x; 
    if (i+x<=n) maze[i][i+x] = 1;
    if (i-x>0) maze[i][i-x] = 1;
  }
  memset(d,-1,sizeof(d));
  queue<int> q; q.push(a); d[a] = 0;
  while (!q.empty()){
    int x = q.front(); q.pop();
    if (x==b) { break;}
    for (int i=1;i<=n;i++){
      if (maze[x][i] && d[i]==-1){
        d[i] = d[x] + 1;
        q.push(i);
      }
    }
  }
  cout << d[b];

  return 0;
}