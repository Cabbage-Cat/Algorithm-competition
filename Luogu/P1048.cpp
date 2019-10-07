#include <bits/stdc++.h>
using namespace std;
const int maxn = 10000 + 10;
const int maxc = 100000 + 10;
int w[maxn],v[maxn];
int f[maxc];
int main(){
  int n,m; cin >> n >> m;
  for (int i=1;i<=m;i++)
    scanf("%d%d",w+i,v+i);
  for (int i=1;i<=m;i++)
    for (int c=w[i];c<=n;c++)
      f[c] = max(f[c],f[c-w[i]] + v[i]);
  cout << f[n];
  return 0;
}