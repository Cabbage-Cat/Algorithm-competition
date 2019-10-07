#include <bits/stdc++.h>
using namespace std;
const int maxn = 60 + 5;
int t[maxn][3];
int w[maxn],v[maxn];
int n,m;
const int maxc = 32000 + 100;
int f[maxc];
map<int,int> group_cache;
int main(){
  cin >> n >> m;
  int vv,p,q;
  int t_s = 0;
  for (int i=1;i<=m;i++){
    scanf("%d%d%d",&vv,&p,&q);
    w[i] = vv; v[i] = p*vv; 
    if (q==0) { t[++t_s][0] = i; group_cache[i] = t_s; }
    else {
      int pos = 0; while (t[group_cache[q]][pos]!=0) pos++;
      t[group_cache[q]][pos] = i;
      w[i] += w[t[group_cache[q]][pos-1]];
      v[i] += v[t[group_cache[q]][pos-1]];
    } 
  }

  for (int i=1;i<=t_s;i++)
    for (int c=n;c>=w[t[i][0]];c--)
      for (int k=0;t[i][k]!=0&&k<3;k++)
        if (c>=w[t[i][k]])
          f[c] = max(f[c],f[c-w[t[i][k]]] + v[t[i][k]]);
  
  cout << f[n];

  return 0;
}