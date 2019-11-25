#include <cstdio>
#include <iostream>
#include <set>
using namespace std;
const int maxn = 1000 + 10;
int fa[maxn];
void makeSet(int n){
  for (int i=0;i<n;i++) fa[i] = i;
}
int find(int x){
  if (fa[x]!=x) fa[x] = find(fa[x]);
  return fa[x];
}
void union_union(int x,int y){
  x = find(x); y = find(y);
  fa[x] = y;
}

int main(){
  int t; cin >> t;
  int n,m;
  int ans=0;
  while (t--){
    cin >> n >> m;
    makeSet(n); ans=0;
    int x,y;
    for (int i=0;i<m;i++){
      cin >> x >> y;
      x--;y--;
      union_union(x,y);
    }
    set<int> s;
    for (int i=0;i<n;i++) s.insert(find(i));
    ans = s.size();
    cout << ans << endl;;
  }
  return 0;
}