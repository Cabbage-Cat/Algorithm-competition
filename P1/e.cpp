#include <cstdio>
#include <iostream>
using namespace std;
const int maxn = 50000 + 10;
int fa[maxn];
int v[maxn];
void makeSet(int n){
  for (int i=0;i<=n;i++) fa[i] = i;
}
int find(int x){
  if (fa[x]==x) return x;
  int t = find(fa[x]);
  v[x] += v[fa[x]]; v[x] %=3;
  return fa[x] = t;
}


int main(){
  int n,k; cin >> n >> k; makeSet(n);
  int cnt = 0;
  int d,x,y;
  while (k--){
    scanf("%d%d%d",&d,&x,&y);
    if (x>n||y>n||(d==2&&x==y)) { cnt++; continue; }
    if (d==1){
      int fx = find(x),fy = find(y);
      if (fx==fy){
        if (v[x]!=v[y]) { cnt++; continue;}
      }
      else{
        fa[fx] = fy;
        v[fx] = (3-v[x]+v[y])%3;
      }
    }
    if (d==2){
      int fx = find(x),fy = find(y);
      if (fx==fy && (v[x]-v[y]+3)%3!=1) { cnt++; continue; }
      else if (fx!=fy){
        fa[fx] = fy;
        v[fx] = (3-v[x]+1+v[y])%3;
      }
    }
  }
  cout << cnt << endl;
  for (int i=1;i<=n;i++) cout << v[i] << " ";
  return 0;
}