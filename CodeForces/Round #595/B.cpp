#include <iostream>

#include <cstring>

using namespace std;
const int MAXN = 200000 + 10;
int fa[MAXN];
int res[MAXN],vis[MAXN];
int p[MAXN];
void init(int n) {
  for (int i = 0; i <= n; i++) fa[i]=i;
}
int find(int u) {
  return fa[u] == u ? fa[u] : fa[u] = find(fa[u]);
}
void unin(int u, int v) {
  int fv = find(v),fu = find(u);
  fa[fv] = fu;
  if (fu!=fv)
    res[fu] += res[fv];
}

int main(){
  int q; cin >> q;
  int n;
  while (q--){
    cin >> n; 
    init(n);for (int i=0;i<=MAXN;i++) res[i] = 1;
    memset(vis,0,sizeof(vis));
    for (int i=1;i<=n;i++) { cin >> p[i]; unin(i,p[i]); }
    // for (int i=1;i<=n;i++){
    //   if (!vis[i]){
    //     vis[i] = 1; res[find(i)]++;
    //     for (int j=i+1;j<=n;j++){
    //       if (vis[j] && find(j)==find(i)) { vis[j]=1; res[find(j)]++; }
    //     }
    //   }
    // }
    for (int i=1;i<=n;i++) cout << res[find(i)] << " ";
    cout << endl;
  }
  return 0;
}