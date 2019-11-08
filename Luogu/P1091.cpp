#include <bits/stdc++.h>
using namespace std;
const int maxn = 100 + 10;
int d[maxn];
int f[2][maxn];
int n;
int main(){
  cin >> n; for (int i=1;i<=n;i++) scanf("%d",d+i);
  for (int i=1;i<=n;i++)
    for (int j=0;j<i;j++)
      if (d[i]>d[j]) f[0][i] = max(f[0][i],f[0][j]+1);
  for (int i=n;i>0;i--)
    for (int j=n+1;j>i;j--)
      if (d[i]>d[j]) f[1][i] = max(f[1][i],f[1][j]+1);
  int res = 0;
  for (int i=1;i<=n;i++) res = max(res,f[0][i]+f[1][i]-1);
  cout << n-res;
  return 0;
}