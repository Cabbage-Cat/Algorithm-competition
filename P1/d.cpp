#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
int n,m;
const int maxn = 200000 + 10;
int fa[maxn];
int v[maxn];
void makeSet(int n){
  for (int i=0;i<n;i++) fa[i] = i;
}
int find(int x){
  if (fa[x]==x) return x;
  int t = find(fa[x]);
  v[x] += v[fa[x]];
  return fa[x] = t;
}
bool addEdge(int x,int y,int s){
  // y to x;
  int fx,fy; fx = find(x); fy = find(y);
  if (fx!=fy){
    fa[fy] = fx;
    v[fy] = v[x] +s -v[y];
  }
  else{
    if (v[y] - v[x] != s) return false;
  }
  return true;
}
int main(){
  cin >> n >> m;
  int x,y,s,cnt=0;
  makeSet(n+1);
  while (m--){
    scanf("%d%d%d",&x,&y,&s); x--;
    if (!addEdge(x,y,s)) cnt++;
  }
  cout << cnt << endl;
  return 0;
}