#include <bits/stdc++.h>
using namespace std;
int n,m;
const int maxn = 30000 + 30;
int w[maxn],v[maxn];
int f[maxn];
int main(){
  cin >> m >> n;
  for (int i=1;i<=n;i++)
    scanf("%d%d",w+i,v+i);
  for (int i=1;i<=n;i++)
    for (int c=m;c>=w[i];c--)
      f[c] = max(f[c],f[c-w[i]]+v[i]*w[i]);
  cout << f[m];
  return 0;
}