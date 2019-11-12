#include <cstdio>
#include <iostream>
const int maxn = 200 + 10;
using namespace std;
int w1[102];
int w2[102];
int f[maxn][maxn];
int main(){
  int n,m,t; cin >> n >> m >> t;
  for(int i=1;i<=n;i++)
    cin >> w1[i] >> w2[i];
  for (int k=1;k<=n;k++)
    for (int i=m;i>0;i--)
      for (int j=t;j>0;j--)
        if (i>=w1[k] && j>=w2[k])
          f[i][j] = max(f[i][j],f[i-w1[k]][j-w2[k]]+1);
  cout << f[m][t];
  return 0;
}